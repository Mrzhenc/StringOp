//    ���еĵ�����ʵ��
//    ͷ�ڵ㣺�ڱ����ã��������ݣ�������ʼ������ʱʹ��ͷ��βָ��ĵط�
//    �׽ڵ㣺ͷ�ڵ���һ���ڵ㣬������

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int Elementype; //    �����������
//    ����ڵ�ṹ
typedef struct Node {
	Elementype Element; //    �����
	struct Node * Next;
} NODE, *PNODE;

//    ������нṹ��
typedef struct QNode {
	PNODE Front, Rear; //    ����ͷ��βָ��
	int len;
} Queue, *PQueue;

//    ����������
void InitLQueue(PQueue queue); //    �������к���

int IsEmptyLQueue(PQueue queue); //    �ж϶����Ƿ�Ϊ�պ���
void InsertLQueue(PQueue queue, int val); //    ��Ӻ���
void DeleteLQueue(PQueue queue, int * val); //    ���Ӻ���
void DestroyLQueue(PQueue queue); //    �ݻٶ��к���
void TraverseLQueue(PQueue queue); //    ������к���
void ClearLQueue(PQueue queue); //    ��ն��к���
int LengthLQueue(PQueue queue); //    ����г��Ⱥ���
