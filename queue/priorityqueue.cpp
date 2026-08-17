#include <iostream>
using namespace std;

#define s 20

int queue[s];
int front = -1, rear = -1;

int full()
{
    if (rear == s - 1)
        return 1;
    else
        return 0;
}

int empty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void enqueue(int x)
{
    if (full())
    {
        cout << "Priority Queue is full!" << endl;
        return;
    }

    if (front == -1)
        front = 0;

    int i = rear;

    while (i >= front && queue[i] > x)
    {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1] = x;
    rear++;

    cout << "Element inserted successfully." << endl;
}

void dequeue()
{
    if (empty())
    {
        cout << "Priority Queue is empty!" << endl;
        return;
    }

    cout << "Deleted element: " << queue[front] << endl;
    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    if (empty())
    {
        cout << "Priority Queue is empty!" << endl;
        return;
    }

    cout << "Priority Queue: ";

    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";

    cout << endl;
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
            enqueue(x);
            break;

        case 2:
            dequeue();
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
}