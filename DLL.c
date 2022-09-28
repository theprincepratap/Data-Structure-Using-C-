#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
struct dcll
{
    struct dcll *prev;
    char name[20];
    int roll;
    struct dcll *next;
}*fresh,*head,*tail,*temp,*ptr;
void insert_at_begin();
void insert_at_end();
void insert_at_position();
void delete_at_begin();
void delete_at_end();
void delete_at_position();
void display();
void display_in_linear_circular();
void update();
void count();
void search();
void exit1();
static int c;
int i;

int main()
{
    char choise;
    int option;
    head=NULL;
    do
    {
        system("cls");
        printf("\nPress 1 for Insert at begin: ");
        printf("\nPress 2 for Insert at end: ");
        printf("\nPress 3 for Insert at position: ");
        printf("\nPress 4 for Delete at begin: ");
        printf("\nPress 5 for Delete at end: ");
        printf("\nPress 6 for Delete at positon: ");
        printf("\nPress 7 for Display at 1st to last record: ");
        printf("\nPress 8 for Display at last to 1st record: ");
        printf("\nPress 9 for search: ");
        printf("\nPress 10 for Count: ");
        printf("\nPress 11 for Update: ");
        printf("\nPress 12 for exit: ");
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
            display_in_linear_circular();
            break;
            case 9:
            search();
            break;
            case 10:
            count();
            break;
            case 11:
            update();
            break;
            case 12:
            exit1();
            break;
            default:
            printf("\nInvalid input.");
        }
        fflush(stdin);
        printf("\nContinue[Y/N]: ");
        choise=toupper(getchar());
    }while(choise!='N');
    return 0;
}

void insert_at_begin()
{
    fresh=(struct dcll*)malloc(sizeof(struct dcll));
    fflush(stdin);
    fresh->prev=NULL;
    fflush(stdin);
    printf("\nEnter your name: ");
    gets(fresh->name);
    fflush(stdin);
    printf("\nEnter your Roll no.: ");
    scanf("%d",&fresh->roll);
    fflush(stdin);
    fresh->next=NULL;
    fflush(stdin);
    if(head==NULL)
    {
        head=tail=fresh;
        c++;
    }
    else
    {
        head->prev=fresh;
        fresh->next=head;
        head=fresh;
        c++;
    }
    printf("\nRecord is added.");
}

void insert_at_end()
{
    fresh=(struct dcll*) malloc(sizeof(struct dcll));
    fflush(stdin);
    fresh->prev=NULL;
    fflush(stdin);
    printf("\nEnter your name: ");
    gets(fresh->name);
    fflush(stdin);
    printf("\nEnter your Roll no.: ");
    scanf("%d",&fresh->roll);
    fflush(stdin);
    fresh->next=NULL;
    fflush(stdin);
    if(head==NULL)
    {
        head=tail=fresh;
        c++;
    }
    else
    {
        tail->next=fresh;
        fresh->prev=tail;
        tail=fresh;
        c++;
    }
    printf("\nRecord is added.");
}

void insert_at_position()
{
    if(head==NULL);
    {
        printf("\nData not found");
        getch();
    }
    int pos; i=1;
    printf("\nEnter your position: ");
    scanf("%d",&pos);
    if(pos==1)
    insert_at_begin();
    else if(pos==(c+1))
    insert_at_end();
    else if(pos>c)
    {
        printf("No any data found.");
        getch();
    }
    else
    {
        ptr=head;
        while(i<pos&&ptr!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
            i++;
        }
        if(i==pos)
        {
            fresh=(struct dcll*) malloc(sizeof(struct dcll));
            fresh->prev=NULL;
            fflush(stdin);
            printf("\nEnter your name: ");
            gets(fresh->name);
            fflush(stdin);
            printf("\nEnter your Roll no.: ");
            scanf("%d",&fresh->roll);
            fflush(stdin);
            fresh->next=NULL;
            temp->next=fresh;
            fresh->prev=temp;
            ptr->prev=fresh;
            fresh->next=ptr;
            printf("\nRecord is added.");
            c++;
        }
    }
}

void delete_at_begin()
{
    if(head==NULL)
    {
        printf("\nRecord not found.");
        getch();
    }
    else
    {
        ptr=head;
        printf("\nDeleted record Name=%s Roll no.=%d",ptr->name,ptr->roll);
        head=ptr->next;
        head->prev=NULL;
        ptr->next=NULL;
        free(ptr);
        c--;
    }
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("\nRecord not found.");
        getch();
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        tail=temp;
        tail->next=NULL;
        ptr->prev=NULL;
        printf("\nDeleted record Name=%s Roll no.=%d",ptr->name,ptr->roll);
        free(ptr);
        c--;
    }
}

void delete_at_position()
{
    int pos;i=1;
    printf("\nEnter your postion: ");
    scanf("%d",&pos);
    if(pos==1)
    delete_at_begin();
    else if (pos==c+1)
    delete_at_end();
    else if(pos>c)
    {
        printf("No any data found.");
        getch();
    }
    else
    {
        ptr=head;
        while(i<pos&&ptr!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
            i++;
        }
        if(i==pos)
        {
            temp->next=ptr->next;
            ptr->next->prev=temp;
            ptr->prev=NULL;
            ptr->next=NULL;
            printf("\nDeleted record Name=%s Roll no.=%d",ptr->name,ptr->roll);
            free(ptr);
            c--;
        }
    }
}

void display()
{
    if(head==NULL)
    {
        printf("\nNo any data found.");
        getch();
    }
    else
    {
        ptr=head;
        printf("\nName\t\t\tRoll No.");
        while(ptr!=NULL)
        {
            printf("\n%s\t\t\t %d",ptr->name,ptr->roll);
            ptr=ptr->next;
        }
    }
}

void display_in_linear_circular()
{
    if(head==NULL)
    {
        printf("\nNo any data found.");
        getch();
    }
    else
    {
        ptr=tail;
        printf("\nName\t\t\tRoll No.");
        while(ptr!=NULL)
        {
            printf("\n%s\t\t\t %d",ptr->name,ptr->roll);
            ptr=ptr->prev;
        }
    }
}

void update()
{
    int rollno;
    if(head==NULL)
    {
        printf("\nNo any data found");
        getch();
    }
    else
    {
        fflush(stdin);
        printf("\nEnter your roll no.: ");
        scanf("%d",&rollno);
        ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->roll==rollno)
            {
                fflush(stdin);
                printf("\nEnter your updated name: ");
                gets(ptr->name);
                fflush(stdin);
                printf("\nEnter your updated roll no.: ");
                scanf("%d",&ptr->roll);
            }
            ptr=ptr->next;
        }
        printf("\nRecord updated");
    }
}

void count()
{
    if(head==NULL)
    {
        printf("\nData not found.");
        getch();
    }
    else
    {
        printf("/n Number of records : %d",c);
    }
}

void search()
{
    int rollno;
    if(head==NULL)
    {
        printf("\nNo any data found");
        getch();
    }
    else
    {
        printf("\nEnter your roll no.: ");
        scanf("%d",&rollno);
        ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->roll==rollno)
            {
                printf("\nName=%s Roll no.=%d",ptr->name,ptr->roll);
                break;
            }
            ptr=ptr->next;
        }
    }
}

void exit1()
{
    exit(0);
}
