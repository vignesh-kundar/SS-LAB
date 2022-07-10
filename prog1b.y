%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token NUM
%left '+''-'
%left '*''/'
%%
input:exp {printf("result=%d\n",$$);exit(0);}	
exp:exp '+' exp	{$$=$1+$3;}
|exp '-' exp	{$$=$1-$3;}
|exp '*' exp	{$$=$1*$3;}
|exp '/' exp	{if($3==0)
	{ 
	printf("Divide by Zero Error\n");exit(0);}}
		|'('exp')' {$$=$2;}
		|NUM {$$=$1;}
                ;
%%
int main()
{
printf("enter the expression to solve:");
yyparse();
}
int yyerror()
{
printf("Invalid input\n");
exit(0);
}

