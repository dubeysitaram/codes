class Solution {
public:
    int dfs(string& beginWord, string& endWord, unordered_map<string, int>& mp, unordered_set<string>& visited) {
        if (beginWord == endWord)return 0;
        visited.insert(beginWord);
        int ans = INT_MAX - 1;
        string orig = beginWord;
        for (int i = 0; i < beginWord.size(); i++) {
            for (int j = 0; j < 26; j++) {
                beginWord[i] = 'a' + j;
                if (mp.count(beginWord) && !visited.count(beginWord)) {
                    int res = dfs(beginWord, endWord, mp, visited);
                    if (res != INT_MAX)
                        ans = min(ans, 1 + res);
                }
            }
            beginWord = orig;
        }
        visited.erase(beginWord);
        return ans;
    }
    int bfs(string beginWord, string endWord, unordered_map<string, int>& mp) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int ct = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string org = q.front();
                q.pop();
                if (org == endWord) return ct;
                visited.insert(org);
                for (int j = 0; j < org.size(); j++) {
                    string temp = org;
                    for (int k = 0; k < 26; k++) {
                        temp[j] = 'a' + k;
                        if (mp.count(temp) && !visited.count(temp)) {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            ct++;
        }

        return 0;
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        unordered_set<string> visited;
        for (auto it : wordList) {
            mp[it]++;
        }
        int res = bfs(beginWord, endWord, mp);
        // if (res == INT_MAX - 1)
        //     return 0;
        return res;
    }
};