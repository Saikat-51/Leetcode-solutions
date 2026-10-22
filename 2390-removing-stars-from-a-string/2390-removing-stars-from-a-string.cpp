class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        stack<char>st2;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='*') st.push(s[i]);
            else st.pop();
        }
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
};