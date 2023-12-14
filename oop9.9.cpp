#include<iostream>
using namespace std;
class matran{
	private:
		int n;
		int **x;
	public:
	matran(){
		n=0;
		x=NULL;
	}
	friend istream &operator >> (istream &cin,matran &a){
		cin>>a.n;
		a.x= new int*[a.n];
		for(int i=0;i<a.n;i++)
		a.x[i]=new int[a.n];
		for(int i=0;i<a.n;i++){
			for(int j=0;j<a.n;j++){
				cin>>a.x[i][j];
			}
		}
		return cin;
	}
	friend ostream &operator << (ostream &cout,matran a){
		for(int i=0;i<a.n;i++){
			for(int j=0;j<a.n;j++){
			cout<<a.x[i][j]<<" ";
			}
			cout<<endl;
		}
		return cout;
		
	}

};


int main(){
	
	matran x;
	cin>>x;
	cout<<x;
	return 0;
	
}
