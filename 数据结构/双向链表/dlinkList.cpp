#include"dlinkList.h"


typedef struct _tag_DLinkListNode
{
	DlinkListNode header;
	DlinkListNode* slider;
	int length;

}TDLinkListNode;

//1.����˫������
DlinkList* dLinkList_Create()
{
	TDLinkListNode* tlist;

	tlist = (TDLinkListNode*)malloc(sizeof(TDLinkListNode));
	if (tlist == NULL)
	{
		printf("func dLinkList_Create() err. -1 \n");
		return NULL;
	}
	memset(tlist, 0, sizeof(TDLinkListNode));

	return tlist;
}

//2.ɾ��˫������
void dLinkList_Destroy(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	if (tlist == NULL)
	{
		printf("func ddLinkList_Destroy() err. -1 \n");
		return;
	}
	free(tlist);
}

//3.���˫������
void dLinkList_Clear(DlinkList* list)
{

	TDLinkListNode* tlist = (TDLinkListNode*)list;
	if (tlist == NULL)
	{
		printf("func ddLinkList_Destroy() err. -1 \n");
		return;
	}

	tlist->header.next = NULL;
	tlist->slider = NULL;
	tlist->length = 0;
}


//4.��ȡ˫������ĳ���
int dLinkList_Length(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	if (tlist == NULL)
	{
		printf("func dLinkList_Length() err. -1 \n");
		return -1;
	}

	return tlist->length;
}


//5.��˫������List��posλ�ò���ڵ�node
int dLinkList_Insert(DlinkList* list, DlinkListNode* node, int pos)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* current = NULL;
	DlinkListNode* next = NULL;


	if (tlist == NULL || node == NULL || pos < 0)
	{
		printf("func dLinkList_Insert err. -1\n");
		return -1;
	}
	//�ݴ�  ��������λ�ô�������ĳ��ȣ���������β�˲���
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	current = &(tlist->header);//currentָ��ָ��ͷ���
	//currentָ���ƶ���pos-1λ��
	for (int i = 0; (i < pos)&&(current->next!=NULL); i++)
	{
		current = current->next;
	}

	next = current->next;

	current->next = node;//��currentָ������node
	node->next = next;//��node���Ӻ����ڵ�
	
	if (next != NULL)
	{
		next->pre = node;//��nextָ������node
	}

	//����������һ��Ԫ�أ������⴦��
	// ���⴦������Ϊͷ������ʱ����node��preָ��current��
	//��Ϊͷ������ʱnode->preΪ��
	node->pre = current;//��node����ǰ��Ľڵ�
	if (current == &(tlist->header))
	{								
		node->pre = NULL;//��node����ǰ��Ľڵ�
	}

	if (tlist->length == 0)
	{
		tlist->slider = node;//�������һ���ڵ�ʱ�������α�
	}
	

	tlist->length++;

	return 0;
}

//6.ɾ��˫������list��posλ�õĽڵ�
DlinkListNode* dLinkList_Delete(DlinkList* list, int pos)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* current = NULL;
	DlinkListNode* next = NULL;
	DlinkListNode* ret = NULL;


	if (tlist == NULL ||  pos < 0)
	{
		printf("func dLinkList_Delete���� err. -1\n");
		return NULL;
	}
	//�ݴ�  ���ɾ����λ�ô�������ĳ���
	if (pos >= tlist->length)
	{
		printf("func dLinkList_Delete���� err. -2\n");
		return NULL;
	}

	current = &(tlist->header);//currentָ��ָ��ͷ���
	//currentָ���ƶ���pos-1λ��
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	ret = current->next;
	next = ret->next;

	current->next = next;//��currentָ�����Ӻ����ڵ�
	if (next != NULL)
	{
		next->pre = ret->pre;//��nextָ������ǰ���ڵ�
	}

	//���ɾ�������α�ָ��Ľڵ㣬���α����
	if (ret == tlist->slider)
	{
		tlist->slider = ret->next;
	}

	tlist->length--;
	return ret;
}

//7.��ȡ˫������list��posλ�õĽڵ�
DlinkListNode* dLinkList_Get(DlinkList* list, int pos)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* current = NULL;
	DlinkListNode* ret = NULL;


	if (tlist == NULL || pos < 0)
	{
		printf("func dLinkList_Get���� err. -1\n");
		return NULL;
	}
	//�ݴ�  �����ȡ��λ�ô�������ĳ���
	if (pos > tlist->length)
	{
		printf("func dLinkList_Get���� err. -2\n");
		return NULL;
	}

	current = &(tlist->header);//currentָ��ָ��ͷ���
	//currentָ���ƶ���pos-1λ��
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	ret = current->next;
	

	return ret;
}


//8.ɾ��˫������list�е�node�ڵ�
//��������в�����node�ڵ㣬����NULL��ɾ���ɹ�����node
DlinkListNode* dLinkList_DeleteNode(DlinkList* list, DlinkListNode* node)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* current = NULL;
	DlinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL || node==NULL)
	{
		printf("func dLinkList_DeleteNode���� err. -1\n");
		return NULL;
	}
	
	current = &(tlist->header);//currentָ��ָ��ͷ���
	//���������ҵ�node�ڵ��λ�ã�ͨ��λ��ɾ��node�ڵ�
	for (i = 0; i<tlist->length; i++)
	{
		if (current->next == node)
		{
			ret = current->next;
			break;
		}
		current = current->next;
	}

	if (ret != NULL)
	{
		dLinkList_Delete(list, i);
	}

	return ret;
}


//9.�����α�ָ�룬���������ú�Ľڵ�
DlinkListNode* dLinkList_Reset(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset���� err. -1\n");
		return NULL;
	}

	tlist->slider = tlist->header.next;
	ret = tlist->slider;

	return ret;
}

//10.��ȡ�α�ָ�뵱ǰָ��Ľڵ�
DlinkListNode* dLinkList_Current(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Current���� err. -1\n");
		return NULL;
	}

	ret = tlist->slider;

	return ret;
}


//11.���α�ָ�����һ�����������ƶ�ǰָ��Ľڵ�
DlinkListNode* dLinkList_Next(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* ret = NULL;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset���� err. -1\n");
		return NULL;
	}

	if (tlist->slider != NULL)
	{
		ret = tlist->slider;
		tlist->slider = tlist->slider->next;
	}
	
	return ret;
}


//12.���α�ָ��ǰ��һ�����������ƶ�ǰָ��Ľڵ�
DlinkListNode* dLinkList_Pre(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* ret = NULL;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset���� err. -1\n");
		return NULL;
	}

	if (tlist->slider != NULL)
	{
		ret = tlist->slider;
		tlist->slider = tlist->slider->pre;
	}

	return ret;
}
