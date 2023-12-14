#include<bits/stdc++.h>
using namespace std;

class MatHang{
	private:
	string mahang,tenhang,nhasanxuat;
	int soluong,dongia;
	public:
		void nhap(){
			getline(cin,tenhang);
			getline(cin,mahang);
			getline(cin,nhasanxuat);
			cin>>soluong>>dongia;
			cin.ignore();
			
		}
		void xuat(){
			cout<<tenhang<<" "<<mahang<<" "<<nhasanxuat<<" "<<dongia<<" "<<soluong<<" ";
		}
		
	
};
class MayTinh:public MatHang{
	private:
		string loaicpu,hedieuhanh;
		int trongluong;
	public:
		void nhap1(){
			nhap();
			getline(cin,loaicpu);
			getline(cin,hedieuhanh);
			cin>>trongluong;
			cin.ignore();
		}
		void xuat1(){
			xuat();
			cout<<loaicpu<<" "<<hedieuhanh<<" "<<trongluong<<endl;
		}
	    	
	
};
int main(){
	int n;
	cin>>n;
	cin.ignore();
	MayTinh a[n];
	for(int i=0;i<n;i++){
		a[i].nhap1();
	}
    for(int i=0;i<n;i++){
		a[i].xuat1();
	}
	
	
	
}
