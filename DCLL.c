#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<process.h>
 struct DCLL
 {
     int RollNo;
     char Name[20];
     struct DCLL *next;
     struct DCLL *prev; 

 }*newnode,*ptr,*temp,*head,*tail;

 void insert_at_begin();
void insert_at_end();
void insert_at_position();
void delete_at_begin();
void delete_at_end();
void delete_at_position();
void display();
void update();
void search();
void count();
void exit1();
static int c;

int main()
{
    head=NULL;
    int option;
    char choice;
    do
    {
         printf("\nPress 1 for Insert at begin: ");
        printf("\nPress 2 for Insert at end: ");
        printf("\nPress 3 for Insert at position: ");
        printf("\nPress 4 for Delete at begin: ");
        printf("\nPress 5 for Delete at end: ");
        printf("\nPress 6 for Delete at position: ");
        printf("\nPress 7 for Display : ");
        printf("\nPress 8 for search: ");
        printf("\nPress 9 for Count: ");
        printf("\nPress 10 for Update: ");
        printf("\nPress 11 for exit: ");
        printf("\n-------------------------------------------------");
        printf("\n Enter your option: ");
        scanf("%d",&option);
    switch(option)
    {
            case 1:
            insert_at_begin();
            break;
            case 2:
            insert_at_end();
            break;
            case 3:
            insert_at_position();
            break;
            case 4:
            delete_at_begin();
            break;
            case 5:
            delete_at_end();
            break;
            case 6:
            delete_at_position();
            break;
            case 7:
            display();
            break;
            case 8:
            search();
            break;
            case 9:
            count();
            break;
            case 10:
            update();
            break;
            case 11:
            exit1();
            default:
            printf("\n Please Inter a Valid Option");
        }
 fflush(stdin);
        printf("\n if you want to enter more record Press:Y otherwise:N ==>> ");
        choice=toupper(getchar());
    }while(choice!='N');
    return 0;
}

void insert_at_begin(){
	newnode = (struct DCLL * )malloc(sizeof(struct DCLL));
	fflush(stdin);
	printf("Enter Name : ");
	gets(newnode->Name);
	fflush(stdin);
	printf("Enter Roll NO : ");
	scanf("%d",&newnode->RollNo);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL){
		head=tail=newnode;
		newnode->next=head;
		newnode->prev=tail;
	}
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
		head->prev=tail;
		tail->next=head;
		c++;
		
	}
}
void insert_at_end(){
	newnode = (struct DCLL *)malloc(sizeof(struct DCLL));
	fflush(stdin);
	printf("Enter Name : ");
	gets(newnode->Name);
	printf("Enter Roll NO : ");
	scanf("%d",&newnode->RollNo);
	newnode->next=NUll;
	newnode->prev = NULL;
	if(head==NULL){
		head=tail=newnode;
		newnode->next=head;
		newnode->prev=tail;
		
	}
	else{
		tail->next=newnode;
		newnode->prev=tail;
	tail=newnode;
	head->prev=tail;
	tail->next=head;
	c++;
	}
	
}

void insert_at_position(){
	int pos;
	printf("Where u want to insert : ");
	scanf("%d",&pos);
	if(pos==1){
		insert_at_begin();
	}else{
		if(pos>c){
			printf("Invailed Position ");
			getch();
		}else{
			int i=1; ptr=head;
			if(i<pos && ptr!=head){
				
			}
		}
	}
}	
