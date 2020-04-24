#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
#define next_child(P) P->next_child
#define info_child(P) P->info_child
#define last(L) L.last
#define first(L) L.first

using namespace std;

typedef infotype{
    int tahun_masuk;
    string jurusan_pilihan, fakultas, akreditasi;
}

typedef struct elmList *address;

struct elmList {
    infotype info_child;
    address next_child;
};

struct List{
    address first;
    address last;
};

void newElement_child(address P, int year, string facultyMajor, string faculty, string Akreditasii);
void create_List_child();
void insertFirst_child(List &L, address P);
void insertAfter_child(List &L, address Prec, address P);
void insertLast_child(List &L, address P);
void deleteFirst_child(List &L, address P);
void deleteAfter_child(List &L, address Prec, address P);
void deleteLast_child(List &L, address P);
void printList_child(List L);
address findbyID_child(List L, string x);

#endif // LIST_CHILD_H_INCLUDED
