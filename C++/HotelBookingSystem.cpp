#include <iostream>
#include <ctime>
#include <string>
#include <fstream>


using namespace std;


struct dataBase {
	char nama[100];
	char email[100], nomor[15];
	int co, ci, lama, InvoiceNO, hargaAkhir;
};

void MenuUtama();
void Fasilitas(int kode);
int generateNo();
void Order();
void displayData();
void adminPanel();
bool cariData(int bookID);
bool hapusData(int bookID);
void updateData(int bookID);


int main() {
	int kode, pilih;
	string pilihan;
	

	do
	{
		MenuUtama();
		cout << "Menu\n";
		cout << (char)192 << "[1] Pesan\n";
		cout << (char)192 << "[2] Cek Fasilitas\n";
		cout << (char)192 << "[3] Cek Pesanan\n";
		cout << (char)192 << "[4] Admin Panel\n";
		cout << (char)192 << "[5] Keluar\n";
		cout << (char)192 << "Masukan Pilihan [1-5]: ";
		cin >> pilih;
		switch (pilih)
		{
		case 1:
			MenuUtama();
			Order();
			break;
		case 2:
			MenuUtama();
			cout << "Masukan kode kamar: ";
			cin >> kode;
			Fasilitas(kode);
			break;
		case 3:
			int bookID;
			cout << "Masukan kode booking yang akan dicari: ";
			cin >> bookID;
			if (cariData(bookID) == 0)
			{
				cout << "\nData dengan kode " << bookID << " tidak ditemukan!" << endl;
			}
			break;
		case 4:
			adminPanel();
			break;
		case 5:
			exit(0);
		default:
			break;
		}

		cout << "\nKembali ke menu utama? y/n :";
		cin >> pilihan;

	} while (pilihan == "y" || pilihan == "Y");

	cout << "PROGRAM SELESAI!" << endl;

	system("pause");
	return 0;
}


void MenuUtama() {
	system("cls");
	cout << (char)201 << "======================================================================" << (char)187 << endl;
	cout << (char)186 << "                            Hotel Melati                              " << (char)186 << endl;
	cout << (char)186 << "         Jl. Prawirotaman, Kec. Mergangsan, Kota Yogyakarta.          " << (char)186 << endl;
	cout << (char)200 << "======================================================================" << (char)188 << endl;
	cout << "Kode\t\t\tTipe Kamar\t\t\tHarga(harian)\n";
	cout << "1\t\t\tStandart Room\t\t\t100000\n";
	cout << "2\t\t\tDeluxe Room\t\t\t150000\n";
	cout << "3\t\t\tSuite Room\t\t\t250000\n";
	cout << "======================================================================\n";
}

void Fasilitas(int kode) {
	switch (kode)
	{
	case 1:
		cout << (char)201 << "================================================================================================" << (char)187 << endl;
		cout << " Tipe kamar standar\n";
		cout << " Tipe kasur\tBreakfast\tUkuran kamar\tJumlah tamu\tFasilitas Tambahan\n";
		cout << " Single Bed\tTidak\t\t20m\t\t2\t\t - \n";
		cout << " Fasilitas semua kamar: TV, AC, Private Bath Room, Wellcome Drink, WiFi dengan kecepatan 150 Mbps" << endl;
		cout << (char)200 << "================================================================================================" << (char)188 << endl;
		break;
	case 2:
		cout << (char)201 << "================================================================================================" << (char)187 << endl;
		cout << " Tipe kamar deluxe\n";
		cout << " Tipe kasur\tBreakfast\tUkuran kamar\tJumlah tamu\tFasilitas Tambahan\n";
		cout << " Double Bed\tYa\t\t25m\t\t2\t\tBalkon \n";
		cout << " Fasilitas semua kamar: TV, AC, Private Bath Room, Wellcome Drink, WiFi dengan kecepatan 150 Mbps" << endl;
		cout << (char)200 << "================================================================================================" << (char)188 << endl;
		break;
	case 3:
		cout << (char)201 << "================================================================================================" << (char)187 << endl;
		cout << " Tipe kamar suite\n";
		cout << " Tipe kasur\tBreakfast\tUkuran kamar\tJumlah tamu\tFasilitas Tambahan\n";
		cout << " Double Bed\tYa\t\t25m\t\t2\t\tPrivate Pool \n";
		cout << " Fasilitas semua kamar: TV, AC, Private Bath Room, Wellcome Drink, WiFi dengan kecepatan 150 Mbps" << endl;
		cout << (char)200 << "================================================================================================" << (char)188 << endl;
		break;
	default:
		cout << "Pilihan tidak tersedia!\n";
		break;
	}
}

int generateNo() {
	int random;
	do
	{
		srand(time(NULL));
		random = rand() % 1000 + 1;

	} while (cariData(random) == 1);

	return random;
}

