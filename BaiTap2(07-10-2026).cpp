#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// CÂU 1:
struct NhanVien {
    int maNV;
    string hoTen;
    string ngaySinh;
    double luong;
};

void inTieuDe() {
    cout << left 
         << setw(10) << "Ma NV" 
         << setw(25) << "Ho va ten" 
         << setw(15) << "Ngay sinh" 
         << setw(20) << "Luong (Trieu VNÐ)" << endl;
    cout << string(70, '-') << endl;
}

void xuatNhanVien(const NhanVien& nv) {
    cout << left 
         << setw(10) << nv.maNV 
         << setw(25) << nv.hoTen 
         << setw(15) << nv.ngaySinh 
         << setw(20) << nv.luong << endl;
}

// CÂU 2:
void nhapDanhSach(vector<NhanVien>& ds, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        NhanVien nv;
        cout << "Ma nhan vien: ";
        cin >> nv.maNV;
        cin.ignore();

        cout << "Ho va ten: ";
        getline(cin, nv.hoTen);

        cout << "Ngay sinh: ";
        getline(cin, nv.ngaySinh);

        cout << "Luong (trieu dong): ";
        cin >> nv.luong;

        ds.push_back(nv);
    }
}

// CÂU 3:
void xuatDanhSach(const vector<NhanVien>& ds) {
    if (ds.empty()) {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    inTieuDe();
    for (size_t i = 0; i < ds.size(); i++) {
        xuatNhanVien(ds[i]);
    }
}

// CÂU 4:
void bubbleSort(vector<NhanVien>& ds) {
    int n = ds.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].luong > ds[j + 1].luong) {
                NhanVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// CÂU 5:
void timKiemNhiPhanTheoLuong(const vector<NhanVien>& ds, double X) {
    int left = 0;
    int right = ds.size() - 1;
    int foundIdx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].luong == X) {
            foundIdx = mid;
            break;
        }
        if (ds[mid].luong < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (foundIdx == -1) {
        cout << "\nKhong tim thay nhan vien nao co luong bang " 
             << X << " trieu dong." << endl;
        return;
    }

    int start = foundIdx;
    while (start > 0 && ds[start - 1].luong == X) {
        start--;
    }

    int end = foundIdx;
    while (end < (int)ds.size() - 1 && ds[end + 1].luong == X) {
        end++;
    }

    cout << "\n=== KET QUA TIM KIEM NHAN VIEN CO LUONG = " 
         << X << " TRIEU DONG ===" << endl;
    inTieuDe();
    for (int i = start; i <= end; i++) {
        xuatNhanVien(ds[i]);
    }
}

// CÂU 6:
int main() {
    int n;
    cout << "Nhap so luong nhan vien n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong nhan vien phai lon hon 0!" << endl;
        return 0;
    }

    vector<NhanVien> dsNhanVien;

    nhapDanhSach(dsNhanVien, n);
    cout << "\n================ DANH SACH VUA NHAP ================" << endl;
    xuatDanhSach(dsNhanVien);

    bubbleSort(dsNhanVien);
    cout << "\n======== DANH SACH SAU KHI SAP XEP (BUBBLE SORT) ========" << endl;
    xuatDanhSach(dsNhanVien);

    double X;
    cout << "\nNhap muc luong X can tim (trieu dong): ";
    cin >> X;
    timKiemNhiPhanTheoLuong(dsNhanVien, X);

    return 0;
}
