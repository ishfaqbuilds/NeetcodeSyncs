class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) 
        {
            freq[nums[i]]++;
        }
        vector<int> vec[10001];
        for (auto& i : freq) 
        {
            vec[i.second].push_back(i.first);
        }

        vector<int> result;
        for (int i = 10000; i >= 1; i--) 
        {
            for (int j = 0; j < vec[i].size(); j++) 
            {
                result.push_back(vec[i][j]);

                if (result.size() == k)
                { 
                    return result;
                }
            }
        }
        return result;
    }
};
