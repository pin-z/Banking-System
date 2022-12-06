#include<iostream>
#include<string.h>
using namespace std;

class Bank;
class Account;
class customer;
class Transections;

class Bank
{
private:
    string code, bank;

public:
    Bank(){
       code = "EBPAPKKA979";
       bank = "Electronic Bank Limited";
    }
    ~Bank(){}
    void display() {
        cout << " Bank Name = " << bank << endl;
        cout << "Bank Branch code = " << code << endl;
    }
};

class Extra{
public:
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

void Start() {
        system("cls");
        box("ELECTRONIC BANK LIMITED");
    }
};

class customer {
    public:
    string name, address, dob;
    string phone, CNIC;
    public:
    customer() {
        name = "";
        address = "";
        dob = "";
        phone = "00";
        CNIC = "";
        
    }
    customer& add_info() {
        string first, last;
        cout << " Fill in the following information about yourself to open an account. " << endl;
        cout << " First Name: ";
        cin >> first;
        cout << " Last Name: ";
        cin >> last;
        cout << " Email Address: ";
        cin >> address;
        cout << " Date of birth: ";
        cin >> dob;
        cout << " Phone no: ";
        cin >> phone;
        cout << " CNIC: ";
        cin >> CNIC;
        name = first + last;
        return *this;
    }
    customer& display_info() {
        cout << " Name: " << name << endl;
        cout << " Email Address: " << address << endl;
        cout << " Date of birth: " << dob << endl;
        cout << " Phone number: " << phone << endl;
        cout << " CNIC number: " << CNIC << endl;
        return *this;
    }
};

class Transections{
    public:
    long Balance;
    Transections() {
        Balance = 0;
    }
    Transections& Withdrawl() {
        path1:
        long W;
        cout << " Amount you want to withdraw: ";
        cin >> W;
        if(W < Balance) {
            Balance = Balance - W;
            cout << "Withdrawl Amount: " << W << endl;
            cout << "Remaining Balance:" << Balance << endl;
        }
        else if (W == Balance) {
            int a;
            cout << " Are you sure you want to withdraw all of your account balance! \n 1.Yes   2.No" << endl << ">>> ";
            cin >> a;
            while (a < 1 || a > 2) {
                cout << " ERROR: INVALID INPUT!" << endl << ">>> ";
                cin >> a;
            }
            if(a == 1){
                Balance = Balance - W;
                cout << "Withdrawl Amount: " << W << endl;
                cout << "Remaining Balance:" << Balance << endl;
            }
            if(a == 2){
                goto path1;
            }
        }
        else if (W > Balance) {
            cout << " Note:- Not enough Balance available in your account! Do you want loan our bank provides loan without any intreast rate. \n";
            int a;
            cout << " 1.Yes    2.No" << endl << ">>> ";
            cin >> a;
            while (a < 1 || a > 2) {
                cout << " ERROR: INVALID INPUT!" << endl << ">>> ";
                cin >> a;
            }
            if(a == 1){
                Balance = Balance - W;
                cout << "Withdrawl Amount: " << W << endl;
                cout << "Remaining Balance:" << Balance << endl;
            }
            if(a == 2){
                goto path1;
            }
        }
        return *this;
    }
    Transections& Deposit() {
        long d;
        cout << " Amount for deposit: ";
        cin >> d;
        Balance += d;
        cout << "Deposited Amount: " << d << endl;
        cout << "Net Account Balance:" << Balance << endl;
        return *this; 
    }
};

class Account: public Bank, public Transections, public Extra {
    long ACnumber;
    string password, type;
    customer A;
    public:
    Account() {
        ACnumber = 00;
        password = "";
    }
    Account& Create_account() {
        Start();
        A.add_info();
        Start();
        int a;
        cout << " Please select type of account." << endl <<  "1.Saving    2.Current" << endl; 
        cout << ">>> ";
        cin >> a;
        while(a < 1 || a > 2) {
            cout << " Please only select from given options only! " << endl;
            cout << " >>> ";
            cin >> a;
        }
        if (a == 1){ type = " Saving Account";}
        else if (a == 2){ type = "Current Account";}
        ACnumber = rand() % 9999999999999999 + 9999999999999999;
        cout << " Set password for your account." << endl;

        cout << " Password: ";
        cin >> password;
        Start();
        cout << " Congratulations you have successfully created an account in our bank!" << endl;
        cout << " your accounnt number is " << ACnumber;
        Save_data();
        
        return *this;
    }
    Account& Account_info() {
        Start();
        cout << " USER ACCOUNT INFO "<< endl;
        A.display_info();
        cout << " Account Number: " << ACnumber << endl;
        cout << " Account Type: " << type << endl;
        return *this;
        }
    void Account_balance(){
        Start();
        cout << " Your Account Balance is " << Balance << endl;
    }
     void Save_data(){
        fstream file("record.txt");
        file << password <<endl;
        file << " Account Number: " << ACnumber << endl;
        file << " Account Type: " << type << endl;
        file << " Name: " << A.name << endl;
        file << " Email Address: " << A.address << endl;
        file << " Date of birth: " << A.dob << endl;
        file << " Phone number: " << A.phone << endl;
        file << " CNIC number: " << A.CNIC << endl;
        file << " Your Account Balance is " << Balance << endl; }
    void Retrive_data() {
        fstream data("record.txt");
        string line;
        while(data.eof() == 0) {
            getline(data, line);
            cout << line << endl;
        }
        data.close();
    }
};


