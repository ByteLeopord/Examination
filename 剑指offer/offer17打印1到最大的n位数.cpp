class Solution {
public:
    bool solve(string& s, int n){
        bool isflow = false;
        int c = 0;
        for(int i = n-1; i >= 0; i--){
            int sum = s[i]-'0'+c;
            if(i == n-1){
                sum++;      //递增操作
            }
            if(sum >= 10){
                if(i == 0){
                    isflow = true;
                }
                else{
                    s[i] = sum%10 + '0';
                    c = 1;
                }
            }
            else{
                s[i] = sum + '0';
                break;
            }
        }
        return isflow;
    }
    vector<int> printNumbers(int n) {
        string s(n, '0');
        vector<int> res;
        while(!solve(s, n)){
            res.push_back(stoi(s));
        }
        return res;
    }
};
