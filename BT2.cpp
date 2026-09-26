#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class NhanVien{
private:
    string maNV;
    string hoTen;
    int luongCoBan;
    int heSoLuong;
    int phuCap;

public:
    NhanVien(){
        maNV = "";
        hoTen = "";
        luongCoBan = 0;
        heSoLuong = 0;
        phuCap = 0;
    }
    NhanVien(string maNV, string hoTen, int luongCoBan, int heSoLuong, int phuCap){
        this->maNV = maNV;
        this->hoTen = hoTen;
        this->luongCoBan = luongCoBan;
        this->heSoLuong = heSoLuong;
        this->phuCap = phuCap;
    }

    long long luongThucLinh() const {
        long long baoHiem = 0.105 * (luongCoBan * heSoLuong);
        return luongCoBan * heSoLuong + phuCap - baoHiem;
    }

    // xếp loại thu nhập
    string xepLoaiThuNhap() const {
    double luong = luongThucLinh();
    if (luong < 7000000) return "Thap";
    if (luong <= 15000000) return "Trung binh";
    if (luong <= 25000000) return "Kha";
    return "Cao";
}

    void nhap(){
        cout << "Nhap Ma NV: ";
        cin >> maNV;
        cout << "Nhap Ho va Ten: ";
        cin >> hoTen;
        cout << "Nhap Luong Co Ban: ";
        cin >> luongCoBan;
        cout << "Nhap He So Luong: ";
        cin >> heSoLuong;
        cout << "Nhap Phu Cap: ";
        cin >> phuCap;
    }
    void xuat(){
        cout << "Ma NV: " << maNV << endl;
        cout << "Ho Ten: " << hoTen << endl;
        cout << "Luong Co Ban: " << luongCoBan << endl;
        cout << "He So Luong: " << heSoLuong << endl;
        cout << "Phu Cap: " << phuCap << endl;
        cout << "Tong Luong: " << luongThucLinh() << endl;
    }
    
    //Chồng toán tử nhập (>>)
    friend istream& operator >>(istream& in, NhanVien& nv) {
        cout << "Nhap ma NV: ";
        in >> nv.maNV;
        in.ignore(); 
        cout << "Nhap ho ten: ";
        getline(in, nv.hoTen);
        cout << "Nhap luong co ban: ";
        in >> nv.luongCoBan;
        cout << "Nhap he so luong: ";
        in >> nv.heSoLuong;
        cout << "Nhap phu cap: ";
        in >> nv.phuCap;
        return in;
    }

    friend ostream& operator<<(ostream& out, const NhanVien& nv) {
        out <<"mã nv"<<"\t"<<"họ tên"<<"\t"<<"lương CBan"<<"\t"<<"HSo Lương"<<"\t"<<"phụ cấp"<<"\t"<<"lương tổng"<<"\t"<<"xếp loại"<<"\t\n"
            << nv.maNV << "\t"
            << nv.hoTen << "\t"
            << nv.luongCoBan << "\t"
            << nv.heSoLuong << "\t"
            << nv.phuCap << "\t"
            << nv.luongThucLinh() << "\t"
            << nv.xepLoaiThuNhap() << "\t";
        return out;
    }

    // Chồng toán tử gán 
    NhanVien& operator=(const NhanVien& nv) {
        if (this != &nv) {
            maNV = nv.maNV;
            hoTen = nv.hoTen;
            luongCoBan = nv.luongCoBan;
            heSoLuong = nv.heSoLuong;
            phuCap = nv.phuCap;
        }
        return *this;
    }
};
int main()
{
    NhanVien nv;
    nv.nhap();
    nv.xuat();
    nv.xepLoaiThuNhap();
    cout<<nv;
    cin>>nv;
    return 0;
}
