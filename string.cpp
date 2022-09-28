#include<stdio.h>
#include<conio.h>
int main(){
	char str[10]= "welcome";
	for(int i = 0 ; str[i]!='\0';i++)
	{
		puts(str+1);
	}
	getch();
	
	return 0;
}
