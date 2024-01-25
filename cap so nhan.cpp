#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
  int n,a,q;
  long long ans=0;
  cin>>n;
  cin>>q;
  vector<int> v(n);
  map<int,long long> freq, pairs;
  for(int i=0;i<n;i++){
  	cin>>v[i];
  }
  for(int i=n-1;i>=0;i--){
  	ans += pairs[v[i]];
	if(v[i]%q==0){
		pairs[v[i]/q] += freq[v[i]];
	}
	freq[v[i]]++;
  }

  cout<<ans<<endl;

  return 0;	
}

