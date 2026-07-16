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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        if (temp1 == NULL || temp2 == NULL) {
            return NULL;
        }
        // Ultimately temp1 has to cover the same distance which temp2 has
        // cover.so basically they are covering the same amount of distance
        // together.
        // It is 3+2=2+3 kind of thing
        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (temp1 == temp2) {
                break;
            }
            if (temp1 == NULL) {
                temp1 = headB;
            }
            if (temp2 == NULL) {
                temp2 = headA;
            }
        }
        return temp1;
    }
};

/*
//Alternative Approach

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        unordered_map<ListNode*,int>mpp;
        while(temp1!=NULL){
            mpp[temp1]=1;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            if(mpp.count(temp2)==1){
                return temp2;
            }
            mpp[temp2]=1;
            temp2=temp2->next;
        }
        return NULL;
    }
*/
