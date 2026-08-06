class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for(auto &num: nums)
        {
            if(uset.find(num) != uset.end())
                return true;
            else
                uset.insert(num);
        }
        return false;
    }
};
/**
我的想法: 這題不能用XOR因為題目只說會出現不只一次，所以要用哈希表，先建一個哈希表，把全部數字放進去之後再看有沒有value !=1的。
======================================================================
Intuition: 一邊走訪陣列、一邊用 Set 紀錄看過的數字。若已在 Set 中即發現重複。時間複雜度O(n)

Corner Cases: 長度為 0 或 1、極端值、負數、資料結構的邊界問題。

Complexity:
(Time Complexity)：O(n)
(Space Complexity)：O(n)

Improve: 
if (!uset.insert(num).second) 
    return true;
insert() 本身就會先尋找元素是否存在。如果不存在就直接插入；如果已存在就放棄插入。優勢：它只會執行 1 次 Hash 運算。
======================================================================
Lessons Learned & Pitfalls
1. unordered_set, unordered_map使用時機

======================================================================
Follow-up

你現在的解法使用 unordered_set<int>，平均時間複雜度是 O(n)，但會使用 O(n) 額外空間。假設 firmware 環境不允許 dynamic allocation，也不能使用 STL，而且輸入陣列最多有 100,000 個元素，你會怎麼改？

回答時請涵蓋：

你會選 sorting 還是固定容量 hash table？
兩種方法的時間與空間複雜度
固定容量 hash table 遇到 collision 怎麼處理
table 滿了要怎麼回報
是否允許修改原始陣列
worst-case execution time 哪種比較容易預估

我的想法: 如果允許修改輸入，我會先排序，再比較相鄰元素。時間複雜度是 O(n log n)，額外空間依排序實作約 O(log n)，優點是 worst-case 較容易預估。如果不能修改輸入，我會使用預先配置的固定容量 hash table，透過 linear probing 處理 collision。平均時間是 O(n)，空間是 O(capacity)。若 table 滿了，API 應回傳明確的 capacity error，而不是誤判沒有 duplicate。

Linear probing 容易讓碰撞的元素黏成一長串；這個連續被占用的區塊就是 clustering。

**/