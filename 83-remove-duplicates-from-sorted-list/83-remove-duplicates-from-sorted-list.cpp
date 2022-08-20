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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode *curr=head;
        ListNode *currNext;
        while(curr->next!=NULL){
            if(curr->val == curr->next->val){
                currNext=curr->next;
                curr->next=curr->next->next;
                delete currNext;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
    }
};