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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        if(!head)
            return NULL;

        // Lookup set
        unordered_set<int> us;
        for(auto e: nums)
            us.insert(e);

        // skipping for first elements
        while(us.find(head->val) != us.end())
            head = head->next;

        // if found in hash set and is in middle then we keep deleting the elements
        ListNode* curr = head;
        while(curr && curr->next){
            if(us.find(curr->next->val) != us.end())
                curr->next = curr->next->next;
            else
                curr = curr->next;

        }
        return head;
    }
};