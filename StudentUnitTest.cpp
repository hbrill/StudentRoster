#include "Student.h"
#include <iostream>

int main(){
   Student testStudent("ID909", "Jane", "Doe", "jane_doe@test.com", 27, 47, 33, 23, Degree::DegreeProgram::SECURITY);
   cout << "-------------- BEGIN TEST --------------" << endl;
   cout << "Expects: ID909               Output: " << testStudent.GetStudentID() << endl;
   cout << endl;
   cout << "Expects: Jane                Output: " << testStudent.GetFirstName() << endl;
   cout << endl;
   cout << "Expects: Doe                 Output: " << testStudent.GetLastName() << endl;
   cout << endl;
   cout << "Expects: jane_doe@test.com   Output: " << testStudent.GetEmailAddress() << endl;
   cout << endl;
   cout << "Expects: 27                  Output: " << testStudent.GetStudentAge() << endl;
   cout << endl;
   cout << "Expects: 33                  Output: " << testStudent.GetRemainingDays()[1] << endl;
   cout << endl;
   cout << "Expects: Security            Output: " << testStudent.GetDegreeProgram() << endl;
   cout << endl;
   cout << "Expects: ID909    First Name: Jane        Last Name: Doe  Age: 27         daysInCourse: {47, 33, 23}      Degree Program: Security" << endl;
   cout << "Output: " << endl;
   testStudent.Print();
   cout << endl;
   cout << "-------------- END TEST ---------------" << endl;

   return 0;
}