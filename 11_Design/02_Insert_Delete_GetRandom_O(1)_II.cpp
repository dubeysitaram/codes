// 381. Insert Delete GetRandom O(1) - Duplicates allowed
RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements and also reporting a random element.

Implement the RandomizedCollection class:

RandomizedCollection() Initializes the empty RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements. The probability of each element being returned is linearly related to the number of the same values the multiset contains.
You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least one item in the RandomizedCollection.

class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int, unordered_set<int>> mp;
    RandomizedCollection() {}

    bool insert(int val) {
        bool ans = false;
        if (mp.find(val)==mp.end())
            ans = true;
        v.push_back(val);
        mp[val].insert(v.size() - 1);
        return ans;
    }
    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;

        int idx = (*(mp[val].begin()));
        mp[val].erase(mp[val].begin());
        if (mp[val].empty())
            mp.erase(val);

        int lastval = v.back();
        int lastidx = v.size() - 1;

        if (idx != lastidx) { // important edge test case
            mp[lastval].erase(lastidx);
            v[idx] = lastval;
            mp[lastval].insert(idx);
        }

        v.pop_back();
        return true;
    }

    int getRandom() {
        int randomindex = rand() % v.size();
        return v[randomindex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

