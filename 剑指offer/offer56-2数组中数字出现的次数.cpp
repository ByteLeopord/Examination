/*
将nums中的所有数字的每一位相加
如果该位相加后可以被3整除说明 要求数字的该位是0 否则为1
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitarr(32, 0);
        
        for(auto it : nums){
            for(int i = 0; i < 32; i++){
                int mask = (1 << i);
                if((it & mask) == mask){
                    bitarr[i] += 1;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++){
            if(bitarr[i] % 3 != 0){
                res += (1 << i);
            }
        }
        return res;
    }
};
