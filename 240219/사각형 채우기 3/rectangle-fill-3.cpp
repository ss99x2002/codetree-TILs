#include <iostream>
using namespace std;

long long dp[1001];

int main() {
    int N;
    cin >> N;

    dp[0] = 1;
    dp[1] = 2;

    for (int i=2; i<=N; i++){
        dp[i] =( 2*dp[i-1] + 3*dp[i-2] ) % 1000000007;
        for (int j=i-3; j>=0; j--) {
            dp[i] = (2*dp[j] + dp[i])%1000000007;
        }
    }

    cout << dp[N];

    return 0;
}