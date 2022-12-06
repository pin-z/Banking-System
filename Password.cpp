#include<iostream>
#include<fstream>
using namespace std;

int main() {
    start:
    string password, Alphabets, Numbers, SpChar, Small_Alpha, Characters;
    Alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Small_Alpha = "abcdefghijklmnopqrstuvwxyz";
    Numbers = "0123456789";
    SpChar = "!£$%^&*()@#/%+-";
    Characters = Alphabets + Small_Alpha + Numbers + SpChar;
    password = "";
    int random;
    for (int i = 0; i<8; i++){
        random = rand() % 78;
        password += Characters[random];
    }
    string word;
    cout << " Password for? ";
    cin >> word;
    cout << " Generated Password is " << password << endl;
    fstream file("Password.txt");
    file.end;
    file << word << " = " << password << endl;
    int a;
    goto start;
    return 0;
}