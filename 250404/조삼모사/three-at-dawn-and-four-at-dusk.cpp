#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// 아침에 하는 일과 저녁의 하는 일의
// 업무강도 차이의 최솟값 구하기

int n;
int works[21][21];
vector<int> days;
vector<int> nights;
vector<pair<int,int>> daysPair;
int ans = 1e9;
int minAns = 0;

int getWorkLoad(const vector<int>& group) {
    int sum = 0;
    for (int i = 0; i < group.size(); i++) {
        for (int j = i + 1; j < group.size(); j++) {
            int a = group[i];
            int b = group[j];
            sum += works[a][b] + works[b][a];
        }
    }
    return sum;
}

void findNights(){
    for(int i=0; i<n; i++){
        bool isDays = false;
        for (int j=0; j<days.size(); j++){
            if (days[j] == i)  isDays = true;
        }
        if (!isDays) nights.push_back(i);
    }
}

void restoreNights(){
    while(!nights.empty()){
        nights.pop_back();
    }
}

void backTraking(int cnt,int startIdx){
    if (cnt == (n/2)){
        findNights(); 
        int nightPairMin = getWorkLoad(nights);
        int daysPairMin = getWorkLoad(days);
        minAns = abs(nightPairMin-daysPairMin);
        ans = min(ans, minAns);
        restoreNights();
        return;
    }

    for (int i=startIdx; i<n; i++){
        days.push_back(i); //낮에 할 일 목록
        backTraking(cnt+1, i+1);
        days.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> works[i][j];
        }
    }

    backTraking(0,0);
    // 필요한 프로세스
    // 1. n개의 일 중 아침에 할 것, 밤에 할 것을 고른다.
    // 2. 완탐 및 백트래킹하여 min값을 갱신한다.

    cout << ans;
    return 0;
}