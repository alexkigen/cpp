#include <iostream>
#include <string>
#include <sstream>

//create a patch to correct system error not recognizing to_string as a member of std

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm;
        stm << n ;
        return stm.str() ;
    }
}

//create a class called employees
class Employees {
	private:
		std::string company;
		
	public:
		std::string empName;
		int age;
		double salary;
		int serviceYears;
		std::string dept;
		
		void getCompany(std::string companyInput) {
			company = companyInput;
		}
		
		std::string toString (int nonString) {
			std::string stringConv = patch::to_string(nonString);
			return stringConv;
		}
		
		std::string printDetails () {
			return (empName + " is age " + toString(age) + " and has worked for " + company + " in "+ dept + " for " + toString(serviceYears) + " years");
		}
		
};

using namespace std;

int main () {
	Employees Susan;
	
	Susan.getCompany("LOLO");
	Susan.empName = "Susan";
	Susan.age = 20;
	Susan.dept = "Marketing";
	Susan.salary = 125000;
	Susan.serviceYears = 5;
	
	cout << Susan.age << endl;
	cout << Susan.printDetails();
}
