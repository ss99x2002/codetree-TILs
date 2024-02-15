#include <iostream>
using namespace std;

int arr[1001];

int main() {
    int n;
    cin >> n;
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    for (int i=4; i<=n; i++){
        arr[n] = arr[n-2]+ arr[n-3];
    }
    cout << arr[n]%10007;
    return 0;
}