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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return {-1, -1};
        }
        ListNode* curr = head->next;
        ListNode* prev = head;

        int idx = 1;
        int FirstCritical = -1;
        int LastCritical = -1;
        int mini = INT_MAX;

        while (curr->next != NULL) {
            ListNode* next = curr->next;
            bool isMax = (curr->val > prev->val && curr->val > next->val);
            bool isMin = (curr->val < prev->val && curr->val < next->val);

            if (isMin || isMax) {
                if (LastCritical == -1) {
                    FirstCritical = idx;
                } else {
                    mini = min(mini, idx - LastCritical);
                }
                LastCritical = idx;
            }
            prev = curr;
            curr = next;
            idx++;
        }

        if (FirstCritical == -1 || FirstCritical == LastCritical) {
            return {-1, -1};
        }

        int maxi = LastCritical - FirstCritical;

        return {mini, maxi};
    }
};