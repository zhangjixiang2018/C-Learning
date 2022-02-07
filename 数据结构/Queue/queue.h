#ifndef QUEUE_H_
#define QUEUE_H_
#define MAXNODES 10;//�������ڵ���

typedef struct item
{
	long	arrive;//�˿͵����ʱ��
	int		process_time;//�˿���ѯʱ�䳤��
}Item;

typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef struct queue
{
	Node* front; //ָ����������ָ��
	Node* rear; //ָ�����β���ָ��
	int items;//�����е�����
}Queue;

void initializeQueue(Queue* pq);//��ʼ������
bool queueIsFull(const Queue* pq);//�������Ƿ����������������������true,���򷵻�false
bool queueIsEmpty(const Queue* pq);//�������Ƿ�Ϊ�գ��������Ϊ�շ���true�����򷵻�false
int queueItemCount(const Queue* pq);//���ض����е�����
bool addItem(Item item , Queue* pq);//�ڶ���ĩβ����item��Ҫ����ӵ���
//�Ӷ��еĿ�ͷɾ���������в�Ϊ�գ������׶˵�item����������*pitem�У�����ɾ�����Һ�������true
//����ò���ʹ�ö���Ϊ�գ������ö���Ϊ�գ���������ڲ���ǰΪ�գ��ú�������false��
bool deItem(Item* pitem, Queue* pq);
void emptyQueue(Queue* pq);//��ն���  
                                   

#endif // !QUEUE_H_

