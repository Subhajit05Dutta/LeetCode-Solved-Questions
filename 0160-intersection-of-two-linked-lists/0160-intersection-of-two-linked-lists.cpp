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
        ListNode* t1=headA;
        ListNode* t2=headB;
        while(t1!=NULL && t2!=NULL){
            if(t1==t2){
                break;
            }
            t1=t1->next;
            t2=t2->next;
            if(t1==NULL && t2!=NULL){
                t1=headB;
            }
            else if(t2==NULL &&t1!=NULL){
                t2=headA;
            }
        }
        return t1;
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
