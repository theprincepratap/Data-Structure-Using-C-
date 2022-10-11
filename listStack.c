#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<process.h>
 struct stack
 {
     int RollNo;
     struct stack *next;

 }*tos,*ptr,*fresh;

 void push();
void pop();
void peek();
int IsEmpty();
void display();
void search();
void update();
void count();
void exit1();
static int c;

int main()
{
    tos=NULL;
    int option,R;
    char choice;
    do
    {
         printf("\nPress 1 for push: ");
        printf("\nPress 2 for pop: ");
        printf("\nPress 3 for peek: ");
        printf("\nPress 4 for cheak empty or not : ");
        printf("\nPress 5 for display");
        printf("\nPress 6 for search: ");
        printf("\nPress 7 for update : ");
        printf("\nPress 8 for count: ");
        printf("\nPress 9 for exit: ");
        printf("\n-------------------------------------------------");
        printf("\n Enter your option: ");
        scanf("%d",&option);
    switch(option)
    {
            case 1:push();
            break;
            case 2:
            pop();break;
            break;
            case 3:
            peek();break;
            break;
            case 4:
            R = IsEmpty();
            if(R==1)
            printf("Stack is empty");
            else
            printf("Stack may be full ");
            break;
            case 5:
            display();break;
            break;
            case 6:
            search();break;
            break;
            case 7:
            update();break;
            break;
            case 8:
            count();break;
            case 9:
            exit1();break;
            default:
            printf("\n Please Inter a Valid Option");
        }
 fflush(stdin);
        printf("\n if you want to enter more record Press:Y otherwise:N ==>> ");
        choice=toupper(getchar());
    }while(choice!='N');
    return 0;
}
void push(){

      fresh = (struct stack * )malloc(sizeof(struct stack));
        printf("Enter a value for insert : ");
        scanf("%d",&fresh->RollNo);
           fresh->next=NULL;
           
     if(tos==NULL){
tos=fresh;
    c++;
     }else{
    fresh->next=tos;
    tos=fresh;
    c++;
     }
    
}



  
void pop(){
    if(tos==NULL){
        printf("\n Nothing here for pop ");
        getch();
    }else{
        ptr=tos;
        tos=tos->next;
          printf("Deleted Data is :  %d ", ptr->RollNo);
        free(ptr);
      
        c--;
    }
}
void peek(){
    if(tos==NULL){
        printf("Stack is Empty");
        getch();
    }else{
        printf("Peek data is : %d",tos->RollNo);
    }
}
int IsEmpty(){
    if(tos==NULL){
        return 1;
    }else{
        return 0;
    }
}
void display(){
    if(tos==NULL){
        printf("Stack is Empty ");
        getch();
    }else{
        printf("Data are : \n");
        for(ptr=tos;ptr!=NULL;ptr=ptr->next){
printf("%3d",ptr->RollNo);
        }
    }
}
void search(){
    int roll;
    printf("What do you want to search Enter rollNO : ");
    scanf("%d",&roll);
    if(tos==NULL){
        printf("Stack is empty ");
        getch();
    }else{
        for(ptr=tos;ptr!=NULL;ptr=ptr->next){
            if(ptr->RollNo==roll){
                printf("Yes! Data is present ");
                break;
            }else
            printf("Data Not Found ");
        }
    }
}


void update(){
    int roll;
    printf("What do you want to update Enter rollNO : ");
    scanf("%d",&roll);
    if(tos==NULL){
        printf("Stack is empty ");
        getch();
    }else{
        for(ptr=tos;ptr!=NULL;ptr=ptr->next){
            if(ptr->RollNo==roll){
               printf("Enter RollNo : ");
               scanf("%d",&ptr->RollNo);
               printf("Updata succesfully ");
              break;
            }else{
                printf("Data Not Found ");
            }
        }

    }
}
void count(){
    printf("Totel element in stack is : %d",c);
    getch();
}
void exit1(){
  	printf("Program is terminated Now ");
	exit(0);
	getch();
}

