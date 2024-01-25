#include<iostream>
#include<vector>
using namespace std;

int n, s;
int a[30], b[30];
vector<vector<int>> res;

void add(int n){
	vector<int> temp;
	for(int i = 1; i <= n; i++){
		temp.push_back(b[i]);
	}
	res.push_back(temp);
}

void Try(int i, int sum, int cur){
	for(int j = cur; j <= n; j++){
		sum += a[j];
		b[i] = a[j];
		if(sum == s){
			add(i);
		}
		else if(sum < s){
			Try(i + 1, sum, j);
		}
		sum -= a[j];
	}
}

int main(){
	res.clear();
	cin >> n >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	Try(1, 0, 1);
	for(int i = 0; i < res.size(); i++){
		cout << "{ ";
		for(int j = 0; j < res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << "}" << endl;
	}
	return 0;
}

