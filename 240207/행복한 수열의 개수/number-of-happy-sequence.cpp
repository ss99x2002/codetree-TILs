#include <iostream>
using namespace std;

int arr[101][101] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 1;
    int ans = 0;
    int stn;

    for (int i = 0; i < n; i++) {
        cnt = 0;
        stn = arr[i][0];
        for (int j = 0; j < n; j++) {
               if (stn == arr[i][j]) {
                    cnt++;
                }
                else {
                    cnt = 0;
                    stn = arr[i][j];
                }
            if (cnt == m) {
                ans++;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cnt = 0;
        stn = arr[0][i];
        for (int j = 0; j < n; j++) {
            if (stn == arr[j][i]) {
                cnt++;
            }
            else {
                cnt = 0;
                stn = arr[j][i];
            }
            if (cnt == m) {
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";
}