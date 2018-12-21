#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//Class definitions
class student 
{
	int id;
	string name;
	string pword;
	int score;
	string grade;
	int level;
	string courseCode;
	
	public:
		void getCourse();
		void displayStudent();
		void displayCourse();
		int getScore();
		int getID() {
			return id;}
		string courseData() {
			return courseCode;}
		int getLevel() {
			return level;}
}studentClass;

class staff 
{
	int id;
	string name;
	string pword;
	
	public:
		void displayStaff();
	 	int getID() {
		 return id;}
}staffClass;

//Function prototyping 
void studentLogin();
void studentSignup();
void studentDashboard();
void adminLogin();
void adminSignup();
void adminDashboard();
void staffLogin();
void staffSignup();
void staffDashboard();
void addCourse();
void deleteCourse();
void deleteStaff();
void deleteStudent();
void displayAllStudent();
void displayAllStaff();
void editCourse();
void deleteCourse();
void editCourse();
void home();
void exitConsole();

//Menu Functions
void studentMenu()
{
	cout << "\n\n\n\t*************** STUDENT DATABASE *****************" << endl;
    cout << "\n\t0 - Exit \n\t1 - Student Signup \n\t2 - Student Login \n\t3 - Home" << endl;
    cout << "\n\n\tEnter your choice: ";
}
void staffMenu()
{
	cout <<  "\n\n\n\t*************** STAFF DATABASE ****************" << endl;
    cout << "\t0 - Exit \n\t1 - Staff Signup \n\t2 - Staff Login" << endl;
    cout << "\t3 - Home \n\n\tEnter your choice: ";
}
void adminMenu()
{
	cout <<  "\n\n\n\t***************** DATABASE ADMIN ********************" << endl;
    cout << "\t0 - Exit \n\t1 - Login as an Admin \n\t2 - Add New Admin \n\t3 - Home";
    cout << "\n\n\tOption: ";
}

void student::getCourse()
{
	 cout<<"Enter Course Code: ";
	 cin.ignore();
	 getline(cin, courseCode);
	 //Reading course from user
	 cout<<"Enter Score: ";
	 cin>>score;
	 //Calculating grade
	if(score >= 80 && score <= 100) grade="A";
	else if(score >= 75 && score <= 79) grade="B+";
	else if(score >= 70 && score <= 74) grade="B";
	else if(score >= 65 && score <= 69) grade="C+";
	else if(score >= 60 && score <= 64) grade="C";
	else if(score >= 55 && score <= 59) grade="D+";
	else if(score >= 50 && score <= 54) grade="D";
	else if(score >= 45 && score <= 49) grade="E";
	else grade="F";
}
void student::displayStudent()
{
	cout<<"=================================================\n";
 	cout<<"ID: " << id << "\tName: " << name << "\tLevel: " << level << "\n";
}
void staff::displayStaff()
{
	cout<<"=================================================\n";
 	cout<<"ID: " << id << "\tName: " << name <<"\n";
}
void student::displayCourse()
{
	cout << "\n\t\tACADEMIC RECORD" << endl;
	cout<<"=================================================\n";
 	cout<<"Course: " << courseCode << "\t\tScore: " << score << "\tGrade: " << grade << "\n";
}
int main()
{
	home();
	getch();
	return 0;
}

