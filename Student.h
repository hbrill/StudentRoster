#ifndef STUDENT_H
#define STUDENT_H

#include "Degree.h"
#include <string>
using namespace std;

class Student{
   public:
      Student();
      Student(string studentID, string firstName, string lastName, string emailAddress, int age, int classOne, int classTwo, int classThree, Degree::DegreeProgram degreeProgram);
      void SetStudentID(string studentID);
      string GetStudentID();
      void SetFirstName(string firstName);
      string GetFirstName();
      void SetLastName(string lastName);
      string GetLastName();
      void SetEmailAddress(string emailAddress);
      string GetEmailAddress();
      void SetStudentAge(int age);
      int GetStudentAge();
      void SetRemainingDays(int classOne, int classTwo, int classThree);
      int* GetRemainingDays();
      void SetDegreeProgram(Degree::DegreeProgram degreeProgram);
      string GetDegreeProgram();
      void Print();


   private:
      string studentID;
      string firstName;
      string lastName;
      string emailAddress;
      int age;
      int remainingDays[3];
      Degree::DegreeProgram degreeProgram;
};

#endif