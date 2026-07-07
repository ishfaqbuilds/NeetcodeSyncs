class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> grp;

        for (int i = 0; i < strs.size(); i++) 
        {
            string org = strs[i];
            string sorted = org;
            sort(sorted.begin(), sorted.end());

            grp[sorted].push_back(org);
        }

        vector<vector<string>> result;
        for (auto& i : grp) 
        {
            result.push_back(i.second);
        }

        return result;
    }
};
