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
	char temp[100], i;		//�������
	list *head, *pre, *now;

	head = (list *)malloc(sizeof(list));		//��������,ָ����
	head->next = NULL; 
	pre = head;
	for(i=0; i<5; i++)
	{
		printf("Please input data : ", i);
		scanf("%s", temp);		//��������
		now = (list *)malloc(sizeof(list));		//�����ڴ�
		strcpy(now->data,temp); 
		now->next = NULL; 
		pre->next = now; 
		pre = now;
	}
	pre->next = NULL;

	now=head->next;
	printf("The data is here : \n");		//�������
	while(now!=NULL)
	{
		printf("%s\n",now->data);
		now=now->next;
	}

	now=head->next;
	while(now!=NULL)		//�ͷ��ڴ�
	{
		free(now);
		now=now->next;
	}
	return 0; 
}