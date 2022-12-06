#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){
    string balance;
    long b = 90, c;
    fstream file("record.txt");
    while (file.eof()==0)
    {
        file >> balance;
    }
    cout << "Balance: " << balance;
    file << balance;
    file.close();
    
}