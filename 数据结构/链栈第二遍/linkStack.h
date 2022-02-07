#pragma once

typedef void LinkStack;


//����ջ
LinkStack* linkStack_Create();


//ɾ��ջ
void linkStack_Destroy(LinkStack* stack);


//���ջ
void linkStack_Clear(LinkStack* stack);

//��ȡջ��С
int linkStack_Length(LinkStack* stack);

//��ջ
int linkStack_Push(LinkStack* stack, void* item);


//��ջ
void* linkStack_Pop(LinkStack* stack);


//��ȡջ��Ԫ��
void* linkStack_Top(LinkStack* stack);
