class Solution {
public:
    void rever(string& s, int left, int right){
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        rever(s, 0, n-1);
        rever(s, n, len-1);
        rever(s, 0, len-1);
        return s;
    }
};
