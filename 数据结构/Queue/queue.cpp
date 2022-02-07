#include<stdlib.h>
#include<stdio.h>
#include "queue.h"

//��ʼ������
void initializeQueue(Queue* pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

//�������Ƿ����������������������true,���򷵻�false
bool queueIsFull(const Queue* pq)
{
	return pq->items == MAXNODES;
}

//�������Ƿ�Ϊ�գ��������Ϊ�շ���true�����򷵻�false
bool queueIsEmpty(const Queue* pq)
{
	return pq->items == 0;
}

//���ض����е�����
int queueItemCount(const Queue* pq)
{
	return pq->items;
}

static void copyToNode(Node* new_node, Item item)
{
	new_node->item = item;
}
//�ڶ���ĩβ����item��Ҫ����ӵ���
//����һ���½ڵ�
//��������½ڵ���
//���ýڵ��nextָ��ΪNULL����ʾ�ýڵ������һ���ڵ�
//���õ�ǰΪ�ڵ��nextָ��ָ���½ڵ㣬���½ڵ����ӵ�������
//��rearָ��ָ���½ڵ㣬�Ա��ҵ����Ľڵ�
//������1
bool addItem(Item item, Queue* pq)
{
	Node* new_node;

	if (queueIsFull(pq) == true)//���������������������м���������
	{
		return false;
	}

	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(1);
	}

	copyToNode(new_node, item);
	new_node->next = NULL;

	if (queueIsEmpty(pq) == true)//����Ϊ��ʱ����λ�ڶ����׶�
	{
		pq->front = new_node;	
	}
	else//���в�Ϊ��ʱ���������ӵ����е�β��
	{
		pq->rear->next = new_node;
	}

	pq->rear = new_node;//��¼����β�˵�λ��
	pq->items++;
	return true;
}

static void copyToItem(Item* pitem, Node* pnode)
{
	*pitem = pnode->item;
}
//�Ӷ��еĿ�ͷɾ���������в�Ϊ�գ������׶˵�item����������*pitem�У�����ɾ�����Һ�������true
//����ò���ʹ�ö���Ϊ�գ������ö���Ϊ�գ���������ڲ���ǰΪ�գ��ú�������false��
bool deItem(Item* pitem, Queue* pq)
{
	Node* pt;//��ʱ����
	if (queueIsEmpty(pq) == true)//����Ϊ��
	{
		return false;
	}

	copyToItem(pitem, pq->front);//ȡ����������

	pt = pq->front;
	pq->front = pq->front->next;//����ָ�����
	free(pt);//�ͷű��Ƴ���Ŀռ�
	pq->items--;

	if (pq->items == 0)
	{
		pq->rear = NULL;
	}

	return true;
}

//��ն���  
void emptyQueue(Queue* pq)
{
	Item item;
	while (!queueIsEmpty(pq))
	{
		deItem(&item, pq);
	}
}

