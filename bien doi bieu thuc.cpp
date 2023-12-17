#include<bits/stdc++.h>
using namespace std;

int uuTien(char kiTu) {
    if(kiTu == '^')
        return 3;
    if(kiTu == '*' || kiTu == '/')
        return 2;
    if(kiTu == '+' || kiTu == '-')
        return 1;
    return -1;
}

string chuyenDoi(string bieuThuc) {
    stack<char> nganXep;
    string ketQua = "";
    for(int i = 0; i < bieuThuc.length(); i++) {
        char kiTu = bieuThuc[i];
        if(isalnum(kiTu))
            ketQua += kiTu;
        else if(kiTu == '(')
            nganXep.push('(');
        else if(kiTu == ')') {
            while(!nganXep.empty() && nganXep.top() != '(') {
                ketQua += nganXep.top();
                nganXep.pop();
            }
            nganXep.pop();
        }
        else {
            while(!nganXep.empty() && uuTien(nganXep.top()) >= uuTien(kiTu)) {
                ketQua += nganXep.top();
                nganXep.pop();
            }
            nganXep.push(kiTu);
        }
    }
    while(!nganXep.empty()) {
        ketQua += nganXep.top();
        nganXep.pop();
    }
    return ketQua;
}

int main() {
    string bieuThuc = "a+b*(c^d-e)^(f+g*h)-i";
    cout << chuyenDoi(bieuThuc);
    return 0;
}

