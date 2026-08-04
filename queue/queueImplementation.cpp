#include <iostream>
using namespace std;

#define s 20
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
        rear++;
        queue[rear] = x;
    }
}

int dequeuer()
{
    int x;
    if (empty())
    {
        exit(0);
    }
    else
    {
        x = queue[front];
        front++;
    }
    return x;
}

int main()
{

    while (1)
    {
        int n;

        cout << "\n1.enqueuer \n2.dequeuer\n3.display\n4.exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            int ele;
            cout << "enter a element to enter in queue :";
            cin >> ele;
            enqueuer(ele);
            break;

        case 2:
            int x;
            x = dequeuer();
            cout << "The dequeued element is: " << x << endl;
            break;
        case 3:
            // Display elements in the queue
            cout << "The elements in the queue are: ";
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
            break;
        case 4:
            exit(0);
            break;
       
        }

        
    }
    return 0;
}