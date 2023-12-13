#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Nut {
    char duLieu;
    unsigned tanSuat;
    Nut *trai, *phai;

    Nut(char duLieu, unsigned tanSuat, Nut* trai = NULL, Nut* phai = NULL) {
        this->trai = trai;
        this->phai = phai;
        this->duLieu = duLieu;
        this->tanSuat = tanSuat;
    }
};

struct soSanh {
    bool operator()(Nut* trai, Nut* phai) {
        return (trai->tanSuat > phai->tanSuat);
    }
};

class CayHuffman {
private:
    Nut* goc;
    unordered_map<char, string> maHoa;

    void inMaHoa(struct Nut* goc, string chuoi) {
        if (!goc)
            return;

        if (goc->duLieu != '$')
            maHoa[goc->duLieu] = chuoi;

        inMaHoa(goc->trai, chuoi + "0");
        inMaHoa(goc->phai, chuoi + "1");
    }

public:
    CayHuffman(string duLieu) {
       unordered_map<char, unsigned> tanSo;
       for (char c : duLieu)
           tanSo[c]++;
           
       priority_queue<Nut*, vector<Nut*>, soSanh> minHeap;

       for (auto cap : tanSo)
          minHeap.push(new Nut(cap.first, cap.second));

       while (minHeap.size() != 1) {
          Nut *trai = minHeap.top(); minHeap.pop();
          Nut *phai = minHeap.top(); minHeap.pop();
          unsigned tong = trai->tanSuat + phai->tanSuat;
          minHeap.push(new Nut('$', tong, trai, phai));
       }

       goc = minHeap.top();
       inMaHoa(goc, "");
    }

    string maHoaChuoi(string dauVao) {
        string dauRa = "";
        for (char c : dauVao) {
            dauRa += maHoa[c];
        }
        return dauRa;
    }

    string giaiMaChuoi(string dauVao) {
        string dauRa = "";
        Nut* nutHienTai = goc;
        for (char c : dauVao) {
            if (c == '0')
                nutHienTai = nutHienTai->trai;
            else
                nutHienTai = nutHienTai->phai;

            if (nutHienTai->trai == NULL && nutHienTai->phai == NULL) {
                dauRa += nutHienTai->duLieu;
                nutHienTai = goc;
            }
        }
        return dauRa;
    }
};

int main() {
    string str = "ABABBCBBDEEEABABBAEEDDCCABBBCDEEDCBCCCCDBBBCAAA";

    CayHuffman huff(str);
    
    string chuoiMaHoa = huff.maHoaChuoi(str);
    cout << "Chu?i sau khi nén: " << chuoiMaHoa << endl;

    string chuoiGiaiMa = huff.giaiMaChuoi(chuoiMaHoa);
    cout << "Chu?i sau khi gi?i nén: " << chuoiGiaiMa << endl;

    return 0;
}

