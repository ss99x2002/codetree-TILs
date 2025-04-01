#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second; // {기간, 수익}
    }

    for (int i = n - 1; i >= 0; i--) {
        int time = arr[i].first, profit = arr[i].second;

        if (i + time <= n) {
            dp[i] = max(dp[i + time] + profit, dp[i + 1]);
        } else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[0] << "\n";
    return 0;
}

   // 내가 구현해야 하는 것
    // 어떤것이든 첫번째로 선택 가능.
    // 그 이후로는 조건이 -> 이전에 선택했던 것의 끝나는 시간 <= 선택하는 것의 시작 시간
    // 이 조건이 맞다면 backTraking 계속 진행 함.
    // 선택한 것의 index가 n에 도달했다면 -> 포인트의 합을 max인지 아닌지 판단 후 갱신 필요.