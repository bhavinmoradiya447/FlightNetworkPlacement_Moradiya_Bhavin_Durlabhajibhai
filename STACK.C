#include<stdio.h>
#include<conio.h>


struct node
{
int No;
struct node *link;
};

struct node *first='\0';
struct node *newnode;
struct node *temp;

int top;

void push(int );
int pop(); 

void main()
{
  int i,ch,no,x,flag=0;
  int pattern[20],p=0;
  clrscr();

   do
   {
    printf("\n\t Enter 1 for \'PUSH\'");
    printf("\n\t Enter 2 for \'POP\'");
    printf("\n\t Enter 3 for \'EXIT\'\n");
    printf("\nENTER YOUR ch:");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:printf("\nEnter Number:");
	     scanf("%d",&no);

	     if(no>9&&no<0)
	     { printf("\n-->You must have to enter number between  (0- 9):");}
			
		 else if(flag==0)
		 {
			top=no;
			push(no);
			flag=1;
		 }
		  
	     else if(no>top+1||no<=top)
	     {
	       
	       printf("\n Previously pused number is:%d",top);
	       printf("\n Please push in correct sequance\n");
	       
	     }
	     else
	     {
	       top=no;
	       push(no);
	     }
	     break;
       case 2: x=pop();
	     if(x!=-1)
	     {
	      pattern[p++]=x;
	      printf("\nPOP:%d",x);
	     }

	     printf("\nPATTERN:");
	     for(i=0;i<p;i++)
	     {  printf("%d ",pattern[i]); }
	     printf("\n");
	     break;
     case 3: exit(0);
	     break;
     default:printf("\n->Enter valid choice\n");
    }
   }while(ch!=3);
   getch();
}




void push(int data) //use for push data into stack
{
  newnode=(struct node*)malloc(sizeof(struct node));//generate memory for new node
	if(newnode=='\0')
	{
		printf("\n no enough memory. ");
		exit(0);
	}
  
  newnode->No=data;
  newnode->link='\0';         //create node

    if(first=='\0')
    {    first=newnode;  }

    else
    {
	temp=first;
	while(temp->link!='\0')
	{
	  temp=temp->link;
	}
	temp->link=newnode;
    }
}


int pop()      //this function is used for pop data from stack
{
  int data;
  struct node *prev;

  if(first=='\0')
  { printf("\n-->List is empty.");
    return -1;
  }

  else
  {
    temp=first;
    while(temp->link!='\0')
    { prev=temp;
      temp=temp->link;
    }

    if(temp==first)
    {
      data=temp->No;
      first='\0';
    }
    else
    {
      data=temp->No;
      prev->link=temp->link;
    }
	
	if(data==9)//use for push number form starting after number 9 poped 
	{top=-1;}
	
    return data;
  }
}
