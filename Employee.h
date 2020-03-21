/*  ENGG1340 Computer Programming 2
    Group Project [Employee Manaagement System]
    Group Number: 27
    Members:  Shandilya Eeshaanee (UID: 3035552234)
              Sinha Shlok (UID: 3035554256)

                                                      Employee.h file
    This is our header file which contains the function declarations by us that will be formally defined with codes in Employee.cpp file
    These attributes are defined by us for use in the Employee Management System's working

*/
#ifndef Employee_h
#define Employee_h
using namespace std;

class Employee
{
public:
  void Salary_Caps();
  void Add_Attributes();
  void Deleting_Employee();
  void Add_Employee();
  void Searching_Function();
  void Display_All_Data();
  void Options();
  void dynamicsorter();
  void sorttheinitialarray();
  void finalresolve();
  void killswitch();
  void Edit_Existing();
  char s1[50];
  void showDetails();

};

#endif // functsheader_H
