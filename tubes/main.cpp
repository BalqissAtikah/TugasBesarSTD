#include "MLL.h"

//Nama  : Wahyu Hauzan Rafi
//NIM   : 1301191313

int main()
{
    List_parent LP;
    List_child LC;
    List_MLL LM;

    createList_parent(LP);
    create_List_child(LC);
    createList_MLL(LM);

    menu(LP, LC, LM);
    return 0;
}
