#include<bits/stdc++.h>
using namespace std;

class KhachHang {
public:
    string hoTen;
    string soDienThoai;
};

class cuocgoi {
public:
    string soDienThoai;
    int soPhut;
    string thoiGian;
    string ngayThang;
    string vung;
};

class TinhTienDienThoai {
public:
    float GIA_CO_BAN = 1100;
    float HE_SO_MIEN_NH = 1;
    float HE_SO_MIEN_LC = 2;
    float HE_SO_MIEN_X = 3;
    float HE_SO_MIEN_RX = 4;

    float tinhTienCuoc(const CuocGoi& cuocGoi) {
        // Code c?a b?n...
    }
};

map<string, KhachHang> docKhachHangTuFile(const string& tenFile) {
    map<string, KhachHang> danhSachKhachHang;
    ifstream file(tenFile);
    
    if (!file.is_open()) {
        cerr << "Không th? m? file!" << endl;
        return danhSachKhachHang;
    }
    
    string dong;
    while (getline(file, dong)) {
        istringstream iss(dong);
        string hoTen, soDienThoai;
        getline(iss, hoTen, ';');
        getline(iss, soDienThoai, ';');
        danhSachKhachHang[soDienThoai] = {hoTen, soDienThoai};
    }
    
    file.close();
    return danhSachKhachHang;
}

vector<cuocgoi> docCuocGoiTuFile(const string& ten_File) {
    vector<cuocgoi> danh_sach_cuoc_goi;
    ifstream file(ten_file);

    if (!file.is_open()) {
        cout << "Không th? m? file!" << endl;
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

void ghiKetQuaVaoFile(const map<string, float>& ketQua, const string& tenFile) {
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
void xuly(){
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
    // Ð?c d? li?u t? file
    map<string, KhachHang> danhSachKhachHang = docKhachHangTuFile("khachhang.txt");
    vector<CuocGoi> danhSachCuocGoi = docCuocGoiTuFile("cuocgoi.txt");

    // Tính ti?n di?n tho?i cho m?i khách hàng
    TinhTienDienThoai tinhTienDienThoai;
    map<string, float> ketQua;
    for (const auto& khachHang : danhSachKhachHang) {
        float tongTien = 0;
        for (const auto& cuocGoi : danhSachCuocGoi) {
            if (cuocGoi.soDienThoai == khachHang.second.soDienThoai) {
                tongTien += tinhTienDienThoai.tinhTienCuoc(cuocGoi);
            }
        }
        ketQua[khachHang.second.soDienThoai] = tongTien;
    }

    // Ghi k?t qu? vào file
    ghiKetQuaVaoFile(ketQua, "ketqua.txt");

    return 0;
}


