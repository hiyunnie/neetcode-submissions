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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        ListNode* dummyHead = new ListNode();
        ListNode* curr = dummyHead;
        
        int carry = 0;
        
        while (p1 != nullptr || p2 != nullptr || carry > 0) {
            int val1 = 0;
            int val2 = 0;
            
            if (p1 != nullptr) {
                val1 = p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                val2 = p2->val;
                p2 = p2->next;
            }
            
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            int remainder = sum % 10;

            curr->next = new ListNode(remainder);
            curr = curr->next;
        }
        
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};