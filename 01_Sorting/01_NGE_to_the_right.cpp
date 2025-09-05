/*

https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

Given an array of N integers and Q queries of indices. For each query indices[i],
determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right
(after the position indices[i]).


Constraints:
1 <= N <= 104
1 <= arr[i] <= 105
1 <= queries <= 100
0 <= indices[i] <= N - 1
*/

// C++ code for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function for performing merge operation
void merge(vector<pair<int, int> >& vec, vector<int>& ans, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<pair<int, int> > arr;
    vector<pair<int, int> > brr;

    for (int i = 0; i < n1; i++) {
        arr.push_back(vec[i + low]);
    }

    for (int i = 0; i < n2; i++) {
        brr.push_back(vec[i + mid + 1]);
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2) {
        if (arr[i].first < brr[j].first) {
            // Finding Number of next greater element
            ans[arr[i].second] += n2 - j;
            vec[k] = arr[i];
            i++;
            k++;
        }
        else {
            vec[k] = brr[j];
            j++;
            k++;
        }
    }

    while (i < n1) {
        vec[k] = arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = brr[j];
        j++;
        k++;
    }
}

// Function for performing Merge Sort
void mergesort(vector<pair<int, int> >& vec, vector<int>& ans, int low, int high)
{
    int mid;
    if (low < high) {
        // Divide them into two different part
        mid = low + (high - low) / 2;
        // Calling mergesort function recursively for both
        // the part
        mergesort(vec, ans, low, mid);
        mergesort(vec, ans, mid + 1, high);
        // Merging both and part and calculating Number of
        // Next greater element
        merge(vec, ans, low, mid, high);
    }
}

// Function to find number of next
// greater elements on the right of
// a given element
void nextGreaterElements(int n, vector<int>& nums, int queries, vector<int>& indices)
{
    // Storing elements of vector with their index into
    // vector of pair
    vector<pair<int, int> > vec;
    for (int i = 0; i < n; i++) {
        vec.push_back({ nums[i], i });
    }

    // Declaring a vector to store Number of next greater
    // element for every element
    vector<int> ans(n, 0);
    mergesort(vec, ans, 0, n - 1);

    // Printing number of next greater element for Q queries
    for (int i = 0; i < queries; i++) {
        int j = indices[i];
        cout << ans[j] << " ";
    }
}

// Driver's code
int main()
{

    vector<int> nums = { 3, 4, 2, 7, 5, 8, 10, 6 };
    int queries = 2;
    vector<int> indices = { 0, 5 };
    // Function call
    nextGreaterElements(nums.size(), nums, queries,
                        indices);
    return 0;
}