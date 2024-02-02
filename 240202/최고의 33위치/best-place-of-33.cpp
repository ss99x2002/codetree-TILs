#include <iostream>
using namespace std;

int arr[21][21] = {};

int getCoinNumber(int row, int col_s, int col_e) {
    int num_of_coin = 0;
    for (int i = row; i <= row + 2; i++) {
        for (int col = col_s; col <= col_e; col++) {
            num_of_coin = arr[i][col] + num_of_coin;
        }
    }
    return num_of_coin;
} // 3*3을 탐색하는 함수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            arr[i][j] = num;
        }
    }

    int max_of_coin = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 2 >= N || j + 2 >= N) {
                continue;
            }
            int num_of_coin = getCoinNumber(i, j, j + 2);
            max_of_coin = max(max_of_coin, num_of_coin);
        }
    }
    cout << max_of_coin << "\n";
}