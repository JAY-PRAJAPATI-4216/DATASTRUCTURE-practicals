#include <iostream>
using namespace std;

#define s 3

int queue[s];
int front = -1, rear = -1;

int full()
{
    if ((rear + 1) % s == front)
        return 1;
    else
        return 0;
}

int empty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

void enqueuer(int x)
{
    if (full())
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % s;
        queue[rear] = x;
    }
}

int dequeuer()
{
    int x;

    if (empty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
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

        return x;
    }
}

void display()
{
    if (empty())
    {
        cout << "Queue is empty!" << endl;
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
        cout << "Front: " << front << ", Rear: " << rear << endl;
    }
}

int main()
{
    int choice, x;

    while (1)
    {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
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

            if (x != -1)
                cout << "Dequeued element: " << x << endl;

            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}