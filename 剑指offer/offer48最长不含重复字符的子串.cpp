class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        map<char, int> mp;
        int len = s.size();
        int maxlen = 1;
        int left = 0;
        for(int right = 0; right < len; right++){
            if(mp.find(s[right]) != mp.end()){
                left = max(left, mp[s[right]] + 1);         //如果出现重复元素,更新左指针
            }
            mp[s[right]] = right;                           //更新元素出现的位置
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