void home()
{
	char choice, choice1, choice2, choice3;
	cout << "\n\t\t<------------------------------------------------------->\n";
	cout << "\t\t\tWELCOME TO THE SCHOOL MANAGEMENT SYSTEM" << endl;
    cout << "\n\t\t<------------------------------------------------------->\n";
    cout << "\n\t\t*********************** HOME ************************";
    cout << "\n\n\t\t0 - Exit \n\t\t1 - Database Admin \n\t\t";
	cout << "2 - Student Database \n\t\t3 - Staff Database";
    cout << "\n\n\t\tChoice: ";
    cin >> choice;
    cout << "\n\n\n\n\n\t\tPowered by JeffTech";
    
    //Clearing console screen
    system("clear");
    switch(choice)
    {
    	case '0':
    		exitConsole();
    		break;
    		
    	case '1':
    		adminMenu();
    		cin >> choice1;
    		system("clear");
    		if (choice1 == '0')
    			exitConsole();
    		else if(choice1 == '1')
    			adminLogin();
    		else if (choice1 == '2')
    			adminSignup();
    		else if (choice1 == '3')
    			home();
    		else
    		{
    			cout << "\n\n\tIncorrect Option Selected. \nPlease try again.";
    			system("clear");
    			adminMenu();
			}
    		break;
    		
    	case '2':
    		studentMenu();
    		cin >> choice2;
    		system("clear");
    		if(choice2 == '0')
    			exitConsole();	
    		else if(choice2 == '1')
    			studentSignup(); 				
    		else if(choice2 == '2')
    			studentLogin();			
			else if(choice2 == '3')
				main();
			else
			{
				cout << "\n\n\tIncorrect Option Entered. \n\tPlease try again.";
				system("clear");
				studentMenu();
			}				
    		
    	case '3':
    		staffMenu();
    		cin >> choice3;
    		system("clear");
    		if (choice3 == '0')
    			exitConsole();
    		else if (choice3 == '1')
    			staffSignup();
    		else if (choice3 == '2')
    			staffLogin();
			else if (choice3 == '3')
				home();
	 		else
    		{
				cout << "\n\n\tIncorrect Option Entered. \n\tPlease try again.";
				system("clear");
				staffMenu();
			}
			break;
	}
}
void exitConsole(){
	cout << "\n\tThank you for using JeffTech School Management System";}

void studentDashboard()
{
	char opt, logout;
    cout << "************************** STUDENT DASHBOARD ******************************";
    cout << "\n\t0 - Exit \n\t1 - Add Course(s) \n\t2 - Delete Course(s)" 
	<< "\n\t3 - Display All Courses \n\t4 - Edit Course \n\t5 - Logout" << endl;
	cout << "\nOption: ";
    cin >> opt;
	switch(opt)
	{
	  	case '0':
	   		exitConsole;
	   		break;
	   	case '1':
	   		addCourse();
	   		break;
	   	case '2':
	   		deleteCourse();
	   		break;
	   	case '3':
	   		studentClass.displayCourse();
	   		break;
	   	case '4':
	   		editCourse();
	   		break;
	   	case '5':
	   		cout << "\nAre you sure you want to logout? (Y/N): ";
	   		cin >> logout;
	   		if (logout == 'y' || logout == 'Y')
	   		{
	   			system("clear");
	   			main();
	   		}
	   		else if (logout == 'n' || logout == 'N')
	   		{
	   			system("clear");
				studentDashboard();
			}		
	   		else
	   		{
	   			cout << "\nWrong option entered. Please try again";
	   			system("clear");
	   			studentDashboard();
			}
	   		break;
	}
}

void staffDashboard()
{
	char choice, logout;
    cout << "\n\n************************ STAFF DASHBOARD *************************";
    cout << "\n\t0 - Exit \n\t1 - Logout \n\ntOption: ";
    cin >> choice;
    system("clear");
    switch(choice)
    {
    	case '0':
    		exitConsole;
    		break;
		case '1':
    		cout << "\nAre you sure you want to logout? (Y/N): ";
    		cin >> logout;
    		if (logout == 'y' || logout == 'Y')
    		{
    			system("clear");
    			main();
    		}
    		else if (logout == 'n' || logout == 'N')
    		{
    			system("clear");
				staffDashboard();
			}		
    		else
    		{
    			cout << "\nWrong option entered. Please try again";
    			system("clear");
    			staffDashboard();
			}
    		break;
	}		
}

