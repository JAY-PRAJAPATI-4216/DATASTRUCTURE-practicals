#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    stack[++top] = ch;
}

// Pop function
char pop() {
    return stack[top--];
}

// Check precedence
int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (i = 0; i < strlen(infix); i++) {

        char ch = infix[i];

        // Operand
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {

            postfix[j++] = ch;
        }

        // Left parenthesis
        else if (ch == '(') {
            push(ch);
        }

        // Right parenthesis
        else if (ch == ')') {

            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }

            pop(); // Remove '('
        }

        // Operator
        else {

            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}