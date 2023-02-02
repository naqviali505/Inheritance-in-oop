#include<iostream>
using namespace std;
class Person 
{
	int age;
	int ID;
	char* lname;
	char* fname;
public:
	Person()
	{
		fname = nullptr;
		lname = nullptr;
		ID = 0;
		age = 0;
	}
	Person(int _ID, char* _fname,char* _lname, int _age)
	{
		cout << "In constructor of class Person\n";
		age = _age;
		ID = _ID;
		fname = new char[strlen(_fname) + 1];
		for (int i = 0; i < strlen(_fname) + 1; i++)
		{
			fname[i] = _fname[i];
		}
		
		lname = new char[strlen(_lname) + 1];
		for (int i = 0; i < strlen(_lname) + 1; i++)
		{
			lname[i] = _lname[i];
		}
		
	}
	int getage()
	{
		return age;
	}
	void print()
	{
		cout << fname <<"  " << lname;
	}
	void setID()
	{
		cout << "Enter an ID\n";
		cin >> ID;
	}
	void setage()
	{
		cout << "Enter an age\n";
		cin >> age;
	}
	void setfname()
	{
		cout << "Enter first name\n";
		cin >> fname;
	}
	void setlname()
	{
		cout << "Enter last name\n";
		cin >> lname;
	}
	~Person()
	{
		cout << "Destructor of class Person\n";
		if (fname != NULL)
		{
			delete[]fname;
			fname = NULL;
		}
		if (lname != NULL)
		{
			delete[]lname;
			lname = NULL;
		}
	}
};
class Student :public Person
{
	double cgpa;
	char* rollno;
public:
	Student()
	{
		rollno = nullptr;
		cgpa = 0.0;
	}
	Student(int ID, char* fname, char* lname, int age,double _cgpa, char* _rollno):Person( ID, fname, lname,age)
	{
		cout << "In constructor of class Student\n";
		cgpa = _cgpa;
		rollno = new char[strlen(_rollno) + 1];
		for (int i = 0; i < strlen(_rollno) + 1; i++)
		{
			rollno[i] = _rollno[i];
		}
		
	}
	void input()
	{
		setID();
		setfname();
		setlname();
		cout << "Enter CGPA\n";
		cin >> cgpa;
		cout << "Enter roll number\n";
		cin >> rollno;
		setage();
	}
	void print()
	{
		Person::print(); 
		cout << " is " << getage() << " years old,his cgpa is " << cgpa;
	}
	~Student()
	{
		cout << "Destructor of class Student\n";
		if (rollno != NULL)
		{
			delete[]rollno;
			rollno = NULL;
		}
	}
};
class Undergraduate :public Student
{
	char* fyp;
public:
	Undergraduate()
	{
		fyp = nullptr;
	}
	Undergraduate(int ID, char* fname, char* lname, int age, char* rollno, double cgpa, char* _fyp)
		:Student(ID, fname, lname, age, cgpa, rollno)
	{
		cout << "In constructor of class Undergraduate\n";
		fyp = new char[strlen(_fyp) + 1];
		for (int i = 0; i < strlen(_fyp) + 1; i++)
		{
			fyp[i] = _fyp[i];
		}
		
	}
	char* getfyp()
	{
		return fyp;
	}
	~Undergraduate()
	{
		cout << "Destructor of class Undergraduate\n";
		if (fyp != NULL)
		{
			delete[]fyp;
			fyp = NULL;
		}
		
	}
	void input()
	{
		cout << "Enter final year project\n";
		cin >> fyp;
	}
	void print()
	{
		Student::print();
		cout << "and his final year project is titled " << fyp << endl;
	}
};
class Graduate : public Student
{
	char* thesis;
	char* supervisor;
public:
	Graduate(int ID, char* fname, char* lname, int age, char* rollno, double cgpa, char* _thesis,char *_supervisor)
		:Student(ID, fname, lname, age, cgpa, rollno)
	{
		cout << "In constructor of class Graduate\n";
		thesis = new char[strlen(_thesis) + 1];
		for (int i = 0; i < strlen(_thesis) + 1; i++)
		{
			thesis[i] = _thesis[i];
		}
		
		supervisor = new char[strlen(_supervisor) + 1];
		for (int i = 0; i < strlen(_supervisor) + 1; i++)
		{
			supervisor[i] = _supervisor[i];
		}
		
	}
	void input()
	{
		cout << "Enter thesis\n";
		cin >> thesis;
		cout << "Enter supervisor's name\n";
		cin >> supervisor;
	}
	void ChangeInfo(char* ThesisTopic)
	{
		thesis = new char[strlen(ThesisTopic) + 1];
		for (int i = 0; i < strlen(ThesisTopic) + 1; i++)
		{
			thesis[i] = ThesisTopic[i];
		}
		
	}
	void ChangeInfo(char* ThesisTopic, char* Supervisor)
	{
		thesis = new char[strlen(ThesisTopic) + 1];
		for (int i = 0; i < strlen(ThesisTopic) + 1; i++)
		{
			thesis[i] = ThesisTopic[i];
		}
		
		supervisor = new char[strlen(Supervisor) + 1];
		for (int i = 0; i < strlen(Supervisor) + 1; i++)
		{
			supervisor[i] = Supervisor[i];
		}
	}
	void print()
	{
		Student::print();
		cout << " and his thesis topic is" << thesis << " under supervision of " << supervisor << endl;
	}
	~Graduate()
	{
		cout << "Destructor of class Graduate\n";
		if (thesis != NULL)
		{
			delete[]thesis;
			thesis = NULL;
		}
		if (supervisor != NULL)
		{
			delete[]supervisor;
			supervisor=NULL;
		}
	}
};
void main()
{
	char roll1[] = "14L-4171";
	char roll2[] = "17L-6171";
	char fname1[] = "Ted";
	char fname2[] = "Arnold";
	char lname2[] = "Gates";
	char lname1[] = "Thompson";
	char fyp[] = "The Event Locator";
	char thesis[] = "Distributed Algorithms";
	char supervisor[] = "Dr. Kashif Zafar";
	char fname3[] = "Ali";
	char lname3[] = "Raza";
	char rollno3[] = "19L-1015";
	char fyp3[] = "Traffic Lights Management System";
	//format (ID, fName, lName, Age, RollNumber, cgpa, fyp/thesis)
	Student* s = new Undergraduate(1, fname1,lname1, 22,roll1, 3.91,fyp );
	Student* s2 = new Graduate(2, fname2, lname2, 25, roll2, 3.01,thesis,supervisor);
	Person* s3 = new Undergraduate(3, fname3, lname3, 20, rollno3, 2.90, fyp3);
	//Exercise_3
	Graduate obj(2, fname2, lname2, 25, roll2, 3.01, thesis, supervisor);
	Undergraduate obj1(4, fname3, lname3, 19, rollno3, 3.33, fyp3);
	obj.input();
	obj1.input();
	char fyp11[] = "Sherlock Holmes";
	char fyp12[] = "Charlie Chaplin";
	char super[] = "Dr. Adeeb Rizvi";
//IN exercise 4, the comiler knows whihc function to execute by 
	//their different parameters
	s->print();
	cout << endl;
	s->input();
	s2->print();
	cout << endl;
	s2->print();
	cout << endl;
	s->print();
	cout << endl;
	s2->print();
	cout << endl;
	//Exercise 3
	//By printing s3, we call print function of Person Class so it will only print the name of the object 
	s3->print();
	cout << endl;
	obj.ChangeInfo(fyp11);
	obj.print();
	cout << endl;
	obj.ChangeInfo(fyp12, super);
	obj.print();
	cout << endl;
}
