/*
 * CircleQueue.c
 *
 *  Created on: 2019-2-28
 *      Author: wanglj
 */
#include"CircleQueue.h"
void InitCQueue(CirLinkQueue *Q)
{
	CNodeptr p = NULL;
	p = (CNodeptr)malloc(sizeof(CNode));
	if(p == NULL)
	{
 		printf("InitCQueue Fail ...");
 		exit(-1);
	}
	Q->rear = p;
	Q->rear->next = p;
	Q->len = 0;
}

int InsertCQueue(CirLinkQueue *Q, int val)
{
	CNodeptr p = (CNodeptr)malloc(sizeof(CNode));
		if(p == NULL)
		{
	 		printf("Insert %d Fail ...\n",val);
	 		exit(-1);
		}
		p->data = val;
		p->next = Q->rear->next;
		Q->rear->next = p;
		Q->rear = p;
		Q->len++;
		return 1;
}

int DeCQueue(CirLinkQueue *Q, int *e)
{
	if(Q->rear->next == Q->rear)
	{
		puts("Circle is empty\n");
		return 0;
	}
	CNodeptr p = Q->rear->next;
	*e = p->next->data;
	CNodeptr q = p->next;
	p->next = q->next;
	if(Q->rear == q)
	{
		Q->rear->next = Q->rear;
	}
	printf("DeCQueue::delete %d\n",*e);
	free(q);
	q = NULL;
	Q->len--;
	printf("DeCQueue:Q->len::%d\n",Q->len);
	return 1;
}
void DestroyCQueue(CirLinkQueue *Q)
{
	ClearCQueue(Q);
	free(Q->rear);
	Q->rear = NULL;
}
void ClearCQueue(CirLinkQueue *Q)
{
	while(Q->rear->next != Q->rear)
	{
		int e;
		DeCQueue(Q,&e);
	}
}
void TraverseCQueue(CirLinkQueue *Q)
{
	 	if (Q->rear->next == Q->rear)
		{
	 		puts("TraverseCQueue::CQueue is empty\n");
	 		exit(-1);
	 	}

	 	printf("TraverseLQueue\n");
	 	CNodeptr P = Q->rear->next;
	 	P = P->next;
	 	while (P != Q->rear->next)
		{
	 		printf("%d ", P->data);
	 		P = P->next;
	 	}
	 	printf("\n");
}
int LengthCQueue(CirLinkQueue *Q)
{
	 printf("LengthCQueue:%d\n",Q->len);
	return Q->len;
}
