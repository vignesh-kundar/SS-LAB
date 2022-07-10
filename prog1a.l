%{
	#include<stdio.h>
	int id=0,op=0,v=0,flag=0,plus=0,min=0,mul=0,dv=0;
%}
%%
[a-zA-Z0-9]+	{id++;printf("\nIdentifier");ECHO;}
[+]	{op++;plus++;printf("\nOperator");ECHO;}
[-]	{op++;min++;printf("\nOperator");ECHO;}
[*]	{op++;mul++;printf("\nOperator");ECHO;}
[/]	{op++;dv++;printf("\nOperator");ECHO;}
"("	{v++;}
")"	{v--;}
.	{flag=1;}
\n	{;}
%%
int main()
{
	printf("Enter Expression:\n");
	yylex();
	if(((op+1)==id)&&(v==0)&&(flag==0))
	{
		printf("Valid Expression\n");
		printf("No. of identifiers: %d\n",id);
		printf("No. of operators: %d\n",op);
		printf("Plus Operators(+): %d\n",plus);
		printf("Minus Operators(-): %d\n",min);
		printf("Multiplication Operators(*): %d\n",mul);
		printf("Division Operators(/): %d\n",dv);
	}
	else
	{
		printf("Invalid Expression\n");
	}
	return 0;
}

