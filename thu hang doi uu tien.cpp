#include <iostream>
using namespace std;

int main() {
    int n, bnum, digit, dec = 0, i = 0;
    cout << "Nh?p s? nh? ph�n: ";
    cin >> bnum;
    n = bnum;

    // V�ng l?p d? t�nh s? th?p ph�n tuong ?ng v?i s? nh? ph�n
    while (n != 0) {
        digit = n % 10;
        dec += digit << i;
        n = n / 10;
        i++;
    }

    cout << "S? th?p ph�n tuong ?ng v?i " << bnum << " l� " << dec << endl;

    return 0;
}

