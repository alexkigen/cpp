#include <iostream>
#include <string>

using namespace std;

class Employees {
	private:
		string company;
		
	public:
		int age;
		double salary;
		int serviceYears;
		string dept;
		
		void getCompany(string companyInput) {
			company = companyInput;
		}
		
		string printDetails () {
			return ("works for " + company + " in "+ dept);
		}
};

int main () {
	Employees Susan;
	
	Susan.getCompany("LOLO");
	Susan.age = 20;
	Susan.dept = "Marketing";
	Susan.salary = 125000;
	Susan.serviceYears = 5;
	
	cout << Susan.age << endl;
	cout << Susan.printDetails();
}
