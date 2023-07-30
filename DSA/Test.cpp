// Power

#include <iostream>
#include "supplement.h"
using namespace std;

// Naive
int power_n(int x, int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        res = res * x;
    }
    return res;
}
// Time Complexity:O(n)
// Auxiliary Space:O(1)

// Driver Code
int main()
{
    int n, x;
    cout << "please enter a numberand its exponent\n";
    cin >> x >> n;
    cout << power_n(x,n)<< endl;
    return 0;
}