void Order() {
	ifstream readData;
	ofstream writeData;
	string pilihan, kamar, email;
	int uang, kembali, harga, jml_harga, kode;
	dataBase db;
	
	order:
	cin.ignore();
	cout << "Masukan Detail customer\n";
	cout << "Nama Tamu\t: ";
	cin.getline(db.nama, 100);
	cout << "Nomor handphone : ";
	cin >> db.nomor;
	cout << "Email\t\t: ";
	cin >> db.email;
	cout << "\nMasukan Detail Pesanan\n";
	cout << "Kode kamar\t\t: ";
	cin >> kode;
	if (kode == 1)
	{
		harga = 100000;
		kamar = "Standart Room";
	}
	else if (kode == 2)
	{
		harga = 150000;
		kamar = "Deluxe Room";
	}
	else if (kode == 3)
	{
		harga = 250000;
		kamar = "Suite Room";
	}
	else
	{
		cout << "Kamar tidak tersedia!\n";
		cout << "Ingin kembali pesan kamar? y/n : ";
		cin >> pilihan;
		if (pilihan == "y" || pilihan == "Y")
		{
			MenuUtama();
			goto order;
		}
		else
		{
			exit(0);
		}

	}
	cout << "Tipe kamar\t\t: " << kamar << endl;
	cout << "Tanggal Cek In (YYYYMMDD) : ";
	cin >> db.ci;
	cout << "Tanggal Cek Out (YYYYMMDD): ";
	cin >> db.co;
	db.lama = db.co - db.ci;
	if (db.lama >= 31 || db.lama <= 0)
	{
		cout << "Kamar kosong!!!\n";
		system("pause");
		MenuUtama();
		goto order;
	}
	cout << "Lama menginap\t\t: " << db.lama << endl;
	jml_harga = db.lama * harga;
	int pajak = jml_harga/10;
	db.hargaAkhir = pajak + jml_harga;
	cout << "pajak 10%\t\t: " << pajak << endl;
	cout << "Total harga\t\t: " << db.hargaAkhir << endl;
	uang:
	cout << "Uang\t\t\t: ";
	cin >> uang;
	kembali = uang - db.hargaAkhir;
	if (kembali < 0)
	{
		cout << "Uang anda kurang!" << endl;
		goto uang;
	}
	cout << "Kembalian\t\t: " << kembali << endl;
	cout << "Apakah data sudah benar? y/n: ";
	cin >> pilihan;
	if (pilihan == "y")
	{
		db.InvoiceNO = generateNo();
		system("cls");
		writeData.open("database.dat", ios::binary | ios::app);
		writeData.write((char*)&db, sizeof(db));
		cout << "======================================================================\n";
		cout << "                            Hotel Melati                              \n";
		cout << "         Jl. Prawirotaman, Kec. Mergangsan, Kota Yogyakarta.          \n\n";
		cout << "Invoice                                               Booking No." << db.InvoiceNO << endl;
		cout << "======================================================================\n";
		cout << "Detail customer\n";
		cout << "Nama\t\t: " << db.nama << endl;
		cout << "Nomor Handphone\t: " << db.nomor << endl;
		cout << "Email\t\t: " << db.email << endl;
		cout << "----------------------------------------------------------------------\n\n";
		cout << "Detail Pesanan\n";
		cout << "Tipe kamar\t: " << kamar << endl;
		cout << "Tanggal Cek In\t: " << db.ci << endl;
		cout << "Tanggal Cek Out\t: " << db.co << endl;
		cout << "Lama\t\t: " << db.lama << " Hari\n" << endl;
		cout << "Total\n";
		cout << "----------------------------------------------------------------------\n";
		cout << "Total harga : " << jml_harga << "\tPajak 10% : " << pajak << "\tTotal Bayar : " << db.hargaAkhir << endl;
		cout << "----------------------------------------------------------------------\n";
		cout << "*1 kamar maksimal 2 tamu" << endl;
		cout << "*Check In diatas jam 14:00 - 18:00, Check Out jam 00:00 - 12:00\n";
		cout << "\n           ***Terimakasih Pembayaran telah diterima!***\n";
		writeData.close();
	}
	else
	{
		goto order;
	}
}

void displayData() {
	ifstream readData;
	dataBase db;
	int pendapatan = 0, i = 0;

	readData.open("database.dat", ios::binary);
	system("cls");
	cout << endl;
	cout << (char)201 <<"===================================DATABASE HOTEL MELATI========================================" << (char)187 << endl;
	cout << " kode booking\tnama\t\t\tnomor\t\tCheckIn\t\tCheckOut\tTotal" << endl;
	while (readData.read((char*)&db, sizeof(db)))
	{

		cout << ' ' << db.InvoiceNO << "\t\t" << db.nama << "\t\t" << db.nomor << "\t" << db.ci << "\t" << db.co << "\t" << db.hargaAkhir << endl;
		pendapatan += db.hargaAkhir;
		i++;
	}
	readData.close();
	cout << endl;
	cout << " Total pendapatan = " << pendapatan << "\t" << "Total pesanan = " << i << endl;
	cout << (char)200 <<"================================================================================================" << (char)188 << endl;
}

