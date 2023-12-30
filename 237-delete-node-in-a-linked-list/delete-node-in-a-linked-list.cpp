/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // by swapping move current node which needs to be deleted to last then delete BINGO!
    void deleteNode(ListNode* node) {
        ListNode* curr = node;

        while(curr->next->next != NULL){
            swap(curr->val, curr->next->val);
            curr = curr->next;
        }
        swap(curr->val, curr->next->val);
        curr->next = NULL;
    }
};