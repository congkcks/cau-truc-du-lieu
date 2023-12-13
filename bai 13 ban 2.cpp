#include<bits/stdc++.h>
using namespace std;
class khachhang {
public:
    string ho_ten;
    string so_dien_thoai;
};
class cuocgoi {
public:
    string so_dien_thoai;
    int so_phut;
    string thoi_gian;
    string ngay_thang;
    string vung;
public:    
  string TinhThu() const {
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


    
};
float Tinh_tien_cuoc(const cuocgoi& cuocgoi) {
    float GIA_CO_BAN = 1100;
    float HE_SO_MIEN_NH = 1;
    float HE_SO_MIEN_LC = 2;
    float HE_SO_MIEN_X = 3;
    float HE_SO_MIEN_RX = 4;
    float he_so_mien=1;
    if(cuocgoi.vung.compare("NH")==0) he_so_mien = 1;
    else if(cuocgoi.vung.compare("LC")==0) he_so_mien = 2;
    else  if(cuocgoi.vung.compare("X")==0) he_so_mien = 3;
    else if(cuocgoi.vung.compare("RX")==0) he_so_mien = 4;
    float Gia_cuoc = GIA_CO_BAN * cuocgoi.so_phut * he_so_mien;
    int gio_goi = stoi(cuocgoi.thoi_gian.substr(0, 2));
    if ((gio_goi >= 23 || gio_goi <= 5) || (cuocgoi.TinhThu() == "TH7" || cuocgoi.TinhThu() == "CN")) {
        Gia_cuoc *= 0.7;
    }
    return Gia_cuoc;
}
vector<khachhang> DocKhachHangTuFile(const string& ten_file) {
    vector<khachhang> danh_sach_khach_hang;
    ifstream file(ten_file);

    if (!file.is_open()) {
        cout << "Không the mo file!" << endl;
        return danh_sach_khach_hang;
    }
    string line;
    while (getline(file, line)) {
        istringstream get(line);
        string ho_ten, so_dien_thoai;
        getline(get, ho_ten, ';');
        getline(get, so_dien_thoai, ';');
        danh_sach_khach_hang.push_back({ho_ten, so_dien_thoai});
    }

    file.close();
	return danh_sach_khach_hang;
}
vector<cuocgoi> DocCuocGoiTuFile(const string& ten_file) {
    vector<cuocgoi> danh_sach_cuoc_goi;
    ifstream file(ten_file);

    if (!file.is_open()) {
        cout << "Không the mo file!" << endl;
        return danh_sach_cuoc_goi;
    }

    string line;
    while (getline(file, line)) {
        istringstream get(line);
        string so_dien_thoai;
        string vung;
        int so_phut;
        string thoi_gian;
        string ngay_thang;
        getline(get, so_dien_thoai, ';');
        get >> so_phut; get.ignore(1);
        getline(get, thoi_gian, ';');
        getline(get, ngay_thang, ';');
        getline(get, vung, ';');
        danh_sach_cuoc_goi.push_back({ so_dien_thoai, so_phut, thoi_gian, ngay_thang, vung });
    }

    file.close();
    return danh_sach_cuoc_goi;
}

void GhiKetQuaVaoFile(const map<string, pair<string, pair<float, map<string, int>>>>& ket_qua, const string& ten_file) {
    ofstream file(ten_file);

    if (!file.is_open()) {
        cout << "Không the mo file!" << endl;
        return;
    }

    for (const auto& kq : ket_qua) {
        file << "Khach hang: " << kq.second.first << "; SDT: " << kq.first << "; Gia cuoc: " << kq.second.second.first << "\n";
        file << "So cuoc goi: ";
        file << "NH: " << kq.second.second.second.at("NH")<< "; ";
        file << "LC: " << kq.second.second.second.at("LC") << "; ";
        file << "X: " << kq.second.second.second.at("X")<< "; ";
        file << "RX: " << kq.second.second.second.at("RX")<< "; ";
        file << "\n";
    }

    file.close();
    cout<<"Ket qua da duoc ghi vao file ketqua.txt !"<<endl;
}

void tinhvaxuatketqua(){
    vector<khachhang> danh_sach_khach_hang;
    vector<cuocgoi> danh_sach_cuoc_goi;
    map<string, pair<string, pair<float, map<string, int>>>> ket_qua;
    danh_sach_khach_hang = DocKhachHangTuFile("khachhang.txt");
    danh_sach_cuoc_goi = DocCuocGoiTuFile("cuocgoi.txt");
    for (const auto& khach_hang : danh_sach_khach_hang) {
        float so_tien = 0;
        map<string, int> so_cuoc = {{"NH", 0}, {"LC", 0}, {"X", 0}, {"RX", 0}};
        for (const auto& cuoc_goi : danh_sach_cuoc_goi) {
            if (cuoc_goi.so_dien_thoai == khach_hang.so_dien_thoai) {
                so_tien += Tinh_tien_cuoc(cuoc_goi);
                so_cuoc[cuoc_goi.vung]++;
            }
        }
        ket_qua[khach_hang.so_dien_thoai] = make_pair(khach_hang.ho_ten, make_pair(so_tien, so_cuoc));
    }
    GhiKetQuaVaoFile(ket_qua, "ketqua.txt");
}
int main()
{
	tinhvaxuatketqua();
	return 0;
}
