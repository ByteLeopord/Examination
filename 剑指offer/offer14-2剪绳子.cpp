class Solution {
public:
    const int mod = 1000000007;
    int cuttingRope(int n) {
        if(n <= 3) 
            return n-1;
        int rest = n % 3;
        long long res = 1, x = 3;
        for(int i = n/3-1; i > 0; i >>= 1){
            if((i & 1) == 1){
                res = (res*x) % mod;
            }
            x = (x*x) % mod;
        }
        if(rest == 1)
            res = (int)(res*4 % mod);
        else if(rest == 0)
            res = (int)(res*3 % mod);
        else
            res = (int)(res*6 % mod);
        return res;
    }
};
