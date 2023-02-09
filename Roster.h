#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"
#include <vector>

class Roster{
   public:
      Roster(const string studentData[], int numStudents);
      vector<string> Parse(const string &studentData);
      void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram);
      void Remove(string studentID);
      void PrintAll();
      void Shift(int removeIndex);
      void PrintAverageDaysInCourse(string studentID);
      void PrintInvalidEmails();

   private:
      Student *classRosterArray[5];
      int index = -1;
      int nullIndex = -1;
};

#endif