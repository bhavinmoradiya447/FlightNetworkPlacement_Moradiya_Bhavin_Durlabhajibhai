#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
char name[20];
struct node *link;
};
struct node *first='\0';
struct node *newnode ='\0',*temp;


void adddetail(char []);
void Eliminate(int);
void show();

void main()
{
int ch,i,M,N,flag=0;
char name[20];
clrscr();

	do
	{
		if(first->link==first)
		{
			printf("\n\t 1) %s Won the game. ",first->name);
			getch();
			exit(0);
		}

		printf("\n\n\tEnter 1 for  \'Enter kids name.\' \n");
		printf("\tEnter 2 for  \'Rendom selection of number to Eleminate kid.\' \n");
		printf("\tEnter 3 for  \'Show position of kids.\' \n");
		printf("\tEnter 4 for  \'Exit.\' \n");
		printf("\nEnter your choice ::");
		scanf("%d",&ch);
			switch(ch)
			{
				case 1:	if(flag==1)
							{printf("\n You has already entered kids name");break;}
						repeat:
						printf("\nENTER NUMBER OF KIDS:");
						scanf("%d",&M);
						if(M<=0)
						{
						printf("\n Invalid entry enter again. ");
						goto repeat;
						}
						for(i=1;i<=M;i++)
						{
						printf("\nEnter name of kid %d : ",i);
						flushall();
						scanf("%[^\n]",name);
						adddetail(name);  //This function add the node into link list
						}
						flag=1;
				break;
				case 2: N=random(M-1)+1;
						printf("\n Random Number is  %d",N);
						Eliminate(N);	
				break;
				case 3:
						show();
				break;
				case 4: exit(0);
				break;
				default :printf("\n Enter correct option::");
				break;
			}
	
	}while(ch!=4);
	
	
}


void adddetail(char name[])
{
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode =='\0')
	{
	printf("\n There is no enough memory.");
	exit(0);
	}
	else
	{
		strcpy(newnode->name,name);
		newnode->link=newnode;             //   create node

		if(first=='\0')
		{     first=newnode;  }

		else
		{
			temp=first->link;
			while(temp->link!=first)
			{
				temp=temp->link;
			}
			newnode->link=temp->link;
			temp->link=newnode;
		}

	}

}

void Eliminate(int no)
{
int i=1;
struct node *prev;
temp=first;//use to locate firs node
while(temp->link!=first) //use to locate prev node to end of list.
{
temp=temp->link;
}
prev=temp;
temp=first;
while(i!=no)
{
prev=temp;
temp=temp->link;
i++;  //count from 1 to N
}

printf("\n%s  from position %d has been eliminated.\n",temp->name,i);
prev->link=temp->link;
first=temp->link;

} 

void show()
{
	int i=1;
	temp =first;
		printf("\n Position         Name\n");
	while (temp->link!=first)
	{
		printf("\n   %d             %s",i,temp->name);
		temp=temp->link;
		i++;
		
	}
		printf("\n   %d             %s",i,temp->name);//to print last node in list
	
}