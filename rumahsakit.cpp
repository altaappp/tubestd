#include "rumahsakit.h"

void createList(ListKlinik &LK){
    LK.first = NULL;
}

adrK newKlinik(klinik kln){
    adrK k = new elmKlinik;
    info(k).dokter = kln.dokter;
    info(k).poliklinik = kln.poliklinik;
    info(k).ruangan = kln.ruangan;
    next(k) = NULL;
    child(k) = NULL;
    return k;
}

adrP newPasien(pasien psn){
    adrP p = new elmPasien;
    info(p).nama = psn.nama;
    info(p).nik = psn.nik;
    info(p).jk = psn.jk;
    info(p).keluhan = psn.keluhan;
    info(p).antrian = 0;
    info(p).lahir = psn.lahir;
    next(p) = NULL;
    return p;
}

void insertKlinik(ListKlinik &LK, adrK k){
    if (LK.first == NULL){
        LK.first = k;
    } else {
        adrK q = LK.first;
        while (next(q) != NULL){
            q = next(q);
        }
        next(q) = k;
    }
}

adrK searchKlinik(ListKlinik LK, string poliklinik){
    adrK k = LK.first;
    while (k != NULL){
        if (info(k).poliklinik == poliklinik){
            return k;
        }
        k = next(k);
    }
    if (k == NULL){
        return k;
    }
}

void showKlinik(ListKlinik LK){
    adrK k = LK.first;
    int i = 1;
    if (k != NULL){
        cout<<"==================Poliklinik=================="<<endl;
        cout<<left<<setw(20)<<setfill(' ')<<"No.";
        cout<<left<<setw(20)<<setfill(' ')<<"Klinik";
        cout<<left<<setw(20)<<setfill(' ')<<"Dokter";
        cout<<left<<setw(20)<<setfill(' ')<<"Ruangan"<<endl;
        while (k != NULL){
            cout<<left<<setw(20)<<setfill(' ')<<i;
            cout<<left<<setw(20)<<setfill(' ')<<info(k).poliklinik;
            cout<<left<<setw(20)<<setfill(' ')<<info(k).dokter;
            cout<<left<<setw(20)<<setfill(' ')<<info(k).ruangan<<endl;
            i++;
            k = next(k);
        }
    } else {
        cout<<"Kosong"<<endl;
    }
}

void showAllData(ListKlinik LK){
    if (LK.first != NULL){
        adrK k = LK.first;
        while (k != NULL){
            cout<<"==============================Polilinik "<<info(k).poliklinik<<"=============================="<<endl;
            cout<<left<<setw(25)<<setfill(' ')<<"Klinik";
            cout<<left<<setw(20)<<setfill(' ')<<"Dokter";
            cout<<left<<setw(20)<<setfill(' ')<<"Ruangan"<<endl;
            if (k != NULL){
                cout<<left<<setw(25)<<setfill(' ')<<info(k).poliklinik;
                cout<<left<<setw(20)<<setfill(' ')<<info(k).dokter;
                cout<<left<<setw(20)<<setfill(' ')<<info(k).ruangan<<endl;
                adrP p = child(k);
                if (p != NULL){
                    cout<<"-----------------------------Daftar Pasien-----------------------------"<<endl;
                    cout<<left<<setw(20)<<setfill(' ')<<"No.";
                    cout<<left<<setw(30)<<setfill(' ')<<"Nama";
                    cout<<left<<setw(20)<<setfill(' ')<<"NIK";
                    cout<<left<<setw(20)<<setfill(' ')<<"Tgl. Lahir";
                    cout<<left<<setw(20)<<setfill(' ')<<"Jenis Kelamin";
                    cout<<left<<setw(30)<<setfill(' ')<<"Keluhan"<<endl;
                    while (p != NULL){
                        cout<<left<<setw(20)<<setfill(' ')<<info(p).antrian;
                        cout<<left<<setw(30)<<setfill(' ')<<info(p).nama;
                        cout<<left<<setw(20)<<setfill(' ')<<info(p).nik;
                        cout<<left<<setw(20)<<setfill(' ')<<info(p).lahir;
                        cout<<left<<setw(20)<<setfill(' ')<<info(p).jk;
                        cout<<left<<setw(30)<<setfill(' ')<<info(p).keluhan<<endl;
                        p = next(p);
                    }
                    cout<<endl;
                }
            }
            k = next(k);
        }
    } else {
        cout<<"Data kosong"<<endl;
    }
}

void insertPasien(ListKlinik &LK, string poliklinik, adrP p){
    adrK k = searchKlinik(LK, poliklinik);
    if (k != NULL){
        if (child(k) == NULL){
            child(k) = p;
            info(p).antrian++;
        } else {
            adrP q = child(k);
            while (next(q) != NULL){
                q = next(q);
            }
            next(q) = p;
            info(p).antrian = info(q).antrian + 1;
        }
    }
}

int countPasienKlinik(ListKlinik LK, string poliklinik){
    adrK k = searchKlinik(LK, poliklinik);
    int total = 0;
    adrP p = child(k);
    while (p != NULL){
        total++;
        p = next(p);
    }
    return total;
}

