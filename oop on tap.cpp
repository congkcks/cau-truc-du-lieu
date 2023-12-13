#include<bits/stdc++.h>

using namespace std;




class dathuc{
	private:
		float *hs;
		int n;
	public:
	dathuc(){
		hs=NULL;
		n=0;	
	}
	void nhap(){
		cin>>n;
		hs=new float[n];
		for(int i=0;i<=n;i++){
			cin>>hs[i];
		}	
	}
	void xuat(){
		cout<<"P(x)=";
		for(int i=0;i<=n;i++){
			if(i!=n) cout<<hs[i]<<"x^"<<i<<"+";
			else{
				cout<<hs[i]<<"x^"<<i;
			}
		}
	}	
    void giatri(){
    	cout<<"\nnhap d vao "<<endl;
    	float d;
    	cin>>d;
    	
    	float s=0;
    	for(int i=0;i<=n;i++){
    		s=s+hs[i]*pow(d,i);
		}
		cout<<"\nGia tri cua da thuc P(d) la :"<<s<<endl;
	}
};
int main(){
	dathuc x;
	x.nhap();
	x.xuat();
	x.giatri();
	return 0;
	
}
