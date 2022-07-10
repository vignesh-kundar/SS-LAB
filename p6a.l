%{
#include<stdio.h>
int sl=0;
int ml=0;
%}
%%
"/*"[a-zA-Z0-9' '\t\n]+"*/"	ml++;
"//".*	sl++;
%%
int main(int argc,char **argv)
{
 if(argc<3)
  {
	printf("Enter input and output file\n");
	exit(0);
  }
 yyin = fopen(argv[1],"r");
 if(!yyin)
 {
	printf("File Error\n");
	exit(1);
 }
 yyout = fopen(argv[2],"w");
 yylex();
 fclose(yyin);
 fclose(yyout);
 printf("\n Number of single line comments are = %d\n",sl);
 printf("\n Number of Multiline comments are = %d\n",ml);
 return 0;
}
