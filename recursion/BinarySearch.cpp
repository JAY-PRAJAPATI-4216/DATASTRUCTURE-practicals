#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if the current element is greater than the next element
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main()
{

    int n;

    cout << "Enter a number of elements: ";
    cin >> n;

    int array[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> array[i];
    }
    bubbleSort(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}