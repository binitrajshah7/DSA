/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Approach 1
    // Make a hashmap where node of old linkedlist will be key and 
    // node of new linkedlist will be in our value

    // Going forward we will initialize next pointer and check if random of old node
    // is already available in our map or not if not we will initialize one and point
    // curr->random to the found one and push it to hash map else we will simply point 

    // Optimised approach
    // make copied linked list in next of every node this way we can keep hash without using extra space
    
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node*curr=head;
        while(curr!=NULL){
            Node* newNode=new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=curr->next->next;
        }
        curr=head;
        while(curr!=NULL){
            if(curr->next!=NULL){
                curr->next->random = (curr->random!=NULL)? curr->random->next: NULL;
            }
            curr = curr->next->next;
        }
        Node* orig=head;
        Node *copy=head->next;
        Node *temp = copy;
        while(orig!=NULL){
            if(orig->next!=NULL && temp->next!=NULL){
                orig->next=orig->next->next;
                temp->next=temp->next->next;    
            }
            else{
                orig->next=NULL;
                temp->next=NULL;
            }
            orig=orig->next;
            temp=temp->next;
        }
        return copy;
    }
};