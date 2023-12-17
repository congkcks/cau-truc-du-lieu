#include<iostream>
using namespace std;

template <class T1,class T2>
T1 cong(T1 x,T2 y){
	return x+y;
}
int timkiem(int a[],int l,int r,int x){
	int mid=(l+r)/2;
	if(a[mid]==x){
		return mid;
	}
	if(a[mid]>x){
		timkiem(a,l,mid,x);
	}
	if(a[mid]<x){
		timkiem(a,mid,r,x);
	}
}
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int x=timkiem(a,0,9,5);
	cout<<x<<endl;

	
	
	return 0;
	
	
}
