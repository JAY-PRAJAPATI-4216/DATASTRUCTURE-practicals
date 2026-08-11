#include <iostream>
using namespace std;

int main(){
    
    int *p,i,a[5];

    p=a;
    for(i=0;i<5;i++)
    {
        cout << "Enter the value of a[" << i << "]: ";
        cin>>*(p);
        p++;
    }
    p=a;
    for(int i =0 ;i<5;i++)
    {
        cout << "The value of a[" << i << "] is: " << *(p) << endl;
        p++;
    }
    
    return 0;
}