#include "Student.h"
#include <iostream>

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, Degree::DegreeProgram degreeProgram, int daysLeft[3]){
   SetStudentID(studentID);
   SetFirstName(firstName);
   SetLastName(lastName);
   SetEmail(emailAddress);
   SetStudentAge(studentAge);
   SetDegreeProgram(degreeProgram);
   SetDaysLeft(daysLeft);
}


void Student::SetStudentID(string studentID){
   this->studentID = studentID;
}

string Student::GetStudentID() const{
   return studentID;
}

void Student::SetFirstName(string firstName){
   this->firstName = firstName;
}

string Student::GetFirstName() const{
   return firstName;
}


void Student::SetLastName(string lastName){
   this->lastName = lastName;
}

string Student::GetLastName() const{
   return lastName;
}

void Student::SetEmail(string emailAddress){
   this->emailAddress = emailAddress;
}

string Student::GetEmail() const{
   return emailAddress;
}

void Student::SetStudentAge(int studentAge){
   this->studentAge = studentAge;
}

int Student::GetStudentAge() const{
   return studentAge;
}

void Student::SetDegreeProgram(Degree::DegreeProgram degreeProgram){
   this->degreeProgram = degreeProgram;
}

Degree::DegreeProgram Student::GetDegreeProgram(){
   return degreeProgram;
}

void Student::SetDaysLeft(int daysLeft[3]){
   for(int i = 0; i < 3; i++){
      this->daysLeft[i] = daysLeft[i];
   }
}

int * Student::GetDaysLeft(){
   return daysLeft;
}

string Student::GetDaysLeftString(){
   string days = "{" ;
   days.append(to_string(this->daysLeft[0]));
   days.append(", ");
   days.append(to_string(this->daysLeft[1]));
   days.append(", ");
   days.append(to_string(this->daysLeft[2]));
   days.append("}");
   return days;
}

void Student::Print(){
   cout << this->GetStudentID() << "\t";
   cout << "First Name: " << this->GetFirstName() << "\t";
   cout << "Last Name: " << this->GetLastName() << "\t";
   cout << "Age: " << this->GetStudentAge() << "\t";
   cout << "daysInCourse:" << this->GetDaysLeftString() << "\t";
   cout << "Degree Program: " << this->GetDegreeProgram() << endl;
}



