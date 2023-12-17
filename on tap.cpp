#include<bits/stdc++.h>
using namespace std;



void mesort(int a[],int l,int m,int r){
	vector<int> s(a+l,a+m+1);
	vector<int> t(a+m+1,a+r+1);
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
		i++;
		l++;
		
	}
	while(j<t.size()){
		a[l]=t[j];
		j++;
		l++;
	}
}
void megesort(int a[],int l,int r){
    if (l < r)
    {
        int mid = l+(r-l)/2;
        megesort(a, l, mid);
        megesort(a, mid+1, r);
        mesort(a, l, mid, r);
    }
}

int main(){
    int a[10]={10,9,8,7,6,5,4,3,2,1};
    megesort(a,0,9);
    for(int x:a){
    	cout<<x<<" ";
	}
    return 0;
}
