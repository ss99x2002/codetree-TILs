#include <iostream>
using namespace std;

int dp[101][101];

int N;

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
        dp[0][i] = min(dp[0][i - 1], dp[0][i]);
    }

    for (int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i][0]);
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N ; j++) {
            int maxV = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = min(dp[i][j], maxV);
        }
    }

    cout << dp[N - 1][N - 1];

    return 0;
}