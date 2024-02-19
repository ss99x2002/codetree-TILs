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

    for (int i = N - 2; i >= 0; i--) {
        dp[0][i] = dp[0][i + 1] + dp[0][i];
    }

    for (int i = 1; i < N; i++) {
        dp[i][N - 1] = dp[i - 1][N - 1] + dp[i][N - 1];
    }

    for (int i = 1; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            dp[i][j] = min(dp[i][j + 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);
        }
    }


    int ans = INT16_MAX;
    
    for (int i = 0; i < N; i++) {
        ans = min(ans, dp[N - 1][i]);
    }

    cout << ans;

    return 0;
}