#include "list_parent.h"

void createList_parent(List_parent &LP){
    first_parent(LP) = NULL;
}

address_parent newElement_parent(parent x){
    address_parent P = new elmList_parent;
    info_parent(P) = x;
    prev_parent(P) = NULL;
    next_parent(P) = NULL;
}

void deallocate_parent(address_parent &P){
    delete P;
}

address_parent input_parent(List_parent LP){
    parent x;
    address_parent P = first_parent(LP);
    if(first_parent(LP) == NULL){
        x.ID = 1;
    } else {
        x.ID = info_parent(prev_parent(P)).ID + 1;
    }
    cin.get();
    cout<<"Nama \t\t\t: ";
    getline(cin, x.nama);
    cout<<"Asal SMA \t\t: ";
    getline(cin, x.sma);
    cout<<"Jurusan SMA \t\t: ";
    getline(cin, x.jurusan_sma);
    cout<<"Jenis Kelamin (L/P)\t: ";
    cin>>x.jenis_kelamin;
    cout<<"Jalur Masuk \t\t: ";
    cin>>x.jalur_masuk;
    cout<<"Sumbangan \t\t: ";
    cin>>x.sumbangan;
    cout<<endl;

    return newElement_parent(x);
}

void insertFirst_parent(List_parent &LP, address_parent P){
    if(first_parent(LP) == NULL){
        first_parent(LP) = P;
        next_parent(P) = P;
        prev_parent(P) = P;
    } else {
        next_parent(P) = first_parent(LP);
        prev_parent(P) = prev_parent(first_parent(LP));
        next_parent(prev_parent(first_parent(LP))) = P;
        prev_parent(first_parent(LP)) = P;
        first_parent(LP) = P;
    }
}

void insertAfter_parent(List_parent &LP, address_parent Prec, address_parent P){
    prev_parent(next_parent(Prec)) = P;
    next_parent(P) = next_parent(Prec);
    next_parent(Prec) = P;
    prev_parent(P) = Prec;
}

void insertLast_parent(List_parent &LP, address_parent P){
    if(first_parent(LP) == NULL){
        insertFirst_parent(LP, P);
    } else {
        next_parent(P) = first_parent(LP);
        prev_parent(P) = prev_parent(first_parent(LP));
        next_parent(prev_parent(first_parent(LP))) = P;
        prev_parent(first_parent(LP)) = P;
    }
}

void deleteFirst_parent(List_parent &LP, address_parent &P){
    if(next_parent(first_parent(LP)) == first_parent(LP)) {
        P = first_parent(LP);
        next_parent(P) = NULL;
        prev_parent(P) = NULL;
        first_parent(LP) = NULL;
    } else {
        P = first_parent(LP);
        first_parent(LP) = next_parent(P);
        prev_parent(first_parent(LP)) = prev_parent(P);
        next_parent(prev_parent(P)) = first_parent(LP);
        next_parent(P) = NULL;
        prev_parent(P) = NULL;
    }
}

void deleteAfter_parent(List_parent &LP, address_parent Prec, address_parent &P){
    if(Prec != NULL){
        P = next_parent(Prec);
        next_parent(Prec) = next_parent(P);
        prev_parent(next_parent(Prec)) = Prec;
        next_parent(P) = NULL;
        prev_parent(P) = NULL;
    }
}

void deleteLast_parent(List_parent &LP, address_parent &P){
    P = prev_parent(first_parent(LP));
    if(P == first_parent(LP)){
        deleteFirst_parent(LP, P);
    } else{
        prev_parent(first_parent(LP)) = prev_parent(P);
        next_parent(prev_parent(P)) = first_parent(LP);
        next_parent(P) = NULL;
        prev_parent(P) = NULL;
    }
}

void printList_parent(List_parent LP){
    address_parent P;
    if(first_parent(LP) == NULL){
        cout<<"============================================================================================================================================"<<endl;
        cout<<"\t\t\t\t\t\t\t\t Daftar Mahasiswa Baru"<<endl;
        cout<<"============================================================================================================================================"<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t\t\t Belum ada Mahasiswa yang terdaftar \n"<<endl;
        cout<<"============================================================================================================================================"<<endl;
    } else {
        cout<<"============================================================================================================================================"<<endl;
        cout<<"\t\t\t\t\t\t\t\t Daftar Mahasiswa Baru"<<endl;
        cout<<"============================================================================================================================================"<<endl;
        cout<<"ID \t| Nama \t\t\t| Asal SMA \t\t| Jurusan SMA \t| Jenis Kelamin \t| Jalur Masuk \t| Sumbangan"<<endl;
        cout<<"============================================================================================================================================"<<endl;
        P = first_parent(LP);
        do{
            cout<<info_parent(P).ID<<"\t| "<<info_parent(P).nama<<"\t| ";
            cout<<info_parent(P).sma<<"\t| "<<info_parent(P).jurusan_sma<<"\t\t| ";
            cout<<info_parent(P).jenis_kelamin<<"\t\t\t| "<<info_parent(P).jalur_masuk<<"\t\t| Rp"<<info_parent(P).sumbangan;
            cout<<endl;
            P = next_parent(P);
        }while(next_parent(P) != first_parent(LP));
        cout<<"============================================================================================================================================"<<endl;
    }
}

address_parent searchbyID_parent(List_parent LP, int id_search){
    address_parent P;
    address_parent found = NULL;
    if(first_parent(LP) != NULL){
        P = first_parent(LP);
        do{
            if(info_parent(P).ID == id_search){
                found = P;
            }
            P = next_parent(P);
        }while(P != first_parent(LP));
    }
    return found;
}

address_parent searchbyName(List_parent LP, string nama_search){
    address_parent P;
    address_parent found = NULL;
    if(first_parent(LP) != NULL){
        P = first_parent(LP);
        do{
            if(info_parent(P).nama == nama_search){
                found = P;
            }
            P = next_parent(P);
        }while(P != first_parent(LP));
    }
    return found;
}

void editData_parent(List_parent LP, address_parent &P){
    cin.get();
    cout<<"Nama \t\t\t: ";
    getline(cin,info_parent(P).nama);
    cout<<"Asal SMA \t\t: ";
    getline(cin,info_parent(P).sma);
    cout<<"Jurusan SMA \t\t: ";
    getline(cin,info_parent(P).jurusan_sma);
    cout<<"Jenis Kelamin (L/P)\t: ";
    getline(cin,info_parent(P).jenis_kelamin);
    cout<<"Jalur Masuk \t\t: ";
    getline(cin,info_parent(P).jalur_masuk);
    cout<<"Sumbangan \t\t: ";
    cin>>info_parent(P).sumbangan;
}

void deleteSearch_parent(List_parent &LP, address_parent &P){
    address_parent Prec;
    if(P != NULL){
        if(P == first_parent(LP)){
            deleteFirst_parent(LP, P);
        } else if(next_parent(P) != first_parent(LP) && prev_parent(P) != first_parent(LP)){
            Prec = prev_parent(P);
            deleteAfter_parent(LP, Prec, P);
        }
    }
}
