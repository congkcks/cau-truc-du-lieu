#include<iostream>
using namespace std;
int n,a[1000];
int used[1000];
void Ktao(){
	for(int i=1;i<=n;i++){
		a[i]=0;
		used[i]=0;
	}
}
void in(){
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<endl;
}
void hoanvi(int k){
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			used[i]=1;
			a[k]=i;
			if(k==n){
				in();
			}else{
				hoanvi(k+1);
			}
			used[i]=0;
		}
	}
	
}

int main(){
	cin>>n;
	hoanvi(1);
	return 0;
	
	
}
