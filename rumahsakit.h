#ifndef RUMAHSAKIT_H_INCLUDED
#define RUMAHSAKIT_H_INCLUDED
#include <iostream>
using namespace std;
#include <iomanip>
#include <sstream>
#define next(p) p->next
#define info(p) p->info
#define child(p) p->child

struct klinik {
    string dokter, poliklinik, ruangan;
};

struct pasien {
    string nama, nik, jk, lahir, keluhan;
    int antrian;
};

typedef struct elmKlinik *adrK;
typedef struct elmPasien *adrP;

struct elmKlinik {
    klinik info;
    adrK next;
    adrP child;
};

struct elmPasien {
    pasien info;
    adrP next;
};

struct ListKlinik {
    adrK first;
};
//1
void insertKlinik(ListKlinik &LK, adrK k); //done
adrK newKlinik(klinik kln); //done
void showKlinik(ListKlinik LK); // 2 done
adrK searchKlinik(ListKlinik LK, string poliklinik); //4 done
//6,7
void insertPasien(ListKlinik &LK, string poliklinik, adrP p); //done
adrP newPasien(pasien p); //done
void searchPasien(ListKlinik LK, string nik); //5 done
void showAllData(ListKlinik LK); //8 done
void showDataKlinik(ListKlinik LK, string poliklinik);
void deleteKlinik(ListKlinik &LK, string poliklinik); //3 1/2done
adrP searchPasienKlinik(ListKlinik &LK, string poliklinik, string nik); //9 done?
void deletePasienKlinik(ListKlinik &LK, string poliklinik); //10 1/2done
int countPasienKlinik(ListKlinik LK, string poliklinik); //11 done
int selectMenu(); //done
void createList(ListKlinik &LK); //done


#endif // RUMAHSAKIT_H_INCLUDED
