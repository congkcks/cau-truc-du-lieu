#include<bits/stdc++.h>
using namespace std; 
int partision(int a[],int l,int r){
	int i=l-1;
	for(int j=l;j<r;j++){
		if(a[j]<a[r]){
			i++;
			swap(a[i],a[j]);
		}
		
	}
	swap(a[i+1],a[r]);
	return i+1;
	
}
void quicksort(int a[],int l,int r){
	if(l>=r) return;
	int pi=partision(a,l,r);
	quicksort(a,l,pi-1);
	quicksort(a,pi+1,r);
}
int main(){
	int a[5]={5,3,4,2,1};
	quicksort(a,0,4);
	for(int x:a){
		cout<<x<<" ";
	}
}
