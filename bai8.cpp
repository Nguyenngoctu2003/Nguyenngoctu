#include<iostream>
#include<string.h>
using namespace std;
class nguoi{
	private:
		char hoten[25];
		int namsinh;
	public:
	friend istream& operator >> ( istream& in , nguoi &a){
			cout<<"\nhap ho va ten:";
			in.getline(a.hoten,25);
			fflush(stdin);
			cout<<"\nnhap nam sinh: ";
			in>>a.namsinh;
			fflush(stdin);
				return in;
		}
		friend  ostream& operator << (ostream& out, nguoi a){
	
			cout<<"\nten: "<<a.hoten;
			cout<<"\nam sinh: "<<a.namsinh;
				return out;}
			
		
};
class tsinh : public nguoi{
	private: 
	 char sbd[10];
	
	 int toan , ly, hoa,tong;
	 public: 
	     	friend istream& operator >> ( istream& in , tsinh &a){
	     		in>>(nguoi&)a;
	     		cout<<"\nhap so bao danh : ";
	     		in.getline(a.sbd,10);
	     		fflush(stdin);
	     		cout<<"\nnhap diem toan: ";
	     		in>>a.toan;
	     		cout<<"\nnhap diem ly: ";
	     		in>>a.ly;
	     		cout<<"\nnhap diem hoa: ";
	     		in>>a.hoa;
	     		fflush(stdin);
	     		
			
			return in;}
			friend  ostream& operator << (ostream& out, tsinh a){
				out<<(nguoi)a;
				cout<<"\nso bao danh: ";
				out<<a.sbd;
				cout<<"\ndiem toan: ";
				out<<a.toan;
				cout<<"\ndiem ly: ";
				out<<a.ly;
				cout<<"\ndiem hoa: ";
				out<<a.hoa;
				return out;
		
			
			return out;
		}
		float set_tongdiem(){
			this->tong= toan+ly+hoa;
			return tong;
			
		}
		char get_sbd(){
			return sbd[10];
		}
		int get_toan(){
			return this->toan;
		}
		int get_ly(){
			return this->ly;
		}
	     int get_hoa(){
	     	return this->hoa;
		 }
};
void nhapthongtin(tsinh a[], int &n){
	for(int i=0 ; i<n ; i++){
		cout<<"\nthi sinh thu: "<<i+1<<endl;
		cin>>a[i];
	}
}
void xuatthongtin(tsinh a[], int n){
	for(int i=0; i<n; i++){
		cout<<"\nthong tin sinh vien thu: "<<i+1<<endl;
		cout<<a[i];
	}
}
void tongdiemtang(tsinh a[], int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(a[i].set_tongdiem()>a[j].set_tongdiem()){
				swap(a[i],a[j]);
			}
		}
	}
	xuatthongtin(a,n);
}
void show(tsinh a[], int n){
	for(int i=0; i<n; i++){
		if(a[i].get_sbd()){
			
			xuatthongtin(a,n);
		}
		break;
		
	}
}
float diemcao(tsinh a[], int n){
	int dem=0;
	for(int i=0; i<n; i++){
		if(a[i].get_toan()>=5 && a[i].get_ly()>=5 && a[i].get_hoa()>=5)
		dem++;
			
		}
		return dem;
	}
float tilediemcao(tsinh a[], int n){
	float tile;
	for(int i=0; i<n; i++){
		tile=((n-diemcao(a,n))*100)/n;
		return tile;		
}
}

int main(){
	int n;
	cout<<"\nnhap n thi sinh: ";cin>>n;
	fflush(stdin);
	tsinh a[n];
	cout<<"\nnhap thong tin: ";
	nhapthongtin(a,n);
	cout<<"\nxuat thong tin: ";
	xuatthongtin(a,n);
	cout<<"\ndanh sach sinh vien co tong diem 3 mon tang dan la: ";
	tongdiemtang(a,n);
	cout<<"\n1sinh vien khi biet sbd: ";
	show(a,n);
	cout<<"\nti le la:"<<tilediemcao(a,n)<<"%";
	return 0;
}

	
	
	
	
	

