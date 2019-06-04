#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


typedef int CElementype;
typedef struct CNode
{
	CElementype data;
	struct CNode *next;
}CNode,*CNodeptr;

typedef struct
{
	CNodeptr rear;
	int len;
}CirLinkQueue;

void InitCQueue(CirLinkQueue *Q);
int InsertCQueue(CirLinkQueue *Q, int val);
int DeCQueue(CirLinkQueue *Q, int *e);
void DestroyCQueue(CirLinkQueue *Q);
void ClearCQueue(CirLinkQueue *Q);
void TraverseCQueue(CirLinkQueue *Q);
int LengthCQueue(CirLinkQueue *Q);
