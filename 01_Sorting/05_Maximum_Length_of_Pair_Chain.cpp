

/*

You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. 
A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

Constraints:

n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000

*/









class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[&](vector<int>p1,vector<int>p2){
            return p1[1]<p2[1];
        });
        int curr = pairs[0][1];
        int ans=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>curr){
                ans++;
                curr= pairs[i][1];
            }
        }
        return ans;
    }
};