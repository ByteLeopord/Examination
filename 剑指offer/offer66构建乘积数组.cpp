class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        vector<int> b1(len, 1);
        vector<int> b2(len, 1);
        for(int i = 1; i < len; i++){
            b1[i] = b1[i-1]*a[i-1];
            b2[len-1-i] = b2[len-i]*a[len-i];
        }
        for(int i = 0; i < len; i++){
            b1[i] *= b2[i];
        }
        return b1;
    }
};
