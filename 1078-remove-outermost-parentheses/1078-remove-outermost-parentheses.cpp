class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(st.empty() && ch=='(')
            st.push(s[i]);
            else if (!st.empty() &&ch=='('){
                st.push(ch);
                ans+=ch;
            }
            else if(ch==')' ){
                st.pop();
                if(!st.empty())
                ans+=ch;
            }
        }
         return ans;
    }
   
};