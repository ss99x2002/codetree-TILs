#include <iostream>
using namespace std;

long long dp[1001];

int main() {
    int n;
    cin >> n;

    dp[0]= 1;
    dp[1] = 1;

    for (int i=2; i<=n; i++){
        dp[i] = (dp[i-1] + 2*dp[i-2])%10007;
        for (int j=i-3; j>=0; j--) {
            dp[i] = (dp[j]*2 + dp[i]) % 10007;
        }
    }
    
    cout << dp[n];
    
    return 0;
}