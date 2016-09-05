/*
** Colin Walsh
** cjw254@psu.edu
** Assignment , 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "bankDatabase.h"
#include "account.h"

using namespace std;

BankDatabase::BankDatabase(){
  string line, name;
  int type, Pin, actNum, found2, found3, found4;
  double total;

  ifstream inFile;
  inFile.open("account.txt");
    
    while(getline(inFile, line)){
      
      type =  stoi(line.substr(0, 1));//type is always from position 0 - 1
      
      found2 = line.find(';', 2);//pos of semi after name
      found3 = line.find(';', found2 + 1);//pos of semi after actNumber
      found4 = line.find(';', found3 + 1);//pos of last semi
      
      name = line.substr(2, (found2 - 2) );
      actNum = stoi(line.substr(found2 + 1, found3 - found2));
      Pin = stoi(line.substr(found3 + 1, found4 - found3));
      total = stod(line.substr(found4 + 1, string::npos));
      
      
    }
    Account act2(actNum, Pin, name, total);
    
    //cout << act2.getAccountNum() << endl;
}
/*bool BankDatabase::athUser(int accountNum, int pin);
Account* BankDatabase::getAccount(int accountNum);
void BankDatabase::display();
void createAccount();
bool deleteAccount();
void credit(double amount);
bool debit(double amount);
~BankDatabase();*/