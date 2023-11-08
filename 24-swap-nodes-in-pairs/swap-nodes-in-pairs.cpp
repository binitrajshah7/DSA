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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode *curr = head;
        ListNode *next = head->next;

        // setting 1s next to 3
        curr->next = next->next;
        // setting 2s next to 1
        next->next = curr;
        // now to get 1s next we take leap of faith of our recursive call
        curr->next = swapPairs(curr->next);
        // we should return second value cause it will be our head after swapping
        return next;
    }
};