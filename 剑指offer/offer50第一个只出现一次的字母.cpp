class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> mark;
        int len = s.size();
        for(int i = 0; i < len; i++){
            mark[s[i]]++;
        }
        for(int i = 0; i < len; i++){
            if(mark[s[i]] == 1){
                return s[i];
            }
        }
        return ' ';
    }
};
