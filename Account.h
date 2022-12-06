#include<iostream>
#include<string.h>
using namespace std;

#include "Bank.h"
#include "functions.h"

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