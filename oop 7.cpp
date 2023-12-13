#include<bits/stdc++.h>
using namespace std;

class PS{
	private:
		float tu;
		float mau;
	public:
	  friend istream &operator >> (istream &cin,PS &a){
	  	cin>>a.tu>>a.mau;
	  }
	  friend ostream &operator << (ostream &cout,PS a){
	  	cout<<a.tu<<" "<<a.mau<<endl;
	  }
	  friend float operator * (PS a,PS b){
	  	return (float)(a.tu*b.tu)/(a.mau*b.mau);
	  } 
};

int main(){
	PS p1,p2;
	cin>>p1>>p2;
	cout<<p1*p2<<endl;
	return 1;
	
	
	
}
