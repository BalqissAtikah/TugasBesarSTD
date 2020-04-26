#include "list_child.h"

void create_List_child(List_child &LC) {
    first_child(LC) = NULL;
    last_child(LC) = NULL;
}

address_child newElement_child(child x){
    address_child P = new elmList_child;
    info_child(P) = x;
    next_child(P) = NULL;
    return P;
}

void deallocate_child(address_child &P){
    delete P;
}

address_child input_child(){
    child x;
    cin.get();
    cout<<"ID \t: ";
    cin>>x.ID;
    cout<<"Fakultas \t: ";
    getline(cin, x.fakultas);
    cout<<"Jurusan \t: ";
    getline(cin, x.jurusan_pilihan);
    cout<<"Akreditasi \t: ";
    cin>>x.akreditasi;

    return newElement_child(x);
}

void insertFirst_child(List_child &LC, address_child P){
    if (first_child(LC) == NULL){
        first_child(LC) = P;
        last_child(LC) = P;
    } else {
        next_child(P) = first_child(LC);
        first_child(LC) = P;
    }
}

void insertAfter_child(List_child &LC, address_child Prec, address_child P){
    if (Prec != NULL){
        if(next_child(Prec) != NULL){
            next_child(P) = next_child(Prec);
            next_child(Prec) = P;
        } else {
            next_child(last_child(LC)) = P;
            last_child(LC) = P;
        }
    }
}

void insertLast_child(List_child &LC, address_child P){
    if (first_child(LC) == NULL) {
        first_child(LC) = P;
        last_child(LC) = P;
    } else {
        next_child(last_child(LC)) = P;
        last_child(LC) = P;
    }
}

void deleteFirst_child(List_child &LC, address_child &P){
    if (first_child(LC) != NULL) {
        P = first_child(LC);
        first_child(LC) = next_child(P);
        next_child(P) = NULL;
    }
}

void deleteAfter_child(List_child &LC, address_child Prec, address_child &P){
    if (Prec != NULL) {
        P = next_child(Prec);
        next_child(Prec) = next_child(P);
        next_child(P) = NULL;
    }
}

void deleteLast_child(List_child &LC, address_child &P) {
    address_child Q;
    if (first_child(LC) == last_child(LC)){
        P = first_child(LC);
        first_child(LC) = NULL;
        last_child(LC) = NULL;
    } else {
        P = last_child(LC);
        Q = first_child(LC);
        while(next_child(Q) != P) {
            Q = next_child(Q);
        }
        last_child(LC) = Q;
        next_child(Q) = NULL;
    }
}

void printList_child(List_child LC){
    address_child P;
    if (first_child(LC) == NULL){
        cout<<"============================================================================================================================================"<<endl;
        cout<<"\t\t\t\t\t\t\tDaftar Jurusan Telkom University"<<endl;
        cout<<"============================================================================================================================================"<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t\t\tBelum Ada Jurusan yang Terdaftar\n"<<endl;
        cout<<"============================================================================================================================================"<<endl;
    } else {
        cout<<"============================================================================================================================================"<<endl;
        cout<<"\t\t\t\t\t\t\tDaftar Jurusan Telkom University"<<endl;
        cout<<"============================================================================================================================================"<<endl;
        cout<<"Fakultas \t\t\t| Jurusan\t\t\t|   Akreditasi\t|"<<endl;
        cout<<"============================================================================================================================================"<<endl;
        P = first_child(LC);
        while(P != NULL){
            cout<<info_child(P).ID<<"\t| "<<info_child(P).fakultas<<"\t\t| ";
            cout<<info_child(P).jurusan_pilihan<<"\t\t|\t["<<info_child(P).akreditasi<<"]\t|";
            cout<<endl;
            P = next_child(P);
        }
        cout<<"============================================================================================================================================"<<endl;
    }
}

address_child searchbyID_child(List_child LC, int x){
    address_child P;
    if(first_child(LC) != NULL){
        P = first_child(LC);
        while(P != NULL){
            if(info_child(P).ID == x){
                break;
            }
            P = next_child(P);
        }
        return P;
    }
}

address_child searchbyMajor(List_child LC, string x){
    address_child P;
    if (first_child(LC) != NULL){
        P = first_child(LC);
        while(P != NULL){
            if(info_child(P).jurusan_pilihan == x){
                break;
            }
            P = next_child(P);
        }
        return P;
    }
}

void editData_child(List_child LC, address_child &P){
    cout<<"Fakultas \t: ";
    cin.get();
    getline(cin,info_child(P).fakultas);
    cout<<"Jurusan \t: ";
    getline(cin,info_child(P).jurusan_pilihan);
    cout<<"Akreditasi \t: ";
    cin>>info_child(P).akreditasi;
}

void deleteSearch_child(List_child &LC, address_child &P){
    address_child Prec, Q;
    Q = first_child(LC);
    while(next_child(Q) != NULL){
        Prec = Q;
        Q = next_child(Q);
    }
    if(P != NULL){
        if(P == first_child(LC)){
            deleteFirst_child(LC, P);
        } else if(P == Q){
            deleteLast_child(LC, P);
        } else {
            deleteAfter_child(LC, Prec, P);
        }
    }
}
