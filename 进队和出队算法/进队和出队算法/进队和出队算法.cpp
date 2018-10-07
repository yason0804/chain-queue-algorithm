#include <stdio.h>
#include <malloc.h>


#define SUCCESS    1
#define FAIL       0

typedef int ElementType;


/* 封装链式队列的节点 */
typedef struct LinkQueueNode
{
	ElementType NodeData;
	struct LinkQueueNode *next;
}LinkQueueNode, *LinkQueueNode_Ptr;

/*
*Summary: 链式队的进队算法；
*Parameters:  head是对首指针， last是队尾指针，data是要进队的数据；
*Return: SUCCESS:表示进队成功； FAIL：表示进队失败；
*/
int LinkQueueAdd(LinkQueueNode_Ptr &head, LinkQueueNode_Ptr &last, ElementType data)
{

	LinkQueueNode_Ptr NewNode = (LinkQueueNode_Ptr)malloc(sizeof(LinkQueueNode));
	if (NewNode == NULL) return FAIL;
	
	NewNode->NodeData = data;
	last->next = NewNode;
	last = NewNode;

	printf("链式队进队元素：%d\n", data);

	return SUCCESS;
}

/*
*Summary: 链式队的出队算法；
*Parameters: last是队尾指针，first是队首指针，data保存要出对的元素；
*Return: SUCCESS;表示出队成功； FAIL：表示出队失败；
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

	/* 链式队的进队算法 */
	LinkQueueNode_Ptr head, last;
	head = last = (LinkQueueNode_Ptr)malloc(sizeof(LinkQueueNode));

	for (int i = 1; i <= 5; i++)
	{
		LinkQueueAdd(head, last, i);
	}
	last->next = NULL; //将队尾的链域置空；
	
	/* 链式队的出队算法 */
	int DelData; //保存要出队的元素的值；

	for (int  i = 1; i <= 5; i++)
	{
		LinkQueueDel(head->next, last, DelData);
		printf("链式队出队元素：%d\n", DelData);
	}

	return 0;
}