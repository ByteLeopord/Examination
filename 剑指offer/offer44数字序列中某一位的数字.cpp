/*
    数字       数量   位数    长度
    1-9        9      1       9
    10-99      90     2       180
    100-999    900    3       2700
    1000-9999  9000   4       36000
*/
class Solution {
public:
    int findNthDigit(int n) {
        int dig = 1;
        long long base = 9;
        //计算该数字的位数
        while((n - dig*base) > 0){
            n -= dig*base;
            base *= 10;
            dig++;
        }
        //计算需要获取的位 对应 该数字的第几位
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
