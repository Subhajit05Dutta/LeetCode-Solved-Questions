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
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* mover = dummy;
        ListNode* temp = head;
        while (temp != NULL) {
            if (mover->val != temp->val) {
                ListNode* newnode = new ListNode(temp->val);
                mover->next = newnode;
                mover = mover->next;
            }

            temp = temp->next;
        }
        return dummy->next;
    }
};