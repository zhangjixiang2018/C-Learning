#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stack>

using namespace std;

//���Ķ�������ʾ�������ڵ�
typedef struct BiNode
{
	int data;
	struct BiNode* lchild, * rchild;
}BiNode, * BiTree;


//�������������
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

//һֱ���ߣ�ֱ��������������
BiNode* goLeft(BiNode* root, stack<BiNode*>& s)
{
	if (root == NULL)
	{
		return NULL;
	}

	//�ж�root��û�����ӣ�û�а�root return
	//�����root��ջ
	while (root->lchild != NULL)
	{
		s.push(root);
		root = root->lchild;
	}
	return root;
}

//�������������,�ǵݹ��㷨
void inOrder2(BiNode* root)
{
	stack<BiNode*> s;
	BiNode* t = NULL;

	t = goLeft(root, s);

	while (t)
	{
		printf("%d	", t->data);

		if (t->rchild != NULL)// ����ڵ������������ظ�����1
		{
			t = goLeft(root->rchild, s);//����������������
		}
		else if (!s.empty())//���tû��������������ջ��ָʾ����
		{
			t = s.top();
			s.pop();
		}
		else//���û�������� ��ջΪ��
		{
			t = NULL;
		}

	}
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
	inOrder(&t1);
	printf("\n");

}

int main()
{

	test01();
	return 0;
}