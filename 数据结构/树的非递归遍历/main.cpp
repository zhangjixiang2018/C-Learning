#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stack>

using namespace std;

//树的二叉链表示法，树节点
typedef struct BiNode
{
	int data;
	struct BiNode* lchild, * rchild;
}BiNode, * BiTree;


//二叉树中序遍历
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

//一直左走，直到中序遍历的起点
BiNode* goLeft(BiNode* root, stack<BiNode*>& s)
{
	if (root == NULL)
	{
		return NULL;
	}

	//判断root有没有左孩子，没有把root return
	//如果有root入栈
	while (root->lchild != NULL)
	{
		s.push(root);
		root = root->lchild;
	}
	return root;
}

//二叉树中序遍历,非递归算法
void inOrder2(BiNode* root)
{
	stack<BiNode*> s;
	BiNode* t = NULL;

	t = goLeft(root, s);

	while (t)
	{
		printf("%d	", t->data);

		if (t->rchild != NULL)// 如果节点有右子树，重复步骤1
		{
			t = goLeft(root->rchild, s);//右子树中序遍历起点
		}
		else if (!s.empty())//如果t没有右子树，根据栈顶指示回退
		{
			t = s.top();
			s.pop();
		}
		else//如果没有右子树 并栈为空
		{
			t = NULL;
		}

	}
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

	printf("二叉树的中序遍历:");
	inOrder(&t1);
	printf("\n");

}

int main()
{

	test01();
	return 0;
}