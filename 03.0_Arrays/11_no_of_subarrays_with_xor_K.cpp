/*

Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Constraints:

1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤105
0 ≤ k ≤ 105

*/

/*

here our key idea is like the number of subarray whose sum equal to k

there we used to first check whether the reqXOR = (currXOR ^ targetXOR) is present in our map or not if not move ahead
by increasing  the frequency of the currXOR

other wise if the reqXOR is present in the map then we will add the frequency of the reqXOR

this was possible becuase

reqXOR^targetXOR = currXOR
multiplying with targetXOR bothsides
it becomes reqXOR ^ targetXOR^ targetXOR = currXOR ^ targetXOR

boils down to reqXOR = currXOR ^ targetXOR

*/

class Solution {
public:
    int subarrayXorequaltoK(vector<int> &arr, int k) {
        map<int, int>freq;
        int ans = 0;
        int n = arr.size();
        int currXOR = 0;
        freq[0] = 1;
        for (int i = 0; i < n; i++) {
            currXOR = currXOR ^ arr[i];

            int reqXOR = currXOR ^ k;
            if (freq.find(reqXOR) != freq.end()) {
                ans += freq[reqXOR];
            }
            freq[currXOR]++;
        }
        return ans;
    }

};


// https://www.interviewbit.com/problems/pairs-with-given-xor/
// have a try