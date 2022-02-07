#pragma once

typedef void SeqStack;


//
SeqStack* seqStack_Create(int capacity);


//
void seqStack_Destroy(SeqStack* stack);


//
void seqStack_Clear(SeqStack* stack);


//
int seqStack_Capacity(SeqStack* stack);


//
int seqStack_Length(SeqStack* stack);


//
int seqStack_Push(SeqStack* stack, void* node);


//
void* seqStack_Pop(SeqStack* stack);


//
void* seqStack_Top(SeqStack* stack);
