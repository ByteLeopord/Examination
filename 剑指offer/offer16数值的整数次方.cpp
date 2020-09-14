class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
            return 1.0;
        if(abs(x-1.0) < 0.00000001)
            return 1.0;
        
        double res = 1.0;
        bool isFu = false;
        if(n < 0){
            isFu = true;
            n = abs(n);
        }
        long long exp = n;
        int cnt = 1;
        while(exp > 0){
            if((exp & 1) == 1)
                res *= x; 
            x *= x;
            exp >>= 1;
        }
        
        if(isFu){
            res = 1.0 / res;
        }
        return res;
    }
};
