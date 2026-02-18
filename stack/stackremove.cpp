#include<stdio.h>
#define size 10
int stk[size],top=-1,data;
int tmp[size],tp=-1;
void push(int data)
{
	if(top==size-1)
	{
		printf("Stack is Overflow ");
		return ;
	}
	else{
		top=top+1;
		stk[top]=data;
	}
}
void display()
{
	if(top==-1)
	{
		printf("Stack is not empty ");
	}
	else{
		for(int i=top;i>=0;i--)
		{
			printf("%d\n",stk[i]);
		}
	}
}
int pop()
{
	int data;
	if(top==-1)
	{
		printf("stack is empty");
	}
	else{
		data=stk[top];
		printf("POP element is %d\n",stk[top]);
		stk[top]=NULL;
		top--;
			}
}

int main()
{
	int ch,data,n;
	do{
	printf("Press 1 for Push: \n");
	printf("Press 2 for Display: \n");
	printf("Press 3 for Pop:\n");
	printf("Press 4 for Remove: \n");
	printf("Enter your choice :-");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			printf("Enter data: ");
			scanf("%d",&data);
			push(data);
			break;
		case 2:display();
			break;
		case 3:
			pop();
			break;

		case 4:
			printf("Enter the position you want to delete: ");
				scanf("%d",&n);
				if(top-n+1<0)
						   printf("\n try again ");
	   			else{
	   				for(int i=0;i<n;i++)
	   				{
	   					data=pop();
	   					tp++;
	   					tmp[tp]=data;
					   }
					   data=pop();
					   printf("\n Removed Element = %d ",data);
					   while(tp!=-1)
					   {
					   	push(tmp[tp]);
					   	tp--;
					   }
					   break;
				   }		   
		default:
			ch=0;
			break;
	}
}while(ch!=0);
return 0;
}
