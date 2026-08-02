#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MAX 50

int stack[MAX];
int tos = -1;

int isEmpty() {
    if (tos == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if (tos == MAX - 1)
        return 1;
    else
        return 0;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow\n";
    }
    else {
        tos++;
        stack[tos] = x;
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    else {
        return stack[tos--];
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return -1;
    }
    else {
        return stack[tos];
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
    }
    else {
        cout << "Stack Elements: ";
        for (int i = tos; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

#endif