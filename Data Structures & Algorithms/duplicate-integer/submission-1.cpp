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