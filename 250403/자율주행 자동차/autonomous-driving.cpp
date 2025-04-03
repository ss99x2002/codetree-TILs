#include <iostream>
#include <stack>
using namespace std;

// n*m도로에 1칸크기 자율주행 자동차 있음
// 현재방향 기준으로 왼쪽 간적 없다면 좌회전해서 해당 방향 1칸 전진
// 만약 왼쪽이 인도거나 이미 방문하면 좌회전하고 1번 과정 시도
// 4방향 모두 확인했으나 전진 못할 경우 바라보는 방향 유지한 채 한칸 후진 후 1번
// 3번과정 시도하려했지만 뒷공간 인도여서 후진조차 못할 경우 작동 멈춤

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};  // 북,동,남,서로 설계

int n,m;
int x,y,d;
int board[51][51];
int visited[51][51];
int cnt =1;

pair<int,int> startCar;

void dfs(){
    visited[x][y] = 1;
    while(1){
        bool moved = false;
        for (int i=0; i<4; i++){
            d= (d+3)%4;
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >=n || ny >= m) continue;
            if (board[nx][ny] == 1 || visited[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt ++;
            moved = true;
            break;
        }
        if (!moved) { 
            int backX = x - dx[d];
            int backY = y - dy[d];
    
             if (board[backX][backY] == 1) break; // 후진 불가 시 종료
    
             x = backX;
            y = backY;
        }
    }
}


int main() {
    cin >> n >> m;
    cin >> x >> y >> d;
    // d = 북, 동, 남, 서
    // +3 하는게 좌회전 하는 것과 동일하네.. %4로 d갱신하면서 이동

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    dfs();

    cout << cnt;

    
    return 0;
}