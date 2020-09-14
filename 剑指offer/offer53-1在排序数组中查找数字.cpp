/*
1.初始化： 左边界 i = 0i=0 ，右边界 j = len(nums) - 1j=len(nums)−1 。
2.循环二分： 当闭区间 [i, j][i,j] 无元素时跳出；
    计算中点 m = (i + j) / 2m=(i+j)/2 （向下取整）；
    若 nums[m] < targetnums[m]<target ，则 targettarget 在闭区间 [m + 1, j][m+1,j] 中，因此执行 i = m + 1i=m+1；
    若 nums[m] > targetnums[m]>target ，则 targettarget 在闭区间 [i, m - 1][i,m−1] 中，因此执行 j = m - 1j=m−1；
    若 nums[m] = targetnums[m]=target ，则右边界 rightright 在闭区间 [m+1, j][m+1,j] 中；左边界 leftleft 在闭区间 [i, m-1][i,m−1] 中。因此分为以下两种情况：
    *若查找 右边界 rightright ，则执行 i = m + 1（跳出时 i 指向右边界）
    *若查找 左边界 leftleft ，则执行 j = m - 1（跳出时 j 指向左边界）
3.返回值： 应用两次二分，分别查找 rightright 和 leftleft ，最终返回 right - left - 1right−left−1 即可。
*/
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
