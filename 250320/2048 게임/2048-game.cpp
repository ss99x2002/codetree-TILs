#include <iostream>
using namespace std;

int n;
int board[21][21];
int tmp[21][21];
bool isSum[21][21]; //이미 중력으로 합쳐진 부분인지 아닌지를 저장하는 board (연쇄 막기 위함)
int maxAns = 0;

int dx[4] = {-1,0,1,0}; // 상 우 하 좌
int dy[4] = {0,1,0,-1};

// 두 숫자 끼리 만나면 합쳐진다. 2+2 = 4, 4+4 = 8.. 2의 제곱 식 
// 한번의 중력 작용으로 이미 합쳐진 숫자는 연쇄적으로 합쳐지지 않는다. 
// 세개이상의 숫자가 중력 방향으로 놓여 있으면, 가까운 숫자 2개씩만 합쳐진다. -> 가까운 순서대로 한쌍 씩 짝 이뤄서 합쳐짐

// 출력 : 5번 움직인 이후 격자판에서 가장 큰 최댓값을 구하는 프로그램
// 상,하,좌,우로 이동하면서 격자판을 기울일 수 있다. 

void copyTmp(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            tmp[i][j] = board[i][j];
        }
    }
}

void initIsSum(){
     for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            isSum[i][j] = false;
        }
    }
}

void returnBoard(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

void moveBoard(int dir){
    dir = dir%4;
    initIsSum();
    if (dir == 0){
        for (int j=0; j<n; j++){
            for (int i=1; i<n; i++){
                if (board[i][j] == 0) continue;
                int x = i;
                while(x > 0 && board[x-1][j] == 0){
                    swap(board[x][j], board[x-1][j]);
                    x--;
                }

                if (x > 0 && board[x-1][j] == board[x][j] && !isSum[x-1][j]){
                    board[x-1][j] = board[x-1][j]*2;
                    board[x][j] = 0;
                    isSum[x-1][j] = true;
                }
                // 최대한 블록을 밀어 이동
                // 같은 숫자 합치기
                // 다시 한번 블럭 이동 
            }
        }
    } else if (dir ==1){
        for (int i=0; i<n; i++){
            for (int j=n-2; j>=0; j--){
                if (board[i][j] == 0) continue;
                int y = j;
                while(y<n-1 && board[i][y+1]==0){
                    swap(board[i][y], board[i][y+1]);
                    y++;
                }
                if (y<n-1 && board[i][y] == board[i][y+1] && !isSum[i][y+1]){
                    board[i][y+1] = board[i][y+1]*2;
                    board[i][y] = 0;
                    isSum[i][y+1]= true;
                }
            }
        }

    } else if (dir == 2){
        for (int j=0; j<n; j++){
            for (int i=n-2; i>=0; i--){
                if (board[i][j] == 0) continue;
                int x = i;
                while(x<n-1 && board[x+1][j] ==0){
                    swap(board[x][j], board[x+1][j]);
                    x++;
                }
                if (x<n-1 && board[x][j] == board[x+1][j] && !isSum[x+1][j]){
                    board[x+1][j] = board[x+1][j]*2;
                    board[x][j] = 0;
                    isSum[x+1][j] = true;
                }
            }
        }
       
    } else if (dir == 3){
         for (int i=0; i<n; i++){
            for (int j=1; j<n; j++){
                if (board[i][j] == 0) continue;
                int y = j;
                while(y>0 && board[i][y-1]==0){
                    swap(board[i][y], board[i][y-1]);
                    y--;
                }
                if (y>0 && board[i][y] == board[i][y-1] && !isSum[i][y-1]){
                    board[i][y-1] = board[i][y-1]*2;
                    board[i][y] = 0;
                    isSum[i][y-1]= true;
                }
            }
        }


    }
}

void backTraking(int cnt){
    if (cnt == 5){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                maxAns = max(maxAns, board[i][j]);
            }
        }
        return;
    }
    for (int dir=0; dir<4; dir++){
        copyTmp();
        moveBoard(dir);
        backTraking(cnt+1);
        returnBoard();
    }
}


int main() {
   
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    backTraking(0);
    cout << maxAns;
    return 0;
}
