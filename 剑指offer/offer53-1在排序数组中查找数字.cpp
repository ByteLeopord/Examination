class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int l = 0, r = nums.size()-1;
        int mark1 = -1, mark2 = -1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] <= target){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        mark2 = l;
        l = 0;
        r = nums.size()-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] >= target){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        mark1 = r;
        
        return mark2-mark1-1;
    }
};
