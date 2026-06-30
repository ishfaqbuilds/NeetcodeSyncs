class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dupli;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (dupli.count(nums[i])) 
            {
                return true;
            }
            dupli.insert(nums[i]);
        }
        return false;
    }
};