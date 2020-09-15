class Solution {
public:
    unordered_map<int, unordered_set<int>> m;
    bool ans = true;
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if(dislikes.size() <= 2)
            return true;
        for(auto it : dislikes){
            m[it[0]].insert(it[1]);
            m[it[1]].insert(it[0]);
        }
        vector<int> color(N+1, 0);
        for(int i = 1; i <= N; i++){
            if(color[i] == 0){
                color[i] = 1;
                dfs(color, 1, i);
                if(!ans)
                    return false;
            }
        }
        return true;
    }
    void dfs(vector<int>& color, int col, int id){
        if(!ans) return;
        int nextcol = (col == 1)?2:1;
        for(auto it = m[id].begin(); it != m[id].end(); it++){
            if(color[*it] == col){
                ans = false;
            }
            else if(color[*it] == 0){
                color[*it] = nextcol;
                dfs(color, nextcol, *it);
            }
        }
    }
};
