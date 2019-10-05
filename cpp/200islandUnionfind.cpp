//Union find 12ms
class UnionFind {
public:
   // vector<int> father;
    int*  father;
    UnionFind(int num) {
        father = new int[num];
        for (int i = 0; i < num; i ++) {
            father[i] = i;
        }
    }

    int Find(int n) {
        if (father[n] == n) return n;
        father[n] = Find(father[n]);
        return father[n];
    }

    /*
    while(father[n] != n)
        n = father[n];
    return n;
    */

    void Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        father[fb] = fa;
    }
};

int encode(int i, int j, int m) {
    return i * m + j;
}

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int n = grid.size(), m = grid[0].size();

        UnionFind UF(n * m);

        // 合并
        int dx[] = {1,  0}, dy[] = {0, -1};
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '1') {
                    for (int d = 0; d < 2; d ++) {
                        int x = dx[d] + i, y = dy[d] + j;
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1') {
                            UF.Union(encode(i, j, m), encode(x, y, m));
                        }
                    }
                }
            }
        }

        // 查找父节点是否为自己
        int res = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '1' && UF.Find(encode(i, j, m))== encode(i, j, m)) {
                    res ++;
                }
            }
        }
        return res;
    }
};

//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        queue<pair<int,int> > q;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(q.size() == 0 && grid[i][j] == '1'){
                    q.push({i,j});
                    grid[i][j] = '2';
                    ans++;    
                }
                while(!q.empty()){
                    pair<int,int> tmp = q.front();
                    q.pop();
                    int l = tmp.first;
                    int r = tmp.second;
                    if(l!=0 && grid[l-1][r] == '1'){
                        q.push({l-1,r});
                        grid[l-1][r] = '2';
                    }
                    if(l!=row-1 && grid[l+1][r] == '1'){
                        q.push({l+1,r});
                        grid[l+1][r] = '2';
                    }
                    if(r!=0 && grid[l][r-1] == '1'){
                        q.push({l,r-1});
                        grid[l][r-1] = '2';
                    }
                    if(r!=col-1 && grid[l][r+1] == '1'){
                        q.push({l,r+1});
                        grid[l][r+1] = '2';
                    }
                    
                }
            }
        }
        return ans;
    }
};


//24ms DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        stack<pair<int,int> > q;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(q.size() == 0 && grid[i][j] == '1'){
                    q.push({i,j});
                    grid[i][j] = '2';
                    ans++;    
                   // cout<<"HHA"<<endl;
                }
                //cout<<"ij"<<i<<" "<<j<<endl;
                while(!q.empty()){
                    pair<int,int> tmp = q.top();
                    q.pop();
                    int l = tmp.first;
                    int r = tmp.second;
                    //cout<<l<<" "<<r<<endl;
                    if(l!=0 && grid[l-1][r] == '1'){
                        q.push({l-1,r});
                        grid[l-1][r] = '2';
                    }
                    if(l!=row-1 && grid[l+1][r] == '1'){
                        q.push({l+1,r});
                        grid[l+1][r] = '2';
                    }
                    if(r!=0 && grid[l][r-1] == '1'){
                        q.push({l,r-1});
                        grid[l][r-1] = '2';
                    }
                    if(r!=col-1 && grid[l][r+1] == '1'){
                        q.push({l,r+1});
                        grid[l][r+1] = '2';
                    }
                    
                }
            }
        }
        return ans;
    }
};



