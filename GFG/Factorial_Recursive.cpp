// Recursive Factorial

// Time Complexity (T(n-1)+theta(1))
// Auxilary space complexity theta(n)
#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
    return 1;
    return n*fact(n-1); 
}

int main()
{
    int n;
    cin >> n;
    cout << fact(n);
    return 0;
}
