#include <iostream>
using namespace std;

 // 경사로 높이가 1이며, 길이 L은 문제마다 다르게 주어진다.
 // 경사로는 높이차이가 1이 나는 보도블럭에 설치 가능, 낮은 칸에 설치된다. 
 // 경사로 길이는 길이 L동안 바닥에 접촉해야하며,
 // 경사로가 높인 보도블럭의 높이는 모두 같아야 한다.

 // 지나갈 수 있는 열과 행의 총 개수는?
 // 경사로의 정보가 격자판에 주어질 때. 

int n, l; //보도블럭 크기 n, 경사로 길이 l
int board[101][101];
int ans = 0;

bool checkColumn(int col){
    bool used[101] = {false};
    for (int i=0; i<n-1; i++){ 
        int cur = board[i][col];
        int next = board[i+1][col];

        if (cur==next) continue;

        if (cur+1 == next) {
            for(int j= i-l+1; j<=i; j++){
                if (j<0||board[j][col] != cur || used[j]) return false;
                used[j] = true;
            }
        } //뒤가 더 높은 경우
        else if (cur == next+1) {
            for (int j=i+1; j<i+1+l; j++){
                if (j>=n || board[j][col] != next || used[j]) return false;
                used[j] = true;
            }
        }// 앞이 더 높은 경우

        else {
            return false;
        } //높이차 2이상
      
    } 

    return true;
}

bool checkRow(int row){
    bool used[101] = {false};
    for (int i=0; i<n-1; i++){
        int curr = board[row][i];
        int next = board[row][i+1];

        if (curr == next) continue;
        if (curr +1 == next) {
            for (int j=i-l+1; j<=i; j++ ) {
                if (j<0 || board[row][j] != curr || used[j]) return false;
                used[j] = true;
            }

        } //뒤가 더 높은 경우

        else if (curr == next +1) {
            for (int j=i+1; j<i+l+1; j++){
                if (j>=n || board[row][j] != next || used[j]) return false;
                used[j] = true;
            }

        } //앞이 더 높은 경우

        else {
            return false;
        } //차이 자체가 높은 경우 => 그러면 경사로 설치도 불가능 => 도달할 수 있는 길이 아님. 
    }

    return true;
}


int main() {
    cin >> n >> l;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for (int i=0; i<n; i++){
        if(checkRow(i)) ans ++;
        if (checkColumn(i)) ans ++;
    }

    cout << ans << "\n";
}
