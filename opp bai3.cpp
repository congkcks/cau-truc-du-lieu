#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class diem{
	private:
		float x;
		float y;
	public:
	 void nhap(){
	 	cin>>x>>y;
	 }
	 void xuat(){
	 	cout<<x<<" "<<y<<endl;
	 }
	 friend float tinhkc(diem a,diem b);
};
float tinhkc(diem a,diem b){
	 	float s=(a.x-b.x)*(a.x-b.x);
	 	float t=(a.y-b.y)*(a.y-b.y);
	 	return sqrt(s+t);
}

int main(){
	int n;
	cin>>n;
	diem a[n];
	for(int i=0;i<n;i++){
		
		a[i].nhap();	
	}
	float s=0;
	for(int i=0;i<n;i++){
		s=s+tinhkc(a[i],a[(i+1)%n]);	
	}
	cout<<"do dai duong gap khuc di qua cac diem la :"<<s<<endl;
	
	
	return 0;
	
}
