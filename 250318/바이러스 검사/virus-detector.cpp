#include <iostream>
#include <cmath>
using namespace std;

long long n; // n개의 식당 
long long customer[1000001]; // 식당에 있는 고객 수
float maxL, maxM; // 팀장 검사 최대 고객 수, 팀원 검사 최대 고객 수
long long ans =0;

long long calNum(long long memberC){
    if(memberC< 0) return 0;
    else return (ceil(memberC/maxM));
}

// 출력 : n개의 식당 고객들 모두 검사하기 위한 검사자의 최소 수 
int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> customer[i];
    }
    cin >> maxL >> maxM;

    for (int i=0; i<n; i++){
        ans ++;
        ans = ans + calNum(customer[i]-maxL);
    }
    cout << ans;
}