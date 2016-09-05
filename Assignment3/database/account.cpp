/*
** Colin Walsh
** cjw254@psu.edu
** Assignment , 
*/
#include <iostream>
#include "account.h"

using namespace std;

Account::Account(int actNum, int pin, string fulName, double balance){
	accountNumber = actNum;
	PIN = pin;
	fullName = fulName;
	totalBalance = balance;
	
	//cout << accountNumber << " " << PIN << " " << fullName << endl;
}
/*bool Account::validatePin(int pin){
	TODO 
		Check the pins in the database and return whether it is thre or not.
*/	
/*}
int Account::getAccountNum() const{
	return accountNumber;
}
double Account::getBalance() const{
	return totalBalance;
}*/
/*string toString(){
	string SactNum, SPin, SBalance, Sresult;
	SactNum = to_string(accountNumber);
	SPin = to_string(PIN);
	SBalance = to_string(totalBalance);
	
	//Sresult = 
}*/
/*void credit(double);
bool debit(double);
friend ostream& operator << (ostream& outs, const Account& source);*/