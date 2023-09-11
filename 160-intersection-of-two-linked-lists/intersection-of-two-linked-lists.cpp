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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2=0;
        
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        while(curr1 != NULL){
            n1++;
            curr1 = curr1->next;
        }
        while(curr2 != NULL){
            n2++;
            curr2 = curr2->next;
        }
        
        if(n1 > n2)
            for(int i=0; i<n1-n2; i++)
                headA = headA->next;
        else if(n2>n1)
            for(int i=0; i<n2-n1; i++)
                headB = headB->next;
        
        while(headA && headB){
            if(headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
            
    }
};