class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y, int xm, int ym){
        if(x < 0 || y < 0 || x > xm-1 || y > ym-1 || board[x][y] != word[index]){
            return false;
        }
        if(index == word.size()-1){
            return true;
        }
        char temp = board[x][y];
        for(int i = 0; i < 4; i++){
            int a = x + dir[i][0];
            int b = y + dir[i][1];
            board[x][y] = '-';
            if(dfs(board, word, index+1, a, b, xm, ym))
                return true;
            board[x][y] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        int xm = board.size();
        int ym = board[0].size();
        for(int i = 0; i < xm; i++){
            for(int j = 0; j < ym; j++){
                if(dfs(board, word, 0, i, j, xm, ym)){
                    return true;
                }
            }
        }
        return false;
    }
};
