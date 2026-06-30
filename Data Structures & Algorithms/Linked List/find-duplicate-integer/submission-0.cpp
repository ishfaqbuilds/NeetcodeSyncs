class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> appeared;
        for(int i : nums)
        {
            if(appeared.count(i))
            {
                return i;
            }
            appeared.insert(i);
        }
        return -1;
    }
};
