class Solution {
public:
    int maxarea = 0;

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r<0|| c<0|| r>= grid.size()|| c>= grid[0].size() || grid[r][c] == 0){
            return 0;
        }

        grid[r][c] = 0;

        return 1 + dfs(grid, r+1,c) + dfs(grid, r-1, c)+ dfs(grid, r, c+1) +dfs(grid, r, c-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    maxarea = max(maxarea, dfs(grid, i, j));
                }
            }
        }

        return maxarea;

    }
};
