class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int num : nums) {
            min_heap.push(num);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};
/**

## Brute Force

Sort the array in descending or ascending order, then return the kth largest element.

- Time: `O(n log n)`
- Space: depends on the sorting implementation

## Optimized Approach

Use a min-heap of size `k`.

For each number:

1. Push it into the min-heap.
2. If the heap size becomes larger than `k`, remove the smallest element.

After processing all numbers, the heap contains the `k` largest elements.

The top of the min-heap is the smallest among these `k` elements, so it is the kth largest element.

## Complexity

- Time: `O(n log k)`
- Space: `O(k)`

## Interview Explanation

I use a min-heap with at most k elements.

For each number, I push it into the heap. If the heap size exceeds k, I remove the smallest element.

This way, the heap always keeps the k largest elements seen so far.

At the end, the top of the min-heap is the kth largest element.

The time complexity is O(n log k), and the space complexity is O(k).

## Follow-up

Can you solve this in average `O(n)` time without sorting the entire array?


**/