#include<iostream>
using namespace std;


int UCLN(int A , int B) {
    if (B == 0) {
        return A;
    } else {
        return UCLN(B, A % B);
    }
}

int main(){
	cout<<UCLN(12,10)<<endl;
	return 0;
}
