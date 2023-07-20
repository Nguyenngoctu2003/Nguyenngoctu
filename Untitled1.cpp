#include<iostream>
using namespace std;

class Sothuc{
	private:
		int ts, ms;
	public:
	void nhap(){
		cout<<"Nhap tu so: "; cin>>ts;
		cout<<"Nhap mau so: "; cin>>ms;
		while(ms==0){
			cout<<"Nhap mau so khac 0: "; cin>>ms;
		}
	}
	void xuat(){
		cout<<"Ket qua: "<<ts<<"/"<<ms<<endl;
	}
};

int main()
{
	Sothuc a;
	a.nhap();
	a.xuat();
	return 0;
}
