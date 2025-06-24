#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[4] = {1, 0, -1, 0};

vector<pair<pair<int, int>, int>> horse;
int minAns = 64;

vector<vector<vector<int>>> dirInfo = {
    {},
    {{0}, {1}, {2}, {3}},                              // 1번
    {{0, 2}, {1, 3}},                                  // 2번
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},                  // 3번
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},      // 4번
    {{0, 1, 2, 3}}                                     // 5번
};

void copyBoard(int dest[9][9], int src[9][9]) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dest[i][j] = src[i][j];
}

void color(int x, int y, const vector<int>& dirs, int board[9][9]) {
    for (int d : dirs) {
        int nx = x, ny = y;
        while (true) {
            nx += dx[d];
            ny += dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 6)
                break;
            if (board[nx][ny] == 0)
                board[nx][ny] = 7;
        }
    }
}

void dfs(int idx, int board[9][9]) {
    if (idx == horse.size()) {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == 0)
                    cnt++;
        minAns = min(minAns, cnt);
        return;
    }

    int x = horse[idx].first.first;
    int y = horse[idx].first.second;
    int type = horse[idx].second;

    for (auto& dirs : dirInfo[type]) {
        int copied[9][9];
        copyBoard(copied, board);         // 현재 board 복사
        color(x, y, dirs, copied);        // 복사본에 색칠
        dfs(idx + 1, copied);             // 복사본으로 재귀
    }
}

int main() {
    cin >> n >> m;
    int board[9][9];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (1 <= board[i][j] && board[i][j] <= 5)
                horse.push_back({{i, j}, board[i][j]});
        }

    dfs(0, board);
    cout << minAns << "\n";
    return 0;
}