#include<stdio.h>
#include<malloc.h>
#include<string.h>

//树的二叉链表示
typedef struct BiNode
{
	int data;
	struct BiNode *lchild, *rchild;
}BiNode,*BiTree;

//二叉树的先序遍历
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


//二叉树的中序遍历
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

//二叉树的后序遍历
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

//求二叉树中叶子节点数
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

//复制树
BiNode* copyTree(BiNode* root)
{
	BiNode* newRoot = NULL;
	BiNode* lchild = NULL;
	BiNode* rchild = NULL;

	if (root == NULL)
	{
		return NULL;
	}

	//构造左子树
	if (root->lchild != NULL)
	{
		lchild = copyTree(root->lchild);
	}
	else
	{
		lchild = NULL;
	}

	//构造右子树
	if (root->rchild != NULL)
	{
		rchild = copyTree(root->rchild);
	}
	else
	{
		rchild = NULL;
	}

	newRoot = (BiNode*)malloc(sizeof(BiNode));//开辟根节点空间
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
	//初始化节点
	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));

	//给节点复制
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//创建树关系
	t1.lchild = &t2;
	t1.rchild = &t3;

	t2.lchild = &t4;

	t3.lchild = &t5;

	printf("二叉树的先序遍历:");
	perOrder(&t1);
	printf("\n");

	printf("二叉树的中序遍历:");
	inOrder(&t1);
	printf("\n");


	printf("二叉树的后序遍历:");
	postOrder(&t1);
	printf("\n");

	int sum = 0;
	leftNodeNum(&t1, &sum);
	printf("leftNodeNum: %d\n", sum);


	//复制树
	printf("复制树\n");
	BiTree p = copyTree(&t1);
	printf("二叉树的后序遍历:");
	postOrder(p);
	printf("\n");
}


int main()
{
	test01();
	return 0;
}