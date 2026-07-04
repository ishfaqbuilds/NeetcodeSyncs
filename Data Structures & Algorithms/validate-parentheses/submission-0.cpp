class Solution {
   public:
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.length(); i++) 
        {
            char ch = str[i];

            if (ch == '(' || ch == '{' || ch == '[') 
            {
                st.push(ch);
            } 
            else 
            {
                if (st.empty())
                {
                    return false;
                }

                char Top = st.top();
                st.pop();

                if (ch == ')' && Top != '(') return false;
                if (ch == '}' && Top != '{') return false;
                if (ch == ']' && Top != '[') return false;
            }
        }
        return st.empty();
    }
};
