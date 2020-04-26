#include "MLL.h"

void createList_MLL(List_MLL &LM){
    first_MLL(LM) = NULL;
}

address_MLL newElement_MLL(address_parent PP, address_child PC){
    address_MLL PM = new elmList_MLL;
    ke_parent(PM) = PP;
    ke_child(PM) = PC;
    next_MLL(PM) = NULL;
    return PM;
}

void deallocate_MLL(address_MLL &PM){
    delete PM;
}

void insertFirst_MLL(List_MLL &LM, address_MLL PM){
    if(first_MLL(LM) == NULL){
        first_MLL(LM) = PM;
        next_MLL(first_MLL(LM)) = first_MLL(LM);
        prev_MLL(first_MLL(LM)) = first_MLL(LM);
    } else {
        next_MLL(PM) = first_MLL(LM);
        prev_MLL(PM) = prev_MLL(first_MLL(LM));
        next_MLL(prev_MLL(first_MLL(LM))) = PM;
        prev_MLL(first_MLL(LM)) = PM;
        first_MLL(LM) = PM;
    }
}

void insertAfter_MLL(List_MLL &LM, address_MLL Prec, address_MLL PM){
    if(first_MLL(LM) == NULL){
        first_MLL(LM) = PM;
        next_MLL(first_MLL(LM)) = first_MLL(LM);
        prev_MLL(first_MLL(LM)) = first_MLL(LM);
    } else {
        prev_MLL(next_MLL(Prec)) = PM;
        next_MLL(PM) = next_MLL(Prec);
        next_MLL(Prec) = PM;
        prev_MLL(PM) = Prec;
    }
}

void insertLast_MLL(List_MLL &LM, address_MLL PM){
    if(first_MLL(LM) == NULL){
        first_MLL(LM) = PM;
        next_MLL(first_MLL(LM)) = first_MLL(LM);
        prev_MLL(first_MLL(LM)) = first_MLL(LM);
    } else {
        address_MLL Q = prev_MLL(first_MLL(LM));
        prev_MLL(PM) = Q;
        prev_MLL(first_MLL(LM)) = PM;
        next_MLL(PM) = first_MLL(LM);
        next_MLL(Q) = PM;
    }
}

void deleteFirst_MLL(List_MLL &LM, address_MLL &PM){
    if(first_MLL(LM) != NULL){
        PM = first_MLL(LM);
        if(next_MLL(PM) == first_MLL(LM)){
            first_MLL(LM) = NULL;
        } else {
            address_MLL Q = prev_MLL(PM);
            first_MLL(LM) = next_MLL(PM);
            prev_MLL(first_MLL(LM)) = Q;
            next_MLL(Q) = first_MLL(LM);
            next_MLL(PM) = NULL;
            prev_MLL(PM) = NULL;
        }
    } else {
        cout<<"Data Kosong"<<endl;
    }
}

void deleteAfter_MLL(List_MLL &LM, address_MLL Prec, address_MLL &PM){
    PM = next_MLL(Prec);
    prev_MLL(next_MLL(PM)) = Prec;
    next_MLL(Prec) = next_MLL(PM);
    next_MLL(PM) = NULL;
    prev_MLL(PM) = NULL;
}

void deleteLast_MLL(List_MLL &LM, address_MLL &PM){
    if(first_MLL(LM) != NULL){
        if(next_MLL(first_MLL(LM)) == first_MLL(LM)){
            PM = first_MLL(LM);
            first_MLL(LM) = NULL;
        } else {
            PM = prev_MLL(first_MLL(LM));
            address_MLL Q = prev_MLL(PM);
            next_MLL(Q) = first_MLL(LM);
            prev_MLL(first_MLL(LM)) = Q;
            next_MLL(PM) = NULL;
            prev_MLL(PM) = NULL;
         }
    } else {
        cout<<"Data Kosong"<<endl;
    }
}

void printList_MLL(List_MLL LM){
    address_MLL PM;
    if(first_MLL(LM) == NULL){
        cout<<"========================================================================="<<endl;
        cout<<"\t\t Daftar Jurusan Yang Dipilih Mahasiswa Baru"<<endl;
        cout<<"========================================================================="<<endl;
        cout<<endl;
        cout<<"\t\tBelum Ada Mahasiswa Yang Memilih Jurusan\n"<<endl;
        cout<<"========================================================================="<<endl;
    } else {
        cout<<"========================================================================="<<endl;
        cout<<"\t\t Daftar Jurusan Yang Dipilih Mahasiswa Baru"<<endl;
        cout<<"========================================================================="<<endl;
        cout<<"ID \t\t| Nama \t\t\t| Asal SMA \t\t| Jurusan \t\t|"<<endl;
        cout<<"========================================================================="<<endl;
        PM = first_MLL(LM);
        do{
            cout<<info_parent(ke_parent(PM)).ID<<" \t| "<<info_parent(ke_parent(PM)).nama<<" \t| "<<info_parent(ke_parent(PM)).sma<<" \t| "<<info_child(ke_child(PM)).jurusan_pilihan<<"\t|";
            cout<<endl;
            PM = next_MLL(PM);
        } while(PM != first_MLL(LM));
        cout<<"========================================================================="<<endl;
    }
}

