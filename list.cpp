#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class NhanVien{
	private:
		string ma,hoten,gioitinh,namsinh;
		int luong;
	public:
	   friend istream &operator >> (istream &cin,NhanVien &a){
	   	getline(cin,a.hoten);
	   	getline(cin,a.namsinh);
	   	getline(cin,a.gioitinh);
	   	getline(cin,a.ma);
	   	cin>>a.luong;
	   	cin.ignore();
	   }
	   friend ostream &operator << (ostream &cout,NhanVien a){
	   	cout<<a.hoten<<" "<<a.namsinh<<" "<<a.gioitinh<<" "<<a.ma<<" "<<a.luong<<endl;
	   }
	   string getma(){
	   	return this->ma;
	   }
	   int getluong(){
	   	return this->luong;
	   }	
};
class List{
	private:
		int n;
		list<NhanVien> l;
	public:
		void tao(){
			cin>>n;
			cin.ignore();
			NhanVien x;
			for(int i=0;i<n;i++){
				cin>>x;
				l.push_back(x);
			}
		}
		void xoa(){
			cout<<"nhap ma can xoa"<<endl;
			string x;
			cin>>x;
			for(auto it = l.begin(); it != l.end(); ++it){
				if(it->getma()==x){
					l.erase(it);
					break;
				}
				
			}
		}
		void in(){
			for(auto x:l){
				if(x.getluong()>2000){
					cout<<x<<endl;
				}
			}
		}
		
	
};
class vecto{
	private:
		int n;
		vector<NhanVien> v;
	public:
		void them(){
			NhanVien x;
			cin>>x;
			v.push_back(x);
		}
		void xoa(){
			cout<<"nhap ma can xoa"<<endl;
			string ma;
			cin>>ma;
			for(auto it=v.begin();it!=v.end();it++){
				if(it->getma()==ma){
					v.erase(it);
				}
			}
		}
		friend int timkiemnhiphan(int arr[],int left,int right,int x){
	
	    while(left<=right){
		 int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
	    }
	// neu khong tim thay
	return -1;
}
};
//class Tree{
//	private:
//		
//		
//};
int main(){
    List l;
    l.tao();
    l.xoa();
    l.in();
	return 0;
	
}

