#include<iostream>
#include<vector>
using namespace std;


vector<int> buildPrefixSum(const vector<int>& a, int C = 0) {
    int n = (int)a.size();
    vector<int> prefixSum(n + 1);

    prefixSum[0] = C;

    for (int i = 0; i < n; i++)
        prefixSum[i + 1] = prefixSum[i] + a[i];

    return prefixSum;
}
int main(){
	
	
	
	
	
}
