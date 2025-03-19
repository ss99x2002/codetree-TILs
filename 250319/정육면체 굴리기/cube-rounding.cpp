#include <iostream>

using namespace std;

int n, m; // 말판 크기
int x, y; // 정육면체 처음 위치
int k; //굴리기 횟수

int board[21][21];
int dirSet[1001]; // 움직일 방향 모아둔 것.

// 각각 굴리기 시행 후 정육면체 상단 면에 있는 숫자를 출력
// 만약 바깥으로 이동시킬 경우, 해당 시도는 무시하며, 출력도 하지 않는다.
// 방향 한번에 1칸 이동한다.
// 처음 정육면체 각 면에는 0이 쓰여있다.

int rect[6]; //정육면체를 일차원 배열처럼 생각.
// rect[1] = 바닥면
// rect[3] = 상단면

// 칸에 쓰인게 0 -> 주사위 바닥 숫자가 복사 -> 주사위 숫자는 안변함.
// 칸에 쓰인게 0아니면 -> 칸 쓰인게 정육면체 바닥에 복사 -> 칸은 0 됨

pair<int, int> moveRect(int dir, pair<int, int> cur) { //상단 값 출력 후 이동한 좌표를 retrun
    int boardValue;
    pair<int, int> nextP = {-1, -1};
    if (dir == 1) { //오
        if (cur.second + 1 < m) {
            int tmp = rect[0];
            for (int i = 0; i < 3; i++) {
                rect[i] = rect[i + 1];
            }
            rect[3] = tmp;
            boardValue = board[cur.first][cur.second + 1];
            if (boardValue == 0) {
                board[cur.first][cur.second + 1] = rect[1];
            } else {
                rect[1] = boardValue;
                board[cur.first][cur.second + 1] = 0;
            }
            nextP = {cur.first, cur.second + 1};
        }
    } else if (dir == 2) { //왼
        if (cur.second - 1 >= 0) {
            boardValue = board[cur.first][cur.second - 1];
            int tmp = rect[3];
            for (int i = 3; i >= 1; i--) {
                rect[i] = rect[i - 1];
            }
            rect[0] = tmp;
            if (boardValue == 0) {
                board[cur.first][cur.second -1] = rect[1];
            } else {
                rect[1] = boardValue;
                board[cur.first][cur.second- 1] = 0;
            }
            nextP = {cur.first, cur.second - 1};
        }
    } else if (dir == 3) { // 상
        if (cur.first - 1 >= 0) {
            int tmp = rect[5];
            rect[5] = rect[1];
            rect[1] = rect[4];
            rect[4]= rect[3];
            rect[3] = tmp;
            boardValue = board[cur.first - 1][cur.second];
            if (boardValue == 0) {
                board[cur.first - 1][cur.second] = rect[1];
            } else {
                rect[1] = boardValue;
                board[cur.first - 1][cur.second] = 0;
            }
            nextP = {cur.first - 1, cur.second};
        }
    } else if (dir == 4) { //하
        if (cur.first +1 < n) {
            int tmp = rect[5];
            rect[5]=rect[3];
            rect[3] = rect[4];
            rect[4] = rect[1];
            rect[1] = tmp;
            boardValue = board[cur.first + 1][cur.second];
            if (boardValue == 0) {
                board[cur.first + 1][cur.second] = rect[1];
            } else {
                rect[1] = boardValue;
                board[cur.first + 1][cur.second] = 0;
            }
            nextP = {cur.first + 1, cur.second};
        }
    }
    if (nextP != pair{-1, -1}) {
        cout << rect[3] << "\n";
    }
    return nextP;
}

int main() {
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> dirSet[i];
    }

    for (int i=0; i<6; i++){
        rect[i] = 0;
    }
    pair<int, int> curP = {x, y};
    pair<int, int> newP;
    for (int i = 0; i < k; i++) {
        newP = moveRect(dirSet[i], curP);
        if (newP != pair{-1, -1}) curP = newP;
    }
    return 0;
}