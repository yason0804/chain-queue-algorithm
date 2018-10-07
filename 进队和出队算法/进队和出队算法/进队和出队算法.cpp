#include <stdio.h>
#include <malloc.h>


#define SUCCESS    1
#define FAIL       0

typedef int ElementType;


/* ��װ��ʽ���еĽڵ� */
typedef struct LinkQueueNode
{
	ElementType NodeData;
	struct LinkQueueNode *next;
}LinkQueueNode, *LinkQueueNode_Ptr;

/*
*Summary: ��ʽ�ӵĽ����㷨��
*Parameters:  head�Ƕ���ָ�룬 last�Ƕ�βָ�룬data��Ҫ���ӵ����ݣ�
*Return: SUCCESS:��ʾ���ӳɹ��� FAIL����ʾ����ʧ�ܣ�
*/
int LinkQueueAdd(LinkQueueNode_Ptr &head, LinkQueueNode_Ptr &last, ElementType data)
{

	LinkQueueNode_Ptr NewNode = (LinkQueueNode_Ptr)malloc(sizeof(LinkQueueNode));
	if (NewNode == NULL) return FAIL;
	
	NewNode->NodeData = data;
	last->next = NewNode;
	last = NewNode;

	printf("��ʽ�ӽ���Ԫ�أ�%d\n", data);

	return SUCCESS;
}

/*
*Summary: ��ʽ�ӵĳ����㷨��
*Parameters: last�Ƕ�βָ�룬first�Ƕ���ָ�룬data����Ҫ���Ե�Ԫ�أ�
*Return: SUCCESS;��ʾ���ӳɹ��� FAIL����ʾ����ʧ�ܣ�
*/
int LinkQueueDel(LinkQueueNode_Ptr &first, LinkQueueNode_Ptr &last, ElementType &data)
{
	//if (first == last) return FAIL;
	
	LinkQueueNode_Ptr p;

	p = first;
	first = p->next;	
	data = p->NodeData;
	
	free(p);

	return SUCCESS;
}



int main()
{

	/* ��ʽ�ӵĽ����㷨 */
	LinkQueueNode_Ptr head, last;
	head = last = (LinkQueueNode_Ptr)malloc(sizeof(LinkQueueNode));

	for (int i = 1; i <= 5; i++)
	{
		LinkQueueAdd(head, last, i);
	}
	last->next = NULL; //����β�������ÿգ�
	
	/* ��ʽ�ӵĳ����㷨 */
	int DelData; //����Ҫ���ӵ�Ԫ�ص�ֵ��

	for (int  i = 1; i <= 5; i++)
	{
		LinkQueueDel(head->next, last, DelData);
		printf("��ʽ�ӳ���Ԫ�أ�%d\n", DelData);
	}

	return 0;
}