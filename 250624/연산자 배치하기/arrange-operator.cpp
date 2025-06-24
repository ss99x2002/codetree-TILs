#include <iostream>
#include <vector>
using namespace std;

// 연산자간 우선순위 무시하고, 앞에서부터 차례대로 연산할 때
// 가능한 최솟값과 최댓값 출력

// 사용가능한 덧셈, 뺄셈, 곱셈의 갯수가 순서대로 주어짐

int n;
int num;
int sum, mnus, mul;
int nums[12];
bool usedNum[12];
bool usedOp[12];
vector<int> op;
long long minAns = 1000000001;
long long maxAns = -1000000001;



void backTraking(long long val, int cnt){
    if (cnt == op.size()){
        minAns = min(minAns, val);
        maxAns = max(maxAns, val);
        return;
    }

    for (int i=0; i<op.size(); i++){
        if (!usedOp[i]){
            int ansVal = val;
            usedOp[i] = true;
            if (op[i] == -1) {
                ansVal = ansVal - nums[cnt+1];
                backTraking(ansVal, cnt+1);
            }
            else if (op[i]== 1) {
                ansVal = ansVal + nums[cnt+1];
                backTraking(ansVal, cnt+1);
            }
            else {
                ansVal = ansVal * nums[cnt+1];
                backTraking(ansVal, cnt+1);
            }
            usedOp[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }

    cin >> sum >> mnus >> mul;

    for (int i=0; i<sum; i++){
        op.push_back(1);
    }

    for (int i=0; i<mnus; i++){
        op.push_back(-1);
    }

    for (int i=0; i<mul; i++){
        op.push_back(2);
    }

    backTraking(nums[0],0);
    cout << minAns <<" " <<  maxAns << "\n";
 
    return 0;
}