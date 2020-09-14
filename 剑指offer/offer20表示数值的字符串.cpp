class Solution {
public:
    bool scanNumber(string s, int& index){
        bool hasNumber = false;
        while(s[index] >= '0' && s[index] <= '9'){
            hasNumber = true;
            index++;
        }
        return hasNumber;
    }
    bool scanInt(string s, int& index){
        if(s[index] == '-' || s[index] == '+'){
            index++;
        }
        return scanNumber(s, index);
    }
    bool isNumber(string s) {
        if(s.empty()) return false;
        int index = 0;
        int len = s.size();
        //去除前面空格
        while(s[index] == ' '){
            index++;
        }
        //判断小数点前的整数
        bool res = scanInt(s, index);
		//判断小数点后的数字
        if(s[index] == '.'){
            index++;
            res |= scanNumber(s, index);        //.123这种数字也符合要求
        }
       	//判断e后是否有整数
        if(s[index] == 'e' || s[index] == 'E'){
            index++;
            res &= scanInt(s, index);           //123e后面必须有整数
        }
        //去除后面的空格
        while(s[index] == ' '){
            index++;
        }

        return (index == len) && res; 
    }
};
