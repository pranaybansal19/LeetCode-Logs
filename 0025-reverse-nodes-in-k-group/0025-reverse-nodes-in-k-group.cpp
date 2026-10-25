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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* nextNd = temp->next;

        while (nextNd != NULL) {
            temp->next = prev;
            prev = temp;
            temp = nextNd;
            nextNd = nextNd->next;
        }
        temp->next=prev;

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while (temp != NULL) {
            ListNode* curr = temp;
            for (int i = 1; i < k && curr != NULL; i++) {
                curr = curr->next;
            }
            // Now current will be the kth node and temp would be the starting
            // node
            if (curr != NULL) {
                nextNode = curr->next;
                curr->next = NULL;

                reverse(temp);

                if (temp == head) {
                    head = curr;
                } else {
                    prev->next = curr;
                }
                prev = temp;
                temp = nextNode;
            } else {
                if(prev!=NULL) prev->next = temp;
                break;
            }
        }
        return head;
    }
};