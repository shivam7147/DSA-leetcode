class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        int li=0 , hi=0;

        for(int i =0; i<nums.size(); i++)
        {
            if(mini > nums[i])
            {
                mini = nums[i];
                li = i;
            }

            if(maxi < nums[i])
            {
                maxi = nums[i];
                hi = i;
            }
        }

        int x = min(li , hi);
        int y = max(li , hi);

        int a = y+1;
        int b = nums.size() - x;
        int c = nums.size() - (y - x - 1);

        int ans = min(a,min(b,c));
        return ans;

    }
};