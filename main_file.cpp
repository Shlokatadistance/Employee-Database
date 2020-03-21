#include <iostream>
#include "Employee.h"
#include <iomanip>
#include <string.h>
#include <fstream>
#include<sstream>
using namespace std;

void Employee:: Salary_Caps()
//This function takes in two ranges of salaries and outputs all the salaries within that range.
{
  //Salary caps (Input the range of the salary and output the list of employees who earn within that range)
  int lower_range, upper_range;
  cout<< "Enter the Lower Range of the Salary Caps: ";
  cin>> lower_range;
  cout<< endl;

  cout<< "Enter the Upper Range of the Salary Caps: ";
  cin>> upper_range;
  cout<< endl;

  string my_line, str_salary;
  int my_salary, str_length, index;
  ifstream fin;
  fin.open("data.txt");

  cout<< "Employees with salary between "<< lower_range<< " and "<< upper_range<<" are: "<<endl;

  while (getline(fin, my_line)){
    str_length=my_line.length();
    str_salary=my_line.substr(str_length-6, str_length);
    istringstream(str_salary)>> my_salary;// error in this

    if (my_salary<upper_range && my_salary> lower_range){
      index=my_line.find('\t');
      cout<< my_line.substr(0, index)<< endl;
    }
  }
  fin.close();
}



void Employee:: Add_Attributes()
// This function allows the user to define an attribute and append it to the main data file. The attribute can be of string type.
{

  string my_line, attr_name, type, user_input="";
  ifstream fin;
  fin.open("data.txt");

  ofstream fout;
  fout.open("New_Employee.txt");

  cout<< "Enter the name of the attribute: ";
  cin >> attr_name;
  cout<< endl;

  cout<< "Press 1. To initialize all values to 0 "<< endl;
  cout<< "Press 2. To input values separately for each employee "<< endl;

  cin >> type;
  cout<< endl;

  if (type=="1"){
    while (getline(fin, my_line))
    {
      fout<< my_line<<'\t'<< 0 << '\n';
    }
  }

  else if (type=="2"){
    while (getline(fin, my_line))
    {
      cin>> user_input;
      fout<< my_line<< '\t'<<user_input << '\n';
    }
  }

  fout.close();
  fin.close();
  int isRemoved= remove("data.txt");
  int isRenamed= rename("New_Employee.txt", "data.txt");
}



void Employee:: Add_Employee()
///This function enables the user to add an employee to the database and append the employee's credentials to the main data file
{

  char name[50], role[20],gender[8];
  string id;

  int age;
  int salary;
  cout<< "Enter New Employee's Name: ";
  cin>> name;
  cout<< "Enter New Employee's ID: ";
  cin>> id;
  cout<< "Enter New Employee's Age: ";
  cin>> age;
  cout<< "Enter New Employee's Salary: ";
  cin>> salary;
  cout<< "Enter New Employee's Role: ";
  cin>> role;
  cout <<"Enter New Employee's Gender: ";
  cin >> gender;

  ofstream fout;
  fout.open("data.txt", ios::app);

  if (fout.fail()) {
		cout << "Error in file opening!" << endl;
    exit(1);
  }
  fout<< name<<'\t'<<id<<'\t'<<age<<'\t'<<role<<'\t'<<gender<<'\t'<<salary<< endl;
  fout.close();
}



void Employee:: Deleting_Employee()
{
  // This function is just another name for 'firing' an employee.
  //Remove the employee (to remove a specific row, we shall replicate all the data into a new file except the one to be removed and then delete the previous file and rename the existing one)
  string id;
  cout<< "Enter the ID of the Employee to be deleted: ";
  cin>>id;

  ifstream fin;
  string my_line;

  fin.open("data.txt");
  int mylen=id.length();

  ofstream fout;
  fout.open("New_Employee.txt");

  while (getline(fin, my_line))
  {
    if (my_line.substr(0,mylen)!=id){
      fout<< my_line<< '\n';
    }
  }

  fout.close();
  fin.close();
  int isRemoved= remove("data.txt");
  int isRenamed= rename("New_Employee.txt", "data.txt");
}
char s1[50];

