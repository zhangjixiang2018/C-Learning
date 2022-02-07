#include<stdio.h>
#include<string.h>
#include<malloc.h>

//���Ķ�������ʾ�������ڵ�
typedef struct BiNode
{
	int date;
	struct BiNode* lchild, * rchild;
}BiNode, *BiTree;

//�������������
void perOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d	", root->date);
	perOrder(root->lchild);
	perOrder(root->rchild);
}


//�������������
void inOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}

	inOrder(root->lchild);
	printf("%d	", root->date);
	inOrder(root->rchild);
}

//�������������
void postOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}

	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d	", root->date);

}

//������
BiTree copyTree(BiNode* t)
{
	BiNode* newRoot = NULL;//���ڵ�
	BiNode* newlc = NULL;//����
	BiNode* newrc = NULL;//�Һ���

	if (t == NULL)
	{
		return NULL;
	}

	//��������
	if (t->lchild != NULL)
	{
		newlc = copyTree(t->lchild);
	}
	else
	{
		newlc = NULL;
	}

	//�����Һ���
	if (t->rchild != NULL)
	{
		newrc = copyTree(t->rchild);
	}
	else
	{
		newrc = NULL;
	}

	//���ٸ��ڵ�ռ�
	newRoot = (BiNode*)malloc(sizeof(BiNode));
	if (newRoot == NULL)
	{
		return NULL;
	}

	newRoot->lchild = newlc;//��������
	newRoot->rchild = newrc;//�����Һ���
	newRoot->date = t->date;//��������

	return newRoot;

}

//���Ķ�������ʾ��
void test01()
{
	
	//��ջ�Ͽ��ٿռ�
	BiNode t1, t2, t3, t4, t5;
	
	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));

	t1.date = 1;
	t2.date = 2;
	t3.date = 3;
	t4.date = 4;
	t5.date = 5;

	//������֮�����ϵ
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;


	printf("���������������	");
	perOrder(&t1);
	printf("\n");


	printf("���������������	");
	inOrder(&t1);
	printf("\n");


	printf("���������������	");
	postOrder(&t1);
	printf("\n");

	//
	printf("���ƶ�����\n");
	BiTree tree = NULL;
	tree = copyTree(&t1);
	if (tree == NULL)
	{
		printf("func test01() copy tree.\n");
	}
	printf("���������������	");
	perOrder(tree);
	printf("\n");

	/*
	//�ڶ��Ͽ��ٿռ�
	BiTree p1, p2, p3, p4, p5;
	p1 = (BiTree)malloc(sizeof(BiNode));
	p2 = (BiTree)malloc(sizeof(BiNode));
	p3 = (BiTree)malloc(sizeof(BiNode));
	p4 = (BiTree)malloc(sizeof(BiNode));
	p5 = (BiTree)malloc(sizeof(BiNode));

	//��ʼ���ռ�
	memset(p1, 0, sizeof(BiNode));
	memset(p2, 0, sizeof(BiNode));
	memset(p3, 0, sizeof(BiNode));
	memset(p4, 0, sizeof(BiNode));
	memset(p5, 0, sizeof(BiNode));

	p1->date = 1;
	p2->date = 2;
	p3->date = 3;
	p4->date = 4;
	p5->date = 5;

	//��������ϵ
	p1->lchild = p2;
	p1->rchild = p3;
	p2->lchild = p4;
	p3->lchild = p5;

	printf("���������������	");
	perOrder(p1);
	printf("\n");


	printf("���������������	");
	inOrder(p1);
	printf("\n");


	printf("���������������	");
	postOrder(p1);
	printf("\n");
	*/


}


int main()
{
	test01();
	return 0;
}