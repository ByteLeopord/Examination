class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> sk;
        sk.push(-1);
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(s[i] == '('){
                sk.push(i);
            }
            else{
                sk.pop();
                if(sk.empty()){
                    sk.push(i);
                }
                else{
                    res = max(res, i-sk.top());
                }
            }
        }
        return res;
    }
};
