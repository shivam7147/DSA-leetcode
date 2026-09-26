class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>mp;
        int l=0;
        int ans = 0;

        for(int i = 0; i<s.size(); i++)
        {
            mp[s[i]]++;

            if(mp[s[i]] >1)
            {
                while(mp[s[i]]>1)
                {
                    mp[s[l++]]--;
                }
            }

            ans  =max(ans, i - l +1);
        }
        return ans;
    }
};
