#ifndef STUDENT_H
#define STUDENT_H

#include "Degree.h"
#include <string>
using namespace std;


class Student{
    public:
      Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, Degree::DegreeProgram degreeProgram, int daysLeft[3]);
      void SetStudentID(string studentID);
      string GetStudentID() const;
      void SetFirstName(string firstName);
      string GetFirstName() const;
      void SetLastName(string lastName);
      string GetLastName() const;
      void SetEmail(string emailAddress);
      string GetEmail() const;
      void SetStudentAge(int studentAge);
      int GetStudentAge() const;
      void SetDegreeProgram(Degree::DegreeProgram degreeProgram);
      Degree::DegreeProgram GetDegreeProgram();
      void SetDaysLeft(int daysLeft[3]);
      string GetDaysLeftString();
      int* GetDaysLeft();
      void Print();
      
    private:
      string studentID;
      string firstName;
      string lastName;
      string emailAddress;
      int studentAge;
      Degree::DegreeProgram degreeProgram;
      int daysLeft[3];
};

#endif