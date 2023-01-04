#include "rumahsakit.h"

int main()
{
    ListKlinik LK;
    createList(LK);
    klinik kk;
    pasien pp;
    adrP p;
    string poli, lahir, nik;
    int pilihan, intantri;
    pilihan = selectMenu();
    cout<<endl;
    while (pilihan != 0){
        switch(pilihan){
        case 1:
            cout<<endl<<"==========Poliklinik Baru=========="<<endl;
            cout<<"Poliklinik: ";
            getline(cin, kk.poliklinik);
            cout<<"Dokter: ";
            getline(cin, kk.dokter);
            cout<<"Ruangan: ";
            getline(cin, kk.ruangan);
            insertKlinik(LK, newKlinik(kk));
            break;
        case 2:
            cout<<endl<<"=============Pasien Baru============="<<endl;
            cout<<"Nama: ";
            getline(cin, pp.nama);
            cout<<"NIK: ";
            getline(cin, pp.nik);
            cout<<"Tanggal Lahir: ";
            getline(cin, pp.lahir);
            cout<<"Jenis Kelamin: ";
            getline(cin, pp.jk);
            cout<<"Keluhan: ";
            getline(cin, pp.keluhan);
            cout<<"Klinik: ";
            getline(cin, poli);
            insertPasien(LK, poli, newPasien(pp));
            break;
        case 3:
            showAllData(LK);
            break;
        case 4:
            showKlinik(LK);
            break;
        case 6:
            showKlinik(LK);
            cout<<endl<<"Poliklinik yang dihapus: ";
            getline(cin, poli);
            deleteKlinik(LK, poli);
            break;
        case 5:
            cout<<endl<<"========Data Sebuah Klinik========"<<endl;
            cout<<"Poliklinik: ";
            getline(cin, poli);
            showDataKlinik(LK, poli);
            break;
        case 8:
            cout<<endl<<"=============Cari Pasien Klinik============="<<endl;
            cout<<"Poliklinik: ";
            getline(cin, poli);
            cout<<"NIK pasien: ";
            getline(cin, nik);
            p = searchPasienKlinik(LK, poli, nik);
            if (p != NULL){
                cout<<left<<setw(20)<<setfill(' ')<<"No.";
                cout<<left<<setw(20)<<setfill(' ')<<"Nama";
                cout<<left<<setw(20)<<setfill(' ')<<"NIK";
                cout<<left<<setw(20)<<setfill(' ')<<"Tgl. Lahir";
                cout<<left<<setw(20)<<setfill(' ')<<"Jenis Kelamin";
                cout<<left<<setw(20)<<setfill(' ')<<"Keluhan"<<endl;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).antrian;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).nama;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).nik;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).lahir;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).jk;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).keluhan<<endl;
            } else {
                cout<<"Tidak ditemukan"<<endl;
            }
            break;
        case 7:
            cout<<endl<<"========Pasien Terdepan Selesai========"<<endl;
            cout<<"Poliklinik pasien yang sudah selesai: ";
            getline(cin, poli);
            deletePasienKlinik(LK, poli);
            showDataKlinik(LK, poli);
            break;
        case 9:
            cout<<endl<<"=============Cari Pasien============="<<endl;
            cout<<"NIK: ";
            getline(cin, nik);
            searchPasien(LK, nik);
            break;
        case 10:
            cout<<endl<<"========Banyak Antrian Klinik========"<<endl;
            cout<<"Poliklinik: ";
            getline(cin, poli);
            cout<<countPasienKlinik(LK, poli)<<" antrian"<<endl;
            break;

        }
        cout<<endl;
        string balik;
        cout<<"Kembali ke menu utama? (Y/N) : ";
        getline(cin, balik);
        if (balik == "Y" || balik == "y"){
            pilihan = selectMenu();
        } else {
            pilihan = 0;
        }

    }
    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;
    return 0;
}
