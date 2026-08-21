class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        vector<long long> pre(n);
        pre[0] = tasks[0];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + tasks[i];
        }

        long long total = pre[n - 1];
        long long done = 0;

        vector<int> ans(shifts.size());



        for (int i = 0; i < shifts.size(); i++) {

            done += shifts[i];

            if (done >= total) {
                ans[i] = 0;

                // IMPORTANT:
                // Extra time is discarded.
                done = 0;
            }
            else {
                auto it = upper_bound(pre.begin(), pre.end(), done);

                int idx = it - pre.begin();

                ans[i] = n - idx;
            }
        }

        return ans;
    }
};