#include <iostream>
#include <string.h>
#include <iomanip>	

using namespace std;
class GV{
    private:
        char ht[30];
        int t;
        char bc[15],chuyenNganh[20];
        float bl;
        float lcb;
    public:
        GV(){
            strcpy(ht, "");
            t=0;
            strcpy(bc, "");
            strcpy(chuyenNganh, "");
            bl=0;
        }
    
        void nhap(){
            cout << "Nhap ho ten: ";
            fflush(stdin);
            cin.getline(ht,30);
            cout << "Nhap tuoi: ";
            cin >> t;
            cout << "Nhap bang cap: ";
            fflush(stdin);
            cin.getline(bc,15);
            cout << "Nhap chuyen nganh: ";
            fflush(stdin);
            cin.getline(chuyenNganh,20);
            cout << "Nhap bac luong: ";
            cin >> bl;
        }
        float tinhLuong(){
           return bl*610;
        }
        void xuat(){
            cout << setw(30) << ht
                 << setw(10) << t
                 << setw(15) << bc
                 << setw(20) << chuyenNganh
                 << setw(20) << bl
                 << setw(15) << tinhLuong() << endl;
        }
        //Ph?n này em có di tham kh?o trên m?ng, vì em không bi?t l?y cái chuyenNganh private ra d? so sánh ki?u gì
        string getchuyenNganh(){
            return chuyenNganh;
        }
};
void tieuDe(){
    cout << setw(30) << "Ho va Ten" 
         << setw(10) << "Tuoi"
         << setw(15) << "Bang cap"
         << setw(20) << "Chuyen nganh"
         << setw(20) << "Bac luong"
         << setw(15) << "Luong co ban" << endl;
}
void nhapDS(GV a[], int &n){
    cout << "\nNhap danh sach " << n << " GV:\n";
    for (int i=0;i<n;i++) {
        cout << "[+] Nhap thong tin cua GV thu " << i+1 << ": \n";
        a[i].nhap();
    }
}
void xuatDS(GV a[], int n) {
    cout << "\nXuat danh sach " << n << " GV:\n";
    cout << endl;
    tieuDe();
    for (int i=0;i<n;i++) {
        a[i].xuat();
    }
}
void xuatDSbehon2000(GV a[], int n) {
    cout << "\nDanh sach cac GV co tien luong < 2000:\n";
    cout << endl;
    tieuDe();
    for (int i=0;i<n;i++) {
        if(a[i].tinhLuong()<2000) {
            a[i].xuat();
        }
    }
}
void xuatDSsausapxep(GV a[], int n) {
    cout << "\nDanh sach cac GV duoc sap xep theo chuyen nganh:\n";
    cout << endl;
    tieuDe();
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            //n?u không dùng get hay set thì l?y cái chuyenNganh ra kh?i private ki?u j ??
            if (a[i].getchuyenNganh()<a[j].getchuyenNganh()) {
                GV temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        } a[i].xuat();
    }
}
int main() { 
    int n;
    cout << "Nhap so giao vien: "; cin >> n;
    GV a[n];
    nhapDS(a,n); 
    xuatDS(a,n);
    xuatDSbehon2000(a,n);
    xuatDSsausapxep(a,n);
    return 0;
}
