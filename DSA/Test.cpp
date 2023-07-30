// Modular mutiplicative inverse

#include <iostream>
using namespace std;

// Mine
// User function Template for C++
class Solution
{
public:
    // Complete this function
    int modInverse(int a, int m)
    {
        int x = -1;
        for (int i = 0; i < m; i++)
        {
            if ((a % m) * (i) % m == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
// Time Complexity: O(logm)
// Auxiliary Space: O(1)

//{ Driver Code Starts.

int main()
{

    int a, m;
    // taking input a and m
    cin >> a >> m;
    Solution ob;
    // calling function modInverse()
    cout << ob.modInverse(a, m) << endl;
    return 0;
}
// } Driver Code Ends