/*
输入一个字符串，打印出该字符串中字符的所有排列，可以以任意顺序返回这个字符串数组，但里面不能有重复元素
限制：1 <= s <= 8
*/
class Solution {
public:
    vector<string> res;

    void solve(string& s, int index){
        if(index == s.size()-1){
            res.push_back(s);
            return;
        }
        set<char> used;
        for(int i = index; i < s.size(); i++){
            if(used.count(s[i]) != 0) continue;     //剪枝,重复的字母在同一层不再使用
            used.insert(s[i]);
            swap(s, index, i);
            solve(s, index+1);
            swap(s, index, i);
        }
    }
    void swap(string& s, int a, int b){
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
    }
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        int len = s.size();
        solve(s, 0);
        return res;
    }
};
