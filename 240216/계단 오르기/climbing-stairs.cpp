#include <iostream>
using namespace std;

long long arr[1001];

int main() {
    int n;
    cin >> n;
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 1;

    for (int i = 5; i <= n; i++) {
        arr[i] = arr[i - 2] + arr[i - 3];
    }
    cout << (arr[n] % 10007);
    return 0;
}