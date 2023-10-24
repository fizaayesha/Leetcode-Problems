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
        ListNode *partA=headA;
        ListNode *partB=headB;
        // if(partA==NULL && partB==NULL){
        //     return NULL;
        // }
        while(partA!=partB){
            if(partA==NULL){
                partA=headB;
            }
            else{
                partA=partA->next;
            }
            if(partB==NULL){
                partB=headA;
            }
            else{
                partB=partB->next;
            }
        }
        return partA;
    }
};