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
    ListNode* reverse(ListNode* temp, int left, int right) {
        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* next = temp;
        while (curr != NULL && left != right) {
            left++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        if (left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // Find node just before 'left'
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // First node of the section to reverse
        ListNode* curr = prev->next;

        // Reverse left to right
        ListNode* revprev = NULL;
        for (int i = left; i <= right; i++) {
            ListNode* next = curr->next;
            curr->next = revprev;
            revprev = curr;
            curr = next;
        }

        // Connect before-left to reversed part
        prev->next->next = curr;
        prev->next = revprev;
        return dummy->next;
    }
};