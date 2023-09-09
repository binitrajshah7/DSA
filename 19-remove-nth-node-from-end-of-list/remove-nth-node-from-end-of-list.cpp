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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        // we keep fast pointer nth step forward
        for(int i=0; i<n; i++)
            fast = fast->next;
        // if our fast reached last i.e it becomes null that implies we have to delete first element
        if(!fast)
            return head->next;
        // else we move both fast and slow so our fast will be n element forward
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        // now we skip the element we need to skip
        slow->next = slow->next->next;
        return head;
    }
};