class Solution {
public:
    int add(int a, int b) {
        unsigned int c;
        do{
            c = (unsigned int)(a&b)<<1;
            a = a ^ b;
            b = c;
        }while(c != 0);
        return a;
    }
};
