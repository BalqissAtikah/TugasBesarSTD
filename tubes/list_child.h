#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
#define next_child(P) P->next_child
#define info_child(P) P->info_child
#define last_child(LC) LC.last_child
#define first_child(LC) LC.first_child
#define ke_child(P) P->ke_child

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

struct child{
    int ID;
    int pendaftar;
    string jurusan_pilihan, fakultas;
    char akreditasi;
};

typedef struct elmList_child *address_child;

struct elmList_child {
    child info_child;
    address_child next_child;
};

struct List_child{
    address_child first_child;
    address_child last_child;
};

void create_List_child(List_child &LC);                                         //Balqis Sayyidahtul Atikah(1301193480)
address_child newElement_child(child x);                                        //Balqis Sayyidahtul Atikah(1301193480)
void deallocate_child(address_child &P);                                        //Balqis Sayyidahtul Atikah(1301193480)
address_child input_child();//Wahyu Hauzan Rafi(1301191313)
void insertFirst_child(List_child &LC, address_child P);                        //Balqis Sayyidahtul Atikah(1301193480)
void insertAfter_child(List_child &LC, address_child Prec, address_child P);    //Balqis Sayyidahtul Atikah(1301193480)
void insertLast_child(List_child &LC, address_child P);                         //Balqis Sayyidahtul Atikah(1301193480)
void deleteFirst_child(List_child &LC, address_child &P);                       //Balqis Sayyidahtul Atikah(1301193480)
void deleteAfter_child(List_child &LC, address_child Prec, address_child &P);   //Balqis Sayyidahtul Atikah(1301193480)
void deleteLast_child(List_child &LC, address_child &P);                        //Balqis Sayyidahtul Atikah(1301193480)
void printList_child(List_child LC);                                            //Balqis Sayyidahtul Atikah(1301193480)
void printText_child(List_child LC);//Wahyu Hauzan Rafi(1301191313)
address_child searchbyID_child(List_child LC, int x);                           //Balqis Sayyidahtul Atikah(1301193480)
address_child searchbyMajor(List_child LC, string x);                           //Balqis Sayyidahtul Atikah(1301193480)
void editData_child(List_child LC, address_child &P);//Wahyu Hauzan Rafi(1301191313)
void deleteSearch_child(List_child &LC, address_child &P);                      //Balqis Sayyidahtul Atikah(1301193480)
void data_child(List_child &LC);//Wahyu Hauzan Rafi(1301191313)
int random_child();//Wahyu Hauzan Rafi(1301191313)
int totalPendaftar_child(List_child  LC);//Wahyu Hauzan Rafi(1301191313)

#endif // LIST_CHILD_H_INCLUDED
