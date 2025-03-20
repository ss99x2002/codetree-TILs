#include <iostream>
using namespace std;

int n;
int board[21][21];
int tmp[21][21];
bool isSum[21][21]; // 합쳐진 여부 확인 (연쇄 합침 방지)
int maxAns = 0;

// 상 우 하 좌
int dx[4] = {-1,0,1,0}; 
int dy[4] = {0,1,0,-1};

void copyTmp() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = board[i][j];
        }
    }
}

void initIsSum() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            isSum[i][j] = false;
        }
    }
}

void returnBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = tmp[i][j];
        }
    }
}

// 보드 이동 로직
void moveBoard(int dir) {
    dir = dir % 4;
    initIsSum();

    if (dir == 0) { // 위로 이동
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                if (board[i][j] == 0) continue;
                int x = i;
                
                while (x > 0 && board[x-1][j] == 0) {
                    swap(board[x][j], board[x-1][j]);
                    x--;
                }

                if (x > 0 && board[x-1][j] == board[x][j] && !isSum[x-1][j]) {
                    board[x-1][j] *= 2;
                    board[x][j] = 0;
                    isSum[x-1][j] = true;
                }
            }
        }
    } else if (dir == 1) { // 오른쪽 이동
        for (int i = 0; i < n; i++) {
            for (int j = n - 2; j >= 0; j--) {
                if (board[i][j] == 0) continue;
                int y = j;

                while (y < n - 1 && board[i][y+1] == 0) {
                    swap(board[i][y], board[i][y+1]);
                    y++;
                }

                if (y < n - 1 && board[i][y+1] == board[i][y] && !isSum[i][y+1]) {
                    board[i][y+1] *= 2;
                    board[i][y] = 0;
                    isSum[i][y+1] = true;
                }
            }
        }
    } else if (dir == 2) { // 아래로 이동
        for (int j = 0; j < n; j++) {
            for (int i = n - 2; i >= 0; i--) {
                if (board[i][j] == 0) continue;
                int x = i;

                while (x < n - 1 && board[x+1][j] == 0) {
                    swap(board[x][j], board[x+1][j]);
                    x++;
                }

                if (x < n - 1 && board[x+1][j] == board[x][j] && !isSum[x+1][j]) {
                    board[x+1][j] *= 2;
                    board[x][j] = 0;
                    isSum[x+1][j] = true;
                }
            }
        }
    } else if (dir == 3) { // 왼쪽 이동
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (board[i][j] == 0) continue;
                int y = j;

                while (y > 0 && board[i][y-1] == 0) {
                    swap(board[i][y], board[i][y-1]);
                    y--;
                }

                if (y > 0 && board[i][y-1] == board[i][y] && !isSum[i][y-1]) {
                    board[i][y-1] *= 2;
                    board[i][y] = 0;
                    isSum[i][y-1] = true;
                }
            }
        }
    }
}

void backTracking(int cnt) {
    if (cnt == 5) { // 5번 움직인 후 최댓값 찾기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxAns = max(maxAns, board[i][j]);
            }
        }
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        copyTmp();
        moveBoard(dir);
        backTracking(cnt + 1);
        returnBoard();
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
