#include<iostream>
using namespace std;


class SinhVien{
	private:
		int n;
		int *x;
	public:
	  void nhap(){
	  	cin>>n;
	  	x=new int[n];
	  	for(int i=0;i<n;i++){
	  		cin>>x[i];
		  }
	  }
	  void xuat(){
	  	for(int i=0;i<n;i++)
	  	{
	  		cout<<x[i]<<" ";
		  }
	  }	
};
int main(){
	SinhVien a;
	a.nhap();
	a.xuat();
	
	
}
