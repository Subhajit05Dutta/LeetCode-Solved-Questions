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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int ans = 0;
        while (temp != NULL) {
            ans = ans * 2 + temp->val;
            temp = temp->next;
        }
        return ans;
    }
};

/*
//Alternative Approach
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* temp = reverse(head);
        int n = 0;
        long long pow = 1;
        while (temp != NULL) {
            n = n + (temp->val * pow);
            pow = pow * 2;
            temp = temp->next;
        }
        return n;
    }
*/