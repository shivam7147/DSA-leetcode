class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int  j = height.size() -1;
        int maxi = 0;

        while(i<j)
        {
            int x = min(height[i] , height[j]);

            int res = x * (j-i);
            maxi = max(maxi , res);

            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxi;
    }
};