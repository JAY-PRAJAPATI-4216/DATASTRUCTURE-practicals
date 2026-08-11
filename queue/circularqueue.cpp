#include <iostream>
using namespace std;
#define s 25

int queue[s];
int front = -1, rear = -1;

int full()
{
    if (rear == s - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empty()
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueuer(int x)
{
    if (full())
    {
        exit(0);
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % s;
        queue[rear] = x;
    }
}   

int dequeuer()
{
    int x;
    if(empty())
    {
        exit(0);
    }
    else
    {
        x = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % s;
        }
    }
    return x;
}
int display()
{
    if (empty())
    {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    else
    {
        int i = front;
        cout << "Queue elements: ";
        while (i != rear)
        {
            cout << queue[i] << " ";
            i = (i + 1) % s;
        }
        cout << queue[rear] << endl;
    }
    return 1;
}
int main()
{
    int choice, x;
    while (1)
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to enqueue: ";
            cin >> x;
            enqueuer(x);
            break;
        case 2:
            x = dequeuer();
            cout << "Dequeued element: " << x << endl;
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}
