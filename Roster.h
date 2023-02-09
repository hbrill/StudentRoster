#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"
#include <vector>

class Roster{
   public:
      ~Roster();
      Roster(const string studentData[]);
      vector<string> Parse(const string &studentData);
      void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram);
      void Remove(string studentID);
      void PrintAll();
      void PrintAverageDaysInCourse(string studentID);
      void PrintInvalidEmails();
      void PrintByDegreeProgram(Degree::DegreeProgram degreeProgram);

   private:
      void Shift(int removeIndex);
      Student *classRosterArray[5];
      int index;
      int nullIndex;
};

#endif