#include "Roster.h"
#include <iostream>
using namespace std;


void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram){
   int daysLeft[] = {daysInCourse1, daysInCourse2, daysInCourse3};
   Student newStudent(studentID, firstName, lastName, emailAddress, age, degreeProgram, daysLeft);
   Student* studentPtr = &newStudent;
   classRosterArray.push_back(studentPtr);

}

void Roster::Remove(string studentID){
   unsigned int i;
   Student *currStudent;
   bool studentFound = false;
   for(i = 0; i < classRosterArray.size(); i++){
      currStudent = classRosterArray.at(i);
      if(currStudent->GetStudentID() == studentID){
        delete currStudent;
        studentFound = true;
        break;
      }
   }

   if(!studentFound){
      cout << "Invalid student ID" << endl;
   }
}

void Roster::PrintAll(){
   int i;
   Student *currStudent;
   for(i = 0; i < classRosterArray.size(); i++){
      currStudent = classRosterArray.at(i);
      currStudent->Print();
   }
}

void Roster::PrintAverageDaysInCourse(string studentID){
   unsigned int i;
   int studentIndex;
   Student *currStudent;
   for(i = 0; i < classRosterArray.size(); i++){
      currStudent = classRosterArray.at(i);
      if(currStudent->GetStudentID() == studentID){
        studentIndex = i;
        break;
      }
   }
   
   if(studentIndex > -1){
      int avg = 0;
      int sum = 0;
      for(i = 0; i < 3; i++){
         sum += (classRosterArray.at(studentIndex))->Student::GetDaysLeft()[i];
      }
      avg = sum / 3;
      cout << "The average number of days for student with ID " << (classRosterArray.at(studentIndex))->GetStudentID() << " is " << avg << endl;
   }else{
      cout << "Invalid student ID" << endl;
   }
   
}


vector<string> Roster::Parse(string data){
   int begin = 0;
   int end;
   char delim = ',';
   vector<string> parsedData;
   for(int i = 0; i < data.size(); i++){
      end = data.find(delim);
      parsedData.push_back(data.substr(begin, end));
      data.replace(begin, end+1, "");
   }

   if(data == "SECURITY"){
      parsedData.at(8) = "0";
   }else if(data == "NETWORK"){
      parsedData.at(8) = "1";
   }else if(data == "SOFTWARE"){
      parsedData.at(8) = "2";
   }

   return parsedData;
}


Roster::Roster(const string studentData[5]){
   vector<string> parsedData;
   
   for(int i = 0; i < 5; i++){
      parsedData = this->Roster::Parse(studentData[i]);
      this->Add(parsedData.at(0), parsedData.at(1), parsedData.at(2), parsedData.at(3), stoi(parsedData.at(4)), stoi(parsedData.at(5)), stoi(parsedData.at(6)), stoi(parsedData.at(7)), (Degree::DegreeProgram) stoi(parsedData.at(8)));
    }
}

void Roster::PrintInvalidEmails(){
   //bool allValid = false;
   Student *currStudent;
   for(int i = 0; i < 5; i++){
      currStudent = (classRosterArray[i]);
      if(!(currStudent->Student::GetEmail().find('@') != string::npos && currStudent->Student::GetEmail().find('.') != string::npos && currStudent->Student::GetEmail().find('@') == string::npos)){
         cout << "Student with ID " << currStudent->Student::GetStudentID() << " has an invalid email address" << endl;
      }
   }
}

void Roster::PrintByDegreeProgram(Degree::DegreeProgram degreeProgram){
   Student *currStudent;
   for(int i = 0; i < 5; i++){
      currStudent = (classRosterArray[i]);
      if(currStudent->Student::GetDegreeProgram() == degreeProgram){
         cout << "Student with ID " << currStudent->Student::GetStudentID() << " is enrolled in this degree program." << endl;
      }
   }
}