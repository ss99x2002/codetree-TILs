#include <iostream>

using namespace std;

int n, m;
char board[11][11];
int dx[4] = {-1, 0, 1, 0}; // 상,우,하,좌
int dy[4] = {0, 1, 0, -1};
int ans = -1;
int ansMin = 11;

// . = 빈칸, # = 장애물, B = 블루 사탕,
// R = 레드 사탕, O = 출구

// 출력 : 빨간 사탕을 꺼내기 위해 기울여야하는 최소 횟수
// 만약 10번이내로 빨간사탕 빼내는거 불가능하다면 -1 출력

// 빼낼때 조건
// 1. 파란색이 밖으로 나오면 안됨
// 2. 빨-파 동시에 나오면 안됨

pair<int, int> red;
pair<int, int> blue;
bool isRedExit = false;
bool isBlueExit = false;


pair<int, int> moveBall(pair<int, int> ball, pair<int, int> other, int dir, bool &isExit) {
    while (true) {
        int nx = ball.first + dx[dir];
        int ny = ball.second + dy[dir];
        if (board[nx][ny] == '#') return {ball.first, ball.second};
        if (board[nx][ny] == 'O') {
            isExit = true;
            return {nx, ny};
        }
        if (nx == other.first && ny == other.second) return {ball.first, ball.second};
        ball = {nx, ny};
    }
}

bool isFirstRed(int dir) {
    dir = dir%4;
    if (dir == 0) { //상
        return red.first < blue.first;
    } else if (dir == 1) { //우
        return red.second > blue.second;
    } else if (dir == 2) { // 하
        return red.first > blue.first;
    } else if (dir == 3) { //좌
        return red.second < blue.second;
    }

}

void moveCandy(int dir) {
    if (isFirstRed(dir)) {
        red = moveBall(red, blue, dir, isRedExit);
        blue = moveBall(blue, red, dir, isBlueExit);
    } else {
        blue = moveBall(blue, red, dir, isBlueExit);
        red = moveBall(red, blue, dir, isRedExit);
    }
}

void backTraking(int cnt) {
    if (cnt > 10) {
        return;
    }

    if (isBlueExit) return;
    if (isRedExit) {
        ansMin = min(ansMin, cnt);
        ans = ansMin;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        pair<int, int> temp_red = red;
        pair<int, int> temp_blue = blue;
        bool tempRedExit = isRedExit;
        bool tempBlueExit = isBlueExit;
        moveCandy(dir);
        if (!isBlueExit) backTraking(cnt + 1);
        red = temp_red;
        blue = temp_blue;
        isRedExit = tempRedExit;
        isBlueExit = tempBlueExit;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'B') blue = pair{i, j};
            else if (board[i][j] == 'R') red = pair{i, j};
        }
    }
    backTraking(0);
    cout << ans;
    return 0;
}