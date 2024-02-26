#include <iostream>
using namespace std;

int K, N;
int arr[9];
bool visited[9];

void func(int k) {
    if (k == N) {
        for (int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=1; i<=K; i++){
        arr[k] = i;
        visited[i] = true;
        func(k+1);
        visited[i] = false;
    }
}



int main() {

    cin >> K >> N;
    // K까지의 수 N개 고르는 순열 만들기 
    func(0);
    return 0;
}