#include "MLL.h"
//MLL Semua Yang Membuat Wahyu Hauzan Rafi(1301191313). Kecuali generateID yang membuat dasarnya Balqis Sayyidahtul Atikah(1301193480)

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

int generateID(address_child PC, address_parent &PP){
   /* if(info_child(PC).jurusan_pilihan=="S1 Teknik Telekomunikasi"){
        info_parent(PP).ID=1101*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Teknik Elektro"){
        info_parent(PP).ID=1102*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Teknik Komputer"){
        info_parent(PP).ID=1103*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Teknik Fisika"){
        info_parent(PP).ID=1104*1000000;
    } else if(info_child(PC).jurusan_pilihan=="S1 Teknik Industri"){
        info_parent(PP).ID=1201*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Sistem Informasi"){
        info_parent(PP).ID=1202*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Teknik Logistik"){
        info_parent(PP).ID=1203*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Informatika"){
        info_parent(PP).ID=1301*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Teknologi Informasi"){
        info_parent(PP).ID=1302*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Rekayasa Perangkat Lunak"){
        info_parent(PP).ID=1303*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 MBTI"){
        info_parent(PP).ID=1401*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Akuntansi"){
        info_parent(PP).ID=1402*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Administrasi Bisnis"){
        info_parent(PP).ID=1501*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Ilmu Komunikasi"){
        info_parent(PP).ID=1502*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Digital Punlic Relation"){
        info_parent(PP).ID=1503*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Desain Komunikasi Visual"){
        info_parent(PP).ID=1601*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Desain Produk"){
        info_parent(PP).ID=1602*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Desain Interior"){
        info_parent(PP).ID=1601*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Seni Rupa"){
        info_parent(PP).ID=1604*1000000;
    }else if(info_child(PC).jurusan_pilihan=="S1 Kriya Tekstil dan Mode"){
        info_parent(PP).ID=1605*1000000;
    }else if(info_child(PC).jurusan_pilihan=="D3 Sistem Informasi"){
        info_parent(PP).ID=6701*1000000;
    }else if(info_child(PC).jurusan_pilihan=="D3 Teknik Komputer"){
        info_parent(PP).ID=6702*1000000;
    }else if(info_child(PC).jurusan_pilihan=="D3 Sistem Informasi Akuntansi"){
        info_parent(PP).ID=6703*1000000;
    }else if(info_child(PC).jurusan_pilihan=="D3 Manajemen Pemasaran"){
        info_parent(PP).ID=6704*1000000;
    }else if(info_child(PC).jurusan_pilihan=="D3 Teknologi Telekomunikasi"){
        info_parent(PP).ID=6705*1000000;
    }else if(info_child(PC).jurusan_pilihan=="D3 Teknik Informatika"){
        info_parent(PP).ID=6706*1000000;
    }else if(info_child(PC).jurusan_pilihan=="D3 Perhotelan"){
        info_parent(PP).ID=6707*1000000;
    }else{
        cout<<"Wrong Input";
    }
    int n = info_child(PC).tahun_masuk;
    if(n/1000>=1){
        int sisa=0;
        sisa=n%1000;
        if(sisa>0){
            info_parent(PP).ID=info_parent(PP).ID + (sisa*10000);
        }else if(sisa==0){
            info_parent(PP).ID=info_parent(PP).ID + (sisa*10000);
        }
   }
   int x = random();
   info_parent(PP).ID=info_parent(PP).ID + x;
   */
   int bebas = random();
   return (info_child(PC).ID * 1000000) + ((info_parent(PP).tahun_masuk % 1000) * 10000) + bebas;
}

