class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n1 = series1.size();
        int n2 = series2.size();

        vector<vector<int>>ans;
        
        int i = 0 ,j =0;
        set<int>st;
        while(i<n1)
        {
            int f = series1[i][0];
            int w = series1[i][1];
            while(j<n2 && series2[j][0]< f)
            {
                j++;
            }

            if(j<n2)
            {
                w += series2[j][1];
            }
            ans.push_back({f,w});
            st.insert(f);
            i++;
        }

        i=0, j=0;
        while(i<n2)
        {
            int f = series2[i][0];
            
            if(st.find(f) == st.end()){
            
            int w = series2[i][1];
            while(j<n1 && series1[j][0]< f)
            {
                j++;
            }

            if(j<n1)
            {
                w += series1[j][1];
            }
            ans.push_back({f,w});
            }
            i++;
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};