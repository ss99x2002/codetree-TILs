#include <iostream>
using namespace std;

int n; // n개의 식당 
int customer; // 식당에 있는 고객 수
int maxL, maxM; // 팀장 검사 최대 고객 수, 팀원 검사 최대 고객 수
long long maxCustomer = 0;
int ans =0;

long long calNum(int maxC){
    if (maxC - maxL <= 0){
        return 1;
    }
    else {
        if ((maxC-maxL)%maxM == 0 || (maxC-maxL)/maxM<0){
            return n*((maxC-maxL)/maxM + 1);
        }
        else{
            return n*((maxC-maxL)/maxM + 2);
        }
    }
}


// 출력 : n개의 식당 고객들 모두 검사하기 위한 검사자의 최소 수 
int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> customer;
        if (maxCustomer < customer) {
            maxCustomer = customer;
        }
    }
    cin >> maxL >> maxM;
    cout << calNum(maxCustomer);
    return 0;
}