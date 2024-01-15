#include<iostream>
using namespace std;

int n,a[105];
void dayconmax(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int res=-1e9+7;
	int temp=0;
	for(int i=0;i<n;i++){
		temp=0;
		for(int j=i;j<n;j++){
			temp+=a[j];
			if(temp<0) break;
			else{
				res=max(res,temp);
			}
		}
	}
	cout<<res<<endl;
}
int main(){
	dayconmax();
	
	return 0;
}
