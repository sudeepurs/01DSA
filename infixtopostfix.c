#include <stdio.h>
#include <stdlib.h>

void push(char item);
char pop();
void evaluate();
int prec(char symb);

char postfix[30], infix[30], stack[30];
int top = -1;

int main()
{
    printf("Enter the valid infix expression: ");
    scanf("%s", infix);

    evaluate();

    printf("The corresponding postfix expression is %s", postfix);

    return 0;
}

void evaluate()
{
    int i, j = 0;
    char temp, symb;

    push('#');

    for (i = 0; infix[i] != '\0'; i++)
    {
        symb = infix[i];

        switch (symb)
        {
        case '(':
            push(symb);
            break;

        case ')':
            temp = pop();

            while (temp != '(')
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':

            while (prec(stack[top]) >= prec(symb))
            {
                temp = pop();
                postfix[j] = temp;
                j++;
            }

            push(symb);
            break;

        default:
            postfix[j] = symb;
            j++;
        }
    }

    while (top > 0)
    {
        temp = pop();
        postfix[j] = temp;
        j++;
    }

    postfix[j] = '\0';
}

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    return stack[top--];
}

int prec(char symb)
{
    switch (symb)
    {
    case '#':
        return -1;

    case '(':
    case ')':
        return 0;

    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
    case '%':
        return 2;

    case '^':
    case '$':
        return 3;

    default:
        return -1;
    }
}