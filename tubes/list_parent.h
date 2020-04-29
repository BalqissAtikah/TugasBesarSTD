#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#define info_parent(P) P->info_parent
#define next_parent(P) P->next_parent
#define prev_parent(P) P->prev_parent
#define first_parent(L) L.first_parent
#define ke_parent(P) P->ke_parent

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

struct parent {
    int ID;
    string nama, sma, jenis_kelamin, jalur_masuk, jurusan_sma;
    int tahun_masuk, sumbangan;
};

typedef struct elmList_parent *address_parent;

struct elmList_parent{
    parent info_parent;
    address_parent next_parent;
    address_parent prev_parent;
};

struct List_parent{
    address_parent first_parent;
};

void createList_parent(List_parent &LP);
address_parent newElement_parent(parent x);
void deallocate_parent(address_parent &P);
address_parent input_parent(List_parent LP);//Wahyu Hauzan Rafi(1301191313)
void insertFirst_parent(List_parent &LP, address_parent P);
void insertAfter_parent(List_parent &LP, address_parent Prec, address_parent P);
void insertLast_parent(List_parent &LP, address_parent P);
void deleteFirst_parent(List_parent &LP, address_parent &P);
void deleteAfter_parent(List_parent &LP, address_parent Prec, address_parent &P);
void deleteLast_parent(List_parent &LP, address_parent &P);
void printList_parent(List_parent LP);
void printText_parent(List_parent LP);//Wahyu Hauzan Rafi(1301191313)
address_parent searchbyID_parent(List_parent &LP, int id_search);
address_parent searchbyName(List_parent LP, string nama_search);
void editData_parent(List_parent LP, address_parent &P);//Wahyu Hauzan Rafi(1301191313)
void deleteSearch_parent(List_parent &LP, address_parent &P);
void data_parent(List_parent &LP);//Wahyu Hauzan Rafi(1301191313)
int totalPendaftar_parent(List_parent LP);//Wahyu Hauzan Rafi(1301191313)

#endif // LIST_PARENT_H_INCLUDED
