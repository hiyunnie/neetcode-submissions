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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        int n = lists.size();
        if (n == 0) return nullptr;
        for (int i = 0; i < n; i++) {
            if (lists[i]) {  // 確保不是空指標才放進去
                minHeap.push(lists[i]);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* curr = minHeap.top();
            minHeap.pop();

            tail->next = curr;  // 串接目前最小的節點
            tail = tail->next;  // 移動 tail 指標

            if (curr->next) minHeap.push(curr->next);
        }
        return dummy.next;
    }
};

// 核心想法：將這 K 條串列的第一筆節點（頭節點）全部放進一個「最小堆疊（Min-Heap）」。