int random(){
    srand(time(NULL));
    int randomize = 1 + (rand() % 9999);
    return randomize;
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

void printText(List_MLL LM){
    ofstream myfile;
    myfile.open("Data PMB.txt");
    myfile<<"=========================================================================================\n";
    myfile<<"\t\t Daftar Jurusan Yang Dipilih Mahasiswa Baru\n";
    myfile<<"=========================================================================================\n";
    myfile<<"ID \t\t| Nama \t\t\t| Asal SMA \t\t| Jurusan \t\t|\n";
    address_MLL PM = first_MLL(LM);
    int ID;
    if(PM != NULL){
        do{
            ID = generateID(ke_child(PM), ke_parent(PM));
            myfile<<ID<<" \t| "<<info_parent(ke_parent(PM)).nama<<" \t| "<<info_parent(ke_parent(PM)).sma<<" \t| "<<info_child(ke_child(PM)).jurusan_pilihan<<"\t|\n";
            PM = next_MLL(PM);
        }while(PM != first_MLL(LM));
    }
    myfile.close();
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
    ofstream myfile;
    cout<<endl;
    cout<<"Nama Mahasiswa Baru: ";
    cin.get();
    getline(cin, parentcari.nama);
    PP = searchbyName(LP, parentcari.nama);
    if(PP != NULL){
        system("cls");
        printList_child(LC);
        cout<<endl;
        cout<<"Nama Mahasiswa Baru: "<<parentcari.nama<<endl;
        cout<<"Jurusan Yang Ingin Dipilih: ";
        getline(cin, childcari.jurusan_pilihan);
        PC = searchbyMajor(LC, childcari.jurusan_pilihan);
        if(PC != NULL){
            info_child(PC).pendaftar = info_child(PC).pendaftar + 1;
            PM = newElement_MLL(PP, PC);
            insertLast_MLL(LM, PM);
            cout<<endl;
            cout<<"Mahasiswa Baru Berhasil Memilih Jurusan"<<endl;
        } else {
            cout<<endl;
            cout<<"Jurusan Tersebut Belum Tersedia Di Kampus Kami"<<endl;
        }
    } else {
        cout<<"Anda Belum Mendaftar Di Kampus Kami"<<endl;
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
    int pil, sum;
    parent parentcari;
    child childcari;
    address_parent PP;
    address_child PC;
    address_MLL PM;
    data_child(LC);
    data_parent(LP);

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
        cout<<" -- PRINT DATA -- "<<endl;
        cout<<"14. Print Data Mahasiswa Yang Terdaftar ke TXT"<<endl;
        cout<<"15. Print Data Jurusan ke TXT"<<endl;
        cout<<"16. Print Data Yang Telah Memilih Jurusan Ke TXT"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"17. Total Pendafar"<<endl;
        cout<<"18. Total Pemilih Jurusan"<<endl;
        cout<<endl;
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
            input_MLL(LP, LC, LM);
            cout<<endl;
            system("pause");
            break;
        case 4:
            system("cls");
            printList_parent(LP);
            cout<<endl;
            cout<<"Nama Mahasiswa Baru Yang Ingin Diubah: ";
            cin.get();
            getline(cin, parentcari.nama);
            PP = searchbyName(LP, parentcari.nama);
            if(PP != NULL){
                cout<<"Mahasiswa Baru Ditemukan"<<endl;
                system("pause");
                system("cls");
                editData_parent(LP, PP);
                cout<<endl;
                cout<<"Data Berhasil Diubah"<<endl;
            } else {
                cout<<endl;
                cout<<"Mahasiswa Baru Tidak Ditemukan"<<endl;
            }
            system("pause");
            break;
        case 5:
            system("cls");
            printList_child(LC);
            cout<<endl;
            cout<<"Jurusan Yang Ingin Diubah: ";
            cin.get();
            getline(cin, childcari.jurusan_pilihan);
            PC = searchbyMajor(LC, childcari.jurusan_pilihan);
            if(PC != NULL){
                cout<<endl;
                cout<<"Jurusan Ditemukan"<<endl;
                system("cls");
                editData_child(LC, PC);
                cout<<endl;
                cout<<"Jurusan Berhasil Diubah"<<endl;
            } else {
                cout<<endl;
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
            cout<<endl;
            if(first_parent(LP) != NULL){
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
            } else {
                cout<<"Belum Ada Mahasiswa Yang Mendaftar"<<endl;
            }
            system("pause");
            break;
        case 10:
            system("cls");
            printList_child(LC);
            cout<<endl;
            if(first_child(LC) != NULL){
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
            } else {
                cout<<"Kampus Kami Belum Memiliki Jurusan Yang Tersedia Untuk Anda"<<endl;
            }
            system("pause");
            break;
        case 11:
            system("cls");
            printList_MLL(LM);
            cout<<endl;
            if(first_MLL(LM) != NULL){
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
            } else {
                cout<<"Belum Ada Mahasiswa Baru Yang Memilih Jurusan"<<endl;
            }
            system("pause");
            break;
        case 12:
            system("cls");
            printList_parent(LP);
            cout<<endl;
            if(first_parent(LP) != NULL){
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
            } else {
                cout<<"Belum Ada Mahasiswa Yang Mendaftar"<<endl;
            }
            system("pause");
            break;
        case 13:
            system("cls");
            printList_child(LC);
            cout<<endl;
            if(first_child(LC) != NULL){
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
            } else {
                cout<<"Kampus Kami Belum Memiliki Jurusan Yang Tersedia Untuk Anda"<<endl;
            }
            system("pause");
            break;
        case 14:
            system("cls");
            printText_parent(LP);
            cout<<"Data Sudah Dicetak"<<endl;
            system("pause");
            break;
        case 15:
            system("cls");
            printText_child(LC);
            cout<<"Data Sudah Dicetak"<<endl;
            system("pause");
            break;
        case 16:
            system("cls");
            printText(LM);
            cout<<"Data Sudah Dicetak"<<endl;
            system("pause");
            break;
        case 17:
            system("cls");
            sum = totalPendaftar_parent(LP);
            cout<<"Total Pendaftar Di Telkom University: "<<sum<<endl;
            cout<<endl;
            system("pause");
            break;
        case 18:
            system("cls");
            sum = totalPendaftar_child(LC);
            cout<<"Total Mahasiswa Yang Telah Memilih Jurusan: "<<sum<<endl;
            cout<<endl;
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
