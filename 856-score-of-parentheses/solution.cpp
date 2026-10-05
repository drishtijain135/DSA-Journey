// 0 ms | 8.2 MB
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char c:s){
            if(c=='(') st.push(0);
            else{
                int v = st.top();
                st.pop();
                //if v==0: if we closed an empty pair so max(1,0)=1
                //if v>0:we closed an existing pair so score is 2*v                
                int score = max(1, 2*v);
                st.top()+=score;
            }
        }
        return st.top();
    }
};