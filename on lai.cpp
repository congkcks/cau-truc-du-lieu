#include<iostream>
#include<vector>
using namespace std;

void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void sapxepchon(int a[],int n){
	for(int i=0;i<n;i++){
		int pos=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[pos]){
				swap(&a[pos],&a[j]);
			}
		}
	}
}
int phanhoach(int a[],int l,int r){
	int i=l-1;
	int pivot=a[r];
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
   if(l<r){
   	int pi=phanhoach(a,l,r);
	quicksort(a,l,pi-1);
	quicksort(a,pi+1,r);
   }
}
// cac thuat toan sap xep co ban

void heaptify(int a[],int i,int n){
	int left=2*i+1;
	int right=2*i+2;
	int largest=i;
	if(left<n&&a[left]>a[largest]){
		largest=left;
	}
	if(right<n&&a[right]>a[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(&a[i],&a[largest]);
		heaptify(a,largest,n);
	}
}
void heapsort(int a[],int n){
	for(int i=n/2-1;i>=0;i--){
		heaptify(a,i,n);
	}
	for(int i=n-1;i>=0;i--){
		heaptify(a,0,i);
		swap(&a[0],&a[i]);
	}	
}
void tron(int a[],int l,int mid,int r){
	vector<int> s(a+l,a+mid+1);
	vector<int> t(a+mid+1,a+r+1);
	int i=0;
	int j=0;
	while(i<s.size()&&j<t.size()){
		if(s[i]<t[j]){
			a[l]=s[i];
			i++;
			l++;
			
		}
		else{
			a[l]=t[j];
			j++;
			l++;
		}
		
	}
	while(i<s.size()){
		a[l]=s[i];
		l++;
		i++;
	}
	while(j<t.size()){
		a[l]=t[j];
		j++;
		l++;
	}
}
void megesort(int a[],int l,int r){
	if(l>=r){
		return;
	}
	int mid=(l+r)/2;
	megesort(a,l,mid);
	megesort(a,mid+1,r);
	tron(a,l,mid,r);
}
int main(){
	
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	megesort(a,0,9);
	for(int x: a){
		cout<<x<<" ";
	}
	
	
}
