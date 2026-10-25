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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int cnt=0;
        ListNode* temp=head;

        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int rot=(k%cnt);
        if(rot==0) return head;
        cnt-=(rot+1);
        temp=head;
        while(cnt--){
            temp=temp->next;
        }
        ListNode* nextNd=temp->next;
        temp->next=NULL;

        temp=nextNd;
        while(temp->next!=NULL) temp=temp->next;

        temp->next=head;
        return nextNd;
        
    }
};