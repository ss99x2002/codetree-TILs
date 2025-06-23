
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


void moveChair(int num,int dir){
    if (num == 1) {
        int tmp = s1[0];
        if (dir == -1) {
            for (int i=1; i<8; i++){
                s1[i-1] = s1[i];
            }
           s1[7] = tmp;
        }
        else {
            int tmp = s1[7];
            for (int i=0; i<7; i++){
                s1[i+1] = s1[i];
            }
           s1[0] = tmp;
        }
    }

    else if (num == 2) {
        int tmp = s2[0];
        if (dir == -1) {
            for (int i=1; i<8; i++){
                s2[i-1] = s2[i];
            }
           s2[7] = tmp;
        }
        else {
            int tmp = s2[7];
            for (int i=0; i<7; i++){
                s2[i+1] = s2[i];
            }
           s2[0] = tmp;
        }

    }

    else if (num == 3) {
         int tmp = s3[0];
        if (dir == -1) {
            for (int i=1; i<8; i++){
                s3[i-1] = s3[i];
            }
           s3[7] = tmp;
        }
        else {
            int tmp = s3[7];
            for (int i=0; i<7; i++){
                s3[i+1] = s3[i];
            }
           s3[0] = tmp;
        }

    }
    else if (num == 4){
        int tmp = s4[0];
        if (dir == -1) {
            for (int i=1; i<8; i++){
                s4[i-1] = s4[i];
            }
           s4[7] = tmp;
        }
        else {
            int tmp = s4[7];
            for (int i=0; i<7; i++){
                s4[i+1] = s4[i];
            }
           s4[0] = tmp;
        }

    }
}

void checkMove(int num, int dir){

if (used[num] != 0) return; // 이미 처리된 의자면 무시
    
    used[num] = dir;

    if (num == 1) {
        if (s1[2] != s2[6]) checkMove(2, -dir);
    }
    else if (num == 2) {
        if (s1[2] != s2[6]) checkMove(1, -dir);
        if (s2[2] != s3[6]) checkMove(3, -dir);
    }
    else if (num == 3) {
        if (s3[6] != s2[2]) checkMove(2, -dir);
        if (s3[2] != s4[6]) checkMove(4, -dir);
    }
    else if (num == 4) {
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

    for(int i=0; i<k; i++){
        cin >> changeNum >> d;
        initUsed();
        checkMove(changeNum,d);
        for (int i=1; i<=4; i++){
        if (used[i] != 0){
            moveChair(i,used[i]);
        }
    }
}

    cout << (s1[0] + (2*s2[0]) + (4*s3[0]) + (8*s4[0]));
    return 0;
}