#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int> > maze;
vector<vector<int> > path_temp;
vector<vector<int> > path_best;

void mazeTrack(int i, int j){
    maze[i][j] = 1;
    path_temp.push_back({i,j});
    
    if(i == N-1 && j == M-1)
        if(path_best.empty() || path_temp.size() < path_best.size())
            path_best = path_temp;
    
    if((i - 1) >= 0 && maze[i-1][j] == 0) //up
        mazeTrack(i-1,j);
    if(i + 1 <= N-1 && maze[i+1][j] == 0)//down
        mazeTrack(i+1,j);
    if(j - 1 >= 0 && maze[i][j-1] == 0)//left
        mazeTrack(i,j-1);
    if(j + 1 <= M-1 && maze[i][j+1] == 0)//right
        mazeTrack(i,j+1);
    
    maze[i][j] = 0;
    path_temp.pop_back();

}

int main(){
    while (cin >> N >> M)
    {
        maze = vector<vector<int>>(N, vector<int>(M, 0));
        path_temp.clear();
        path_best.clear();
        for (auto &i : maze)
            for (auto &j : i)
                cin >> j;
        mazeTrack(0, 0);//回溯寻找迷宫最短通路
        for (auto i : path_best)
            cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
    }
    return 0;
}











