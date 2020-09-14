class Solution {
public:
    int findNthDigit(int n) {
        int dig = 1;
        long long base = 9;
        while((n - dig*base) > 0){
            n -= dig*base;
            base *= 10;
            dig++;
        }

        int index = n % dig;
        if(index == 0){
            index = dig;
        }
        long long num = 1;
        for(int i = 1; i < dig; i++){
            num *= 10;
        }
        num += (index == dig) ? n/dig-1 : n/dig;

        for(int i = index; i < dig; i++){
            num /= 10;
        }

        return num % 10;

    }
};
