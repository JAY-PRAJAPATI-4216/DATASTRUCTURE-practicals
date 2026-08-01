#include <iostream>
using namespace std;

void CallByValue(int a, int b) {
    
    
    int temp = a;
    a = b;
    b = temp;
    
    cout << "Inside CallByValue function: " << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

void CallByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    
    cout << "Inside CallByReference function: " << endl;
    cout << "a = " << a << ", b = " << b << endl;
}
int main() {
    int x,y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    CallByValue(x, y);
    cout << "Outside CallByValue function: " << endl;
    cout << "x = " << x << ", y = " << y << endl;

    CallByReference(x, y);
    cout << "Outside CallByReference function: " << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
