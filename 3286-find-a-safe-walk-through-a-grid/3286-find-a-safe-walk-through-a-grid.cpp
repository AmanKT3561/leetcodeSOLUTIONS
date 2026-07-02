class Solution {
    bool safe(int i, int j, int m, int n, vector<vector<int>>& visited) {
        if(i<0 || j<0 || i>=m || j>= n || visited[i][j] == 1) return false;
        return true;
    }
    bool walk(int x, int y, vector<vector<int>>& grid, int health, int m, int n, 
    vector<vector<int>>& visited, vector<vector<vector<int>>> &dp) {
        if(health <= 0) return false;
        if(x==m-1 && y == n-1) {
            if(health >= 1) return true;
            else return false;
        }
        if (dp[x][y][health] != -1) {
            return dp[x][y][health];
        }
        visited[x][y] = 1;
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int newx = x+delx[i];
            int newy = y+dely[i];
            if(safe(newx, newy, m, n, visited)) {
                int nh = health;
                if(grid[newx][newy] == 1) nh--;
                if(walk(newx, newy, grid, nh, m, n, visited, dp)) 
                    return dp[x][y][health] = true;
            }
        }
        visited[x][y] = 0;
        return dp[x][y][health] = false;
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if(grid[0][0] == 1) health--;
        int m = grid.size(), n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>
        (n, vector<int>(health + 1, -1)));  
        vector<vector<int>> visited(m, vector<int> (n, 0));
        return walk(0, 0, grid, health, m, n, visited, dp);
    }
};