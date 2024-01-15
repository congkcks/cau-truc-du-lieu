#include<iostream>
using namespace std;
template <class T>
T cong(T a,T b){
	
	return a+b;	
}

int main(){
	int a=10;
	int b=20;
	cout<<cong(a,b)<<endl;
	
	return 0;
}
