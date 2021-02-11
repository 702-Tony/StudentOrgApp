#pragma once
#include<string>
#include<vector>
#include "degree.h"

using namespace std;

class Student {
	public:
    //Default Constructor
		Student();
    //Constructor with string data from table
		Student(string student_ID, string first_Name, string last_Name, string email_Address, int _age, int daysInCourse1, int daysInCourse2, int daysInCourse3);
    //Destructor
		~Student();
		// Setters
		void SetStudentID(string studID);
		void SetFirstName(string FName);
		void SetLastName(string LName);
		void SetEmail(string emailAddr);
		void SetStudentAge(int studentAge);
    void SetCourseCompletion1(int daysNum);
    void SetCourseCompletion2(int daysNum);
    void SetCourseCompletion3(int daysNum);
		//Getters
		string GetStudentID();
		string GetFirstName();
		string GetLastName();
		string GetEmail();
		int GetStudentAge();
		int GetCourseCompletion1();
		int GetCourseCompletion2();
		int GetCourseCompletion3();
		virtual void print();
		virtual int GetDegreeProgram();

	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int courseComplete[3];

  protected:
     DegreeType degreeType;
};
