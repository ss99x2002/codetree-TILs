#include <iostream>
#include <queue>
using namespace std;

int board[101][101];
bool visited[101][101];

int dx[4] = {0,1,0,-1}; // 아래, 위 
int dy[4] = {1,0,-1,0}; // 오른, 왼

int main() {
    int n, m;
    cin >> n >> m;

    queue<pair<int,int>> q;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    visited[0][0] = 1;
    q.push({0,0});

    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        for (int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx >= n || nx < 0 || ny>=m || ny < 0 ) continue;
            if (visited[nx][ny] == 1 || board[nx][ny]!=1) continue;
            q.push({nx,ny});
            visited[nx][ny]=1;
        }
    }

    cout << visited[n-1][m-1];

    return 0;
}