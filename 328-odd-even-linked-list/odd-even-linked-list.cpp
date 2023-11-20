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
    // Intution we keep 2 pointers to our odd and even list we just keep jumping two steps in both linked list
    // breaking the current next and pointing to curr->next->next

    // For adding even list to end of odd list we keep a reference to even head 
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;

        ListNode* odd = head, *odd_head = head;
        ListNode* even = head->next, *even_head = head->next;

        while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return odd_head;
    }
};