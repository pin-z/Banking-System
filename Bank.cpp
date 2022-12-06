#include<iostream>
#include<fstream>
using namespace std;

#include "Bank.h"
#include "functions.h"

int main() {
    Start();
    box("LOGIN/SIGHNUP");
    int opt;
    cout << "Select from given menu!" << endl;
    cout << "   1.Login\n   2.Register" << endl << ">>> ";
    cin >> opt;
    while (opt < 1 || opt >2)
    {   system("cls");
        box("LOGIN/SIGHNUP");
       cout << "Select from given menu!" << endl;
        cout << "   1.Login\n   2.Register" << endl << ">>> ";
        cin >> opt;
    }
    Account A;
    if(opt == 1) {
        login();
    }
    if(opt == 2) {
        A.Create_account();
        A.Deposit();
        A.Save_data();
    }
    Home:
    Start();
    int O;
    cout << " Select from the given menu... " << endl;
    cout << "    1.Create new account. \n    2.Deposit money. \n    3.Withdraw money. \n    4.Check Balance. \n    5.Apply for Bank card. \n";
    cout << "    6.Account Info. \n    7.Exit Application." << endl << endl << ">>> ";
    cin >> O;
    while (O<1 ||O >7)
    {
        cout << " Please select from the given menu only!! " << endl;
        cout  << endl << endl << ">>> ";
        cin >> O;
    }
    switch (O)
    {
    case 1:
        A.Create_account();
        A.Deposit();
        A.Save_data();
        goto Home;
        break;
    case 2:
        A.Deposit();
        A.Save_data();
        goto exit;
        break;
    case 3:
        A.Withdrawl();
        A.Save_data();
        goto exit;
        break;
    case 4:
        A.Account_balance();
        goto exit;
        break;
    case 5:
        Card();
        goto exit;
        break;
    case 6:
        A.Retrive_data();
        goto exit;
        break;
    case 7:
        exit:
        int q;
        cout << " Do you want to exit? \n   1.Yes     2.No" << endl <<">>> ";
        cin >> q;
        while (q<1||q>2)
        {
        cout << " Do you want to exit? \n   1.Yes     2.No" << endl <<">>> ";
        cin >> q;
        }
        if(q==1) {
            cin.get();
        }
        if(q == 2) {
            goto Home;
        }
        break;
    default:
        goto Home;
        break;
    }
    return 0;
}