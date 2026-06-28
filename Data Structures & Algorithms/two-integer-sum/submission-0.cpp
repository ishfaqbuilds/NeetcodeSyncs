class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            int number = target - nums[i];
            if (seen.count(number)) 
            {
                return {seen[number], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
