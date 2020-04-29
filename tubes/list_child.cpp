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

address_child input_child(){//Wahyu Hauzan Rafi(1301191313)
    child x;
    cin.get();
    x.ID = random_child();
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
        cout<<"===================================================================================="<<endl;
        cout<<"\t\tDaftar Jurusan Telkom University"<<endl;
        cout<<"===================================================================================="<<endl;
        cout<<endl;
        cout<<"\t\tBelum Ada Jurusan yang Terdaftar\n"<<endl;
        cout<<"===================================================================================="<<endl;
    } else {
        cout<<"===================================================================================="<<endl;
        cout<<"\t\tDaftar Jurusan Telkom University"<<endl;
        cout<<"===================================================================================="<<endl;
        cout<<"ID \t| Fakultas \t| Jurusan\t\t\t|   Akreditasi\t| Pendaftar|"<<endl;
        cout<<"===================================================================================="<<endl;
        P = first_child(LC);
        while(P != NULL){
            cout<<info_child(P).ID<<"\t| "<<info_child(P).fakultas<<"\t\t| ";
            cout<<info_child(P).jurusan_pilihan<<"\t\t|\t["<<info_child(P).akreditasi<<"]\t| "<<info_child(P).pendaftar;
            cout<<endl;
            P = next_child(P);
        }
        cout<<"===================================================================================="<<endl;    }
}

void printText_child(List_child LC){//Wahyu Hauzan Rafi(1301191313)
    ofstream myfile;
    myfile.open("Data Jurusan.txt");
    myfile<<"====================================================================================\n";
    myfile<<"\t\tDaftar Jurusan Telkom University\n";
    myfile<<"====================================================================================\n";
    myfile<<"ID \t| Fakultas \t| Jurusan\t\t\t|   Akreditasi\t| Pendaftar|\n";
    myfile<<"====================================================================================\n";
    address_child P = first_child(LC);
    while(P != NULL){
        myfile<<info_child(P).ID<<"\t| "<<info_child(P).fakultas<<"\t\t| "<<info_child(P).jurusan_pilihan<<"\t\t|\t["<<info_child(P).akreditasi<<"]\t| "<<info_child(P).pendaftar<<"\n";
        P = next_child(P);
    }
    myfile.close();
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

void editData_child(List_child LC, address_child &P){//Wahyu Hauzan Rafi(1301191313)
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

void data_child(List_child &LC){//Wahyu Hauzan Rafi(1301191313)
    child x;
    address_child PC;

    x.fakultas = "FTE";
    x.jurusan_pilihan = "S1 Tek Telekomunikasi";
    x.akreditasi = 'A';
    x.ID = 1101;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FTE";
    x.jurusan_pilihan = "S1 Teknik Elektro";
    x.akreditasi = 'A';
    x.ID = 1102;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FTE";
    x.jurusan_pilihan = "S1 Teknik Komputer";
    x.akreditasi = 'B';
    x.ID = 1103;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FTE";
    x.jurusan_pilihan = "S1 Teknik Fisika";
    x.akreditasi = 'A';
    x.ID = 1104;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FRI";
    x.jurusan_pilihan = "S1 Teknik Industri";
    x.akreditasi = 'A';
    x.ID = 1201;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FRI";
    x.jurusan_pilihan = "S1 Sistem Informasi";
    x.akreditasi = 'A';
    x.ID = 1202;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FRI";
    x.jurusan_pilihan = "S1 Teknik Logistik";
    x.akreditasi = 'C';
    x.ID = 1203;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIF";
    x.jurusan_pilihan = "S1 Informatika";
    x.akreditasi = 'A';
    x.ID = 1301;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIF";
    x.jurusan_pilihan = "S1 Tekno Informasi";
    x.akreditasi = 'B';
    x.ID = 1302;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIF";
    x.jurusan_pilihan = "S1 RPL Reguler";
    x.akreditasi = 'B';
    x.ID = 1303;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FEB";
    x.jurusan_pilihan = "S1 MBTI Reguler";
    x.akreditasi = 'A';
    x.ID = 1401;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FEB";
    x.jurusan_pilihan = "S1 Akuntansi Reguler";
    x.akreditasi = 'A';
    x.ID = 1402;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FKB";
    x.jurusan_pilihan = "S1 Admin Bisnis";
    x.akreditasi = 'A';
    x.ID = 1501;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FKB";
    x.jurusan_pilihan = "S1 Ilmu Komunikasi";
    x.akreditasi = 'A';
    x.ID = 1502;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FKB";
    x.jurusan_pilihan = "S1 DPR Reguler";
    x.akreditasi = 'B';
    x.ID = 1503;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIK";
    x.jurusan_pilihan = "S1 DKV Reguler";
    x.akreditasi = 'A';
    x.ID = 1601;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIK";
    x.jurusan_pilihan = "S1 Desain Produk";
    x.akreditasi = 'A';
    x.ID = 1602;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIK";
    x.jurusan_pilihan = "S1 Desain Interior";
    x.akreditasi = 'A';
    x.ID = 1603;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIK";
    x.jurusan_pilihan = "S1 Seni Rupa Reguler";
    x.akreditasi = 'A';
    x.ID = 1604;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIK";
    x.jurusan_pilihan = "S1 Kriya Reguler";
    x.akreditasi = 'A';
    x.ID = 1605;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIT";
    x.jurusan_pilihan = "D3 Sistem Informasi";
    x.akreditasi = 'A';
    x.ID = 6701;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIT";
    x.jurusan_pilihan = "D3 Teknik Komputer";
    x.akreditasi = 'A';
    x.ID = 6702;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIT";
    x.jurusan_pilihan = "D3 SisFo Akuntansi";
    x.akreditasi = 'A';
    x.ID = 6703;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIT";
    x.jurusan_pilihan = "D3 Digital Marketing";
    x.akreditasi = 'B';
    x.ID = 6704;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIT";
    x.jurusan_pilihan = "D3 Tekno Telekom";
    x.akreditasi = 'A';
    x.ID = 6705;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIT";
    x.jurusan_pilihan = "D3 Teknik Informatika";
    x.akreditasi = 'A';
    x.ID = 6706;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);

    x.fakultas = "FIT";
    x.jurusan_pilihan = "D3 Perhotelan Reguler";
    x.akreditasi = 'A';
    x.ID = 6707;
    x.pendaftar = 0;
    PC = newElement_child(x);
    insertLast_child(LC, PC);
}

int random_child(){//Wahyu Hauzan Rafi(1301191313)
    int randomize = rand() % 9999 + 1000;
    return randomize;
}

int totalPendaftar_child(List_child LC){//Wahyu Hauzan Rafi(1301191313)
    address_child PC = first_child(LC);
    int total = 0;
    if(first_child(LC) != NULL){
        while(PC != NULL){
            total = total + info_child(PC).pendaftar;
            PC = next_child(PC);
        }
    }
    return total;
}
