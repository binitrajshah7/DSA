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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* curr = list1;
        ListNode* prev = list1;
        b = b-a+1;
        while(a--){
            prev = curr;
            curr = curr->next;
        }

        prev->next = list2;
        while(b--){
            prev = curr;
            curr = curr->next;   
        }

        while(list2->next){
            list2 = list2->next;
        }

        list2->next = curr;
        // cout << list2->val << endl;
        // cout << prev->val << endl;
        // cout << curr->val << endl;
        return list1;
    }
};