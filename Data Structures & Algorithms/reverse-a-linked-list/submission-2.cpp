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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

/**

## Clarification

- Can the input list be empty?
- Should I reverse the list in place?
- Is modifying the original links allowed?

## Brute Force

Store all nodes in an auxiliary array or vector, then reconnect them in reverse order.

- Time: `O(n)`
- Space: `O(n)`

## Optimized Approach

Reverse the linked list in place using three pointers:

- `curr`: current node
- `prev`: previous node
- `temp`: temporarily saves the next node

Steps:

1. Save `curr->next` into `temp`.
2. Reverse the link with `curr->next = prev`.
3. Move `prev` to `curr`.
4. Move `curr` to `temp`.
5. Continue until `curr == nullptr`.

At the end, `prev` becomes the new head.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Edge Cases

1. Empty list
2. Single-node list
3. Two-node list

## Interview Explanation

I reverse the list in place using three pointers.
`curr` points to the current node, `prev` points to the already reversed part, and `temp` saves the next node before I modify the link.
For each node, I first save `curr->next`, then point `curr->next` to `prev`.
After that, I move both pointers forward.
When `curr` becomes null, `prev` points to the new head.
The time complexity is O(n) and the space complexity is O(1).

## Follow-up
Can you reverse the linked list recursively? What would be the time and space complexity?
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
Time:  O(n)
Space: O(n)
## Note
Recursive reverse linked list：先遞迴到尾巴，再利用 call stack 回來時反轉 next pointer。

**/
