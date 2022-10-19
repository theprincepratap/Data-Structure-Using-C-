#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
#define size 5
int QUEUE[size];
int front = -1;
int rear = -1;

void ENQUEUE();
void DEQUEUE();
void DISPLAY();
void SEARCH();
void UPDATE();
void COUNT();
void exit1();
static int c; 
int main(){
	char choice;
	int option;
	do{
		printf("\n Press 1 for insert item in queue ");
		printf("\n Press 2 for delete item from queue");
		printf("\n Press 3 for Display ");
		printf("\n Press 4 for search ");
		printf("\n Press 5 for update");
		printf("\n Press 6 for count");
			printf("\n Press 7 for exit  ");
	printf("Enter Option:  ");
	scanf("%d",&option);
	switch(option){
		case 1: ENQUEUE(); break;
		case 2: DEQUEUE(); break;
		case 3: DISPLAY(); break;
		case 4: SEARCH(); break;
		case 5: UPDATE(); break;
		case 6: COUNT(); break;
		case 7: exit1();  break;
		default:
            printf("\n Please Inter a Valid Option");break;
	}
	fflush(stdin);
        printf("\n if you want to enter more record Press:Y otherwise:N ==>> ");
        choice=toupper(getchar());
    }while(choice!='N');
    return 0;
}
void ENQUEUE(){
	int addition;
	if(front==-1 && rear==(size-1))
	{
		printf("\n Queue is full ");
	getch();
	}else{
		printf("Enter data in Queue : ");
		scanf("%d",&addition);
		if(front==-1 && front==rear){
			front=0;
			rear=0;
			QUEUE[rear]=addition;
			c++;
		}
		else{
			if(front>-1 && rear<=(size-1)){
				rear++;
				QUEUE[rear]=addition;
				c++;
			}
			else{
				printf("Queue may be full ");
			}
		}
	}
}
void DEQUEUE(){
	if(front==rear && front==-1){
		printf("\n No Record Found ");
		getch();
	}else{
		if(front>-1 && front==rear){
			printf("Deleted Data will be: %d",QUEUE[front]);
			front=-1;
			rear=-1;
			c--;
			
		}else{
			if(front>-1 && rear <=(size-1)){
				printf("\n Deleted Data will be %d ",QUEUE[front]);
				front++;
				c--;
			}
		}
	}
}
void DISPLAY(){
	if(front==-1 && front==rear){
		printf("\n No Record Found");
		getch();
	}
	else{
		printf("Data are : \n");
		int i=front;
	
		while(i<=rear){
			printf(" Index = %d , Data = %d ",i,QUEUE[i]);
			i++;
		}
	}
}

void SEARCH(){
	int i=front,sroll,f=0;
	if(front==-1 && front==rear){
		printf("\n Queue is Empty ");
		getch();
	}else{
		printf("\n What you want to search Enter Roll : ");
		scanf("%d",&sroll);
		while(i<=rear){
			if(sroll==QUEUE[i])
			f=1;
			i++;
		}
		if(f==1){
			printf("\n Data found ");
		}else{
			printf("Data not found ");
		}
	}
}

void UPDATE(){
		int i=front,sroll,f=0;
	if(front==-1 && front==rear){
		printf("\n Queue is Empty ");
		getch();
	}else{
		printf("\n What you want to update Enter Roll : ");
		scanf("%d",&sroll);
		while(i<=rear){
			if(sroll==QUEUE[i]){
				f=1;
		       	break;
			}
		i++;
		}
		if(f==1){
			printf("Enter Roll you want to update");
			scanf("%d",&QUEUE[i]);
			printf("\n Update successfully");
			
		}else{
			printf("Data not found ");
		}
	}
}

void COUNT(){
	printf("\n Total count = %d ", c);
	getch();
}
void exit1(){
	printf("program has been terminated");
	exit(0);
	
	getch();
}
