#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 북부 N, 남부 S

// n번째 의자가 회전하기 전 인접한 의자(n-1, n+1)에 있던 의자에서
// 제일 가깝게 마주치는 두명의 사람의 출신 지역이 다르다면 n번쨰 의자 회전할 때
// 인접한 의자 또한 반대방향으로 회전하게 된다.

// 회전요청에 따라 의자 회전시킨 후 모든 회전이 끝날때까지 기다린다.
// 이 과정에서 한번 회전한 의자는 다시 회전 x


// 각 의자의 12시 방향에 앉아있던 남쪽 지방 사람의 착석 여부 알아내기


int s1[8]; // 0: 북쪽지방, 1:남쪽지방 의미.
int s2[8];
int s3[8];
int s4[8];
string s;
int k;
int changeNum;
int d; // 1: 시계방향, -1: 반시계방향
int used[5] = {0};


void moveChair(int arr[8],int dir){
    int tmp[8];
    
    if (dir == 1) {
        for (int i=0; i<8; i++){
            tmp[(i+1)%8] = arr[i];
        }
    } //시계 방향
    else {
        for (int i=0; i<8; i++){
            tmp[i] = arr[(i+1)%8];
        }
    } //반시계 방향

    for (int i=0; i<8; i++){
        arr[i] = tmp[i];
    }
    
}

void checkMove(int num, int dir) {
    if (used[num]) return;
    used[num] = dir;

    if (num == 1) {
        if (s1[2] != s2[6]) checkMove(2, -dir);
    } else if (num == 2) {
        if (s1[2] != s2[6]) checkMove(1, -dir);
        if (s2[2] != s3[6]) checkMove(3, -dir);
    } else if (num == 3) {
        if (s3[6] != s2[2]) checkMove(2, -dir);  // ✅ 이 줄 수정됨
        if (s3[2] != s4[6]) checkMove(4, -dir);
    } else if (num == 4) {
        if (s4[6] != s3[2]) checkMove(3, -dir);
    }
}

void initUsed(){
    for (int i=1; i<=4; i++){
        used[i] = 0;
    }
}


int main() {
    cin >> s;
for (int i = 0; i < 8; i++) s1[i] = s[i] - '0';

cin >> s;
for (int i = 0; i < 8; i++) s2[i] = s[i] - '0';

cin >> s;
for (int i = 0; i < 8; i++) s3[i] = s[i] - '0';

cin >> s;
for (int i = 0; i < 8; i++) s4[i] = s[i] - '0';
    cin >> k;

 for (int i = 0; i < k; i++) {
        int changeNum, d;
        cin >> changeNum >> d;

        initUsed();
        checkMove(changeNum, d);

       if (used[1]) moveChair(s1, used[1]); //used[i]가 0만 아니면 조건문 통과함 따라서 -1일때도 moveChiar가능
       if (used[2]) moveChair(s2, used[2]);
       if (used[3]) moveChair(s3, used[3]);
       if (used[4]) moveChair(s4, used[4]);
    }

    int result = s1[0] + 2 * s2[0] + 4 * s3[0] + 8 * s4[0];
    cout << result << endl;
    return 0;
}