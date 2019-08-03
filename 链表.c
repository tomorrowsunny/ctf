#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define tsize 100
struct book{
	char title[tsize];
	struct book *next;
};
void main()
{
	struct book *head=NULL;
	struct book *pre,*now;
	char input[tsize];
	puts("Enter data");
while(gets(input)!=NULL && input[0]!='\0')
	{
		now=(struct book*)malloc(sizeof(struct book));
		if(head==NULL)
			head=now;
		else
			pre->next=now;
		now->next=NULL;
		strcpy(now->title,input);
		//puts("enter");
		while(getchar()!='\n')
			continue;
		puts("Enter");
		pre=now;
	}

	now=head;
	while(now!=NULL)
	{
		printf("%s\n",now->title);
		now=now->next;
	}
	now=head;
	while(now!=NULL)
	{
		free(now);
		now=now->next;
	}
	printf("bye\n");
}