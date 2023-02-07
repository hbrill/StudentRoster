#ifndef ROSTER_H
#define ROSTER_H
#include <vector>
#include "Student.h"

class Roster{
   public:
       void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram);
       void Remove(string studentID);
       void PrintAll();
       void PrintAverageDaysInCourse(string studentID);
       void PrintInvalidEmails();
       void PrintByDegreeProgram(Degree::DegreeProgram degreeProgram);
       vector<string> Parse(string data);
       Roster(const string data[5]);
       
   private:
      vector<Student*> classRosterArray;
};

#endif