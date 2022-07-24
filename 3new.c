// Matchs strings with starting a  followed by any no b's end a
// Input test case valid exp aa$ or aba$ ot abba$....
//Input test case invalid exp ab$, abbab$ ..
// @github.com/adithyapaib

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char prod[3][10] = {"A->aBa", "B->bB", "B->@"}, input[10], stack[30];
int top = -1;
int j = 0, k, l;

// Stack operations

void push(char item){
    stack[++top] = item;
}

void pop(){
    top = top - 1;
}

void stackpush(char p)
{
    if (p=='A'){ // Pop A and Push aBa into stack
        pop();
        // Or j=5
        for (j = strlen(prod[0])-1; j >= 3; j--)
            push(prod[0][j]);
    }
    else // else if B
    {
        pop();
        // or j =4
        for (j = strlen(prod[1]) - 1; j >= 3; j--)
            push(prod[1][j]);
    }
}

void main()
{
    char c;
    int i;
    printf("First (A) = {a} \t");
    printf("Follow (A) = {$} \n");
    printf("First (B) = {b,@} \t");
    printf("Follow (B) = {a} \n");
    printf("\t\t a \t\t b \t\t$");

    printf("A\t\t %s \n", prod[0]);
    printf("B\t\t %s\t\t%s\n", prod[2], prod[1]);

    printf("\nEnter a string with $to terminate string :");
    scanf("%s", input);

    // Check if input contains only a and b and $
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != 'a' && input[i] != 'b' && input[i] != '$')
        {
            printf("Invalid String");
            exit(0);
        }
    }
    // check if input is terminated with $ eg: abba$
    if (input[i - 1] != '$')
    {
        printf("Enter a string with $ as end marker :");
        exit(0);
    }

    push('$');
    push('A');
    i = 0;

    printf("\n\nstack \t\t Input \t\t action\t\n");

    while (i != strlen(input) && stack[top] != '$')
    {
        printf("\n");
        for (l = top; l >= 0; l--)
            printf("%c", stack[l]);
        printf("\t\t");


        for (l = i; l < strlen(input); l++)
            printf("%c", input[l]);
        printf("\t\t");

        if (stack[top] == 'A'){
            printf("A->aBA");
            stackpush('A');
        }
        else if (stack[top] == 'B')
        {
            if (input[i] != 'b')
            {
                printf("B->@");
                printf(" matched  @");
                pop();
            }
            else
            {
                printf("B->bB");
                stackpush('B');
            }
        }
        else
        {
            if (stack[top] == input[i])
            {
                printf("pop %c", input[i]);
                printf("\t\t matched %c", input[i]);
                pop();
                i++;
            }
            else
                break;
        }
        
    }
        // Final check
    if (stack[top] == '$' && input[i] == '$')
        // Stack only has $
         printf("\n$ \t\t $ \nValid Expression");
    
           
        else
            printf("\nInvalid Exp");
}
