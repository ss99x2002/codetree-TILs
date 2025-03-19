#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char board[11][11];
int dx[4] = {-1, 0, 1, 0}; // 상, 우, 하, 좌
int dy[4] = {0, 1, 0, -1};
int ans = -1;
int ansMin = 11;

pair<int, int> red;
pair<int, int> blue;
pair<int, int> exits;

bool isBlueExit = false;
bool isRedExit = false;

// 빨간 공이 먼저 이동해야 하는지 확인
bool isFirstRed(int dir) {
    if (dir == 0) return red.first < blue.first; // 위쪽 이동 시, 더 위에 있는 공이 먼저
    if (dir == 1) return red.second > blue.second; // 오른쪽 이동 시, 더 오른쪽에 있는 공이 먼저
    if (dir == 2) return red.first > blue.first; // 아래쪽 이동 시, 더 아래쪽에 있는 공이 먼저
    if (dir == 3) return red.second < blue.second; // 왼쪽 이동 시, 더 왼쪽에 있는 공이 먼저
    return false;
}

// 공을 이동하는 함수
pair<int, int> moveBall(pair<int, int> ball, pair<int, int> other, int dir, bool& isExit) {
    while (true) {
        int nx = ball.first + dx[dir];
        int ny = ball.second + dy[dir];

        if (board[nx][ny] == '#') break; // 벽이면 멈춤
        if (board[nx][ny] == 'O') { // 구멍에 빠짐
            isExit = true;
            return {nx, ny};
        }
        if (nx == other.first && ny == other.second) break; // 다른 공이 있으면 멈춤

        ball = {nx, ny}; // 이동
    }
    return ball;
}

// 빨간 공과 파란 공을 이동시키는 함수
void moveCandy(int dir) {
    bool firstRed = isFirstRed(dir);

    if (firstRed) {
        red = moveBall(red, blue, dir, isRedExit);
        blue = moveBall(blue, red, dir, isBlueExit);
    } else {
        blue = moveBall(blue, red, dir, isBlueExit);
        red = moveBall(red, blue, dir, isRedExit);
    }
}

// 백트래킹 함수
void backTraking(int cnt) {
    if (cnt >= 10) {
        if (ansMin == 11) ans = -1; // 답이 갱신되지 않았으면 -1
        return;
    }
    if (isBlueExit) return;
    if (isRedExit) {
        ansMin = min(ansMin, cnt);
        ans = ansMin;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        pair<int, int> tempRed = red;
        pair<int, int> tempBlue = blue;
        bool tempIsRedExit = isRedExit;
        bool tempIsBlueExit = isBlueExit;

        moveCandy(dir);

        if (!isBlueExit) backTraking(cnt + 1);

        // 상태 복원
        red = tempRed;
        blue = tempBlue;
        isRedExit = tempIsRedExit;
        isBlueExit = tempIsBlueExit;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'B') blue = {i, j};
            else if (board[i][j] == 'R') red = {i, j};
            else if (board[i][j] == 'O') exits = {i, j};
        }
    }
    backTraking(0);
    cout << ans;
    return 0;
}