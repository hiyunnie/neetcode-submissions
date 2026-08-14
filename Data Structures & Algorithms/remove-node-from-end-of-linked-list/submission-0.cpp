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
        if (!head) return head;
        ListNode dummyhead(0, head);  // 直接將 next 指向 head

        ListNode* fast = &dummyhead;
        ListNode* slow = &dummyhead;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // remove node
        ListNode* tobedelete = slow->next;
        slow->next = slow->next->next;
        delete tobedelete;

        return dummyhead.next;
    }
};

/**

## Approach

Create a dummy node before `head` so removing the first real node does not need a special case.

Use two pointers:

1. Initialize both `fast` and `slow` at the dummy node.
2. Move `fast` forward by `n` steps.
3. Move both pointers together until `fast->next == nullptr`.
4. At this point, `slow->next` is the node to remove.
5. Bypass and delete that node.
6. Return `dummyhead.next`.

The key idea is to keep a gap of `n` nodes between `fast` and `slow`.

## Complexity

- Time: `O(L)`
- Space: `O(1)`

`L` is the length of the linked list.

## Interview Explanation
I use a dummy node and two pointers.
First, I move the fast pointer `n` steps ahead. Then I move both fast and slow one step at a time.
When `fast` reaches the last node, `slow->next` is the nth node from the end.
I use a dummy node so deleting the original head can be handled with the same logic.
The time complexity is O(L) and the extra space is O(1).

## Follow-up
We start both pointers from the dummy node so that removing the original head does not require a special case.

**/
