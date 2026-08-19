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
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
/*
如果 list1 的值比較小：
list1 的下一個節點（list1->next）應該要接上什麼？
答案：應該接上「剩餘節點合併出來的結果」！
接完之後，這整串新的 Linked List 頭是誰？
答案：是 list1！


以 list1 = [1, 2], list2 = [1, 3] 為例：
mergeTwoLists(1, 1)
├── 1 <= 1，選 list1 的 1
├── list1->next = mergeTwoLists(2, 1)
│                 ├── 2 > 1，選 list2 的 1
│                 ├── list2->next = mergeTwoLists(2, 3)
│                 │                 ├── 2 <= 3，選 list1 的 2
│                 │                 ├── list1->next = mergeTwoLists(null, 3) -> 回傳 3
│                 │                 └── 回傳 2 (此時 2 -> 3)
│                 └── 回傳 1 (此時 1 -> 2 -> 3)
└── 回傳 1 (最終 1 -> 1 -> 2 -> 3)

*/