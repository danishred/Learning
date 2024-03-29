// CPP Program to find maximum AND value of a pair
#include <bits/stdc++.h>
using namespace std;

// Utility function to check number of elements
// having set msb as of pattern
int checkBit(int pattern, int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if ((pattern & arr[i]) == pattern)
            count++;
    return count;
}

// Function for finding maximum and value pair
int maxAND(int arr[], int n)
{
    int res = 0, count;

    // iterate over total of 32bits from msb to lsb
    for (int bit = 31; bit >= 0; bit--)
    {
        // find the count of element having same pattern as
        // obtained by adding bits on every iteration.
        count = checkBit(res | (1 << bit), arr, n);

        // if count >= 2 set particular bit in result
        if (count >= 2)
            res = res | (1 << bit); // this is the pattern we continued
    }

    return res;
}
// Time Complexity: O(N*log(M)) where M is the maximum element from the array and N is the size of the array.
// Auxiliary Space: O(1)



// Driver function
int main()
{
            int arr[] = {4, 8, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum AND Value = " << maxAND(arr, n) << endl;
    return 0;
}

// ------------------Also-------------------------
// // CPP Program to find maximum XOR value of a pair
// #include <bits/stdc++.h>
// using namespace std;

// // Function for finding maximum and value pair
// int maxAND(int arr[], int n)
// {
//     int res = 0;
//     for (int i = 0; i < n; i++)
//         for (int j = i + 1; j < n; j++)
//             res = max(res, arr[i] & arr[j]);

//     return res;
// }

// // Driver function
// int main()   
// {
//     int arr[] = { 4, 8, 6, 2 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Maximum AND Value = " << maxAND(arr, n);
//     return 0;
// }
// Time Complexity: O(N2)
// Auxiliary Space: O(1)


