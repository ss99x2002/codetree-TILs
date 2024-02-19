#include <iostream>
using namespace std;

int N;
int dp[101][101];
int main() {
    cin >> N;

    int input;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input;
            dp[i][j] = input;
        }
    }

    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i][0];
    }

    for (int i = 1; i < N; i++) {
        dp[0][i] = dp[0][i - 1] + dp[0][i];
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            dp[i][j] = max(dp[i - 1][j] + dp[i][j], dp[i][j - 1] + dp[i][j]);
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[N - 1][i]);
    }

    cout << ans;


    return 0;
}