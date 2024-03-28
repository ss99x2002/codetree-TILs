#include <iostream>
using namespace std;
int arr[10];
int k,n;

void func(int m){
    if (m==n) {
        for (int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=1; i<=k; i++){
        arr[m] = i;
        func(m+1);
    }
}
int main() {
    cin >> k >> n;
    func(0);
}