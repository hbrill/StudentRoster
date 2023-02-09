#include <iostream>
#include "Roster.h"

int main(){
   const string studentData[] = {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
      "A5,Heather,Brillant,hbrill1@wgu.edu,22,11,3,18,SOFTWARE"
   };

   int numStudents = sizeof(studentData) / sizeof(string);
   Roster newRoster(studentData, numStudents);
   newRoster.PrintAll();
   newRoster.Remove("A2");
   newRoster.PrintAverageDaysInCourse("A5");
   newRoster.PrintInvalidEmails();
   return 0;
}