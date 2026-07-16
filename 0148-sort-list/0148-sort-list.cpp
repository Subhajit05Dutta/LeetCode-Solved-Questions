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
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        // We are doing it because we want the 1st middle (not 2nd middle) to
        // break the linkedlist in case of even length linkedlist.
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        if (list1 != NULL) {
            temp->next = list1;
        } else if (list2 != NULL) {
            temp->next = list2;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* middle = findmiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = NULL;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return mergeTwoLists(leftHead, rightHead);
    }
};
/*
//Alternative Approach
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        vector<int>arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            temp->val=arr[i];
            temp=temp->next;
        }
        return head;
    }
*/
