#pragma once
#include "student.h"

class NetworkStudent : public Student {
  public:
    NetworkStudent(string student_ID, string first_Name, string last_Name, string email_Address, int _age, int daysInCourse1, int daysInCourse2, int daysInCourse3) : Student(student_ID, first_Name, last_Name, email_Address,  _age, daysInCourse1, daysInCourse2, daysInCourse3){
      degreeType = NETWORK;
    };
    int GetDegreeProgram();
};
