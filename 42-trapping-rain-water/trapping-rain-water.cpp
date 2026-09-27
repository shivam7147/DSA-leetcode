class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        stack<int>st;

        vector<int>maxr(n,0);
        vector<int>maxl(n,0);

        maxl[0] =0;

        for(int i=1; i<n; i++)
        {
          maxl[i] = max(maxl[i-1] , height[i-1]);
        }

        maxr[n-1]=0;

        for(int i=n-2; i>=0; i--)
        {
         maxr[i] = max(maxr[i+1], height[i+1]);
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int mini = min(maxr[i] , maxl[i]);

            if(mini -height[i] >0) ans += mini -height[i];
        }

        return ans;

    }
};