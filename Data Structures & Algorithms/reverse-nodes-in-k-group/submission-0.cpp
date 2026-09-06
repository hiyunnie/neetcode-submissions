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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for (int i = 0; i < k; i++) {
            if (!node) return head;  // 不足 k 個，不反轉直接回傳
            node = node->next;
        }

        ListNode* prev = reverseKGroup(node, k);
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
