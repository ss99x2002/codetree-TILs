#include <iostream>
#include <algorithm>
using namespace std;

int n, t, p;
int maxSum = 0;
vector<pair<int, int>> tasks;  // {소요시간, 수익}
vector<int> dp;  // DP 배열

// 백트래킹 함수
void backTracking(int idx, int sum) {
    // 최대 수익 갱신
    maxSum = max(maxSum, sum);

    // 가능한 다음 작업을 탐색
    for (int i = idx + 1; i < n; i++) {
        // 현재 작업이 끝난 시간 <= 다음 작업이 시작하는 시간일 경우
        if (tasks[idx].first + idx <= i) {
            backTracking(i, sum + tasks[i].second);  // 선택된 작업을 추가
        }
    }
}

int main() {
    cin >> n;

    // 작업 정보 입력
    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        tasks.push_back({t, p}); // 소요 시간과 수익
    }

    // 모든 작업을 시작점으로 해서 backtracking 호출
    for (int i = 0; i < n; i++) {
        backTracking(i, tasks[i].second);  // 현재 작업부터 시작
    }

    cout << maxSum << "\n";  // 최대 수익 출력
    return 0;
}