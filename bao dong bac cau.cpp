#include<iostream>
using namespace std;

int main() {
    int R[5][5] = {
        {1, 0, 0, 1, 0},  // a
        {0, 0, 1, 0, 1},  // b
        {1, 0, 1, 0, 0},  // c
        {0, 0, 0, 0, 1},  // d
        {0, 0, 1, 0, 0}   // e
    };
                                                        
    int n = 5;

    // Áp d?ng thu?t toán Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
            }
        }
    }

    // In ra ma tr?n dóng R
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

