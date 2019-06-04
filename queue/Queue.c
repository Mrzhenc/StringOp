/*
 ============================================================================
 Name        : Queue.c
 Author      : wanglijuan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"
#include "ArrayQueue.h"
#include"CircleQueue.h"
#define OPT_SRC 1
int main(void)
{

	//顺序数组
#if 0 == OPT_SRC
	int i;
	int e;
	ArrayQueue Q;
	initQueue(&Q);
	EnQueue(&Q,1);
	EnQueue(&Q,2);
	EnQueue(&Q,3);
	EnQueue(&Q,4);
	EnQueue(&Q,5);
	EnQueue(&Q,6);
	EnQueue(&Q,7);
	EnQueue(&Q,8);
	EnQueue(&Q,9);
	i = EnQueue(&Q,10);
	i = EnQueue(&Q,11);
	LengthAQueue(&Q);
	printf("new ArrayQueue：\n");
	printQueue(&Q);
	printf("frist DeQueue：\n");
	DeQueue(&Q,&e);
	LengthAQueue(&Q);
	printf("second DeQueue：\n");
	DeQueue(&Q,&e);
	LengthAQueue(&Q);
	printf("new ArrayQueue：\n");
	printQueue(&Q);
#endif

	//单项链表
#if 1 == OPT_SRC
	int val;
	Queue queue;    //    �������б���
	InitLQueue(&queue);    //    ���ó�ʼ�����к���
	IsEmptyLQueue(&queue);    //    �����ж϶����Ƿ�Ϊ�պ���
	InsertLQueue(&queue, 100);    //������Ӻ���
	InsertLQueue(&queue, 200);
	LengthLQueue(&queue);
	InsertLQueue(&queue, 300);
	InsertLQueue(&queue, 400);
	InsertLQueue(&queue, 500);
	InsertLQueue(&queue, 600);
	LengthLQueue(&queue);
	IsEmptyLQueue(&queue);
	TraverseLQueue(&queue);    //    ���ö��б�����
	DeleteLQueue(&queue, &val);    //    ���ó��Ӻ���
	LengthLQueue(&queue);
	TraverseLQueue(&queue);
	ClearLQueue(&queue);        //    ������ն��к���
	LengthLQueue(&queue);
	IsEmptyLQueue(&queue);
	DestroyLQueue(&queue);    //    ���ôݻٶ��к���
	LengthLQueue(&queue);
#endif

	//   循环链表
#if 2 == OPT_SRC
	int e;
	CirLinkQueue Cq;
	InitCQueue(&Cq);
	InsertCQueue(&Cq,1);
	InsertCQueue(&Cq,2);
	InsertCQueue(&Cq,3);
	InsertCQueue(&Cq,4);
	TraverseCQueue(&Cq);
	LengthCQueue(&Cq);
	DeCQueue(&Cq,&e);
	TraverseCQueue(&Cq);
	LengthCQueue(&Cq);
	//DeCQueue(&Cq,&e);
	ClearCQueue(&Cq);
	TraverseCQueue(&Cq);
	LengthCQueue(&Cq);
	DestroyCQueue(&Cq);
	LengthCQueue(&Cq);
#endif
	//////////////////////////////////////




	return EXIT_SUCCESS;
}
