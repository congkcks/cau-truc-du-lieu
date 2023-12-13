#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
    unsigned char c;
    int freq;
    bool used;
    int nLeft, nRight;
};

struct MaBit {
    char* bits;
    int soBit;
};

const int MAX_NODE = 256*9;
const int MAX_BIT_LEN = 10000;
Node huffTree[MAX_NODE];
MaBit bangMaBit[256];

void KhoiTao() {
    for (int i = 0; i < MAX_NODE; i++) {
        huffTree[i].c = i;
        huffTree[i].freq = 0;
        huffTree[i].used = false;
        huffTree[i].nLeft = -1;
        huffTree[i].nRight = -1;
    }
}

void ThongKeTanSoXuatHien(string tenFile) {
    FILE* fi = fopen(tenFile.c_str(), "rt");
    unsigned char c;

    while (1) {
        fscanf(fi, "%c", &c);
        if (feof(fi)) {
            break;
        }
        huffTree[c].freq++;
    }

    fclose(fi);
}

void XuatBangThongKe() {
    cout << "Bang thong ke tan suat: \n";
    for (int i = 0; i < 256; i++) {
        if (huffTree[i].freq > 0) {
            cout << char(i) << ": " << huffTree[i].freq << "\n";
        }
    }
}

bool Tim2PhanTuMin(int &i, int &j, int nNode) {
    i = -1;
    j = -1;

    for (int k = 0; k < nNode; k++)
        if (huffTree[k].used == false && huffTree[k].freq > 0) {
            if (i == -1) {
                i = k;
            }
            else if (j == -1) {
                j = k;
            }
            else {
                if (huffTree[i].freq > huffTree[j].freq) {
                    if (huffTree[k].freq < huffTree[i].freq) {
                        i = k;
                    }
                }
                else {
                    if (huffTree[k].freq < huffTree[j].freq) {
                        j = k;
                    }
                }
            }
        }

    if (i != -1 && j!= -1) {
        if ((huffTree[i].freq > huffTree[j].freq) || ((huffTree[i].freq > huffTree[j].freq) && (huffTree[i].c > huffTree[j].c))) {
            int t = i;
            i = j;
            j = t;
        }
        return true;
    }
    else {
        return false;
    }
}

int TaoCayHuffman() {
    int nNode = 256;
    int i, j;
    bool timThay = false;

    while (true) {

        timThay = Tim2PhanTuMin(i, j, nNode);
        if (!timThay) {
            break;
        }

        huffTree[nNode].c = (huffTree[i].c < huffTree[j].c) ? huffTree[i].c : huffTree[j].c; 
        huffTree[nNode].freq = huffTree[i].freq + huffTree[j].freq;
        huffTree[nNode].nLeft = i;
        huffTree[nNode].nRight = j;

        huffTree[i].used = true;
        huffTree[j].used = true;

        huffTree[nNode].used = false;

        nNode++;
        
    }

    return nNode - 1; 
}

void XuatCayHuffman(int node, int tab) {
    if (node == -1) {
        return;
    }

    for (int i = 0; i < tab; i++) {
        cout << "\t";
    }

    if (huffTree[node].nLeft == -1 && huffTree[node].nRight == -1)   {
        cout << char(huffTree[node].c) << "\n";
    }
    else   {
        cout << char(huffTree[node].c) << "..\n";
        XuatCayHuffman(huffTree[node].nLeft, tab + 1);
        XuatCayHuffman(huffTree[node].nRight, tab + 1);
    }
}

void DuyetCayHuffman(int node, char maBit[], int nMaBit) {
    if (node == -1) {
        return;
    }

    if (huffTree[node].nLeft == -1 && huffTree[node].nRight == -1) {
        bangMaBit[node].soBit = nMaBit;
        bangMaBit[node].bits = new char[nMaBit];
        for (int i = 0; i < nMaBit; i++) {
            bangMaBit[node].bits[i] = maBit[i];
        }
        return;
    }
    else {
        maBit[nMaBit] = 0;        
        DuyetCayHuffman(huffTree[node].nLeft, maBit, nMaBit + 1);
        
        maBit[nMaBit] = 1;
        DuyetCayHuffman(huffTree[node].nRight, maBit, nMaBit + 1);
    }
}

void PhatSinhMaBit(int nRoot) {
    for (int i = 0; i < 256; i++) {
        bangMaBit[i].soBit = 0;
        bangMaBit[i].bits = NULL;
    }

    char maBit[MAX_BIT_LEN];
    DuyetCayHuffman(nRoot, maBit, 0);
}

int main() {
    KhoiTao();
    ThongKeTanSoXuatHien("input.txt");
 

    return 0;
}