void Employee:: showDetails(void)
//Displays all details according to Employee's id. The user types in an id and the program displays the employee's information.
//This function is using c style of input and reading. We chose this method because the streaming method was not able to output any information after the 'strcmp' part.
//The methods we are using the FILE pointer and using the scanf,fopen and fclose methods
//The printing of the name of the employee was an issue, for which we declared s1 as a global variable
{
            FILE *file;
            string s;
            char name[100];
            char id[10];
            int age;
            char role[20];
            int salary;
            char gender[8];
            char checkId[10];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;



            strcpy(s1, checkId);

            file= fopen("data.txt", "r");

            while(fscanf(file, "%s", &name[0])!=EOF)
            {
                char temp_name[50], temp_id[10];
                strcpy(temp_name, name);
                fscanf(file, "%s", &id[0]);
                strcpy(temp_id, id);


                fscanf(file, "%d", &age);
                fscanf(file, "%s", &role[0]);
                fscanf(file, "%s", &gender[0]);
                fscanf(file, "%d", &salary);

                if(!strcmp(s1,id))
                {
                  cout<<"\nName: "<<temp_name;
                  cout<<"\nId: "<<temp_id;
                  cout<<"\nAge: "<<age;
                  cout<<"\nRole: "<<role;
                  cout<<"\nGender: "<<gender;
                  cout<<"\nSalary: "<<salary;
                }
            }
            fclose(file);
        }


void Employee:: Display_All_Data()
//This is a basic function. It simply outputs all the information of the employees present in the data file onto the computer screen.
{
  string my_line, name, id, age, role, gender, salary;
  /*char name[50];
  char id[10];
  int age;
  char role[20];
  char gender[8];
  int salary;*/

    cout << "Please enter Yes to continue" << endl;
    string ch;
    cin >> ch;

    string hello;

    if (ch == "Yes"){
      ifstream fin;
      fin.open("data.txt");
      if (fin.fail())
      {
        cout << "The file cannot be opened!" << endl;
        exit(1);
      }
      else
        cout<<"File working"<<endl;

      /*while (fin>> name>> id>> age>> role>> gender>> salary){
        cout<< name<<'\t'<< id<<'\t'<< age<<'\t'<< role<<'\t'<< gender<< '\t'<< salary<< endl;
      }*/
      while (getline(fin, my_line)){
        cout << my_line << endl;
      }
      fin.close();
    }
}


void Employee:: Edit_Existing ()
{
  string emp_name;
  cout<< "Enter the Employee name whose data is to be editted: ";
  cin>> emp_name;
  cout<< endl;
  int my_length;
  string role, salary, age, id, gender, myline;

  ifstream fin;
  fin.open("data.txt");

  ofstream fout;
  fout.open("my_data.txt");

  while (getline(fin, myline))
  {
    my_length=myline.find('\t');
    if (emp_name==myline.substr(0, my_length))
    {
      cout<< "Enter Employee's ID: ";
      cin>> id;
      cout<< "Enter Employee's Age: ";
      cin>> age;
      cout<< "Enter Employee's Gender: ";
      cin>> gender;
      cout<< "Enter Employee's Salary: ";
      cin>> salary;
      cout<< "Enter Employee's Role: ";
      cin>> role;
      fout<< emp_name<< '\t'<< id<<'\t'<< age <<'\t'<< role << '\t' << gender <<'\t'<< salary<< endl; //the new set of data
    }
    else
    {
      fout<<myline<<endl;
    }
  }
  int isRemoved= remove("data.txt");
  int isRenamed= rename("my_data.txt", "data.txt");
}



void killswitch(){
  //This is creative function we have added to the project.
  //Many databases have master control swtiches which allow the user to carry out some very important changes in the program.
  //This function,along with finalresolve allows to user to delete the data text file, in which all the employee information is sourced.
  cout << "Please respond with a choice" << endl;
  cout << "Yes or No?" << endl;
  string agreement;
  cin >> agreement;
  if (agreement == "Yes"){
    remove("data.txt");
    cout << "You have successfully deleted the employee database" << endl;
    cout << "Have a nice day" << endl;

  }
  else
    cout << "Make up your mind next time and try again " << endl;

}

