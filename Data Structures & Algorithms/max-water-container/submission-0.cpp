class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int r = heights.size() - 1;
        int l = 0;
        int max_contain = 0;
        while (r > l) {
            max_contain = max(max_contain, min(heights[r], heights[l]) * (r - l));
            if (heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return max_contain;
    }
};
// 容量 = 兩邊較矮的高度 x 兩邊的距離
// 容量是由「較矮的木板」決定的（短板效應）。