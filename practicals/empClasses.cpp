//create a class called Employees to hold employee details

#include <iostream>
#include <string>
#include <sstream>
#include <map>

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

//create a class called Employees

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
		//	std::string stringConv = patch::to_string(nonString); //use with Dev C++
            std::string stringConv = std::to_string(nonString); //use with Visual Studio
			return stringConv;
		}
		
		std::string printDetails () {
			return (empName + " is age " + toString(age) + " and has worked for " + company + " in "+ dept + " for " + toString(serviceYears) + " years");
		}

        //build a constructor for the class
        //default constructor
        Employees () {
            getCompany("LOLO");
            empName = "Average Employee";
            age = 45;
            salary = 120000;
            serviceYears = 3;
            dept = "Operations";
        }

        //input-supplied constructor (we can also supply default inputs here e.g. int age_ = 45, etc. instead of the default above)
        Employees (std::string company_, std::string empName_, int age_, double salary_, int serviceYears_, std::string dept_) {
            
            getCompany(company_);
            empName = empName_;
            age = age_;
            salary = salary_;
            serviceYears = serviceYears_;
            dept = dept_;

        }

		
};

using namespace std;

int main () {
    Employees Susan("LOLO", "Susan", 45, 130000, 5, "Marketing");
    Employees Karen("LOLO", "Karen", 32, 206000, 5, "Operations");

    cout << "Karen is age " << Karen.age << " and they work in " << Karen.dept << " earning $" << Karen.salary << endl;
    cout << "Susan is age " << Susan.age << " and they work in " << Susan.dept << " earning $" << Susan.salary << endl;

    //using printDetails function

    cout << Karen.printDetails() << endl;
    cout << Susan.printDetails() << endl;

    //Test default constructor
    Employees AvgEmp;
    cout << AvgEmp.printDetails() << endl;

    //create a map with employee names and index

    map<string, int> empMap;

    empMap.insert(make_pair("Susan", 1));
    empMap.insert(make_pair("Karen", 2));
    empMap.insert(make_pair("Jedidiah", 3));
    empMap.insert(make_pair("Obadiah", 4));

    cout << "\t" << "Employee Name" << "\t\t" << "Index Number" << endl;
    for (auto emp : empMap) {
        cout << "\t" << emp.first << "\t\t" << "Employee " << emp.second << endl;
    }

}