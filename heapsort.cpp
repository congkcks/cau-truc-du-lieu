#include<bits/stdc++.h>
using namespace std;

swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void heaptify(int a[],int i,int n){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n&&a[left]>a[largest]){
		largest=left;
	}
	if(right<n&&a[right]>a[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(&a[i],&a[largest]);
	}
	
}
void heapsort(int a[],int n){
	for(int i=n/2-1;i>=0;i--){
		heaptify(a,i,n);
	}
	for(int i=n;i>=0;i--){
		heaptify(a,0,i);
		swap(&a[0],&a[i]);
	}
	
	
}


int main(){
	int a[6]={6,7,4,3,2,1};
	heapsort(a,5);
	
	for(int x:a){
		cout<<x<<" ";
	}
	
}
