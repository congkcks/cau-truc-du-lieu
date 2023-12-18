#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	
	int n;
	cout<<"nhap so n con bup be da sap xep"<<endl;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(q.empty()){
			q.push(v[i]);
		}
		if(q.front()-v[i]>=3){
			q.pop();
			q.push(v[i]);
		}
		else{
			q.push(v[i]);
		}
	}

	cout<<q.size()<<endl;
	return 0;
}

