#include <iostream>
#include <string>
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

    int luongThucLinh(){
        return luongCoBan * heSoLuong + phuCap;
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
};
int main()
{
    NhanVien nv;
    nv.nhap();
    nv.xuat();
    return 0;
}
