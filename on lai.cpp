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
void sapxepnoibot(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
			}
		}
	}
	
}
void sapxepchen(int a[],int n){
	
	for(int i=1;i<n;i++){
		//lay ra phan tu o chi so i
		int key=a[i];
		int pos=i-1;
		while(pos>=0&&key<a[pos]){
			a[pos+1]=a[pos];
			--pos;
		}
		a[pos+1]=key;
	}
	
}
int timkiemnhiphan(int arr[],int left,int right,int x){
	
	while(left<=right){
		 int mid = (left+right)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid;
        else
            right = mid;
	}
	// neu khong tim thay
	return -1;
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
	
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int x=timkiemnhiphan(a,0,9,9);
	cout<<x<<endl;
	
	return 0;
}
