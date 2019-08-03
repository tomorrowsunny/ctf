#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	char data[100]; 
	struct node *next;
}list;

int main()
{
	char temp[100], i;		//定义变量
	list *head, *pre, *now;

	head = (list *)malloc(sizeof(list));		//建立链表,指向结点
	head->next = NULL; 
	pre = head;
	for(i=0; i<5; i++)
	{
		printf("Please input data : ", i);
		scanf("%s", temp);		//输入数据
		now = (list *)malloc(sizeof(list));		//分配内存
		strcpy(now->data,temp); 
		now->next = NULL; 
		pre->next = now; 
		pre = now;
	}
	pre->next = NULL;

	now=head->next;
	printf("The data is here : \n");		//输出数据
	while(now!=NULL)
	{
		printf("%s\n",now->data);
		now=now->next;
	}

	now=head->next;
	while(now!=NULL)		//释放内存
	{
		free(now);
		now=now->next;
	}
	return 0; 
}