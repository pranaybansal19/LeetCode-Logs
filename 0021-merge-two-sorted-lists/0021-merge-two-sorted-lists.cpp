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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;

        ListNode* newhead=NULL;
        ListNode* temp3=newhead;

        while(temp1!=NULL && temp2!=NULL){
            ListNode* curr= NULL;
            if(temp1->val < temp2->val){
                curr=temp1;
                temp1=temp1->next;
            }else{
                curr=temp2;
                temp2=temp2->next;
            }

            if(newhead==NULL){
                newhead=curr;
                temp3=curr;
            }else{
                temp3->next=curr;
                temp3=temp3->next;
            }
        }
        if(temp1!=NULL){
            temp3->next=temp1;           
        }
        if(temp2!=NULL){
            temp3->next=temp2;
        }   
        return newhead;     
    }
};