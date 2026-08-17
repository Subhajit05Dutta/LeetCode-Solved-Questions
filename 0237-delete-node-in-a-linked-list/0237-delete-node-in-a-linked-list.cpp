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
    void deleteNode(ListNode* node) {
        
        ListNode* curr=node;
        ListNode* del=curr->next;;
        curr->val=curr->next->val;
        curr->next=curr->next->next;
        del->next=NULL;
        delete(del);
        return;
    }
};