#pragma once

typedef void LinkStack;

//创建栈
LinkStack* linkStack_Create();


//删除栈
void linkStack_Destroy(LinkStack* stack);

//清空栈
void linkStack_Clear(LinkStack* stack);


//获取栈的大小
int linkStack_Length(LinkStack* stack);


//进栈
int linkStack_Push(LinkStack* stack, void* item);


//出栈
void* linkStack_Pop(LinkStack* stack);


//获取栈顶元素
void* linkStack_Top(LinkStack* stack);



//