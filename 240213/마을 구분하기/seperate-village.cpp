#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int board[25][25];
bool visit[25][25];

int dx[4] = {1,0,-1,0}; // 아래, 위
int dy[4] = { 0,1,0,-1 }; // 오른, 왼

int n;
vector<int> people;
int cnt = 0;
int ans = 0;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[nx][ny] == 0 || visit[nx][ny] == 1) continue;
        visit[nx][ny] = 1;
        cnt++;
        dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 0 && visit[i][j] == 0) {
                visit[i][j] = 1;
                dfs(i, j);
                people.push_back(cnt+1);
                cnt = 0;
                ans++;
            }
        }
    }

    sort(people.begin(), people.end());

    cout << ans << "\n";
    for (int i = 0; i < people.size(); i++) {
        cout << people[i] << "\n";
    }
}