#include<stdio.h>
#include<string.h>
#include<malloc.h>

//树的二叉链表示法，树节点
typedef struct BiNode
{
	int date;
	struct BiNode* lchild, * rchild;
}BiNode, *BiTree;

//二叉树先序遍历
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


//二叉树中序遍历
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

//二叉树后序遍历
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

//复制树
BiTree copyTree(BiNode* t)
{
	BiNode* newRoot = NULL;//根节点
	BiNode* newlc = NULL;//左孩子
	BiNode* newrc = NULL;//右孩子

	if (t == NULL)
	{
		return NULL;
	}

	//拷贝左孩子
	if (t->lchild != NULL)
	{
		newlc = copyTree(t->lchild);
	}
	else
	{
		newlc = NULL;
	}

	//拷贝右孩子
	if (t->rchild != NULL)
	{
		newrc = copyTree(t->rchild);
	}
	else
	{
		newrc = NULL;
	}

	//开辟根节点空间
	newRoot = (BiNode*)malloc(sizeof(BiNode));
	if (newRoot == NULL)
	{
		return NULL;
	}

	newRoot->lchild = newlc;//连接左孩子
	newRoot->rchild = newrc;//连接右孩子
	newRoot->date = t->date;//复制数据

	return newRoot;

}

//树的二叉链表示法
void test01()
{
	
	//在栈上开辟空间
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

	//创建树之间的联系
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;


	printf("二叉树先序遍历：	");
	perOrder(&t1);
	printf("\n");


	printf("二叉树中序遍历：	");
	inOrder(&t1);
	printf("\n");


	printf("二叉树后序遍历：	");
	postOrder(&t1);
	printf("\n");

	//
	printf("复制二叉树\n");
	BiTree tree = NULL;
	tree = copyTree(&t1);
	if (tree == NULL)
	{
		printf("func test01() copy tree.\n");
	}
	printf("二叉树先序遍历：	");
	perOrder(tree);
	printf("\n");

	/*
	//在堆上开辟空间
	BiTree p1, p2, p3, p4, p5;
	p1 = (BiTree)malloc(sizeof(BiNode));
	p2 = (BiTree)malloc(sizeof(BiNode));
	p3 = (BiTree)malloc(sizeof(BiNode));
	p4 = (BiTree)malloc(sizeof(BiNode));
	p5 = (BiTree)malloc(sizeof(BiNode));

	//初始化空间
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

	//建立树联系
	p1->lchild = p2;
	p1->rchild = p3;
	p2->lchild = p4;
	p3->lchild = p5;

	printf("二叉树先序遍历：	");
	perOrder(p1);
	printf("\n");


	printf("二叉树中序遍历：	");
	inOrder(p1);
	printf("\n");


	printf("二叉树后序遍历：	");
	postOrder(p1);
	printf("\n");
	*/


}


int main()
{
	test01();
	return 0;
}