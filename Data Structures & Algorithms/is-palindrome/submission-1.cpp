class Solution {
   public:
    bool isPalindrome(string s) 
    {
        string str = "";

        for (int i = 0; i < s.length(); i++) 
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) 
            {
                str += tolower(s[i]);
            }
        }

        int left = 0, right = str.length() - 1;
        
        while (left < right) 
        {
            if (str[left++] != str[right--]) 
            {
                return false;
            }
        }
        return true;
    }
};
