#include<stdio.h>
#define size 10
int stk[size],top=-1,data;
void push(int data)
{
	if(top==size-1)
	{
		printf("Stack is not empty ");
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
void pop()
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
void update()
{
	int n,val;
	printf("enter the value to update at :");
	scanf("%d",&n);
	printf("\nEnter the updated value :");
	scanf("%d",&val);
	int up=top-n+1;
		if(up<0)
		{
			printf("choice is invalid");
		}
		else
		stk[top-n+1]=val;
}
void pick()
{
	int n;
	printf("enter the value to update at :");
	scanf("%d",&n);
	int up=top-n+1;
	if(up<0)
		{
			printf("choice is invalid");
		}
		else
		printf("Value at %d position is = %d",n,stk[top-n+1]);
}

int main()
{
	int ch,data;
	do{
	printf("Press 1 for Push: \n");
	printf("Press 2 for Display: \n");
	printf("Press 3 for Pop:\n");
	printf("Press 4 for Update: \n");
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
			update();
			break;
		case 5:
			pick;
			break;
		default:
			ch=0;
			break;
	}
}while(ch!=0);
return 0;
}
