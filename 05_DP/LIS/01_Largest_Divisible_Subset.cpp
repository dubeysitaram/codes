// 01_Largest_Divisible_Subset.cpp
/*
Given an array arr[] of positive integers. 
Your task is to find the largest subset such that for every pair of elements (x, y) in the subset, 
either x divides y or y divides x.
Note : If multiple subsets of the same maximum length exist,
return the one that is lexicographically greatest, after sorting the subset in ascending order.
*/

// https://www.geeksforgeeks.org/problems/largest-divisible-subset--170643/1

    vector<int> largestSubset(vector<int>& arr) {
    int n = arr.size();
    sort(arr.rbegin(),arr.rend());
    vector<int>lds(n,1),hash(n,0);
    for(int i=1;i<n;i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if(arr[j]%arr[i]==0 && lds[i]<lds[j]+1){
                hash[i]=j;
                lds[i]=lds[j]+1;
                }
        }
    }
    vector<int>fans;
    int ind  = max_element(lds.begin(),lds.end())-lds.begin();
    while(hash[ind]!=ind){
        fans.push_back(arr[ind]);
        ind  = hash[ind];
    }
    fans.push_back(arr[ind]);
    return fans;
    }