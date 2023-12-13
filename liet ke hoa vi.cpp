#include<bits/stdc++.h>
using namespace std;
int a[100];
int n,used[100];

void ktao(){
	for(int i=1;i<=n;i++){
		a[i]=0;
		used[i]=0;
		
  }
}
void in(){
	for(int i=1;i<=n;i++){
		cout<<a[i]<<"";
		
	}
	cout<<endl;
}
void quaylui(int k){
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			a[k]=i;
			used[i]=1;
			if(k==n){
				in();
			}
			else{
				quaylui(k+1);
			}
			used[i]=0;
		}
	}
	
}
int main(){
	
	cin>>n;
	ktao();
	quaylui(1);
	return 0;
	
}
