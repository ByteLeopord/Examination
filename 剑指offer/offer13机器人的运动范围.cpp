class Solution {
public:
    
    int getSum(int a){
        int res = 0;
        while(a > 0){
            res += a%10;
            a /= 10;
        }
        return res;
    }
    int movingCount(int m, int n, int k) {
        int result = 1;        
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0,0});
        flag[0][0] = true;
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();

            for(int i = 0; i < 2; i++){
                int x = temp.first + dir[i][0];
                int y = temp.second+ dir[i][1];
                if(x >= 0 && x < m && y >= 0 && y < n && !flag[x][y] && getSum(x)+getSum(y) <= k){
                    q.push({x, y});
                    flag[x][y] = true;
                    result++;
                }
            }
        }
        return result;
    }
};