void adminDashboard()
{
	char choice, logout;
    cout << "\n\n********************* ADMIN DASHBOARD *********************";
    cout << "\n\t0 - Exit \n\t1 - Delete Staff Record";
	cout << " \n\t2 - Delete Student Record \n\t3 - Display All Student Record" << endl;
	cout << "\t4 - Display All Staff \n\t5 - Logout \n\n\tOption: ";
    cin >> choice;
    system("clear");
    switch(choice)
    {
    	case '0':
    		exitConsole();
    		break;
    		
    	case '1':
    		cout << "\t\t************** DELETE STAFF RECORD *************";
    		deleteStaff();
    		break;
    		
    	case '2':
    		cout << "\t\t************* DELETE STUDENT RECORD **************";
    		deleteStudent();
			break;    
		case '3':
			displayAllStudent();
			break;
		case '4':
			displayAllStaff();
			break;
		case '5':
    		cout << "\nAre you sure you want to logout? (Y/N): ";
    		cin >> logout;
    		if (logout == 'y' || logout == 'Y')
    		{
    			system("clear");
    			main();
    		}
    		else if (logout == 'n' || logout == 'N')
    		{
    			system("clear");
				adminDashboard();
			}		
    		else
    		{
    			cout << "\nWrong option entered. Please try again";
    			system("clear");
    			adminDashboard();
			}
    		break;
	}
}

void studentSignup()
{
    string name;
    int id, level;
    string pword, newPword;
    char hide1=' ', hide2=' ';
    cout << "\n\t\t*********************** Student Registraion **********************\n";
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Name: ";
    getline(cin, name);
    cout << "Enter Level: ";
    cin >> level;
    cout << "Password: ";
    //Masking user's input with asterisk to prevent data breach
    while (hide1 != 13)//13 == Enter key
    {
    	hide1 = getch();
    	if (hide1!=13)
    	{
    		pword+=hide1;
    		cout << "*";
		}
	}
    cout << "\nConfirm Password: ";
    while (hide2 != 13)//13 == Enter key
    {
    	hide2 = getch();
    	if (hide2!=13)
    	{
    		newPword+=hide2;
    		cout << "*";
		}
	}
    if (pword == newPword)
    { 
        //Saving new record to the database
    	ofstream write("studentDatabase.txt", ios::app);
        write << id << " " << pword << " " << name << " " << level << endl;
        cout << "\n\n\tCongratulations, you have successfully registered.";
        write.close();
        system("clear");
        studentDashboard();
    }

    else
    {
    	cout << "\n\nPasswords do not match.\n";
    	cout << "Please try again.\n";
    	system("clear");
		studentSignup(); 
	}
}

void staffSignup()
{
    string name;
    int id;
    string pword, newPword;
    char hide1=' ', hide2=' ';
    cout << "********************* Staff Registraion ***********************\n";
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Name: ";
    getline(cin, name); 
    cout << "Password: ";
    while (hide1 != 13)//13 == Enter key
    {
    	hide1 = getch();
    	if (hide1!=13)
    	{
    		pword+=hide1;
    		cout << "*";
		}
	}
    cout << "\nConfirm Password: ";
    while (hide2 != 13)//13 == Enter key
    {
    	hide2 = getch();
    	if (hide2!=13)
    	{
    		newPword+=hide2;
    		cout << "*";
		}
	}
    if (pword == newPword)
    { 
    	//Saving new record to the database
    	ofstream write("staffDatabase.txt", ios::app);
        write << id << " " << pword << " " << name << endl;
        cout << "\n\n\tCongratulations, you have successfully registered.";
        write.close();
        system("clear");
    	staffDashboard(); 
    }
    else
    {
        cout << "\n\nPasswords do not match.\n";
        cout << "Please try again.\n";
        system("clear");
        staffSignup();
    }     
       
}

void staffLogin()
{
    //Variable declarations
    int id, idAttempt;
    string pword, newPword;
    char hide=' ';
	int exist;
	cout << "\n\t\t\t\t<--------------------------------------------------->" << endl;
	cout << "\t\t\t\t\t\tSTAFF LOGIN" << endl;
	cout << "\n\t\t\t\t<--------------------------------------------------->" << endl;	
    cout << "Enter ID: ";
    cin >> idAttempt;
	cout << "Enter Password: ";
    while (hide != 13)//13 == Enter key
    {
    	hide = getch();
    	if (hide!=13)
    	{
    		newPword+=hide;
    		cout << "*";
		}
	}
    //Checking database to see if pass attempts are valid
    ifstream read("staffDatabase.txt");
    while (read >> id >> pword)
    {
        if (id == idAttempt && pword == newPword)
            exist = 1;
    }
    read.close();
    if (exist == 1)
    {
        cout << "Login Successful";
        cin.get();
        system("clear");
        staffDashboard();
    }
    else
    {
    	cout << "\n\nWrong ID or password.\n";
        cout << "Please try again.\n" << endl;
        system("clear");
        staffLogin();
	}
}

