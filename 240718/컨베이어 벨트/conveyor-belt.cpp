#include <iostream>
using namespace std;

int n,t;
int A[201];

void changeElement(int end){
    int endE = A[2*end-1];
    for (int i=2*end-1; i>=1; i--){
        A[i] = A[i-1];
    }
    A[0] = endE;
}

int main() {
    cin >> n >> t;
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    for (int i=n; i<2*n; i++){
        cin >> A[i];
    }
    
    for (int i=0; i<t; i++){
        changeElement(n);
    }

    for (int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
     for (int i=n; i<2*n; i++){
        cout << A[i] << " ";
    }
    return 0;
}