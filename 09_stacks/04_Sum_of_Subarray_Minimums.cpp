// 907. Sum of Subarray Minimums

/* Given an array of integers arr, find the sum of min(b), 
where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.
*/



// max - min


class Solution {
public:
    vector<long long> getNGE(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> res(n, n);
        stack<long long> st;
        for (long long i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<long long> getPGEE(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> res(n, -1);
        stack<long long> st;
        for (long long i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }
    vector<long long> NSERIGHT(vector<int>& v) {
        stack<long long> st;
        long long n = v.size();
        vector<long long> ans(n, n);

        for (long long i = 0; i < n; ++i) {
            while (!st.empty() && v[st.top()] > v[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<long long> PS_EQUAL_ELEMENT_LEFT(vector<int>& v) {
        stack<long long> st;
        long long n = v.size();
        vector<long long> ans(n, -1);

        for (long long i = 0; i < n; ++i) {
            while (!st.empty() && v[st.top()] > v[i]) {
                st.pop();
            }
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& arr) {
        vector<long long> nge = getNGE(arr);
        vector<long long> pgee = getPGEE(arr);
        long long finalans1 = 0;

        for (long long i = 0; i < arr.size(); i++) {
            long long x = nge[i] - i;
            long long y = i - pgee[i];
            long long contribution = (x * y);
            finalans1 = (finalans1 + (contribution * arr[i]));
        }
        vector<long long> nse = NSERIGHT(arr);
        vector<long long> psee = PS_EQUAL_ELEMENT_LEFT(arr);
        long long finalans2 = 0;

        for (long long i = 0; i < arr.size(); i++) {
            long long x = nse[i] - i;  // Distance to next smaller
            long long y = i - psee[i]; // Distance to previous smaller-or-equal
            long long contribution = (x * y);
            finalans2 = (finalans2 + (contribution * arr[i]));
        }
        return finalans1 - finalans2; // formulae for Range 
    }
};