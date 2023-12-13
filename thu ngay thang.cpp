#include<bits/stdc++.h>
using namespace std;

string TinhThu(string ngay_thang){
    int ngay = stoi(ngay_thang.substr(0, 2));
    int thang = stoi(ngay_thang.substr(3, 2));
    int nam = stoi(ngay_thang.substr(6, 4));
    if (thang < 3) {
        thang += 12;
        nam -= 1;
    }
    int h = (ngay + 2*thang + 3*(thang + 1)/5 + nam + nam/4 - nam/100 + nam/400 + 1) % 7;
    switch (h) {
        case 0: return "CN";
        case 1: return "TH2";
        case 2: return "TH3";
        case 3: return "TH4";
        case 4: return "TH5";
        case 5: return "TH6";
        case 6: return "TH7";
    }
    return "";
}


int main(){
 string s="19/10/2018";
 cout<<TinhThu(s);
 
 return 0;	
	
}