address_MLL search_MLL(List_MLL LM, string x, string y){
    bool found;
    address_MLL PM;
    if(first_MLL(LM) != NULL){
        found = false;
        PM = first_MLL(LM);
        do{
            if(info_parent(ke_parent(PM)).nama == x){
                if(info_child(ke_child(PM)).jurusan_pilihan == y){
                    found = true;
                    return PM;
                }
            }
            PM = next_MLL(PM);
        }while(found != true && PM != first_MLL(LM));
    }
    if(found != true){
        PM = NULL;
    }
    return PM;
}

void input_MLL(List_parent LP, List_child LC, List_MLL &LM){
    address_parent PP;
    address_child PC;
    address_MLL PM;
    parent parentcari;
    child childcari;
    printList_parent(LP);
    cout<<"Nama Mahasiswa Baru: ";
    cin.get();
    getline(cin, parentcari.nama);
    PP = searchbyName(LP, parentcari.nama);
    if(PP != NULL){
        system("cls");
        printList_child(LC);
        cout<<"Nama Mahasiswa Baru: "<<parentcari.nama<<endl;
        cout<<"Jurusan Yang Ingin Dipilih: ";
        getline(cin, childcari.jurusan_pilihan);
        PC = searchbyMajor(LC, childcari.jurusan_pilihan);
        if(PC != NULL){
            //generate ID baru buat parent
            PM = newElement_MLL(PP, PC);
            insertLast_MLL(LM, PM);
            cout<<endl;
            cout<<"Mahasiswa Baru Berhasil Memilih Jurusan"<<endl;
        } else {
            cout<<endl;
            cout<<"Jurusan Tersebut Belum Tersedia Di Kampus Kami"<<endl;
        }
    } else {
        cout<<"Data Mahasiswa Baru Tidak Tersedia Dalam Pilihan"<<endl;
    }
}

void delete_parent(List_MLL &LM, List_parent &LP, address_parent &PP){
    address_MLL PM = first_MLL(LM);
    if(first_MLL(LM) != NULL){
        do{
            if(ke_parent(PM) == PP){
                delete_MLL(LM, PM);
            }
            PM = next_MLL(PM);
        }while(PM != first_MLL(LM));
    }
    deleteSearch_parent(LP, PP);
}

void delete_child(List_MLL &LM, List_child &LC, address_child &PC){
    address_MLL PM = first_MLL(LM);
    if(first_MLL(LM) != NULL){
        do{
           if(ke_child(PM) == PC){
                delete_MLL(LM, PM);
           }
           PM = next_MLL(PM);
        }while(PM != first_MLL(LM));
    }
    deleteSearch_child(LC, PC);
}

void delete_MLL(List_MLL &LM, address_MLL &PM){
    address_MLL Q, Prec;
    if(PM != NULL){
        Q = first_MLL(LM);
        do{
            Q = next_MLL(Q);
        }while(next_MLL(Q) != first_MLL(LM));
        if(PM == first_MLL(LM)){
            deleteFirst_MLL(LM, PM);
        } else if(PM == Q){
            deleteLast_MLL(LM, PM);
        } else {
            Prec = prev_MLL(PM);
            deleteAfter_MLL(LM, Prec, PM);
        }
    }
}

void search_parent(List_MLL LM, List_parent LP, address_parent PP){
    address_MLL PM = first_MLL(LM);
    int i = 0;
    if(first_MLL(LM) != NULL){
        do{
            if(info_parent(PP).nama == info_parent(ke_parent(PM)).nama){
                i ++;
                cout<<"Pilihan ke-"<<i<<" : "<<info_child(ke_child(PM)).jurusan_pilihan<<endl;
            }
            PM = next_MLL(PM);
        }while(PM != first_MLL(LM));
        if(i == 0){
            cout<<"Anda Belum Memilih Jurusan"<<endl;
        }
    } else {
        cout<<"Belum Ada Mahasiswa Baru Yang Memilih Jurusan"<<endl;
    }
}

