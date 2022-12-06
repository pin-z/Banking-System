#include<iostream>
#include<fstream>
using namespace std;

void box(string word) {
    int a, b, c = 80;
    a = 2*(word.length());
    b = a/4;
    for (int i = 0; i<= c; i++) {
     cout << " ";
    }
    for (int i = 0; i<=a; i++){
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i<= c; i++) {
     cout << " ";
    } 
    cout << "#";
    
    for (int i = 0; i<= b; i++) {
     cout << " ";
    }
    cout << word;
    for (int i = 0; i<= b-2; i++) {
     cout << " ";
    }
    cout << "#" << endl;
    for (int i = 0; i<= c; i++) {
     cout << " ";
    }
    for (int i = 0; i<=a; i++){
        cout << "#";
    }
    cout << endl;
}

int Card() {
    int card;
    path2:
    int a;
    cout << " YOU WANT TO APPLY FOR A CREDIT/DEBIT CARD? " << endl;
    cout << " 1.YES    2.NO" << endl << ">>> ";
    cin >> a;
    while (a < 1 || a > 2) {
        cout << " ERROR: INVALID INPUT!" << endl << ">>> ";
        cin >> a;
    }
    if(a == 1){
        int b;
        cout << " SELECT THE TYPE OF CARD. " << endl << "1.CREDIT    2.DEBIT    3.ATM " << endl << ">>> ";
        cin >> b;
        while (b < 1 || b > 3) {
            cout << " ERROR: INVALID INPUT!" << endl << ">>> ";
            cin >> b;}
        card = rand() % 9999 + 999;
        cout << " Congragulations! your request has been accepted. \n your card no is " << card << "."<< endl;
        cout << " Your card will be ready in next five working days " << endl;
        return card;
    }
    if(a == 2){
      goto path2;
     }
     return card;
}

void login(){
    string ID,password, email, pass;
    fstream read;
    cout << " NOTE:- Fill in the login credentials." << endl;
    input:
    cout << " Email ID: ";
    cin >> ID;
    read.open("record.txt");
    while (read.eof()==0) {
        read >> email;
        if(email == ID) {
            read.close();
            goto code;
        }
    }
    cout << "NOTE:- This ID is not registered!" << endl;
    read.close();
    goto input;
    code:
    read.open("record.txt");
    cout << " Password: ";
    cin >> password;
    while (read.eof()==0) {
        read >> pass;
        if(pass == password) {
           cout << " Welcome" << endl;
           read.close();
           break;
        }
    }
    if(pass!= password){
        read.close();
        cout << "Warning: Incorect Password!" << endl;
        goto code;  }
    }

    void Start() {
        system("cls");
        box("ELECTRONIC BANK LIMITED");
    }