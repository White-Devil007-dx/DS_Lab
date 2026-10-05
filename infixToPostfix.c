#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int priority(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}

int main(void) {
    char exp[100], x;

    printf("Enter expression (infix): ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        }
        else if (exp[i] == '(') {
            push(exp[i]);
        }
        else if (exp[i] == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }
        else {
            while (top != -1 && (priority(stack[top]) >= priority(exp[i]))) {
                printf("%c", pop());
            }
            push(exp[i]);
        }
    }

    while (top != -1) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}
