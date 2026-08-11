#include <iostream>
using namespace std;
#define s 20

int queue[s];
int front = -1, rear = -1;

int findmin()
{
    if (front == -1)
    {
        return -1; 
    }
    int min = queue[front];
    for (int i = front; i <= rear; i++)
    {
        if (queue[i] < min)
        {
            min = queue[i];
        }
    }
    return min;
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



int main()
{
    int i,n;
    cout << "Enter the number of elements: ";
    cin >> n;
    for(i=0;i<n;i++)
    {
        cout << "Enter the element: ";
        cin >> queue[i];
    }

    int min = findmin();
    cout << "the minimum value is:" << min << endl;
    return 0;
}