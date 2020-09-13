class Solution {
public:
    int strToInt(string str) {
        int len = str.size();
        int index = 0;
        //去除空格
        while(str[index] == ' '){
            index++;
            if(index >= len)
                return 0;
        }
        //判断正负
        bool isLess0 = false;
        if(str[index] == '-'){
            index++;
            isLess0 = true;
        }
        else if(str[index] == '+')
            index++;
        //long long防止溢出
        long long res = 0;
        //计算数值
        while(index < len && str[index] >= '0' && str[index] <= '9'){
            res = res * 10 + (str[index]-'0');
            if(!isLess0 && res > INT_MAX)
                return INT_MAX;
            else if(isLess0 && -res < INT_MIN)
                return INT_MIN;
            index++; 
        }
        
        if(isLess0) res = -res;
        return res;
    }
};
