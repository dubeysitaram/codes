
/*

380. Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. 
Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. 
Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements
(it's guaranteed that at least one element exists when this method is called). 
Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

*/

class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>v;
    RandomizedSet() {
        
    }
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;
        int idx = mp[val];
        int lastval = v[v.size()-1];
        v[idx]  =lastval;
        mp[lastval]=idx;
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomindex  = rand()% v.size();
        return v[randomindex];
    }
};

