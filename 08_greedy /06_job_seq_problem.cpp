
// Job Sequencing Problem



/*

You are given two arrays: deadline[], and profit[], which represent a set of jobs,
where each job is associated with a deadline, and a profit.
Each job takes 1 unit of time to complete, and only one job can be scheduled at a time.
You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.

Constraints:
1 ≤ deadline.size() == profit.size() ≤ 105
1 ≤ deadline[i] ≤ deadline.size()
1 ≤ profit[i] ≤ 500

*/






// C++ program to solve job sequencing
// problem with maximum profit

#include<bits/stdc++.h>
using namespace std;

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();


    // pair the profit and deadline of
    // all the jos together
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({deadline[i], profit[i]});
    }

    // sort the jobs based on deadline
    // in ascending order
    sort(jobs.begin(), jobs.end());

    // to maintain the scheduled jobs based on profit
    multiset<int>ms;
    for (const auto &job : jobs) {

        // if job can be scheduled within its deadline
        if (job.first > ms.size())
            ms.insert(job.second);

        // Replace the job with the lowest profit
        else if (!ms.empty() && ms.begin() < job.second) {
            ms.erase(ms.begin());
            ms.insert(job.second);
        }
    }
    vector<int> ans = {0, 0};
    while (!ms.empty()) {
        ans[1] += ms.begin();
        ms.erase(ms.begin());
        ans[0]++;
    }

    return ans;
}

int main() {
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> ans = jobSequencing(deadline, profit);
    cout << ans[0] << " " << ans[1];
    return 0;
}