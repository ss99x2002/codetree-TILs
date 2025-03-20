#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[21][21];
int maxAns = 0;

// 이동 방향 (상, 우, 하, 좌)
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1};

// 보드 이동 로직
void moveBoard(int dir) {
    vector<vector<bool>> isSum(n, vector<bool>(n, false)); // 합친 여부 체크
    if (dir == 0) { // 위로 이동
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                if (board[i][j] == 0) continue;
                int x = i;
                while (x > 0 && board[x - 1][j] == 0) { // 빈 칸이면 이동
                    board[x - 1][j] = board[x][j];
                    board[x][j] = 0;
                    x--;
                }
                if (x > 0 && board[x - 1][j] == board[x][j] && !isSum[x - 1][j]) { // 합칠 수 있는 경우
                    board[x - 1][j] *= 2;
                    board[x][j] = 0;
                    isSum[x - 1][j] = true;
                }
            }
        }
    } else if (dir == 1) { // 오른쪽 이동
        for (int i = 0; i < n; i++) {
            for (int j = n - 2; j >= 0; j--) {
                if (board[i][j] == 0) continue;
                int y = j;
                while (y < n - 1 && board[i][y + 1] == 0) { // 빈 칸이면 이동
                    board[i][y + 1] = board[i][y];
                    board[i][y] = 0;
                    y++;
                }
                if (y < n - 1 && board[i][y + 1] == board[i][y] && !isSum[i][y + 1]) { // 합칠 수 있는 경우
                    board[i][y + 1] *= 2;
                    board[i][y] = 0;
                    isSum[i][y + 1] = true;
                }
            }
        }
    } else if (dir == 2) { // 아래로 이동
        for (int j = 0; j < n; j++) {
            for (int i = n - 2; i >= 0; i--) {
                if (board[i][j] == 0) continue;
                int x = i;
                while (x < n - 1 && board[x + 1][j] == 0) { // 빈 칸이면 이동
                    board[x + 1][j] = board[x][j];
                    board[x][j] = 0;
                    x++;
                }
                if (x < n - 1 && board[x + 1][j] == board[x][j] && !isSum[x + 1][j]) { // 합칠 수 있는 경우
                    board[x + 1][j] *= 2;
                    board[x][j] = 0;
                    isSum[x + 1][j] = true;
                }
            }
        }
    } else if (dir == 3) { // 왼쪽 이동
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (board[i][j] == 0) continue;
                int y = j;
                while (y > 0 && board[i][y - 1] == 0) { // 빈 칸이면 이동
                    board[i][y - 1] = board[i][y];
                    board[i][y] = 0;
                    y--;
                }
                if (y > 0 && board[i][y - 1] == board[i][y] && !isSum[i][y - 1]) { // 합칠 수 있는 경우
                    board[i][y - 1] *= 2;
                    board[i][y] = 0;
                    isSum[i][y - 1] = true;
                }
            }
        }
    }
}

// 백트래킹으로 5번 이동하며 최대값 탐색
void backTracking(int cnt) {
    if (cnt == 5) { // 5번 이동 후 최대값 저장
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxAns = max(maxAns, board[i][j]);
            }
        }
        return;
    }

    int tempBoard[21][21]; // 현재 상태 저장
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tempBoard[i][j] = board[i][j];

    for (int dir = 0; dir < 4; dir++) {
        moveBoard(dir);
        backTracking(cnt + 1);

        // 이전 상태로 복구
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = tempBoard[i][j];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    backTracking(0);
    cout << maxAns;
    return 0;
}
