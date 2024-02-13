#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int n, m;
int root;
int board[101][101];
bool visit[101][101];

void dfs(int x, int y) {
    int dx[2] = { 1,0 }; //오른쪽 이동
    int dy[2] = { 0,1 };  // 아래로 이동
    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == 0 || visit[nx][ny] == 1) continue;
        visit[nx][ny] = 1;
        dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> root;
            board[i][j] = root;
        }
    }
    visit[0][0] = 1;
    dfs(0, 0);

    cout << visit[n - 1][m - 1] << "\n";
}