#include<bits/stdc++.h>
using namespace std;
class nguoi{
	private:
		string ten;
		int tuoi;
	public:
	void nhap(){
		getline(cin,ten);
		cin>>tuoi;
	}
	void xuat(){
		cout<<ten<<" "<<tuoi<<endl;
	}
		
		
	
};
class QLNV:public nguoi{
	private:
		int snct;
		int luong;
	public:
		void nhap1(){
			nhap();
			cin>>snct>>luong;
			cin.ignore();
		}
		void xuat1(){
			xuat();
			cout<<snct<<" "<<luong<<endl;
		}
		int getluong(){
			return this->luong;
		}
		
};



int main(){
	int n;
	cout<<"nhap so nhan vien"<<endl;
	cin>>n;
	QLNV a[n];
	cin.ignore();
	for(int i=0;i<n;i++){
		a[i].nhap1();
	}
	float s=0;
	for(int i=0;i<n;i++){
		s=s+a[i].getluong();
	}
	for(int i=0;i<n;i++){
		a[i].xuat1();
	}
	cout<<"so tien luong trung binh cua cac nhan vien la: "<<(float)s/n<<endl;
	
	
	return 0;
	
}