void search_child(List_MLL LM, List_child LC, address_child PC){
    address_MLL PM = first_MLL(LM);
    int i = 0;
    if(first_MLL(LM) != NULL){
        do{
            if(info_child(PC).jurusan_pilihan == info_child(ke_child(PM)).jurusan_pilihan){
                i ++;
                cout<<i<<". "<<info_parent(ke_parent(PM)).nama<<endl;
            }
            PM = next_MLL(PM);
        }while(PM != first_MLL(LM));
        if(i == 0){
            cout<<"Belum Ada Mahasiswa Baru Yang Memilih Jurusan Ini"<<endl;
        }
    } else {
        cout<<"Belum Ada Jurusan Yang Dipilih"<<endl;
    }
}

void menu(List_parent LP, List_child LC, List_MLL LM){
    int pil;
    parent parentcari;
    child childcari;
    address_parent PP;
    address_child PC;
    address_MLL PM;

    do{
        system("cls");
        cout<<"======================================================="<<endl;
        cout<<"\t\t Penerimaan Mahasiswa Baru"<<endl;
        cout<<"======================================================="<<endl;
        cout<<" -- INPUT -- "<<endl;
        cout<<"1.  Data Mahasiswa Baru"<<endl;
        cout<<"2.  Tambah Jurusan Baru (Jika Ingin)"<<endl;
        cout<<"3.  Pilihan Jurusan"<<endl;
        cout<<endl;
        cout<<" -- EDIT -- "<<endl;
        cout<<"4.  Edit Data Mahasiswa"<<endl;
        cout<<"5.  Edit Pilihan Jurusan"<<endl;
        cout<<endl;
        cout<<" -- LIHAT DATA --"<<endl;
        cout<<"6.  Lihat Mahasiswa Baru Yang Telah Terdaftar"<<endl;
        cout<<"7.  Lihat Jurusan Yang Tersedia"<<endl;
        cout<<"8.  Lihat Jurusan Yang Telah Dipilih Mahasiswa Baru"<<endl;
        cout<<endl;
        cout<<" -- DELETE -- "<<endl;
        cout<<"9.  Hapus Data Mahasiswa Baru"<<endl;
        cout<<"10. Hapus Jurusan"<<endl;
        cout<<"11. Hapus Pilihan Jurusan Mahasiswa Baru"<<endl;
        cout<<endl;
        cout<<" -- SEARCHING -- "<<endl;
        cout<<"12. Cari Data Mahasiswa Baru"<<endl;
        cout<<"13. Cari Data Jurusan"<<endl;
        cout<<endl;
        cout<<"0. Exit"<<endl;
        cout<<endl;
        cout<<"Masukkan Pilihan : ";
        cin>>pil;
        switch(pil){
        case 1:
            system("cls");
            cout<<"============================================================================="<<endl;
            cout<<"\t\tPendaftaran Mahasiswa Baru"<<endl;
            cout<<"============================================================================="<<endl;
            PP = input_parent(LP);
            insertLast_parent(LP, PP);
            cout<<endl;
            cout<<"Anda Berhasil Terdaftar"<<endl;
            cout<<endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout<<"============================================================================="<<endl;
            cout<<"\t\t\tTambah Jurusan Baru"<<endl;
            cout<<"============================================================================="<<endl;
            PC = input_child();
            insertLast_child(LC, PC);
            cout<<endl;
            cout<<"Jurusan Berhasil Ditambahkan. Yeay!"<<endl;
            cout<<endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"============================================================================="<<endl;
            cout<<"\t\t\t Pilih Jurusan Anda"<<endl;
            cout<<"============================================================================="<<endl;
            input_MLL(LP, LC, LM);
            cout<<endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout<<"============================================================================="<<endl;
            cout<<"\t\t\t Edit Data Diri"<<endl;
            cout<<"============================================================================="<<endl;
            printList_parent(LP);
            cout<<"Nama Mahasiswa Baru Yang Ingin Diubah: ";
            cin.get();
            getline(cin, parentcari.nama);
            PP = searchbyName(LP, parentcari.nama);
            if(PP != NULL){
                cout<<"Mahasiswa Baru Ditemukan"<<endl;
                system("pause");
                system("cls");
                editData_parent(LP, PP);
                cout<<"Data Berhasil Diubah"<<endl;
            } else {
                cout<<"Mahasiswa Baru Tidak Ditemukan"<<endl;
            }
            system("pause");
            break;
        case 5:
            system("cls");
            cout<<"============================================================================="<<endl;
            cout<<"\t\t\t Edit Jurusan Yang Telah Dipilih"<<endl;
            cout<<"============================================================================="<<endl;
            printList_child(LC);
            cout<<"Jurusan Yang Ingin Diubah: ";
            cin.get();
            getline(cin, childcari.jurusan_pilihan);
            PC = searchbyMajor(LC, childcari.jurusan_pilihan);
            if(PC != NULL){
                cout<<"Jurusan Ditemukan"<<endl;
                system("cls");
                editData_child(LC, PC);
                cout<<"Jurusan Berhasil Diubah"<<endl;
            } else {
                cout<<"Jurusan Tersebut Tidak Ada"<<endl;
            }
            system("pause");
            break;
        case 6:
            system("cls");
            printList_parent(LP);
            system("pause");
            break;
        case 7:
            system("cls");
            printList_child(LC);
            system("pause");
            break;
        case 8:
            system("cls");
            printList_MLL(LM);
            system("pause");
            break;
        case 9:
            system("cls");
            printList_parent(LP);
            cout<<"Masukkan Nama Mahasiswa Baru Yang Ingin Dihapus: ";
            cin.get();
            getline(cin,parentcari.nama);
            PP = searchbyName(LP, parentcari.nama);
            if(PP != NULL){
                delete_parent(LM, LP, PP);
                cout<<endl;
                cout<<"Data Mahasiswa Baru Berhasil Dihapus"<<endl;
                cout<<"Semoga Bertemu Lagi Di PMB TELKOM UNIVERSITY Tahun Depan!"<<endl;
                cout<<endl;
            } else {
                cout<<endl;
                cout<<"Data Mahasiswa Baru Tidak Ditemukan"<<endl;
                cout<<endl;
            }
            system("pause");
            break;
        case 10:
            system("cls");
            printList_child(LC);
            cout<<"Masukkan Jurusan Yang Ingin Dihapus: ";
            cin.get();
            getline(cin, childcari.jurusan_pilihan);
            PC = searchbyMajor(LC, childcari.jurusan_pilihan);
            if(PC != NULL){
                delete_child(LM, LC, PC);
                cout<<endl;
                cout<<"Jurusan Berhasil Dihapus"<<endl;
                cout<<endl;
            } else {
                cout<<endl;
                cout<<"Jurusan Tidak Ditemukan"<<endl;
                cout<<endl;
            }
            system("pause");
            break;
        case 11:
            system("cls");
            printList_MLL(LM);
            cout<<"Masukkan Nama Mahasiswa Baru Yang Ingin Dihapus: ";
            cin.get();
            getline(cin, parentcari.nama);
            cout<<"Masukkan Jurusan Yang Ingin Dihapus: ";
            getline(cin, childcari.jurusan_pilihan);
            PM = search_MLL(LM, parentcari.nama, childcari.jurusan_pilihan);
            if(PM != NULL){
                delete_MLL(LM, PM);
                cout<<"Data Berhasil Dihapus"<<endl;
            } else {
                cout<<"Data Tidak Ditemukan"<<endl;
            }
            system("pause");
            break;
        case 12:
            system("cls");
            printList_parent(LP);
            cout<<"Masukkan Nama Mahasiswa Baru Yang Ingin Dicari: ";
            cin.get();
            getline(cin, parentcari.nama);
            PP = searchbyName(LP, parentcari.nama);
            if(PP != NULL){
                cout<<endl;
                cout<<parentcari.nama<<endl;
                search_parent(LM, LP, PP);
                cout<<endl;
            } else {
                cout<<"Mahasiswa Baru Tidak Ditemukan\n"<<endl;
            }
            system("pause");
            break;
        case 13:
            system("cls");
            printList_child(LC);
            cout<<"Masukkan Jurusan Yang Dicari: ";
            cin.get();
            getline(cin, childcari.jurusan_pilihan);
            PC = searchbyMajor(LC, childcari.jurusan_pilihan);
            if(PC != NULL){
                cout<<endl;
                cout<<"Mahasiswa Yang Memilih Jurusan "<<childcari.jurusan_pilihan<<": "<<endl;
                search_child(LM, LC, PC);
                cout<<endl;
            } else {
                cout<<"\nJurusan Tidak Ditemukan\n"<<endl;
            }
            system("pause");
            break;
        case 0:
            system("cls");
            cout<<"\nTerima Kasih Telah Menggunakan Layanan Penerimaan Mahasiswa Baru\n"<<endl;
            system("pause");
            break;
        default:
            cout<<endl;
            cout<<"Pilihan Yang Anda Masukkan Tidak Ada, Silakan Memasukkan Pilihan dari 0 hingga 13"<<endl;
            cout<<endl;
            system("pause");
            break;
        }
    }while(pil != 0);
}
