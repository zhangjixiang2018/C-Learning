#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void testQueue()
{
	long	arrive;//顾客到达的时间
	int		process_time;//顾客咨询时间长度
	Item item;
	Queue queue;

	initializeQueue(&queue);

	if (queueIsEmpty(&queue))
	{
		printf("The Queue Is Empty\n");
	}
	else
	{
		printf("The Queue Have %d Items\n", queue.items);
	}

	while (scanf("%d %ld", &process_time, &arrive) != EOF)
	{
		item.arrive = arrive;
		item.process_time = process_time;
		
		if (addItem(item, &queue))
		{
			printf("Add Item Suceess\n");
		}
		else
		{
			printf("Add Item Fail\n");
		}
		printf("The Queue Have %d Items\n", queue.items);
		printf("The Queue Have %d Items\n\n", queueItemCount(&queue));
	}

	while (!queueIsEmpty(&queue))
	{
		deItem(&item, &queue);
		printf("item.arrive=%ld    item.process_time=%d\n", item.arrive, item.process_time);
		printf("The Queue Have %d Items\n", queue.items);
	}

	if (queueIsEmpty(&queue))
	{
		printf("The Queue Is Empty\n");
	}
	else
	{
		printf("The Queue Have %d Items\n", queue.items);
	}
}
int main()
{
	
	return 0;
}