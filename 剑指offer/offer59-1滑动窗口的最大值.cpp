class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            if(!dq.empty() && dq.front() < i-k+1){
                dq.pop_front();
            }
            dq.push_back(i);
            if(i >= k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
