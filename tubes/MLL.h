#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include "list_parent.h"
#include "list_child.h"
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>

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

void createList_MLL(List_MLL &LM);
address_MLL newElement_MLL(address_parent PP, address_child PC);
void deallocate_MLL(address_MLL &PM);
void insertFirst_MLL(List_MLL &LM, address_MLL PM);
void insertAfter_MLL(List_MLL &LM, address_MLL Prec, address_MLL PM);
void insertLast_MLL(List_MLL &LM, address_MLL PM);
void deleteFirst_MLL(List_MLL &LM, address_MLL &PM);
void deleteAfter_MLL(List_MLL &LM, address_MLL Prec, address_MLL &PM);
void deleteLast_MLL(List_MLL &LM, address_MLL &PM);
void printList_MLL(List_MLL LM);
address_MLL search_MLL(List_MLL LM, string x, string y);
void input_MLL(List_parent LP, List_child LC, List_MLL &LM);
void delete_parent(List_MLL &LM, List_parent &LP, address_parent &PP);
void delete_child(List_MLL &LM, List_child &LC, address_child &PC);
void delete_MLL(List_MLL &LM, address_MLL &PM);
void search_parent(List_MLL LM, List_parent LP, address_parent PP);
void search_child(List_MLL LM, List_child LC, address_child PC);
void menu(List_parent LP, List_child LC, List_MLL LM);

#endif // MLL_H_INCLUDED
