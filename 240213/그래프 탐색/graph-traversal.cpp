#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

vector<int> vec[1001];
bool vis[1001];
int cnt = 0;

void dfs(int x) {
    vis[x] = true;
    for (int i = 0; i < vec[x].size(); i++) {
        if (!vis[vec[x][i]]) {
            cnt++;
            dfs(vec[x][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int x, y;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        vec[x].push_back(y); //양방향 간선처리
        vec[y].push_back(x);
    }

    for (int i = 1; i <= N; i++) {
        sort(vec[i].begin(), vec[i].end()); //낮은 간선부터 탐색
    }
    dfs(1);
    cout << cnt;
}