#include "roster.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com, 20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,4,SECURITY",
"A5,Anthony,Adams,aada220@wgu.edu,31,25,25,25,SOFTWARE"
};
Roster::~Roster() {
  //destructor
  for (int i = 0; i < studentCounter; ++i) {
    delete classRosterArray.at(i);
  }
  classRosterArray.clear();
  return;
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, int degreeProgramInt) {
  switch (degreeProgramInt) {
    case 0: //SOFTWARE
      classRosterArray.push_back(new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3));
      break;
    case 1: //SECURITY
      classRosterArray.push_back(new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3));
      break;
    case 2: //NETWORK
      classRosterArray.push_back(new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3));
      break;
  }
  studentCounter += 1;
  return;
}

void Roster::remove(string studentID) {
  bool matchFound = false;
  for (int i = 0; i < studentCounter; ++i) {
    if (classRosterArray.at(i)->GetStudentID() == studentID) {
      matchFound = true;
      delete classRosterArray.at(i);
      classRosterArray.erase(classRosterArray.begin() + i);
      studentCounter -= 1;
      //cout << "Match Found: " << studentID << " Deleted!" << endl;
      break;
    }
  }
  if (matchFound == false) {
    cout << "No student ID match found: Could Not Delete ";
    cout << studentID << "!" << endl;
  }
  return;
}
void Roster::printAll() {
  for (int i = 0; i < studentCounter; ++i) {
      classRosterArray.at(i)->print();
  }
  return;
}

void Roster::PrintAverageDaysInCourse(string studentID) {
  bool matchFound = false;
  for (int i = 0; i < studentCounter; ++i) {
    if (classRosterArray.at(i)->GetStudentID() == studentID) {
      int avg = (classRosterArray.at(i)->GetCourseCompletion1()
        + classRosterArray.at(i)->GetCourseCompletion2()
        + classRosterArray.at(i)->GetCourseCompletion3()) / 3;
      cout << "Average number of days for StudentID ";
      cout << classRosterArray.at(i)->GetStudentID() << " : ";
      cout << avg << endl;
      matchFound = true;
    }
  }
  if (!matchFound) {
    cout << "No Match Found for " << studentID << "!" << endl;
  }
  return;
}

void Roster::printInvalidEmails() {
  cout << "Invalid Emails : " << endl;
  //verifies all emails and prints invalid ones
  for (int i = 0; i < studentCounter; ++i) {
    // loop through classRosterArray and store Email
    bool validCheck = true;
    string str = classRosterArray.at(i)->GetEmail();
    int atIdx; //stores at sign index
    string sbstr;
    //check for spaces
    if (str.find(' ') != string::npos) {
      validCheck = false;
    }
    //check for @ sign
    if (str.find('@') == string::npos) {
      validCheck = false;
    } else {
      atIdx = str.find('@') + 1;
    }
    sbstr = str.substr(atIdx + 1);

    //check for period after at sign but not at end of string
    if (sbstr.find('@') != string::npos ||
        (sbstr.find('.') == string::npos ||
          sbstr.find('.') == sbstr.length()-1)) {
        validCheck = false;
    }
    if (!validCheck) {
      cout << str << endl;
    }
  }
  return;
}

void Roster::printByDegreeProgram(DegreeType degreeProgram) {
// 0: Software; 1: Security; 2: Network
  for (int i = 0; i < studentCounter; ++i) {
    if (classRosterArray.at(i)->GetDegreeProgram() == degreeProgram) {
      //cout << "Found" << endl;
      classRosterArray.at(i)->print();
    }
  }
  return;
}

int main() {
  //IMPORTANT project submission details below...
  cout << "Course Title : C867 Scripting and Programming" << endl;
  cout << "Language Used : C++" << endl;
  cout << "Student ID : 000968458" << endl;
  cout << "Student Name : Anthony Adams" << endl;
  //create roster object
  Roster classRoster;
  // array size of studentData for loop
  int arrSize = (sizeof(studentData)/sizeof(*studentData));
  //loop through array
  for (int i = 0; i < arrSize; ++i) {
    //Parse Data in each line and add to roster
    stringstream mySStream(studentData[i]);
    vector<string> result;
    int CSV_LENGTH = 9;//length of values delimited in student data string
    for (int k = 0; k < CSV_LENGTH; ++k) {
        string sbstr; //substring to store getline from
        getline(mySStream, sbstr , ','); //get line up to ',' and store in sbstr
        result.push_back(sbstr); //push substring into vector for values declared below
      }
    int RESULT_SIZE = static_cast<int>(result.size());
    //string is now parsed... add result items to individual variables
    string mainStudentID = result.at(0); //0: StudentID
    string mainFirstName = result.at(1); //1: firstName
    string mainLastName = result.at(2); //2: lastName
    string mainEmail = result.at(3); //3: email
    int mainAge = stoi(result.at(4)); //4: age
    int mainDaysInCourse1 = stoi(result.at(5)); //5: daysInCourse1
    int mainDaysInCourse2 = stoi(result.at(6)); //6: daysInCourse2
    int mainDaysInCourse3 = stoi(result.at(7)); //7: daysInCourse3
    int mainDegreeProgram;
    //8: degreeProgram--sets degree program corresponding to degree.h file
    if (result.at(8) == "SOFTWARE") {
      mainDegreeProgram = 0;
    } else if (result.at(8) == "SECURITY") {
      mainDegreeProgram = 1;
    } else if (result.at(8) == "NETWORK") {
      mainDegreeProgram = 2;
    }
    //add student to roster
    classRoster.add(mainStudentID, mainFirstName, mainLastName, mainEmail, mainAge, mainDaysInCourse1, mainDaysInCourse2, mainDaysInCourse3, mainDegreeProgram);
  }
  //pseudo code converted below
  classRoster.printAll();
  classRoster.printInvalidEmails();

  string stIDArr[5] = {"A1", "A2", "A3", "A4", "A5"};
  for (int j = 0; j < arrSize; ++j) {
    classRoster.PrintAverageDaysInCourse(stIDArr[j]);
  }

  cout << "Printing by degree program : Software" << endl;
  classRoster.printByDegreeProgram(SOFTWARE); //prints all students within Software degree program

  classRoster.remove("A3");//removes student
  classRoster.remove("A3");//prints error message because student is not found
}
