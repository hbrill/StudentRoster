#include "Student.h"
#include <iostream>

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int classOne, int classTwo, int classThree, Degree::DegreeProgram degreeProgram){
   SetStudentID(studentID);
   SetFirstName(firstName);
   SetLastName(lastName);
   SetEmailAddress(emailAddress);
   SetStudentAge(age);
   SetRemainingDays(classOne, classTwo, classThree);
   SetDegreeProgram(degreeProgram);
}

void Student::SetStudentID(string studentID){
   this->studentID = studentID;
}

string Student::GetStudentID(){
   return studentID;
}

void Student::SetFirstName(string firstName){
   this->firstName = firstName;
}

string Student::GetFirstName(){
   return firstName;
}

void Student::SetLastName(string lastName){
   this->lastName = lastName;
}

string Student::GetLastName(){
   return lastName;
}

void Student::SetEmailAddress(string emailAddress){
   this->emailAddress = emailAddress;
}

string Student::GetEmailAddress(){
   return emailAddress;
}

void Student::SetStudentAge(int age){
   this->age = age;
}

int Student::GetStudentAge(){
   return age;
}

void Student::SetRemainingDays(int classOne, int classTwo, int classThree){
   remainingDays[0] = classOne;
   remainingDays[1] = classTwo;
   remainingDays[2] = classThree;
}

int* Student::GetRemainingDays(){
   return remainingDays;
}

void Student::SetDegreeProgram(Degree::DegreeProgram degreeProgram){
   this->degreeProgram = degreeProgram;
}

string Student::GetDegreeProgram(){
   string program;
   if(degreeProgram == 0){
      program = "Security";
   }else if(degreeProgram == 1){
      program = "Network";
   }else if(degreeProgram == 2){
      program = "Software";
   }

   return program;
}

void Student::Print(){
   cout << GetStudentID();
   cout << "\t First Name: " << GetFirstName() << "\t Last Name: " << GetLastName();
   cout << "\t Age: " << GetStudentAge() << "\t daysInCourse: {" << GetRemainingDays()[0] << 
   ", " << GetRemainingDays()[1] << ", " << GetRemainingDays()[2] << "}";
   cout << "\t Degree Program: " << GetDegreeProgram() << endl;
}