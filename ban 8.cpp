#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;
struct Nut {
    char duLieu;
    unsigned tanSo;
    Nut *trai, *phai;
    Nut(char duLieu, unsigned tanSo, Nut* trai = NULL, Nut* phai = NULL) {
        this->trai = trai;
        this->phai = phai;
        this->duLieu = duLieu;
        this->tanSo = tanSo;
    }
};
struct soSanh {
    bool operator()(Nut* l, Nut* r) {
        return (l->tanSo > r->tanSo);
    }
};
class CayHuffman {
private:
    Nut* goc;
    unordered_map<char, string> maHoa;
    void duyetma(Nut* goc, string str) {
        if (!goc)
            return;

        if (goc->duLieu != '$')
            maHoa[goc->duLieu] = str;

        duyetma(goc->trai, str + "0");
        duyetma(goc->phai, str + "1");
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
          unsigned tong = trai->tanSo + phai->tanSo;
          minHeap.push(new Nut('$', tong, trai, phai));
       }

       goc = minHeap.top();
       duyetma(goc, "");
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
    
    void inMaHoa() {
    for (auto i : maHoa) {
        cout << i.first << ": " << i.second << "\n";
    }
}
};
int main() {
    string str = "ABABBCBBDEEEABABBAEEDDCCABBBCDEEDCBCCCCDBBBCAAA";
    CayHuffman huff(str);
    string chuoiMaHoa = huff.maHoaChuoi(str);
    cout << "Chuoi sau khi nen: " << chuoiMaHoa << endl;
    string chuoiGiaiMa = huff.giaiMaChuoi(chuoiMaHoa);
    cout << "Chuoi sau khi giai nen: " << chuoiGiaiMa << endl;
    huff.inMaHoa();
    return 0;
}

