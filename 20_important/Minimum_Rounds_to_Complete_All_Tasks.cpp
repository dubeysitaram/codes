/*
You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task.
In each round, you can complete either 2 or 3 tasks of the same difficulty level.
Return the minimum rounds required to complete all the tasks,
or -1 if it is not possible to complete all the tasks.
*/


int minimumRounds(vector<int>& tasks) {
	map<int, int> mp;
	for (int i = 0; i < tasks.size(); i++) {
		mp[tasks[i]]++;
	}
	int ans = 0;
	for (auto it : mp) {
		int p = it.second;
		int k;
		if (p == 1)return -1;
		// case1: if divisible by 3
		if (p % 3 == 0) {
			k = p / 3;
		}
		else if (p % 2 != 0) { // case2: if not divisible by 3 and not divisible by 2
			int z = (p % 3);
			if (z == 2)
				k = (p / 3) + 1;
			else  // rem ==1
				k = ((p / 3) - 1) + 2;
			// if not divisible by 3 and 2 then we have to take 2set 2jobs and remaing 3sets job
		} else if (p % 2 == 0) {
			k = (p / 3) + 1;
		}
		cout << it.first << " " << it.second << " " << k << "\n";
		ans += k;
	}
	return ans;
}