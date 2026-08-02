#include <iostream>
using namespace std;

void traversal(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion(int arr[], int &n) {
    int pos, value;

    cout << "Enter position: ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> value;

    if (pos < 1 || pos > n + 1) {
        cout << "Invalid Position!\n";
        return;
    }

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    cout << "Element inserted successfully.\n";
}

void deletion(int arr[], int &n) {
    int pos;

    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Enter position to delete: ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid Position!\n";
        return;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Element deleted successfully.\n";
}

void search(int arr[], int n) {
    int key;

    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            return;
        }
    }

    cout << "Element not found.\n";
}

int main() {
    int arr[100], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n===== ARRAY OPERATIONS =====\n";
        cout << "1. Traversal\n";
        cout << "2. Insertion\n";
        cout << "3. Deletion\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                traversal(arr, n);
                break;

            case 2:
                insertion(arr, n);
                break;

            case 3:
                deletion(arr, n);
                break;

            case 4:
                search(arr, n);
                break;

            case 5:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}