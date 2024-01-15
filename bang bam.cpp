#include<iostream>
#include<vector>
using namespace std;

class BangBam {
private:
    vector<int> duLieu;
    int kichThuoc;

    int hamBam(int khoa) {
        return khoa % kichThuoc;
    }

public:
    BangBam(int kichThuoc) : kichThuoc(kichThuoc) {
        duLieu.resize(kichThuoc, -1);
    }

    void chen(int khoa) {
        int chiSo = hamBam(khoa);
        while(duLieu[chiSo] != -1) {
            chiSo = (chiSo + 1) % kichThuoc;
        }
        duLieu[chiSo] = khoa;
    }

    bool timKiem(int khoa) {
        int chiSo = hamBam(khoa);
        while(duLieu[chiSo] != -1) {
            if(duLieu[chiSo] == khoa) {
                return true;
            }
            chiSo = (chiSo + 1) % kichThuoc;
        }
        return false;
    }

    void hienThi() {
        for(int i = 0; i < kichThuoc; i++) {
            if(duLieu[i] != -1) {
                cout << i << " --> " << duLieu[i] << endl;
            } else {
                cout << i << endl;
            }
        }
    }
};

int main() {
    BangBam bb(10);
    bb.chen(23);
    bb.chen(43);
    bb.chen(13);
    bb.chen(27);
    bb.hienThi();
    cout << "Tim kiem 23: " << (bb.timKiem(23) ? "Tim thay" : "Khong tim thay") << endl;
    cout << "Tim kiem 50: " << (bb.timKiem(50) ? "Tim thay" : "Khong tim thay") << endl;

    return 0;
}

