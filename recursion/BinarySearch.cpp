#include <iostream>
using namespace std;


void binarySearch(int arr[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            cout << "Element found at index " << mid << endl;
        else if (arr[mid] > x)
            binarySearch(arr, left, mid - 1, x);
        else
            binarySearch(arr, mid + 1, right, x);
    }
    else
    {
        cout << "Element not found in the array" << endl;
    }
}
int main(){
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    int i;
    cout << "Enter the elements in sorted order: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element to search: ";
    cin >> x;

    binarySearch(arr, 0, n - 1, x);
    return 0;
}