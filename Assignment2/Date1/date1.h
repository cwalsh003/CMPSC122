/*
** Colin Walsh
** cjw254@psu.edu
** Assignment 2,
** Date class 
*/
class Date1
{
	private:
		int month;
		int day;
		int year;
	public:
		Date1();
		Date1(int, int, int);
		int getMonth() const;
		int getDay() const;
		int getYear() const;
		void setMonth(int mon);
		void setDay(int day);
		void setYear(int year);
		void display();
		bool operator ==(const Date1& r1);
		
};