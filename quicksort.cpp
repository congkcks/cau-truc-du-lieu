#include<bits/stdc++.h>
using namespace std;

swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int partition(int a[],int l,int r){
	int pivot=a[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}
void quicksort(int a[],int l,int r){
	
	if(l<=r){
	int pi=partition(a,l,r);
	quicksort(a,l,pi-1);
	quicksort(a,pi+1,r);
	}
}
int main(){
	
	int a[6]={6,7,4,3,2,1};
	quicksort(a,0,5);
	
	for(int x:a){
		cout<<x<<" ";
	}
	
}
