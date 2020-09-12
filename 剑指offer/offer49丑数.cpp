class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 7) return n;
        vector<int> ugly(n);
        int p2 = 0, p3 = 0, p5 = 0;
        int index = 1;
        ugly[0] = 1;
        while(index < n){
            int temp = min(ugly[p2]*2, min(ugly[p3]*3, ugly[p5]*5));
            ugly[index++] = temp;
            if(temp == ugly[p2]*2){
                p2++; 
            }
            if(temp == ugly[p3]*3){
                p3++;
            }
            if(temp == ugly[p5]*5){
                p5++;
            }
        }
        return ugly[n-1];
    }
};
