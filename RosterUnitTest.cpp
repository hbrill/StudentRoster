#include "Roster.h"
#include <iostream>

int main(){
   const string testData[] = {
      "ID001,Danielle,Moonstar,dani_mirage@hotmail.com,18,39,40,35,NETWORK",
      "ID002,Douglas,Ramsey,douglasramsey@gmailcom,17,32,27,29,SOFTWARE",
      "ID003,Roberto,DaCosta,dacosta_bobby @mac.com,16,47,43,44,SECURITY",
      "ID004,Samuel,Guthrie,samuel.guthrietyahoo.com,19,45,43,46,SOFTWARE",
      "ID005,Katherine,Pryde,katherine_pryde@outlook.com,17,29,35,41,NETWORK"
   };

   cout << "\t\t\t\t\t\t -------------- BEGIN TEST --------------" << endl;
   Roster testRoster(testData);

   cout << "Testing PrintAll(). Expected: Print all students from ID001 to ID005." << endl;
   cout << "Output:" << endl;
   testRoster.PrintAll();
   cout << endl;

   cout << "Testing PrintInvalidEmails(). Expected: Invalid email output for students with IDs ID002, ID003 and ID004." << endl;
   cout << "Output:" << endl;
   testRoster.PrintInvalidEmails();
   cout << endl;

   cout << "Testing Remove(). Expected: Student with ID ID003 has been removed from the roster." << endl;
   cout << "Output: ";
   testRoster.Remove("ID003");
   cout << endl;

   cout << "Testing PrintAll(). Expected: Print remaining students with IDs 001, 002, 004 and 005." << endl;
   cout << "Output:" << endl;
   testRoster.PrintAll();
   cout << endl;

   cout << "Testing Remove(). Expected: No existing student with ID ID003." << endl;
   cout << "Output: ";
   testRoster.Remove("ID003");
   cout << endl;

   cout << "Testing PrintAverageDaysInCourse(). Expected: Average number of days to complete classes for student with ID ID002: 29.3 days." << endl;
   cout << "Output: ";
   testRoster.PrintAverageDaysInCourse("ID002");
   cout << endl;

   cout << "Testing PrintInvalidEmails(). Expected: Invalid email output for students with IDs ID002 and ID004." << endl;
   cout << "Output:" << endl;
   testRoster.PrintInvalidEmails();
   cout << endl;

   cout << "Testing PrintByDegreeProgram(). Expected: Information for students with IDs ID001 and ID005." << endl;
   cout << "Output:" << endl;
   testRoster.PrintByDegreeProgram(Degree::DegreeProgram::NETWORK);
   cout << endl;

   cout << "Testing Remove(). Expected: Student with ID ID005 has been removed from the roster." << endl;
   cout << "Output: ";
   testRoster.Remove("ID005");
   cout << endl;

   cout << "Testing PrintByDegreeProgram(). Expected: Information for student with ID ID001." << endl;
   cout << "Output:" << endl;
   testRoster.PrintByDegreeProgram(Degree::DegreeProgram::NETWORK);
   cout << endl;

   cout << "Testing PrintByDegreeProgram(). Expected: No students currently enrolled in the Security program." << endl;
   cout << "Output:" << endl;
   testRoster.PrintByDegreeProgram(Degree::DegreeProgram::SECURITY);
   cout << endl;

   cout << "\t\t\t\t\t\t -------------- END TEST ---------------" << endl;
   return 0;
}