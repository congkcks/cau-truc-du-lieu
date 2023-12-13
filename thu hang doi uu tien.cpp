#include <iostream>
using namespace std;

int main() {
    int n, bnum, digit, dec = 0, i = 0;
    cout << "Nh?p s? nh? phân: ";
    cin >> bnum;
    n = bnum;

    // Vòng l?p d? tính s? th?p phân tuong ?ng v?i s? nh? phân
    while (n != 0) {
        digit = n % 10;
        dec += digit << i;
        n = n / 10;
        i++;
    }

    cout << "S? th?p phân tuong ?ng v?i " << bnum << " là " << dec << endl;

    return 0;
}

