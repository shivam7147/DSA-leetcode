/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* nex = cur->next;

        if(nex == nullptr) return {-1,-1};
        vector<int>dis;
        int i=1;
        while(nex)
        {
            if((cur->val > prev->val) && (cur->val > nex->val) )
            {
                dis.push_back(i);
            }

            if((cur->val < prev->val) && (cur->val < nex->val) )
            {
                dis.push_back(i);
            }

            prev = cur;
            cur = nex;
            nex = nex->next;
            i++;
        }

        int n = dis.size();

        if(n<2) return {-1, -1};

        int maxi = dis[n-1] - dis[0];

        int mini  = dis[1] - dis[0];

        for(int i = 1; i<n-1; i++)
        {
            mini  = min(mini , dis[i+1] - dis[i]);
        }

        vector<int>z = {mini , maxi};
        return z;        
    }
};