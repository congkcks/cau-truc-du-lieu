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
};
class tien_dien_thoai {
public:
    float GIA_CO_BAN = 1100;
    float HE_SO_MIEN_NH = 1;
    float HE_SO_MIEN_LC = 2;
    float HE_SO_MIEN_X = 3;
    float HE_SO_MIEN_RX = 4;
    float Tinh_tien_cuoc(const cuocgoi& cuocgoi) {
        float he_so_mien=1;
       if(cuocgoi.vung.compare("NH")==0) he_so_mien = 1;
       else if(cuocgoi.vung.compare("LC")==0) he_so_mien = 2;
       else  if(cuocgoi.vung.compare("x")==0) he_so_mien = 3;
       else if(cuocgoi.vung.compare("RX")==0) he_so_mien = 4;
        float Gia_cuoc = GIA_CO_BAN * cuocgoi.so_phut * he_so_mien;
        int gio_goi = stoi(cuocgoi.thoi_gian.substr(0, 2));
        if ((gio_goi >= 23 || gio_goi <= 5) && (cuocgoi.ngay_thang == "TH7" || cuocgoi.ngay_thang == "CN")) {
            Gia_cuoc *= 0.7;
        }
        return Gia_cuoc;
    }
};

vector<khachhang> DocKhachHangTuFile(const string& ten_file) {
    vector<khachhang> danh_sach_khach_hang;
    ifstream file(ten_file);

    if (!file.is_open()) {
        cerr << "Không the mo file!" << endl;
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
        istringstream iss(line);
        string so_dien_thoai;
        string vung;
        int so_phut;
        string thoi_gian;
        string ngay_thang;
        getline(iss, so_dien_thoai, ';');
        iss >> so_phut; iss.ignore(1);
        getline(iss, thoi_gian, ';');
        getline(iss, ngay_thang, ';');
        getline(iss, vung, ';');
        size_t pos = vung.find_last_not_of(" ");
        if (pos != string::npos) {
        vung = vung.substr(0, pos + 1);
}
        danh_sach_cuoc_goi.push_back({ so_dien_thoai, so_phut, thoi_gian, ngay_thang, vung });
    }

    file.close();
    return danh_sach_cuoc_goi;
}

void GhiKetQuaVaoFile(const vector<string>& ket_qua, const string& ten_file) {
    ofstream file(ten_file);

    if (!file.is_open()) {
        cout << "Không the mo file!" << endl;
        return;
    }

    for (const auto& kq : ket_qua) {
        file << kq << "\n";
    }

    file.close();
    cout<<"Ket qua da duoc ghi vao file ketqua.txt !"<<endl;
}
void tinhvaxuatketqua(){
    vector<khachhang> danh_sach_khach_hang;
    vector<cuocgoi> danh_sach_cuoc_goi;
    tien_dien_thoai tdt;
    vector<string> ket_qua;
    danh_sach_khach_hang = DocKhachHangTuFile("khachhang.txt");
    danh_sach_cuoc_goi = DocCuocGoiTuFile("cuocgoi.txt");
    for (const auto& khach_hang : danh_sach_khach_hang) {
        string ket_qua_dong ="Khach hang: " + khach_hang.ho_ten + ";" + " SDT: " + khach_hang.so_dien_thoai + ";";
        int so_cuoc_NH = 0, so_cuoc_LC = 0, so_cuoc_X = 0, so_cuoc_RX = 0;
        float so_tien = 0;
        for (const auto& cuoc_goi : danh_sach_cuoc_goi) {
            if (cuoc_goi.so_dien_thoai == khach_hang.so_dien_thoai) {
                so_tien += tdt.Tinh_tien_cuoc(cuoc_goi);
                if (cuoc_goi.vung == "NH") so_cuoc_NH++;
                else if (cuoc_goi.vung == "LC") so_cuoc_LC++;
                else if (cuoc_goi.vung == "X") so_cuoc_X++;
                else if (cuoc_goi.vung == "RX") so_cuoc_RX++;
            }
        }

        ket_qua_dong += + " Gia cuoc: " + to_string(so_tien) + ";" + " so cuoc goi NH: " + to_string(so_cuoc_NH) + ";" +  " so cuoc goi LC: " + to_string(so_cuoc_LC)
            + ";" +  " so cuoc goi X: " + to_string(so_cuoc_X) + ";" +  " so cuoc goi RX: " + to_string(so_cuoc_RX);

        cout<<ket_qua_dong<<endl;
        ket_qua.push_back(ket_qua_dong);
    }
    GhiKetQuaVaoFile(ket_qua,"ketqua.txt");
}
int main() {
    tinhvaxuatketqua();
    return 0;
}



