 #include "LinkQueue.h"
 
 //    ������г�ʼ������
 void InitLQueue(PQueue queue)
 {
 	queue->Front = queue->Rear = (PNODE)malloc(sizeof(NODE));    //    ��̬����ͷ�ڵ㣬ʹ��ͷ����βָ��ýڵ�
 	//ͷ�ڵ��൱���ڱ�ڵ�����ã����洢��ݣ�������׽ڵ㣩
 	if (queue->Front == NULL) 
	{        //    �ж��ڴ��Ƿ����ɹ�
 		printf("InitLQueue Fail ...");
 		exit(-1);
 	}
 	queue->Front->Next = NULL;    //    ��ʼ����ͷ�ڵ�ָ��ָ��Ϊ��
 	queue->len = 0;
 	printf("InitLQueue Finish...\n");
 }
 
 //    �����ж϶����Ƿ�Ϊ�պ���
 int IsEmptyLQueue(PQueue queue)
 {
 	if (queue->Front == queue->Rear)
	{
 		printf("LQueue is Empty...\n");
 		return 1;
 	}
 	else
	{
 		//printf("LQueue is not Empty...\n");
 		return 0;
 	}
 
 }
 //    ������Ӻ���
 //    �Ӷ���β���������val
 void InsertLQueue(PQueue queue,int val)
 {
 	PNODE P = (PNODE)malloc(sizeof(NODE));    //    ����һ���½ڵ����ڴ�Ų����Ԫ��
 	if (P == NULL)
	{
 		printf("Insert %d fail...", val);
 		exit(-1);
 	}
 	P->Element = val;    //    ��Ҫ�������ݷŵ��ڵ������
 	queue->len++;
 	P->Next = NULL;        //    �½ڵ�ָ��ָ��Ϊ��
 	queue->Rear->Next = P;    //    ʹ��һ������β���Ľڵ�ָ��ָ���½��Ľڵ�
 	queue->Rear = P;    //    ���¶�βָ�룬ʹ��ָ��������Ľڵ�
 	printf("Insert %d ...\n", val);
 }
 
 //    ������Ӻ���
 //    �Ӷ��е��׽ڵ㿪ʼ����
 //    �����ӳɹ�����val������ֵ
 void DeleteLQueue(PQueue queue,int* val)
 {
	 PNODE  P = NULL;
 	if (IsEmptyLQueue(queue))
	{
 		printf("LQueue is Empty,delete fail...\n");
 		exit(-1);
 	}
 	P= queue->Front->Next;    //    ��ʱָ��
 	*val = P->Element;    //    ������ֵ
 	queue->Front->Next = P->Next;        //    ����ͷ�ڵ�
 	if (queue->Rear==P)
 		queue->Rear = queue->Front;
 	free(P);    //    �ͷ�ͷ����
 	queue->len--;
 	P = NULL;    //    ��ֹ����Ұָ��
 	printf("Delete %d\n", *val);
 }
 //    ������б�����
 void TraverseLQueue(PQueue queue)
 {
	 PNODE P = queue->Front->Next;    //�Ӷ����׽ڵ㿪ʼ�����ͷ�ڵ㣬ע����֣�
 
 	if (IsEmptyLQueue(queue))
	{
 		exit(-1);
 	}        
 	printf("TraverseLQueue\n");
 	while (P != NULL) 
	{
 		printf("%d ", P->Element);
 		P = P->Next;
 	}
 	printf("\n");
 }
 //    ������еĴݻٺ���
 //    ɾ��������У�����ͷ�ڵ�
 void DestroyLQueue(PQueue queue)
 {
	 ClearLQueue(queue);
	 free(queue->Front);
	 queue->Front = queue->Rear = NULL;

 	printf("DestroyLQueue finish...\n");
 }
 //    ������ն��к���
 void ClearLQueue(PQueue queue)
 {
	 while(!IsEmptyLQueue(queue))
	 {
		 int e;
		 DeleteLQueue(queue,&e);
	 }

 	printf("ClearLQueue finish...\n");
 
 }
 int LengthLQueue(PQueue queue)
 {
	 if(queue->Front != NULL)
	 {
		 printf("LengthLQueue:%d\n",queue->len);
		 return queue->len;
	 }

	 else
	 {
		 exit(-1);
	 }
 }
