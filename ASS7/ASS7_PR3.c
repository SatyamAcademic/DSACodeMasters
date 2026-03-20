#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    int i = 0;
    int op1, op2;

    while (exp[i] != '\0') {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');   
        }
        else {
            op2 = pop();
            op1 = pop();

            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression (with space separated");
    scanf("%s", exp);

    printf("Result = %d\n", evaluatePostfix(exp));
    return 0;
}

