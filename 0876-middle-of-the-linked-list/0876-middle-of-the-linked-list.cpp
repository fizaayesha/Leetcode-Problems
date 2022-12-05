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
    int lengthOfLL(ListNode* head){
        int ans=0;
        while(head!=NULL){
            ans++;
            head=head->next;
        }
        return ans;
    }
    ListNode* middleNode(ListNode* head) {
        int length=lengthOfLL(head);
        int l=length/2;
        while(l--){
            head=head->next;
        }
        return head;
    }
};