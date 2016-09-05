//
//  bankdatabase.cpp
//  ** Colin Walsh
//  ** cjw254@psu.edu
//  ** Assignment 3,
//  Implementation for the bankdatabase class
//
//


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <istream>
#include "account.h"
#include "basic.h"
#include "bankdatabase.h"

using namespace std;
BankDatabase::BankDatabase(){
    numofAccounts = 0;
    string line, name;
    int type, Pin = 0, actNum = 0,  ctr = 0;
    size_t found2, found3, found4;
    double total = 0.0;
    
    ifstream inFile;
    inFile.open("/Users/cwalsh/Desktop/bankDatabase/bankDatabase/account.txt");
    
    while(getline(inFile, line)){
        
        type =  stoi(line.substr(0, 1));//type is always from position 0 - 1
        
        found2 = line.find(';', 2);//pos of semi after name
        found3 = line.find(';', found2 + 1);//pos of semi after actNumber
        found4 = line.find(';', found3 + 1);//pos of last semi
        
        name = line.substr(2, (found2 - 2) ); //Parse string form first semi to second
        actNum = stoi(line.substr(found2 + 1, found3 - found2));//Parse string form second semi to third
        Pin = stoi(line.substr(found3 + 1, found4 - found3));//Parse string form third  semi to 4th
        total = stod(line.substr(found4 + 1, string::npos));//Parse string form 4th semi to the end
        
        //creates account based on type
        if (type == 1) {
            Account *act = new Basic(actNum, Pin, name, total);
            accounts[ctr] = act;
            ctr++;
            numofAccounts++;
        }
        else if (type == 2) {
            Account *act = new Premium(actNum, Pin, name, total);
            accounts[ctr] = act;
            ctr++;
            numofAccounts++;
        }else {
            Account *act = new Platinum(actNum, Pin, name, total);
            accounts[ctr] = act;
            ctr++;
            numofAccounts++;

        }
    }
    inFile.close();
}
bool BankDatabase::athUser(){

    int actNum, PiN;
    cout << "Enter your Account Number... ";
    cin >> actNum;
    cout << "Enter your PIN: ";
    cin >> PiN;
    cin.ignore();
    //sets account pointer to account requested
    Account* act = getAccount(actNum);
    
if(act != nullptr){//check if the account exists
    if(act->validatePin(PiN)){//check if PIN is correct
        theAccount = act;
        return true;
    }
    }

    return false;
}
void BankDatabase::display(){
    for (int i = 0; i < numofAccounts; i++) {//loop through array of pointers
        cout << accounts[i]->toString() << endl; //print each account
    }
}
Account* BankDatabase::getAccount(int accountNum){
    for (int i = 0; i < numofAccounts; i++) {//loop through array of pointers
        if(accountNum == accounts[i]->getAccountNum()){//if account number matches entered number
            return accounts[i];
        
        }
    }
    return nullptr;
}

void BankDatabase::createAccount(){
    string name;
    int pin, type, actNum;
    double total;
    cout << "enter your name. ";
    getline(cin, name, '\n');
    cout << "Enter the pin you want to use. ";
    cin >> pin;
    cout << "What is your Initial Balance? ";
    cin >> total;
    cout << "What type of account to you want, 1, 2, or 3? ";
    cin >> type;
    
    actNum = numofAccounts + 1000 + pin + type; //creates account number
    
    if (type == 1) {
        Account *act = new Basic(actNum, pin, name, total);
        accounts[numofAccounts] = act;
        numofAccounts++;
    }
    else if (type == 2) {
        Account *act = new Premium(actNum, pin, name, total);
        accounts[numofAccounts] = act;
        numofAccounts++;
    }else {
        Account *act = new Platinum(actNum, pin, name, total);
        accounts[numofAccounts] = act;
        numofAccounts++;
        
    }
}
bool BankDatabase::deleteAccount(){
    int actNum, PiN;
    
    cout << "Enter your Account Number ";
    cin >> actNum;
    cout << "Enter your PIN: ";
    cin >> PiN;
    
    Account* act = getAccount(actNum);//get requested account
    
    if(act != nullptr){
        if(act->validatePin(PiN)){
            for (int i = 0; i < numofAccounts; i++) {
                if (accounts[i] == act) {
                    accounts[i] = accounts[numofAccounts - 1];//moves last element to position to position found
                    accounts[numofAccounts - 1] = nullptr;//moves
                    numofAccounts--;    
                    return true;
                }
            }
        }
    }
    
    return false;
}
void BankDatabase::credit(double amount){
    if(athUser()){//asks user for account and the authorizes that user
    theAccount->credit(amount);//calls account class credit member using the account pointer
    }
}
bool BankDatabase::debit(double amount){
    if(athUser()){//asks user for account and the authorizes that user
   return theAccount->debit(amount);//calls account class debit member using the account pointer
    }else{
        return false;
    }
}
BankDatabase::~BankDatabase(){
    ofstream outfile("/Users/cwalsh/Desktop/bankDatabase/bankDatabase/account.txt");
    for (int i = 0; i < numofAccounts; i++) {
            outfile << setprecision(2) << fixed <<  accounts[i]->toString() << endl;
            delete accounts[i];
        
    }

    outfile.close();
}