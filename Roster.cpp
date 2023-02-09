#include "Roster.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


Roster::Roster(const string studentData[], int numStudents){
    vector<string> parsedData;
    for(int i = 0; i < numStudents; i++){
        parsedData = Parse(studentData[i]);
        Add(parsedData.at(0), parsedData.at(1), parsedData.at(2), parsedData.at(3), stoi(parsedData.at(4)), stoi(parsedData.at(5)), stoi(parsedData.at(6)), stoi(parsedData.at(7)), Degree::DegreeProgram(stoi(parsedData.at(8))));
    }
}

vector<string> Roster::Parse(const string &studentData){
    char delim = ','; // comma separates data
    int start = 0; // beginning of string
    int end; // will be the first occurrence of the delimiter
    vector<string> studentVector;

    while(studentData.find(delim, start) != string::npos){
        end = studentData.find(delim, start); 
        studentVector.push_back(studentData.substr(start, (end-start)));
        start = end + 1;
    }

    end = studentData.size();

    if(studentData.substr(start, (end-start)) == "SECURITY"){
        studentVector.push_back("0");
    }else if(studentData.substr(start, (end-start)) == "NETWORK"){
        studentVector.push_back("1");
    }else if(studentData.substr(start, (end-start)) == "SOFTWARE"){
        studentVector.push_back("2");
    }

    return studentVector;
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram){
   index++;
   classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::Remove(string studentID){
   bool found = false;
   for(int i = 0; i < index; i++){
      if(classRosterArray[i]->GetStudentID() == studentID){
        found = true;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
        nullIndex = i;
        break;
      }
   }

   if(found){
    cout << "Student with ID " << studentID << " has been removed from the roster" << endl; 
    Shift(nullIndex);
    index--;
   }else{
    cout << "No existing student with student ID " << studentID << endl;
   }
}

void Roster::PrintAll(){
    for(int i = 0; i <= index; i++){
        classRosterArray[i]->Print();
    }
}

void Roster::Shift(int removeIndex){
   int toRemove = removeIndex;
   while(toRemove < index){
       classRosterArray[toRemove] = classRosterArray[toRemove + 1];
       classRosterArray[toRemove + 1] = nullptr;
       toRemove++;
   }
}

void Roster::PrintAverageDaysInCourse(string studentID){
    bool found = false;
    unsigned int i;
    for(i = 0; i <= index; i++){
        if(classRosterArray[i]->GetStudentID() == studentID){
            found = true;
            break;
        }
    }

    if(found){
        cout << fixed << setprecision(2);
        double classOne = classRosterArray[i]->GetRemainingDays()[0];
        double classTwo = classRosterArray[i]->GetRemainingDays()[1];
        double classThree = classRosterArray[i]->GetRemainingDays()[2];
        double average = (classOne + classTwo + classThree) / 3;
         
        cout << "Average number of days to complete classes for student with ID " << classRosterArray[i]->GetStudentID() << ": " << average << endl;
    }else{
        cout << "No existing student with student ID " << studentID << endl;
    }
}

void Roster::PrintInvalidEmails(){
    int invalidCount = 0;
    for(int i = 0; i <= index; i++){
        if(!(classRosterArray[i]->GetEmailAddress().find('@')) || 
        !(classRosterArray[i]->GetEmailAddress().find('.')) || 
        (classRosterArray[i]->GetEmailAddress().find(' ') != string::npos)){
            cout << "Student with ID " << classRosterArray[i]->GetStudentID() << "'s email does not meet the email standards." << endl;
            invalidCount++;
        }
    }

    if(invalidCount == 0){
        cout << "All student emails meet the email standards!" << endl;
    }
}