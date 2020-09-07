class Solution {
public:
    static bool cmp(int& a, int& b){
        string x = to_string(a) + to_string(b);
        string y = to_string(b) + to_string(a);
        return x < y;
    }
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        for(auto it : nums){
            res += to_string(it);
        }
        return res;
    }
};
