#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (arr[n-1] > sum)
        return isSubsetSum(arr, n-1, sum);
    return isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum-arr[n-1]);
}

bool findPartiion(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return false;
    return isSubsetSum(arr, n, sum / 2);
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int A[N];
        for(int i=0; i<N; i++)
            cin >> A[i];
        if (findPartiion(A, N) == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

