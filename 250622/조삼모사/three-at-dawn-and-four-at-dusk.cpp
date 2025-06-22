#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
// 3:34
using namespace std;
// 아침에 하는 일과 저녁에 하는 일의 업무 강도 차이의 최솟값은?

int n; // 하는 일의 양
int works[21][21];
bool checked[21];
int ans = 190 * 20 * 100;
vector<int> mornings;
vector<int> nights;

pair<int,int> calSum(){
    int morningSum = 0;
    int nightSum = 0;
    for (int i=0; i<mornings.size(); i++){
        for (int j=0; j<mornings.size(); j++){
            if (i!=j){
                morningSum = morningSum + works[mornings[i]][mornings[j]];
            }
        }
    }

    for (int i=0; i<nights.size(); i++){
        for (int j=0; j<nights.size(); j++){
            if (i!=j){
                nightSum = nightSum + works[nights[i]][nights[j]];
            }
        }
    }
        mornings.clear();
        nights.clear();
    return {morningSum, nightSum};
}


pair<int,int> calWorks(){
    for (int i=0; i<n; i++){
        if (checked[i]) {
            mornings.push_back(i);
        }
        else {
            nights.push_back(i);
        }
    }
    return calSum();
}

void backTraking(int idx, int cnt){
    if (cnt == (n/2)) {
        int minAns = abs(calWorks().first - calWorks().second);
        ans = min(ans, minAns);
        return;
    }

    for (int i=idx; i<n; i++){
        if (!checked[i]){
          checked[i] = true;
          backTraking(i, cnt+1);
          checked[i] = false;
        }
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
    cout << ans << "\n";
    return 0;
}