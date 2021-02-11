#include "student.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
//### CONSTRUCTORS ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ###
Student::Student()
{
	studentID = "-1";
	firstName = "NoName";
	lastName = "NoLName";
	email = "None";
	age = -1;
  courseComplete[0] = -1;
  courseComplete[1] = -1;
  courseComplete[2] = -1;
  degreeType = SOFTWARE;
	return;
}
Student::Student(string student_ID, string first_Name, string last_Name, string email_Address, int _age, int daysInCourse1, int daysInCourse2, int daysInCourse3) {
  studentID = student_ID;
  firstName = first_Name;
  lastName = last_Name;
  email = email_Address;
  age = _age;
  courseComplete[0] = daysInCourse1;
  courseComplete[1] = daysInCourse2;
  courseComplete[2] = daysInCourse3;
  return;
}

//### DESTRUCTOR ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ###

Student::~Student()
{
  return;
}

//### MUTATORS ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ###

void Student::SetStudentID(string studID)
{
	studentID = studID;
}
void Student::SetCourseCompletion1(int daysNum)
{
  courseComplete[0] = daysNum;
}
void Student::SetCourseCompletion2(int daysNum)
{
  courseComplete[1] = daysNum;
}
void Student::SetCourseCompletion3(int daysNum)
{
  courseComplete[2] = daysNum;
}
void Student::SetFirstName(string FName)
{
	firstName = FName;
}
void Student::SetLastName(string LName)
{
	lastName = LName;
}
void Student::SetEmail(string emailAddr)
{
	email = emailAddr;
}
void Student::SetStudentAge(int studentAge)
{
	age = studentAge;
}

//### ACCESSORS ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ### ###

string Student::GetStudentID()
{
	return studentID;
}

string Student::GetFirstName()
{
	return firstName;
}

string Student::GetLastName()
{
	return lastName;
}
string Student::GetEmail()
{
	return email;
}

int Student::GetStudentAge()
{
	return age;
}
int Student::GetCourseCompletion1()
{
	return courseComplete[0];
}
int Student::GetCourseCompletion2()
{
	return courseComplete[1];
}
int Student::GetCourseCompletion3()
{
	return courseComplete[2];
}
int Student::GetDegreeProgram() {
	return -1;
}

void Student::print() {
	char tab_char = '\t';
  string degrees[3] = {"Software", "Security", "Network"};
  cout << studentID << tab_char;
  cout << "First Name: " << firstName << tab_char;
  cout << "Last Name: " << lastName << tab_char;
  cout << "Age: " << age << tab_char;
  cout << "daysInCourse: {" << courseComplete[0] << ", " << courseComplete[1] << ", " << courseComplete[2] << "}" << tab_char;
  cout << "Degree Program: " << degrees[degreeType];
  cout << endl;
  return;
}
