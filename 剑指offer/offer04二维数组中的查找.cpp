class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int x = col-1, y = 0;
        while(x >= 0 && y < row){
            if(matrix[y][x] > target){
                x--;
            }
            else if(matrix[y][x] < target){
                y++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
