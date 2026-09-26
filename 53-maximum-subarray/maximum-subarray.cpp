class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>sum(n+1);
        vector<int>lm(n+1);

        sum[0] = 0;

        for(int i = 0; i<n; i++)
        {
            sum[i+1] = sum[i] + nums[i];
        }
        lm[0] = 0;

        for(int i=1; i<n+1; i++)
        {
            lm[i] = min(lm[i-1] , sum[i-1]);
        }

        int ans = nums[0];

        for(int i = 1; i<n+1; i++)
        {
            int x = sum[i] - lm[i];
            ans = max(ans, x);
        }
        return ans;

    }
};