#include<iostream>
using namespace std;
int a[11], n, s, b[11];

void out(int i){
    cout << "[";
    for(int j = 1; j < i; j++){
        cout << b[j] << " ";
    }
    cout << b[i] << "]";
}

void Try(int i, int sum, int cur){
    for(int j = cur; j <= n; j++){
        sum = sum + a[j];
        b[i] = a[j];
        if(sum == s) out(i);
        else if(sum < s) Try(i+1, sum, j+1);
        sum = sum - a[j];	
    }	
}

int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    Try(1, 0, 1);
    return 0;
}

