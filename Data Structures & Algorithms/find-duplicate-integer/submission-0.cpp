class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];        // 走 1 步
            fast = nums[nums[fast]];  // 走 2 步
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];  // 走 1 步
            fast = nums[fast];  // 走 1 步
        }

        return slow;  // 相遇點即為環的入口 (重複的數字)
        // 相遇後，必須將其中一個指標放回起點（nums[0]），然後讓兩個指標每次都只走 1
        // 步，再次相遇的地點才是環的入口（重複的數字）。
    }
};
// 把val當成linked list的next address