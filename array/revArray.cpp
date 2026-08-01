#include <iostream> 
using namespace std;

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    int *ptr = arr + n - 1;
    cout << "Reversed array: ";
    for(int i=0; i<n; i++) {
        cout << *ptr << " ";
        ptr--;
    }
    
    return 0;
}