
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<process.h>
 struct LLL
 {
     int RollNo;
     char Name[20];
     struct LLL *next;

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

void insert_at_begin()
{
    newnode = (struct LLL *)malloc(sizeof(struct LLL));
 fflush(stdin);
    printf("\nEnter Name : ");
    gets(newnode->Name);
    fflush(stdin);
    printf("\nEnter RollNo : ");
    scanf("%d",&newnode->RollNo);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        c++;
    }
    else
    {
    newnode->next=head;
    head=newnode;
    c++;
    }
}
void insert_at_end()
{
    newnode=(struct LLL *)malloc(sizeof(struct LLL));
    fflush(stdin);
    printf("\n Enter Name : ");
    gets(newnode->Name);
    printf("\n Enter RollNo : ");
    scanf("%d",&newnode->RollNo);
    newnode->next=NULL;
    if(head==NULL)
    {
     head=tail=NULL;
     c++;
    }else
    {
    	tail->next=newnode;
    	tail=newnode;
    	c++;
	}
}

void insert_at_position()
{
    int pos,i;
    printf("Enter Your Position :");
    scanf("%d",&pos);
    if(pos==1)
    insert_at_begin();
    else{
    	if(pos > c)
    	{
    		printf("\n Your Position is not in List");
    		getch();
		}
		else
		{
			i=1;
			ptr=head;
			while(i<pos && ptr->next!=NULL)
			{
				temp=ptr;
				ptr=ptr->next;
				i++;
			}
			if(i==pos){
			   newnode = (struct LLL *)malloc(sizeof(struct LLL));
    fflush(stdin);
    printf("\n Enter Name :");
    gets(newnode->Name);
        printf("\n Enter RollNo : ");
    scanf("%d",&newnode->RollNo);
    newnode->next=NULL;
	temp->next=newnode;
	newnode->next=ptr;
	c++;	
			}
		}
	}
}

void delete_at_begin()
{
	if(head==NULL){
		printf("\n No record Found ");
		getch();
	}else{
		ptr=head;
		head=head->next;
		ptr->next=NULL;
			printf("Deleted Data is : Name = %s Roll NO = %d",ptr->Name,ptr->RollNo);
		free(ptr);
		c--;
	}
}
void delete_at_end()
{
	if(head==NULL){
		printf("\n No record Found");
		getch();
	}else{
		ptr=head;
		while(ptr->next!=NULL){
			temp=ptr;
			ptr=ptr->next;
		}
		tail=temp;
		tail->next=NULL;
		printf("Deleted Data is : Name = %s Roll NO = %d",ptr->Name,ptr->RollNo);
		free(ptr);
		c--;
	}
}
void delete_at_position()
{
	int pos;
	printf("\n Which You want to delete ");
	scanf("%d",&pos);
	if(pos==1){
		delete_at_begin();
	}else{
		if(pos>c){
			printf("Invailed Position ");
			getch();
		}else{
			int i=1;
			while(i < pos && ptr->next!=NULL)
			{
			    temp=ptr;
				ptr=ptr->next;
				i++;
		 
			}

			temp->next=ptr->next;
			ptr->next=NULL;
			printf("\n Deleted Data : Name = %s RollNo = %d ",ptr->Name,ptr->RollNo);
			free(ptr);
			c--;
		}
	}
}
void display()
{
	if(head==NULL){
		printf("\n No Record Found");
		getch();
	}else{
		int i=1;
		printf("\n Sr.No \t\t Name \t\t RollNo");
		for(ptr=head;ptr!=NULL;ptr=ptr->next){
			printf("\n %d \t\t %s \t\t %d ",i,ptr->Name,ptr->RollNo);
			i++;
		}
	}
}  
void search()
{
	int Roll,f=0;
	if(head==NULL){
		printf("\n No record Found ");
		getch();
	}else{
		
		printf("Enter Roll No For Searching : ");
		scanf("%d",&Roll);
		for(ptr=head;ptr!=NULL;ptr=ptr->next){
			if(Roll==ptr->RollNo){
				f=1;break;
			}
		}
		if(f==1)
		{
			printf("User Available \n");
			printf("Name: %s RollNo: %d ",ptr->Name,ptr->RollNo);
			getch();
		}else{
			printf("User Not Found ");
			getch();
		}
	}
}
void update()
{   
        int Roll,i=1;
	if(head==NULL){
		printf("\n No Record Found ");
		getch();
	}else{
		printf("Enter Roll No For Update : ");
		scanf("%d",&Roll);
		for(ptr=head;ptr->next!=NULL;ptr=ptr->next){
			if(Roll==ptr->RollNo){
				printf("\n Enter Name : ");
				gets(ptr->Name);
				printf("\n Enter Roll NO : ");
				scanf("%d",&ptr->RollNo);
				printf("\n Update SuccessFully!! ");
			}
		}
		
	}
}
void count()
{
	printf("Total Number Of Count is : %d ",c);
	getch();
}

void exit1()
{
	printf("Program is terminated Now ");
	exit(0);
	getch();
}

