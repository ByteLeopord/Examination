class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int gui = 0;
        bool firstcard = false;
        for(int i = 0; i < 5; i++){
            if(nums[i] == 0){
                gui++;
                continue;
            }
            //找到第一张非王牌的数字牌 跳过
            if(!firstcard && nums[i] != 0){
                firstcard = true;
                continue;
            }
            //非王牌相等 不可能成顺子
            if(nums[i] == nums[i-1] && nums[i] != 0) 
                return false;
            //使用一张王牌 代替一张牌
            if((nums[i]-nums[i-1] == 2) && (gui > 0)){
                gui--;
            }
            //使用两张王牌 代替两张牌
            else if((nums[i]-nums[i-1] == 3) && (gui > 1)){
                gui -= 2;
            }
            //前后两张牌是顺子
            else if(nums[i] - nums[i-1] == 1){

            }
            else{
                return false;
            }
        }
        return true;
    }
};
