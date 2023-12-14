#include<bits/stdc++.h>
using namespace std;

class PS{
	private:
		int ms,ts;
	public:
	PS(){
		ms=2022;
		ts=2023;
	}
	PS(int x,int y){
		this->ts=x;
		this->ms=y;
	}
	void nhap(){
		cin>>ts>>ms;
	}
	friend ostream &operator << (ostream &cout,PS a){
		if(a.ts>a.ms){
			for(int i=a.ms;i>1;i--){
				if(a.ts%i==0&&a.ms%i==0){
					a.ts=a.ts/i;
					a.ms=a.ms/i;
				}
			}
		}
		else{
				for(int i=a.ts;i>1;i--){
				if(a.ts%i==0&&a.ms%i==0){
					a.ts=a.ts/i;
					a.ms=a.ms/i;
				}
			}
			
		}
		
		cout<<a.ts<<"/"<<a.ms<<endl;
		return cout;
	}
	friend PS &operator * (PS a,PS b){
		PS x;
		x.ts=a.ts*b.ts;
		x.ms=a.ms*b.ms;
		return x;
	} 	
};
int main(){
	PS p1;
	PS p2(2,5);
	
	PS p=p1*p2;
	cout<<p1<<endl;
	cout<<p2<<endl;
	cout<<p<<endl;
	return 0;
	
	
	
}



