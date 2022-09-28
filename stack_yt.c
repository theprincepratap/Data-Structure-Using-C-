#include<stdio.h>
#include<conio.h>
#define size 5
void push();
void pop();
int isEmpty();
int isFull();
int stack[size];
int tos=-1;
char choice;
int R;
int main(){
	int option;
 do
    {
         printf("\nPress 1 for push	: ");
        printf("\nPress 2 for Pop: ");
        printf("\nPress 3 for cheak is empty: ");
        printf("\nPress 4 for cheak is full : ");
        printf("\nPress 5 for peek : ");

        printf("\n-------------------------------------------------");
        printf("\n Enter your option: ");
        scanf("%d",&option);
    switch(option)
    {
            case 1:
           push();
            break;
            case 2:
            pop();
            break;
            case 3:
            R = isEmpty();
            if(R==1){
            	printf("Stack is Empty");
            	getch();
			}else{
				printf("Stack may be full ");
				getch();
			}
            break;
            case 4:
            R = isFull();
            if(R==1){
            	printf("stack is full");
            	getch();
			}else{
				printf("stack may be empty");
				getch();
			}
            break;

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
	int n;
	if(tos==size-1){
		printf("Stack overflow ");
		getch();
		
	}
	else{
		printf(" \n Enter an element to be insert in stack : ");
		scanf("%d",&n);
		tos += 1;
		stack[tos] = n;
		printf("\n inserted Successfully ");;
	}
	
}
void pop(){
	if(tos==-1){
		printf("Nothing to pop ");
		getch();
	}else{
      printf("Poped Elemtnt : %d ",stack[tos]);
      tos = tos-1;
	}
	
}

int isEmpty(){
	if(tos==-1){
		return 1;
	}else{
		return 0;
	}
}
int isFull(){
	if(tos==size-1){
		return 1;
		}else{
			return 0;
		}
}


