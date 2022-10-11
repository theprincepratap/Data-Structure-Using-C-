#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 5
int QUEUE[size];
FRONT = -1;
REAR = -1;

void ENQUEUE();
void DEQUEUE();
int ISEMPTY();
int ISFULL();
void DISPLAY();
void SEARCH();
void UPDATE();
void COUNT();
void EXIT();
static int c; 
int main(){
	char choice;
	int option;
	do{
		printf("\n Press 1 for insert item in queue ");
		printf("\n Press 2 for delete item from queue");
		printf("\n Press 3 for cheak is empty");
		printf("\n Press 4 for cheak is full ");
		printf("\n Press 5 for Display ");
		printf("\n Press 6 for update ");
		printf("\n Press 7 for count ");
		printf("\n Press 8 for exit");
	}
	
	
	
	
	
	
	return 0;
}
