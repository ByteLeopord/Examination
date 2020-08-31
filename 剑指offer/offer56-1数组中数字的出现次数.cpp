/* 
分组异或：
1. 将数组中的全部数字进行异或运算 - 因为除了两个数字外，其它的数字都出现了两次，所以最后的结果为这两个数字的异或;
2. 找到上面结果中其中一个为1的位，以这一位作为分组的依据 - 因为相同数字的这一位必定同为1或0，所以重复出现的数字必定分在同一组中;
                                                        - 其次两个只出现一次的数字这一位必定不相同(基于异或的性质)，会分在不同的组中;
3. 将上述分开的两组分别进行异或运算，得出要求的两个数字。
*/
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int mark = nums[0];
        for(auto it = nums.begin()+1; it != nums.end(); it++){
            mark ^= *it;
        }
        int div = 1;
        while(div){
            if(div & mark) break;
            div <<= 1;
        }
        int res1 = 0, res2 = 0;
        for(auto it : nums){
            if(it & div){
                res1 ^= it;
            }
            else{
                res2 ^= it;
            }
        }
        return {res1, res2};
    }
};
