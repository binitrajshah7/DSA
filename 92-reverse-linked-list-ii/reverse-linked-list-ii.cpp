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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // We create dummy node to handle all the edge cases when our whole linked list needs to be reversed
        // we keep it as left_pre if whole node is to be reversed
        ListNode* dummy = new ListNode(-1, head);
        
        ListNode* left_pre = dummy;
        ListNode* curr_node = head;

        for(int i=0; i<left-1; i++){
            left_pre = left_pre->next;
            curr_node = curr_node->next;
        }

        // left_pre = 1, curr_node = 2
        ListNode* sub_list_head = curr_node;

        // plain reverse a linked list but for limited window
        ListNode* prev = NULL;
        for(int i=0; i<right-left+1; i++){
            ListNode* next_node = curr_node->next;
            curr_node->next = prev;
            prev = curr_node;
            curr_node = next_node;
        }

        // 2's next should point to 5
        sub_list_head->next = curr_node;
        // 1's next should point to head of reversed linked list i.e 4
        left_pre->next = prev;

        return dummy->next;
    }
};