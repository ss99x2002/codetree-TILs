#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//불이 퍼지지 않는 영역이 최대일 때 크기 출력

int n,m;
int board[9][9];
int temp[9][9];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt = 0;
int ans = 0;
vector<pair<int,int>> wallsCandi;
// 방화벽 3개 추가 설치 시 방화벽 제외 불 퍼지지 않는 영역 크기 최댓값 출력
void restoreBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = temp[i][j];
        }
    }
}



void dfs(int x, int y){
    stack<pair<int,int>> s;
    s.push({x,y});

    while(!s.empty()){
        pair<int,int> tops = s.top();
        s.pop();
        for (int i=0; i<4; i++){
            int curX = dx[i] + tops.first;
            int curY = dy[i] + tops.second;
            if (curX < 0 || curY < 0 || curX >=n || curY >=m) continue;
            if (board[curX][curY] == 1 || board[curX][curY] == 2) continue;
            board[curX][curY] = 2;
            s.push({curX,curY});
        }
    }
}

void saveTemp(){
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            temp[i][j] = board[i][j];
        }
    }
}

void backTraking(int cnts,int startIdx){
    if (cnts == 3){
        cnt = 0;
        saveTemp();
        for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == 2){
                dfs(i,j);
            }
        }
        }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == 0 ) {
                cnt ++;
            }
        }
    }
        ans = max(ans,cnt);
        restoreBoard();
    return;
    }

    for (int i=startIdx; i<wallsCandi.size(); i++){
        auto [x,y] = wallsCandi[i];
        board[x][y] = 1;
        backTraking(cnts+1, i+1);
        board[x][y] = 0;
    }



}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    //방화벽 세개 피킹방법..
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == 0) {
                wallsCandi.push_back({i,j});
            }
        }
    }
    
    backTraking(0,0);

    cout << ans;

    return 0;
}