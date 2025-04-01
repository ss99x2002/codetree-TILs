#include <iostream>
#include <algorithm>
using namespace std;

int n,t,p;
int task[16];
int maxSum = 0;

// 외주작업에 걸리는 시간 t, 수익 p 
// work = {idx(시작 시간),p} 담고있음. 
// time = {시작시간, 끝나는 시간} 담도록. 

vector<pair<int,int>> work;
vector<pair<int,int>> times;

void backTraking(int idx, int sum){
    if (times[idx].first > n) {
        return; 
    }
    for (int i= idx+1; i<n; i++){
        if (times[idx].second <= times[i].first && times[i].second <=n){
            backTraking(i, sum+work[i].second); 
        }
    }
    
    maxSum = max(maxSum,sum);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t >> p;
        work.push_back({i,p}); //시작 시간(이자 idx 역할도 됨.),point
        times.push_back({i, i+t}); // 시작시간, 끝나는 시간
    }

    for (int i=0; i<n; i++){
        backTraking(i,work[i].second);
    }

    cout << maxSum << "\n";
    return 0;
}

   // 내가 구현해야 하는 것
    // 어떤것이든 첫번째로 선택 가능.
    // 그 이후로는 조건이 -> 이전에 선택했던 것의 끝나는 시간 <= 선택하는 것의 시작 시간
    // 이 조건이 맞다면 backTraking 계속 진행 함.
    // 선택한 것의 index가 n에 도달했다면 -> 포인트의 합을 max인지 아닌지 판단 후 갱신 필요.