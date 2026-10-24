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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // one traversal for finding the total number of nbodes
        // another iteration for doing the change 
        // Time complexity = O(2n)
        int cnt=0;
        ListNode* temp=head;

        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        ListNode* prev=NULL;
        temp=head;
        int cnt2=0;

        while(temp!=NULL && (cnt-n)!=cnt2){
            cnt2++;
            prev=temp;
            temp=temp->next;
        }
        if(prev==NULL) return head->next;
        prev->next=temp->next;
        return head;
    }
};