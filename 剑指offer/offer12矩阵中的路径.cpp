class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y, int xm, int ym){
        if(x < 0 || y < 0 || x > xm-1 || y > ym-1 || board[x][y] != word[index]){
            return false;
        }
        if(index == word.size()-1){
            return true;
        }
        char temp = board[x][y];
        board[x][y] = '-';
        bool res = dfs(board, word, index+1, x+1, y, xm, ym) || dfs(board, word, index+1, x-1, y, xm, ym) || dfs(board, word, index+1, x, y+1, xm, ym) || dfs(board, word, index+1, x, y-1, xm, ym);
        board[x][y] = temp;

        return res;
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
