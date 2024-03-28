#include <iostream>
using namespace std;

int arr[11];
int isUsed[11];

int n,cnt=0;

void func(int m) {
    if (m==n) {
        for (int i=0; i<n; i++){
            if (isUsed[i]%(i+1)!=0) {
                return;
            }
        }
        cnt ++;
        return;
    }

    for (int i=1; i<=n; i++){
        arr[m] = i;
        isUsed[i]++;
        func(m+1);
    }
}

int main() {
    cin >> n; //n자리의 아름다운 수를 구해야 함.
    // 1을 1번, 2를 2번, 3을 3번, n은 n번 되어있어야 함.

    for (int i=0; i<11; i++){
        isUsed[i]=0;
    }
    func(0);
    cout << cnt;

    return 0;
}