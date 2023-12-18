#include<iostream>
#include<stack>
using namespace std;

// tinh gia tri bieu thuc hau to
int tinh(string c){
	stack<int> s;
	int t=0;
	for(char x:c){
		if(x=='+'||x=='-'){
			int a=s.top();
			s.pop();
			int b=s.top();
			s.pop();
			if(x=='+'){
				t=a+b;
			}
			if(x=='-'){
				t=a-b;
			}
			s.push(t);
			
		}
		else{
			s.push(x-'0');
		}
		
	}
	return t;
}
int main(){
	string str="34+";
	cout<<tinh(str)<<endl;
	return 0;
	
	
	
}
