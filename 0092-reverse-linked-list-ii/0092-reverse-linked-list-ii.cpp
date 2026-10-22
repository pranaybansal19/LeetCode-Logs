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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        // Move prev to the node before position left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* curr = start;
        ListNode* next = nullptr;
        ListNode* revPrev = nullptr;

        // Reverse the sublist from left to right
        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = revPrev;
            revPrev = curr;
            curr = next;
        }

        // Reconnect the reversed sublist
        prev->next = revPrev;
        start->next = curr;

        return dummy.next;
    }

};