void Employee:: finalresolve()
{
  cout <<setw(10)<<"Enter your passcode" << endl;
  string x;
  cin >> x;
  if (x=="pass"){
    killswitch();
  }
  else
    cout << "access denied" << endl;
}


void Employee:: sorttheinitialarray(string *nameholder, int length)
//This function uses the concepts of dynamic memory allocation.
//In this, a certain number of names from another file are read and are dynamically sorted.
//This function works in conjunction with dynamicsorter.
//The sorting algorithm applied in the below lines is similar to the bubble sort method.
//However, we haven't created any specific function for sort and simply made us of the swap functionality of c++.
{
	for (int a = 0; a < length-1; ++a)
	{
		int c = a;
		for (int b = a + 1; b < length; ++b)
		{
			if (nameholder[b] < nameholder[c])//checking lexographically
				c = b;
		}
		swap(nameholder[a], nameholder[c]);
	}
}
void Employee:: dynamicsorter()
{
  cout << "The number of names to be sorted";
	int length;
	cin >> length;
  ifstream fin;
  fin.open("test1.txt");

	if (fin.fail()){
    cout << "This file has errors" << endl;
    exit(1);
  }
  else
  cout << "The file works" << endl;

	int count = 0;
  string name;
  /*while (fin>>name){
    cout << name<<"\n";
    count++;
  }*/

  string *nameholder = new string[length];
	fin>>name;
  int count1 = 0;
	for (int i =0;i<length;++i){
		getline(fin,name);
		nameholder[i] = name;
		cout << name << endl;

	}
  //The following was another method we tried implementing, however, we were not able to pinpoint the exact number of inputs to be taken.
  //while (getline(fin, name)){
			//nameholder[count1]=name.substr(0, 10);
			//cout<< nameholder[count1]<< endl;
			//count1++;

		//}
		//swap(length,count1);


 sorttheinitialarray(nameholder, length);
 cout << "The sorted list is";
 for (int i = 0; i < length; ++i)
		cout << ": " << nameholder[i] << '\n';
    //removing the unecessary nullptr from the array
 delete[] nameholder;
}


void Employee:: Options()
{
  //This function serves as the startup menu or page for the user.
  //The function makes use of switch functionality and keeps on asking for inputs utill the user enters 0 and goes out the loop
  //The setfill manipulator has also been made use of.

    cout << "Welcome to the Employee Management system" << endl;
    cout << setfill('*');
    cout << " Please select your option" << endl;
    cout << "1. List of all Employees" << endl;
    cout << "2. Search for a particular Employee" << endl;
    cout << "3. Add an employee" << endl;
    cout << "4. Edit the details of an employee" << endl;
    cout << "5. Delete an employee" << endl;
    cout << "6. Generate the salary caps" << endl;
    cout << "7. Define an attribute" << endl;
    cout << "8. Do the dynamic sorting" << endl;
    cout << "9. The last straw" << endl;
    cout << setfill('*');

    cout << "Please enter your choice" << endl;
    int choice;
    //cin >> choice;
    int continuation=1;
    while (continuation != 0)
    {
      cin >> choice;
      switch (choice) {
                      case 1:
                          Display_All_Data();
                          break;
                          //after selecting 1, please enter Yes, so that the screen shows the required output
                      case 2:
                          showDetails();
                          break;
                      case 3:
                          Add_Employee();
                          break;
                     case 4:
                          Edit_Existing();
                          break;
                      case 5:
                          Deleting_Employee();
                          break;

                      case 6:
                          Salary_Caps();
                          break;
                      case 7:
                          Add_Attributes();
                          break;
                      case 8:
                          finalresolve();
                          break;
                      case 9:
                          dynamicsorter();
                          break;
                      default:
                          cout<<"\n Make a choice you imbecile \n";
                          break;
                  }
          cout<< "\nDo you want to continue?\n" << endl;
          cout<< "Press 0 To Exit"<<endl;
          cout<< "Press 1 To Continue"<<endl;
          cin>> continuation;
          cout<< endl;
 }
}

int main()
{
  Options();
  return 0;
}
