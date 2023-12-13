#include<bits/stdc++.h>
using namespace std;
struct p{
	int a;
	int b;
};
using p=p;

p arr[105];
int dp[100];
bool cmp(p x,p y){
	return x.a-y.a;
}
void solve(){
int n;cin>>n;
for(int i=1;i<=n;i++) cin>>arr[i].a>>arr[i].b;
sort(arr+1,arr+n+1,cmp);
memset(dp,0,sizeof(dp));
dp[1]=1;
for(int i=1;i<=n;i++){
	for(int j=0;j<i;j++){
		if(arr[i].b>arr[j].a) dp[i]=max(dp[i],dp[j]+1);
		
		
	}
}
sort(dp,dp+n+1);
cout<<dp[n]<<endl;
}
int main(){
	solve();
	return 0;
	
}
