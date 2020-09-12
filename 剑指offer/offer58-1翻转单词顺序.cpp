class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return "";
        string res;
        int len = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ' ' && len != 0){
                res += s.substr(i+1, len) + " ";
                len = 0;
                continue;
            }
            if(s[i] != ' '){
                len++;
            }
        }
        if(len != 0){
            res += s.substr(0, len);
        }
        if(len == 0 && res.size() > 0){
            res.pop_back();
        }
        return res;
        // stringstream ss(s);
        // string temp, res;
        // stack<string> sk;
        // while(ss >> temp){
        //     sk.push(temp);
        // }
        // if(sk.empty())
        //     return "";
        // while(!sk.empty()){
        //     res += sk.top() + ' ';
        //     sk.pop();
        // }
        // res.pop_back();
        // return res;
    }
};