void adminPanel() {
	int pilih, bookID;
	string inputKode, pilihan;
	string aksesKode = "admin";
	
	system("cls");
	cout << "Akses kode diperlukan: ";
	cin >> inputKode;
	if (inputKode == aksesKode)
	{
		do
		{
			system("cls");
			cout << (char)201 << "====================================================================" << (char)187 << endl;
			cout << (char)186 << "                      PANEL ADMIN HOTEL MELATI                      " << (char)186 << endl;
			cout << (char)200 << "====================================================================" << (char)188 << endl;
			cout << "Menu" << endl;
			cout << (char)192 << "[1] Lihat semua data" << endl;
			cout << (char)192 << "[2] Update data" << endl;
			cout << (char)192 << "[3] Cari data" << endl;
			cout << (char)192 << "[4] Hapus data" << endl;
			cout << (char)192 << "[5] Keluar" << endl;
			cout << "Masukan pilihan [1-5]: ";
			cin >> pilih;
			switch (pilih)
			{
			case 1:
				displayData();
				break;
			case 2:
				cout << "Hanya customer detail yang dapat diupdate!";
				cout << "Masukan kode booking yang akan diupdate: ";
				cin >> bookID;
				updateData(bookID);
				break;
			case 3:
				cout << "Masukan kode booking yang akan dicari: ";
				cin >> bookID;
				if (cariData(bookID) == 0)
				{
					cout << endl;
					cout << "Kode booking " << bookID << " tidak terdapat dalam database!" << endl;
				}
				break;
			case 4:
				cout << "Masukan kode booking yang akan dihapus: ";
				cin >> bookID;
				hapusData(bookID);
				break;
			case 5:
				exit(0);
			default:
				cout << "Pilihan anda tidak tersedia!!" << endl;
				break;
			}
			cout << "\nKembali ke menu admin? y/n: ";
			cin >> pilihan;
		} while (pilihan == "y" || pilihan == "Y");
		
	}
	else
	{
		cout << "Kode akses salah!";
	}
}

bool cariData(int bookID) {

	ifstream readData;
	dataBase db;
	bool cek = 0;

	readData.open("database.dat", ios::binary);

	while (readData.read((char*)&db, sizeof(db)))
	{
		if (db.InvoiceNO == bookID)
		{
			cout << endl;
			cout << (char)201 << "========================================HOTEL MELATI============================================" << (char)187 << endl;
			cout << " kode booking\tnama\t\t\tnomor\t\tCheckIn\t\tCheckOut\tTotal" << endl;
			cout << ' ' << db.InvoiceNO << "\t\t" << db.nama << "\t\t" << db.nomor << "\t" << db.ci << "\t" << db.co << "\t" << db.hargaAkhir << endl;
			cout << (char)200 << "================================================================================================" << (char)188 << endl;
			cek = 1;
		}

	}
	readData.close();
	return cek;
}

bool hapusData(int bookID) {
	ifstream readData;
	ofstream writeData;
	dataBase db;
	int rm, rn;
	bool cek = false;

	if (cariData(bookID) == 1)
	{
		readData.open("database.dat", ios::binary);
		while (readData.read((char*)&db, sizeof(db)))
		{

			if (db.InvoiceNO != bookID)
			{
				writeData.open("temp.dat", ios::binary | ios::app);
				writeData.write((char*)&db, sizeof(db));
				writeData.close();
			}
		}

		readData.close();
		rm = remove("database.dat");
		rn = rename("temp.dat", "database.dat");
		if (rm != 0 && rn != 0)
		{
			cout << "\nAda masalah pada database!" << endl;
		}
		else
		{
			cout << "\nData sukses dihapus!" << endl;
			cek = true;
		}
	}
	else
	{
		cout << "\nData gagal dihapus!" << endl;
		cout << "Kode booking " << bookID << " tidak terdapat dalam database!" << endl;
	}
	
	return cek;
}

void updateData(int bookID) {
	ifstream readData;
	ofstream writeData;
	dataBase db;


	if (cariData(bookID) == 1) {
		readData.open("database.dat", ios::binary);
		while (readData.read((char*)&db, sizeof(db)))
		{

			if (db.InvoiceNO == bookID)
			{
				writeData.open("temp.dat", ios::binary | ios::app);
				db.InvoiceNO = bookID;
				db.ci = db.ci;
				db.co = db.co;
				db.hargaAkhir = db.hargaAkhir;
				cin.ignore();
				cout << "Nama: ";
				cin.getline(db.nama, 100);
				cout << "Nomor: ";
				cin >> db.nomor;
				cout << "Email: ";
				cin >> db.email;
				writeData.write((char*)&db, sizeof(db));
				writeData.close();
			}
			else
			{
				writeData.open("temp.dat", ios::binary | ios::app);
				writeData.write((char*)&db, sizeof(db));
				writeData.close();
			}	
		}
		readData.close();
		bool rm = remove("database.dat");
		bool rn = rename("temp.dat", "database.dat");
		if (rn == 0 && rm == 0)
		{
			cout << "Data sukses diupdate!" << endl;
		}
		else
		{
			cout << "Data gagal diupdate!" << endl;
		}	
	}
	else
	{
		cout << endl;
		cout << "Kode booking " << bookID << " tidak terdapat dalam database" << endl;
	}
}
