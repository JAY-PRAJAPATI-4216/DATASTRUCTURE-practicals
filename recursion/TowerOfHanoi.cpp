#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char auxiliary, char to)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }

    towerOfHanoi(n - 1, from, to, auxiliary);

    
    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    
    towerOfHanoi(n - 1, auxiliary, from, to);
}

int main()
{
    int n;

    cout << "Enter the number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}