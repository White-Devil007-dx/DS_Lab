#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Implementing a program to convert Expression from infix to postfix

char stack[100];
int top = -1;


void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    char ch = stack[top];
    top--;
    return ch;
}

int priority(char op) {
    if (op == '^') {
        return 3;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

int main(void) {
    char exp[100], x;
    int ch; 
    while (1) {
        printf("Enter expression (infix): ");
        scanf("%s", exp);

        for (int i = 0; exp[i] != '\0'; i++) {

            if (isalnum(exp[i])) {
                printf("%c", exp[i]);
            }
            else if (exp[i] == '(') {
                push (exp[i]);
            }
            else if (exp[i] == ')') {
                while ((x = pop()) != '(') {
                    printf("%c", x);
                }
            }
            else {
                if (priority(stack[top]) == 3) {
                    push(exp[i]);
                }
                else {
                    while (top != -1 && (priority(stack[top]) >= priority(exp[i]))) {
                        printf("%c",pop());
                    }
                    push(exp[i]);
                }
            }

        }
        while (top != -1) {
            printf("%c", pop());
        }
        printf("\nDo you want to continue (0-No, 1-Yes)");
        scanf("%d", &ch);
        if (ch == 0) {
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}
