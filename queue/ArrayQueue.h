#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

 #define AQMAXSIZE 10
  #define QAELEMTYPE int
 //const int N =  10;
 typedef struct 
 {
	 QAELEMTYPE data[AQMAXSIZE];
	 int front;
	 int rear;

 }ArrayQueue;
 //  **ע��˳����еĳ�ʼ��������Q.head=Q.tail=0��Ҳ����Q.head=Q.tail=1�� 
 // 	 ǰ���൱�ڴ�ͷ����������;�����൱�ڲ���ͷ����������**
 void initQueue(ArrayQueue *Q);
  void printQueue(ArrayQueue *Q);
   int isQueueEmpty(ArrayQueue *Q);
   int isQueueFull(ArrayQueue *Q);
   int EnQueue(ArrayQueue *Q,QAELEMTYPE e);
   int DeQueue(ArrayQueue *Q,QAELEMTYPE *e);
   int LengthAQueue(ArrayQueue *Q);
