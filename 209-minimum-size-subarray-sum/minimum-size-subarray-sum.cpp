class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r=0;
        int sum =0;
        int ans = INT_MAX;

        while(r<nums.size())
        {
            sum += nums[r];

            if(sum >= target)
            {
                int x = r -l +1;
                ans = min(x , ans);

                while(l<nums.size() && sum > target)
                {
                    sum -= nums[l];
                    l++;

                    if(sum >= target)
                    {
                        int x = r -l +1;
                        ans  = min(x,ans);
                    }
                }
            }
            r++;
        }

        
        return ans==INT_MAX? 0 : ans;
    }
};