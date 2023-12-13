#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class QLH{
	private:
		string mahang;
		string tenhang;
		string xuatxu;
		int loai;
		int soluong;
	public:
		void nhap(){
			getline(cin,tenhang);
		    getline(cin,xuatxu);
		    cin>>mahang>>loai>>soluong;
		}
		void xuat(){
			cout<<tenhang<<" "<<xuatxu<<" "<<" "<<mahang<<" "<<loai<<" "<<soluong<<endl;
		}
	   int getloai(){
			return this->loai;
		}
		
		
};
class dientu:public QLH{
	private:
		int thoigianbh;
	public:
		void nhap1(){
		nhap();
		cin>>thoigianbh;
		
		}
		int getthoigian(){
			return this->thoigianbh;
		}
};
void thongke(dientu a[],int n){
	map<int,int> mp1;
	int check=0;
	for(int i=0;i<n;i++){
		mp1[a[i].getloai()]++;
		if(a[i].getthoigian()>=12){
			check++;
			
		}
	}
	cout<<"so luong mat hang tung loai la"<<endl;
	for(auto x: mp1){
		cout<<" so mat hang loai"<<x.first<<" la "<<x.second<<endl;
	}
	
} 
int main(){
	int n;
	cout<<"nhap so hang "<<endl;
	cin>>n;
	cin.ignore(1);
	dientu a[n];
	for(int i=0;i<n;i++){
		a[i].nhap1();
	}
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
	thongke(a,n);
	return 0;
}