void studentLogin()
{
    //Variable declarations
    int id, idAttempt;
	char hide=' '; 
	int exist;
    string pword, newPword;
	cout << "\n\t<--------------------------------------------------->" << endl;
	cout <<"\t\tSTUDENT LOGIN" << endl;
	cout << "\n\t<--------------------------------------------------->" << endl;	
    cout << "Enter ID: ";
    cin >> idAttempt;
    cout << "Enter Password: ";
    while (hide != 13)//13 == Enter key
    {
    	hide = getch();
    	if (hide!=13)
    	{
    		newPword+=hide;
    		cout << "*";
		}
	}
    //Checking database to see if pass attempts are valid
    ifstream read("studentDatabase.txt");
    while (read >> id >> pword)
    {
        if (id == idAttempt && pword == newPword)
            exist = 1;
    }
    read.close();
    if (exist == 1)
    {
        cout << "\n\n\tLogin Successful";
        cin.get();
        system("clear");
        studentDashboard();
    }
    else
    {
    	cout << "\n\nWrong ID or password.\n";
        cout << "Please try again.\n" << endl;
        system("clear");
        studentLogin();
	}
}

void adminLogin()
{
	string username, unameAttempt;
	string adminPass="", pword="";
	char hide=' ';
	int exist;
	cout << "\n\t<--------------------------------------------------->" << endl;
	cout << "\t\t\tADMIN LOGIN" << endl;
	cout << "\n\t<--------------------------------------------------->" << endl;
	cout << "Username: ";
	cin >> unameAttempt;
	cout << "Password: ";
	while (hide != 13)//13 == Enter key
    {
    	hide = getch();
    	if (hide!=13)
    	{
    		adminPass+=hide;
    		cout << "*";
		}
	}
	//Checking database to see if pass attempts are valid
    ifstream read("admin.txt");
    while (read >> username >> pword)
    {
        if (username == unameAttempt && pword == adminPass)
            exist = 1;
    }
    read.close();
    if (exist == 1)
    {
        cout << "\nLogin Successful";
        cin.get();
        system("clear");
        adminDashboard();
    }
    else
    {
    	cout << "\n\nWrong ID or password.\n";
        cout << "Please try again.\n" << endl;
        system("clear");
        adminLogin();
	}
}

void adminSignup()
{
    string username;
    string pword="", newPword="";
    char hide1=' ', hide2=' '; 
    cout << "********************** Admin Registraion **********************\n";

    cout << "Enter Username: ";
    cin >> username;
    cout << "Password: ";
    
    while (hide1 != 13)//13 == Enter key
    {
    	hide1 = getch();
    	if (hide1!=13)
    	{
    		pword+=hide1;
    		cout << "*";
		}
	}
    cout << "\nConfirm password: ";
    while (hide2 != 13)//13 == Enter key
    {
    	hide2 = getch();
    	if (hide2!=13)
    	{
    		newPword+=hide2;
    		cout << "*";
		}
	}
    
    if (pword == newPword)
    { 
	    //Saving new record to the database
    	ofstream write("admin.txt", ios::app);
        write << username << " " << pword << endl;
        cout << "\n\n\tCongratulations, you have successfully registered.";
        write.close();
        system("clear");
        adminDashboard();
    }

    else
    {
        cout << "\n\nPasswords do not match.\n";
        cout << "Please try again.\n";
        system("clear");
        adminSignup();
    }     
}

//For adding the data into the file.
void addCourse()
{
 char opt='y';
 ofstream output("studentDatabase.txt", ios::app);
 while(opt=='y'||opt=='Y')
 {
  studentClass.getCourse();
  output.write((char*)&studentClass,sizeof(studentClass));
  cout<<"\nDo you want to add courses: ";
  cin>>opt;
  system("clear");
 }
 cout<<"\nCourse has been added successfully...\n";
 output.close();
 system("clear");
 studentDashboard();
}

