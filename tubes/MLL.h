#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include "list_parent.h"
#include "list_child.h"
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

#define next_MLL(P) P->next_MLL
#define prev_MLL(P) P->prev_MLL
#define first_MLL(L) L.first_MLL

typedef struct elmList_MLL *address_MLL;

struct elmList_MLL{
    address_MLL next_MLL;
    address_MLL prev_MLL;
    address_parent ke_parent;
    address_child ke_child;
};

struct List_MLL{
    address_MLL first_MLL;
};
//MLL Semua Yang Membuat Wahyu Hauzan Rafi(1301191313). Kecuali generateID yang membuat dasarnya Balqis Sayyidahtul Atikah(1301193480)
void createList_MLL(List_MLL &LM);                                         //Wahyu Hauzan Rafi(1301191313)
address_MLL newElement_MLL(address_parent PP, address_child PC);           //Wahyu Hauzan Rafi(1301191313)
void deallocate_MLL(address_MLL &PM);                                      //Wahyu Hauzan Rafi(1301191313)
void insertFirst_MLL(List_MLL &LM, address_MLL PM);                        //Wahyu Hauzan Rafi(1301191313)
void insertAfter_MLL(List_MLL &LM, address_MLL Prec, address_MLL PM);      //Wahyu Hauzan Rafi(1301191313)
void insertLast_MLL(List_MLL &LM, address_MLL PM);                         //Wahyu Hauzan Rafi(1301191313)
void deleteFirst_MLL(List_MLL &LM, address_MLL &PM);                       //Wahyu Hauzan Rafi(1301191313)
void deleteAfter_MLL(List_MLL &LM, address_MLL Prec, address_MLL &PM);     //Wahyu Hauzan Rafi(1301191313)
void deleteLast_MLL(List_MLL &LM, address_MLL &PM);                        //Wahyu Hauzan Rafi(1301191313)
int generateID(address_child PC, address_parent &PP);                      //Wahyu Hauzan Rafi(1301191313)
int random();                                                              //Wahyu Hauzan Rafi(1301191313)
void printList_MLL(List_MLL LM);                                           //Wahyu Hauzan Rafi(1301191313)
void printText(List_MLL LM);                                               //Wahyu Hauzan Rafi(1301191313)
address_MLL search_MLL(List_MLL LM, string x, string y);                   //Wahyu Hauzan Rafi(1301191313)
void input_MLL(List_parent LP, List_child LC, List_MLL &LM);               //Wahyu Hauzan Rafi(1301191313)
void delete_parent(List_MLL &LM, List_parent &LP, address_parent &PP);     //Wahyu Hauzan Rafi(1301191313)
void delete_child(List_MLL &LM, List_child &LC, address_child &PC);        //Wahyu Hauzan Rafi(1301191313)
void delete_MLL(List_MLL &LM, address_MLL &PM);                            //Wahyu Hauzan Rafi(1301191313)
void search_parent(List_MLL LM, List_parent LP, address_parent PP);        //Wahyu Hauzan Rafi(1301191313)
void search_child(List_MLL LM, List_child LC, address_child PC);           //Wahyu Hauzan Rafi(1301191313)
void menu(List_parent LP, List_child LC, List_MLL LM);                     //Wahyu Hauzan Rafi(1301191313)

#endif // MLL_H_INCLUDED
