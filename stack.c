#include<stdio.h>
#include<conio.h>
#define Size 5
int tos= -1,stack[Size];
void push();
void pop();
void peek();
int IsEmpty();
int IsFull();
void display();
void search();
void update();
void count();
void exit();
static int c;
int R;

int main(){
	
	do{
printf("\n Press \n 1. for Push  \n 2. for pop \n 3. for display ");


printf("\n Enter Your Option : ");
scanf("%d",&choice);

switch(choice)
{

case 1 : push(); break;
case 2 : pop(); break;
case 3 : peek();break;
case 4 : {
	 R = IsEmapty();
	if(R==1){
		printf(" \n Stack is Emapty ");	
	}
	else{
			printf("\n Stack is not Emapty ");
	getch();
	}

}break;
case 6 : {
R = IsFull();
if(R==1){
	printf("\n Stack is full ");
	getch();
}	
	else{
		pritnf("\n Stack is not full");
		getch();
	}
}
case 7 : display();
case 8 : search();
case 8 : update();
case 9 : count();
case 10 : exit();
}
}
while(1);


}

void push(){
	int n;
	if(tos==Size-1){
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
void peek(){
	if(tos==-1){
		printf("Stack is Emapty ");
		getch();
		
	}
	else{
		printf("The peek value is = %d and index = %d ",stack[tos],tos);
	}
}

void display(){
	if(tos==-1){
		printf("Nothing to Display ");
		getch();
		
	}
	else{
		int i;
		printf("Stack Data Are \n");
		for(i=0;i<=tos ; i++ ){
			printf("%d ",stack[i]);
		}
	}
}
