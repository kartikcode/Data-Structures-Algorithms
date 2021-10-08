class Solution {
public:
    int res = 0;
    void dfs(vector<vector<int>> grid, int x, int y, int zeros){
        if(x == grid.size() || y == grid[0].size() || x < 0 || y < 0 || grid[x][y] <= -1)
            return;
        if(grid[x][y] == 2){
           if(zeros == -1)
                res++;
            return; 
        }
        grid[x][y] = -2;
        dfs(grid, x+1, y, zeros-1);
        dfs(grid, x-1, y, zeros-1);
        dfs(grid, x, y+1, zeros-1);
        dfs(grid, x, y-1, zeros-1);
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zeros = 0;
        pair<int, int> start;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    zeros++;
                }
                else if(grid[i][j] == 1){
                    start = make_pair(i, j);
                }
            }
        }
        dfs(grid, start.first, start.second, zeros);
        return res;
    }
};
