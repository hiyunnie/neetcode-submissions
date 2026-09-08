class KthLargest {
   private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int heap_size;

   public:
    KthLargest(int k, vector<int>& nums) {
        heap_size = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > heap_size) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