void editCourse()
{
 fstream file("studentDatabase.txt",ios::in|ios::out|ios::binary|ios::app);
 string myCourse;
 char found='n';
 file.seekg(0);
 cout<<"\nEnter Course to be modified: ";
 cin>>myCourse;

while(file)
{
   int loc=file.tellg();
   file.read((char*)&studentClass,sizeof(studentClass));
   
	if(studentClass.courseData() == myCourse)
	{
  		studentClass.getCourse();
  		found='y';
  		file.seekg(loc);
  		file.write((char*)&studentClass,sizeof(studentClass));
  		cout<<"\nYour Course "<< myCourse <<" has been updated...";
	}
}
 if(found=='n') cout<<"\nCourse "<<myCourse<<" is not in the file...\n";
 file.close();
 system("clear");
 studentDashboard();
}

void deleteCourse()
{
 	string myCourse; 
 	char found='n';
 	fstream file("studentDatabase.txt",ios::in|ios::out|ios::binary|ios::app);

 	cout<<"\nEnter Course Code to be deleted: ";
 	cin>>myCourse;

while(file.read((char*)&studentClass,sizeof(studentClass)))
{
  	if(studentClass.courseData()==myCourse)
  	{
   		file.write((char*)&studentClass,sizeof(studentClass));
   		found='y';
		cout<<"\nCourse "<<myCourse<<" has been successfully deleted...\n";
		system("clear");
 		studentDashboard();
  	}
  	else
  	{
   		file.write((char*)&studentClass,sizeof(studentClass));
  	}
}
 	if(found=='n') 
	 	cout<<"\nCourse "<<myCourse<<" has not been registered...\n";
 	file.close();
 	system("clear");
 	studentDashboard();
}

void deleteStaff()
{
 int staffID; 
 char found='n';
 fstream file("staffDatabase.txt",ios::in|ios::out|ios::binary|ios::app);

 cout<<"\nEnter Staff ID to be deleted: ";
 cin >> staffID;

 while(file.read((char*)&staffClass,sizeof(staffClass)))
 {
  if(staffClass.getID() == staffID)
  {
   file.write((char*)&staffClass,sizeof(staffClass));
   found='y';
   cout<<"\nStaff Record of " << staffID <<" has been deleted successfully...\n";
   system("clear");
   adminDashboard();
  }
  else
  {
   file.write((char*)&staffClass,sizeof(staffClass));
  }
 }
 if(found=='n') cout<<"\nStaff " << staffID <<" could not be deleted...\n";
 file.close();
 system("clear");
 adminDashboard();
}

void deleteStudent()
{
 int studentID; 
 char found='n';
 fstream file("studentDatabase.txt",ios::in|ios::out|ios::binary|ios::app);

 cout<<"\nEnter Student ID to be deleted: ";
 cin >> studentID;

 while(file.read((char*)&studentClass,sizeof(studentClass)))
 {
  if(studentClass.getID() == studentID)
  {
   file.write((char*)&studentClass,sizeof(studentClass));
   found='y';
   cout<<"\nStudent Record of " << studentID <<" has been deleted successfully...\n";
   system("clear");
   adminDashboard();
  }
  else
  {
   file.write((char*)&studentClass,sizeof(studentClass));
  }
 }
 if(found=='n') cout<<"\nStudent " << studentID <<" could not be deleted...\n";
 file.close();
 system("clear");
 adminDashboard();
}

void displayAllStudent()
{
 ifstream input("studentDatabase.txt",ios::in|ios::binary);
 while(input.read((char*)&studentClass,sizeof(studentClass)))
 {
  studentClass.displayStudent();
 }
 input.close();
	system("clear");
	adminDashboard();
}

void displayAllStaff()
{
	ifstream input("staffDatabase.txt",ios::in|ios::binary);
	while(input.read((char*)&staffClass,sizeof(staffClass)))
	{
		staffClass.displayStaff();
	}
	input.close();
	system("clear");
	adminDashboard();
}
