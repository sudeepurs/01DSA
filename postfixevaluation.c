#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <ctype.h>
#include <math.h>

int stack[50];
int top = -1;

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[50];
    int i, op1, op2, result;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        char symb = postfix[i];

        if (isdigit(symb))
        {
            push(symb - '0'); // Convert character to integer
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch (symb)
            {
            case '+':
                result = op1 + op2;
                break;

            case '-':
                result = op1 - op2;
                break;

            case '*':
                result = op1 * op2;
                break;

            case '/':
                result = op1 / op2;
                break;

            case '%':
                result = op1 % op2;
                break;

            case '^':
                result = pow(op1, op2);
                break;

            default:
                printf("Invalid Operator\n");
                return 1;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}