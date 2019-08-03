#include<stdio.h>
#define N 17
int str[N][N];
int main()
{
	void home();
	void compete();
	void computer();
	int i,m;
	for(i=0;i<100;i++)
	{
		system("CLS");
		home();
		scanf("%d",&m);
		switch(m)
		{
			case 1: compete();break;
			case 2: computer();break;
			default: return 0;
		}
	}
	return 0;
}
void home()
{
	int i;
	printf("\n\n\n\n\n\n");

	printf("\t\t\t\t\t");
	for(i=0;i<51;i++)printf("*");
	printf("\n\n");

	printf("\t\t\t\t\t 五\t\t\t子\t\t\t棋\n\n");
	printf("\t\t\t\t\t");
	for(i=0;i<51;i++)printf("*");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\tPlease choose what do you want:\n\n\n");
	printf("\t\t\t\t\t\t  1.Play with players\n\n");
	printf("\t\t\t\t\t\t  2.play with computer\n\n");
	printf("\t\t\t\t\t\t  3.exit program\n\n\n\n\n\n");
	printf("\t\t\t\t\tYour choice : ");
}
void compete()
{
	void picture();
	int judge(int x,int y);
	int i,winner,x,y;
	picture();
	printf("\t\t\tPlease intput (x y):\t( ");
	for(i=0;i<N*N;i++)
	{
		scanf("%d %d",&x,&y); 
		y=N-y;
		getchar();
		if(str[y][x]!=0 || x<0 || x>N || y<0 || y>N)
		{
			printf("\t\t\tPlease choose the right place\n");
			i=i-1;
			continue;
		}
		winner=i%2+1;
		str[y][x]=winner;
		
		picture();
		if(judge(x,y)==1)break;
		if(i%2==1) printf("\t\t\tBlack's turn :  ");
		else printf("\t\t\tWhite's turn :  ");
	}
	if(winner==1)printf("black win !");
	else printf("white win !");
}

void computer()
{
	//
}
int judge(int x,int y)
{
	int j1(int x,int y);
	int j2(int x,int y);
	int j3(int x,int y);
	int j4(int x,int y);
	int i;
	if(j1(x,y)==5 || j2(x,y)==5 || j3(x,y)==5 || j4(x,y)==5)return 1;
	else return 0;

}
int j1(int x,int y)
{
	int p,k;
	for(p=1,k=1;k<6;k++)
		if(y-k>=0 && str[y-k][x]==1)p++;
		else break;
	for(k=1;k<6;k++)
		if(y+k<=N && str[y+k][x]==1)p++;
		else break;
	return p;
}	
int j2(int x,int y)
{
	int p,k;
	for(p=1,k=1;k<6;k++)
		if(x-k>=0 && str[y][x-k]==1)p++;
		else break;
	for(k=1;k<6;k++)
		if(x+k<=N && str[y][x+k]==1)p++;
		else break;
	return p;
}
int j3(int x,int y)
{
	int p,k;
	for(p=1,k=1;k<6;k++)
		if(y-k>=0 && x+k<=N && str[y-k][x+k]==1)p++;
		else break;
	for(k=1;k<6;k++)
		if(y+k<=N && x-k>=0 && str[y+k][x-k]==1)p++;
		else break;
	return p;
}
int j4(int x,int y)
{
	int p,k;
	for(p=1,k=1;k<6;k++)
		if(y+k<=N && x+k<=N && str[y+k][x+k]==1)p++;
		else break;
	for(k=1;k<6;k++)
		if(y-k>=0 && x-k>=0 && str[y-k][x-k]==1)p++;
		else break;
	return p;
}
void picture()											
{
	int x,y,i;
	system("CLS");
	printf("\t五子棋对弈:");
	printf("\n\t\t\t\t   ");
	for(i=0;i<N;i++)printf("   __");
	
	printf("\n\n");
	for(y=0;y<N;y++)
	{
		printf("\t\t\t\t%2d|  ",17-y);
		for(x=1;x<=N;x++)
		{
			switch(str[y][x])
			{
				case 0: printf(" ·  ");break;
				case 1: printf(" ●  ");break;
				default: printf(" ○  ");
			}	
		}
		printf("  |\n\n");
	}

	printf("\t\t\t\t  |");
	for(i=0;i<N;i++)printf("   __");
	printf("\n\t\t\t\t");
	for(i=0;i<=N;i++)printf(" %2d  ",i);
	printf("\n\n");
}
