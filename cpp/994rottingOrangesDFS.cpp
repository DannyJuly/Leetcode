class Solution {
public:
    
    struct S {
        int x;
        int y;
        int time;
    };

    int orangesRotting(vector<vector<int>>& grid) {
        queue<S> st;
        int rows = grid.size(), cols = grid[0].size();
        if(rows == 0 || cols == 0) return 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    st.push({i, j, 0});
                }
            }
        }
        int t = 0;
        while (!st.empty()) {
            S s = st.front();

            int x = s.x;
            int y = s.y;
            t = s.time;
            st.pop();

            if(x-1>=0 && grid[x-1][y] == 1) {
                st.push({x-1, y, t+1});
                grid[x-1][y] = 2;
            }
            if(x+1<rows && grid[x+1][y] == 1) {
                st.push({x+1, y, t+1});
                grid[x+1][y] = 2;
            }
            if(y-1>=0 && grid[x][y-1] == 1) {
                st.push({x, y-1, t+1});
                grid[x][y-1] = 2;
            }
            if(y+1<cols && grid[x][y+1] == 1) {
                st.push({x, y+1, t+1});
                grid[x][y+1] = 2;
            }
        }

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return t;
    }
};

