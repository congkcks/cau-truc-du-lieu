#include<iostream>
using namespace std;
int n,a[105],ok,sum;
void Try(int i,int s){
	if(s==sum/2){
		ok=1;
		return;
	}
	for(int j=i;j<=n;j++){
		if(s+a[j]<sum/2) Try(i+1,s+a[j]);
	}
	
	
}
void giai(){
	cin>>n;
  ok=0;
  sum=0;
  for(int i=1;i<=n;i++){
  	cin>>a[i];
  	sum=sum+a[i];
  }
  if(sum%2==1){
  	cout<<"NO"<<endl;
  	return;
  }
  Try(1,0);
  if(ok==0){
  	cout<<"NO"<<endl;
  }
  else{
  	cout<<"YES"<<endl;
  }
}

int main(){
  giai();
  return 0;
  	
	
	
	
	
}
