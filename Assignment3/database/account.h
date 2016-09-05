/*
** Colin Walsh
** cjw254@psu.edu
** Assignment , 
*/
#include <iostream>
#include <string>


using namespace std;

class Account{
	public:
		int accountNumber;
		int PIN;
		string fullName;
		double totalBalance;
	
		Account(int, int, string, double);
		/*bool validatePin(int);
		int getAccountNum() const;
		double getBalance() const;
		string toString();
		void credit(double);
		bool debit(double);
		friend ostream& operator << (std::ostream& outs, const Account& source);*/
	};