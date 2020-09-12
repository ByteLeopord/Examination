class Solution {
public:
    string replaceSpace(string s) {
        int spacecnt = 0;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(s[i] == ' ') spacecnt++;
        }
        int newlen = len + spacecnt*2;
        string res(newlen, ' ');
        for(int i = len; i >= 0; i--){
            if(s[i] != ' ')
                res[newlen--] = s[i];
            else{
                res[newlen--] = '0';
                res[newlen--] = '2';
                res[newlen--] = '%';
            }
        }
        
        return res;
    }
};
