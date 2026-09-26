class Solution {
public:
    int characterReplacement(string s, int k) {

        map<char, int> mp;

        int maxi = 0;
        int l = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            mp[s[i]]++;

            maxi = max(maxi, mp[s[i]]);

            while (i - l + 1 > maxi + k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};