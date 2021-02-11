#pragma once
#include <vector>
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

class Roster {

  public:
    ~Roster();
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, int degreeProgramInt);
    void remove(string studentID);
    void printAll(); //see section E.3.c
    void PrintAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeType degreeProgram);

  private:
    vector<Student*>classRosterArray;
    int studentCounter = 0;
};
