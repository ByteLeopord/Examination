class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        int up = 0, left = 0;
        int down = matrix.size()-1;
        int right = matrix[0].size()-1;
        while(up <= down && left <= right){
            for(int i = left; i <= right; i++){
                res.push_back(matrix[up][i]);
            }
            up++;
            if(up > down) break;
            for(int i = up; i <= down; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(left > right) break;
            for(int i = right; i >= left; i--){
                res.push_back(matrix[down][i]);
            }
            down--;
            if(up > down) break;
            for(int i = down; i >= up; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
