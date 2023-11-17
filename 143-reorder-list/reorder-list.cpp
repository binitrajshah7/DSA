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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;

        ListNode *prev = NULL;
        while(head){
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }

    // Intuition: we find the middle element break it into two linked list
    // reverse the second half and do first->next = second and second->next = first_next and so on
    // if list has odd number of elements then head2 will have 1 more value so we have to handle that 
    // has to be appeneded at last
    void reorderList(ListNode* head) {
        if(!head)
            return;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev;
        while (fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        ListNode *head1 = head;
        ListNode *head2 = reverse(slow);
        ListNode *last;
        while (head1)
        {
            ListNode *h1_next = head1->next;
            ListNode *h2_next = head2->next;

            head1->next = head2;
            head2->next = h1_next;
            last = head2;
            head1 = h1_next;
            head2 = h2_next;
        }

        if(head2)
            last->next = head2;
    }
};