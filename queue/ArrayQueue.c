#include "ArrayQueue.h"


void initQueue(ArrayQueue *Q)
{
	Q->rear = 0;
	Q->front = 0;
}

void printQueue( ArrayQueue *Q )
{

	int i = 0;
	if( isQueueEmpty(Q))
		printf("The ArrayQueue is Empty\n");

	i = Q->front;
	while(i != Q->rear )
	{
		printf("%d ",Q->data[i]);
		i = (i+1) % AQMAXSIZE;
	}
	printf("\n");

}

int isQueueEmpty( ArrayQueue *Q )
{
	return Q->rear == Q->front;
}
/*

 *  ����������˵�3�ִ��?����
 */
int isQueueFull( ArrayQueue *Q )
{
	return (Q->rear + 1)%AQMAXSIZE == Q->front;
}

int EnQueue( ArrayQueue *Q,QAELEMTYPE e )
{
	if (isQueueFull(Q))
	{
		printf("The ArrayQueue is Full\n");

		return -1;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1)%AQMAXSIZE;


	return 1;
}

int DeQueue( ArrayQueue *Q,QAELEMTYPE *e )
{
	if (isQueueEmpty(Q))
	{
		printf("The ArrayQueue is Empty\n");

		return -1;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1)%AQMAXSIZE;
	return 1;
}
int LengthAQueue(ArrayQueue *Q)
{
	int count = (Q->rear + AQMAXSIZE - Q->front)%AQMAXSIZE;
	printf("LengthAQueue:%d\n",count);
	return count;
}
