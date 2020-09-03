/*
求1到n的和
不能使用乘除法 for while等循环语句
*/
class Solution {
public:
    int sumNums(int n) {
        if(n == 1) return 1;
        return n + sumNums(n-1);
    }
};
