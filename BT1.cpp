#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class ThoiGian{
private:
    int gio;  
    int phut; 
    int giay;

public:
    // Khởi tạo mặc định
    ThoiGian() {
        gio =0;
        phut=0;
        giay=0;
    }

    bool kiemTraHopLe() const {
        return (gio >= 0 && gio <= 23) && 
               (chut >= 0 && chut <= 59) && 
               (giay >= 0 && giay <= 59);
    }

friend istream& operator>>(istream& in, ThoiGian& tg) {
        char c1, c2;
        in >> tg.gio >> c1 >> tg.chut >> c2 >> tg.giay;
        while (in.fail() || c1 != ':' || c2 != ':' || !tg.kiemTraHopLe()) {
            in.clear();
            in.ignore(1000, '\n');
            cout << "Thoi gian khong hop le! Vui long nhap lai (hh:mm:ss): ";
            in >> tg.gio >> c1 >> tg.chut >> c2 >> tg.giay;
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const ThoiGian& tg) {
        out << setfill('0') << setw(2) << tg.gio << ":"
            << setfill('0') << setw(2) << tg.chut << ":"
            << setfill('0') << setw(2) << tg.giay;
        return out;
    }
    ThoiGian& operator=(const ThoiGian& tg) {
        if (this != &tg) {
            gio = tg.gio;
            chut = tg.chut;
            giay = tg.giay;
        }
        return *this;
    }

int main() {
    ThoiGian tg1, tg2;
    cout << "Nhap thoi gian 1: ";
    cin >> tg1;
    cout << "Nhap thoi gian 2: ";
    cin >> tg2;
}
