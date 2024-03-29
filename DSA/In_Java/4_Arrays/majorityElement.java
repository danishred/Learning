/*Our Task: Find the majority element in the array. A majority element in an array A[] of size n is 
an element that appears more than n/2 times (and hence there is at most one such element).*/

// Test Cases:-
// Input 5 then 8 2 8 4 8 output 0 or 3 or 4
// Input 6 then 3 7 4 7 7 5 output -1
// Input 7 then 20 30 40 50 50 50 50 output 3 or 4 or 5 or 6

import java.util.Scanner;

public class majorityElement {
    
    // Mine|Naive
    // Time Complexity: O(n^2)
    // Auxiliary Space: O(1)
    public static int majorityElement1(int[] arr, int n) {
        int k = n / 2, count = 0, majority = 0, num = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++; // for every element count how many times it appears
                }
            }
            if ((count > k) && (count > majority)) {
                majority = count;
                num = i;
            }
            count = 0;
        }
        return num;
    }

    // Sir's|Naive
    // Time Complexity: O(n^2)
    // Auxiliary Space: O(1)
    static int findMajority(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            int count = 1;

            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j])
                    count++;
            }
            // if count turn out to be greater than n/2 then by default
            // the element become majority
            if (count > n / 2)
                return i;
        }
        return -1;
    }

    // Mine|Efficient
    // Time Complexity: O(n)
    // Auxiliary Space: O(1)
    static int findMajority1(int arr[], int n) {
        int count = 0, maxCount = 0, majority = -1;
        // First phase produces a candidate for majority element
        for (int i = 0; i < n; i++) {
            // cyclic array check
            if (arr[i] == arr[(i + 1) % n]) {
                count++;
                // stores index of current majority
                if (count > maxCount) {
                    majority = i;
                }
                // resets count if consecutive equals not found
            } else
                count = 0;
        }
        // Took second part from sir and it works
        // Checks whether the chosen element is actually majority
        count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[majority] == arr[i])
                count++;
        }
        if (count <= n / 2)
            majority = -1;
        return majority;
    }

    // Sir's|Efficient
    // Time Complexity: O(n)
    // Auxiliary Space: O(1)
    static int findMajority2(int arr[], int n) {
        int res = 0, count = 1;

        for (int i = 1; i < n; i++) {
            if (arr[res] == arr[i])
                count++;
            else
                count--;

            if (count == 0) {
                res = i;
                count = 1;
            }
        }

        count = 0;

        for (int i = 0; i < n; i++)
            if (arr[res] == arr[i])
                count++;

        if (count <= n / 2)
            res = -1;

        return res;
    }

    // Driver Code
    public static void main(String[] args) {
        int n;
        Scanner val = new Scanner(System.in);
        System.out.print("Enter the number of elements you want to store: ");
        n = val.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter elements of the Array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = val.nextInt();
        }
        val.close();
        System.out.println(majorityElement1(arr, n));
        System.out.println(findMajority(arr, n));
        System.out.println(findMajority1(arr, n));
        System.out.println(findMajority2(arr, n));
    }
}