void searchPasien(ListKlinik LK, string nik){
    adrK k = LK.first;
    adrP p;
    int i = 1;
    while (k != NULL){
        p = child(k);
        while (p != NULL){
            if (info(p).nik == nik){
                cout<<"==================Poliklinik "<<info(k).poliklinik<<"=================="<<endl;
                cout<<"---------------------------Daftar Pasien---------------------------"<<endl;
                cout<<left<<setw(20)<<setfill(' ')<<"No.";
                cout<<left<<setw(20)<<setfill(' ')<<"Nama";
                cout<<left<<setw(20)<<setfill(' ')<<"NIK";
                cout<<left<<setw(20)<<setfill(' ')<<"Tgl. Lahir";
                cout<<left<<setw(20)<<setfill(' ')<<"Jenis Kelamin"<<endl;
                cout<<left<<setw(20)<<setfill(' ')<<i;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).nama;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).nik;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).lahir;
                cout<<left<<setw(20)<<setfill(' ')<<info(p).jk<<endl;
                i++;
            }
            p = next(p);
        }
        k = next(k);
    }
}

void deleteKlinik(ListKlinik &LK, string poliklinik){
    adrK k = searchKlinik(LK, poliklinik);
    if (k != NULL){
        if (k == LK.first){
            LK.first = next(k);
            next(k) = NULL;
            child(k) = NULL;
        } else if (next(k) == NULL){
            adrK p = LK.first;
            while (next(next(p)) != NULL){
                p = next(p);
            }
            next(p) = NULL;
        } else {
            adrK p = LK.first;
            while (next(p) != k){
                p = next(p);
            }
            next(p) = next(k);
            next(k) = NULL;
        }
    }
}

adrP searchPasienKlinik(ListKlinik &LK, string poliklinik, string nik){
    adrK k = searchKlinik(LK, poliklinik);
    if (k != NULL){
        if (child(k) != NULL){
            adrP p = child(k);
            while (p != NULL){
                if (info(p).nik == nik){
                    return p;
                }
                p = next(p);
            }
            if (p == NULL){
                return p;
            }
        }
    }
}

void deletePasienKlinik(ListKlinik &LK, string poliklinik){
    adrK k = searchKlinik(LK, poliklinik);
    if (k != NULL){
        if (child(k) != NULL){
            adrP p = child(k);
            child(k) = next(p);
            next(p) = NULL;
        }
    }
}

void showDataKlinik(ListKlinik LK, string poliklinik){
    adrK k = searchKlinik(LK, poliklinik);
    if (k != NULL){
        cout<<"==============================Polilinik "<<info(k).poliklinik<<"=============================="<<endl;
        cout<<left<<setw(20)<<setfill(' ')<<"Dokter";
        cout<<left<<setw(20)<<setfill(' ')<<"Ruangan"<<endl;
        cout<<left<<setw(20)<<setfill(' ')<<info(k).dokter;
        cout<<left<<setw(20)<<setfill(' ')<<info(k).ruangan<<endl;
        adrP p = child(k);
            if (p != NULL){
                cout<<"---------------------------Daftar Pasien---------------------------"<<endl;
                cout<<left<<setw(20)<<setfill(' ')<<"No.";
                cout<<left<<setw(30)<<setfill(' ')<<"Nama";
                cout<<left<<setw(20)<<setfill(' ')<<"NIK";
                cout<<left<<setw(20)<<setfill(' ')<<"Tgl. Lahir";
                cout<<left<<setw(20)<<setfill(' ')<<"Jenis Kelamin";
                cout<<left<<setw(30)<<setfill(' ')<<"Keluhan"<<endl;
                while (p != NULL){
                    cout<<left<<setw(20)<<setfill(' ')<<info(p).antrian;
                    cout<<left<<setw(30)<<setfill(' ')<<info(p).nama;
                    cout<<left<<setw(20)<<setfill(' ')<<info(p).nik;
                    cout<<left<<setw(20)<<setfill(' ')<<info(p).lahir;
                    cout<<left<<setw(20)<<setfill(' ')<<info(p).jk;
                    cout<<left<<setw(30)<<setfill(' ')<<info(p).keluhan<<endl;
                    p = next(p);
                }
        }
    } else if (k == NULL){
        cout<<"Tidak ditemukan"<<endl;
    }
}

int selectMenu(){
    cout<<"==================MENU=================="<<endl;
    cout<<"[1] Polilinik baru"<<endl;
    cout<<"[2] Pasien baru"<<endl;
    cout<<"[3] Tampilkan data semua klinik"<<endl;
    cout<<"[4] Tampilkan semua klinik"<<endl;
    cout<<"[5] Tampilkan data suatu klinik"<<endl;
    cout<<"[6] Hapus suatu klinik"<<endl;
    cout<<"[7] Hapus antrian terdepan suatu klinik"<<endl;
    cout<<"[8] Cari pasien suatu klinik"<<endl;
    cout<<"[9] Cari pasien dari seluruh data"<<endl;
    cout<<"[10] Banyak antrian suatu klinik"<<endl;
    cout<<"[0] EXIT"<<endl;
    cout<<"Masukkan Menu : ";

    string input;
    int inputint;
    getline(cin, input);
    stringstream obj;
    obj << input;
    obj >> inputint;

    return inputint;
}
