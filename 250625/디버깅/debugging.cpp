#include <iostream>
using namespace std;

int n, m, h;
int a, b;
int board[32][12];
int ans = -1;
bool done = false;

bool check() {
    for (int start = 1; start <= n; start++) {
        int col = start;
        for (int row = 1; row <= h; row++) {
            if (board[row][col] == 1) col++;
            else if (board[row][col] == 2) col--;
        }
        if (col != start) return false;
    }
    return true;
}

void initBoard() {
    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 12; j++)
            board[i][j] = 0;
}

void dfs(int row, int col, int cnt, int max_cnt) {
    if (cnt > max_cnt || done) return;

    if (check()) {
        ans = cnt;
        done = true;
        return;
    }

    for (int i = row; i <= h; i++) {
        for (int j = (i == row ? col : 1); j < n; j++) {
            if (board[i][j] != 0 || board[i][j + 1] != 0) continue;

            // 가로선 두 개 연속 연결 방지
            board[i][j] = 1;
            board[i][j + 1] = 2;

            dfs(i, j + 1, cnt + 1, max_cnt);

            board[i][j] = 0;
            board[i][j + 1] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> h;
    initBoard();

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        board[a][b] = 1;
        board[a][b + 1] = 2;
    }

    if (check()) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 1; i <= 3; i++) {
        dfs(1, 1, 0, i);
        if (done) break;
    }

    cout << ans << "\n";
    return 0;
}