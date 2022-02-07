#include<stdio.h>
#include<malloc.h>
#include<string.h>

//���Ķ�������ʾ
typedef struct BiNode
{
	int data;
	struct BiNode *lchild, *rchild;
}BiNode,*BiTree;

//���������������
void perOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d	", root->data);
	perOrder(root->lchild);
	perOrder(root->rchild);
}


//���������������
void inOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}

	inOrder(root->lchild);
	printf("%d	", root->data);
	inOrder(root->rchild);
}

//�������ĺ������
void postOrder(BiNode* root)
{
	if (root == NULL)
	{
		return;
	}

	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d	", root->data);
}

//���������Ҷ�ӽڵ���
void leftNodeNum(BiNode* node, int* sum)
{
	if (node == NULL)
	{
		return;
	}

	if (node->lchild == NULL && node->rchild == NULL)
	{
		(*sum)++;

	}

	leftNodeNum(node->lchild, sum);
	leftNodeNum(node->rchild, sum);
}

//������
BiNode* copyTree(BiNode* root)
{
	BiNode* newRoot = NULL;
	BiNode* lchild = NULL;
	BiNode* rchild = NULL;

	if (root == NULL)
	{
		return NULL;
	}

	//����������
	if (root->lchild != NULL)
	{
		lchild = copyTree(root->lchild);
	}
	else
	{
		lchild = NULL;
	}

	//����������
	if (root->rchild != NULL)
	{
		rchild = copyTree(root->rchild);
	}
	else
	{
		rchild = NULL;
	}

	newRoot = (BiNode*)malloc(sizeof(BiNode));//���ٸ��ڵ�ռ�
	if (newRoot == NULL)
	{
		return NULL;
	}
	newRoot->lchild = lchild;
	newRoot->rchild = rchild;
	newRoot->data = root->data;

	return newRoot;
}



void test01()
{
	BiNode t1, t2, t3, t4, t5;
	//��ʼ���ڵ�
	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));

	//���ڵ㸴��
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//��������ϵ
	t1.lchild = &t2;
	t1.rchild = &t3;

	t2.lchild = &t4;

	t3.lchild = &t5;

	printf("���������������:");
	perOrder(&t1);
	printf("\n");

	printf("���������������:");
	inOrder(&t1);
	printf("\n");


	printf("�������ĺ������:");
	postOrder(&t1);
	printf("\n");

	int sum = 0;
	leftNodeNum(&t1, &sum);
	printf("leftNodeNum: %d\n", sum);


	//������
	printf("������\n");
	BiTree p = copyTree(&t1);
	printf("�������ĺ������:");
	postOrder(p);
	printf("\n");
}


int main()
{
	test01();
	return 0;
}