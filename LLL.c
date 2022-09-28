#include<stdio.h>
#include<stdlib.h>
#include<process.h>
void insert_at_begin();
struct LLL
{
    char name[20];
    struct LLL *next;
}*newnode,*ptr,*head,*tail,*temp;
static int c;
int main()
{
    head=NULL;
    insert_at_begin();
    display(head);
    return 0;

}
void display(struct LLL *ptr){


    while(ptr!=NULL)
        {

        puts(ptr->name);
        printf("\n");
    ptr = ptr->next;
    }

}
void insert_at_begin()

{
    for(int i=0;i<3;i++){
    newnode=(struct LLL *)malloc(sizeof(struct LLL));
    fflush(stdin);
    printf("Enter your name");
    gets(newnode->name);
    newnode->next=NULL;
if(head==NULL){
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
}
