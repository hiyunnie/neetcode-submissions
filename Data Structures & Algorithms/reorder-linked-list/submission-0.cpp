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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;  // 務必記得將前半段截斷！

        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        ListNode* curr_tail = prev;
        ListNode* curr_head = head;

        while (curr_tail != nullptr && curr_head != nullptr) {
            ListNode* next_head = curr_head->next;
            ListNode* next_tail = curr_tail->next;

            curr_head->next = curr_tail;
            curr_tail->next = next_head;

            curr_head = next_head;
            curr_tail = next_tail;
        }
    }
};

/**
## Approach

1. Use slow and fast pointers to find the middle of the list.
2. Split the list into two halves.
3. Reverse the second half.
4. Merge the two halves alternately:

   first node from left half
   first node from reversed right half
   second node from left half
   second node from right half
   ...

Example:

`1 -> 2 -> 3 -> 4 -> 5`
Split:
`1 -> 2 -> 3`
`4 -> 5`
Reverse second half:
`5 -> 4`
Merge:
`1 -> 5 -> 2 -> 4 -> 3`

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Interview Explanation

First, I use slow and fast pointers to find the middle of the linked list.
Then I split the list and reverse the second half in place.
Finally, I merge the first half and reversed second half by alternating nodes from each list.
Each node is visited only a constant number of times, so the time complexity is O(n), and the extra space is O(1).

## Follow-up

Why do we need to set:
`slow->next = nullptr`
before merging?

We cut the list first to avoid keeping the old connection, which could create a cycle during merging.

## Note
Remember to save both next pointers before reconnecting nodes during the merge.

**/