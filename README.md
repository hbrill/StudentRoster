# C867: StudentRoster Project

The StudentRoster project simulates a school database that stores student records with data such as student ID, name, age, current days in classes, and degree program. The project consists of two core classes to function, as well as these classes header files:

* Student.cpp / Student.h - The header file and definition for Student. It defines all of the data members, accessors and mutators previously mentioned for the Student class, as well as the constructor. Each object of type student should have a student ID, first name, last name, email, age, an array containing the days of three different classes, and a enum variable that specifies the degree program. It also defines a constructor for the class, and all setters and getters for the previously mentioned data members.

* Roster.cpp / Roster.h - The class header and definition for Roster. A roster should contain an array of pointers to various student objects, and the following methods:
  - A constructor that takes in student data and parses it to create objects.
  - A class destructor to remove the memory allocated by instantiating the Roster class
  - A private Parser() method that takes a string and parses it into student data for objects.
  - An Add() method that takes in the data parsed by the Parser() method and uses this data to create an object of the student class.
  - A Remove() method that takes in a student ID, and if it finds a student with that ID, removes it from the roster.
  - A PrintAll() method that iterates over the roster array and prints all data for each object in a formatted manner.
  - A PrintAverageDaysInCourse() method, which also takes in a student ID and if it finds a student with that ID it prints the student's average days in classes.
  - A PrintInvalidEmails() method, which prints which students, if any, have emails that do not meet the standard. The standard for emails is to include a dot, an @, and no spaces.
  - A PrintByDegreeProgram() method, which takes in a degree program and prints which, if any, of the students are enrolled in the specified degree program.
  - A private Shift() method, which should be used internally only to adjust the roster array when a student object is removed.

* Degree.h - A header file that only contains the enum definition for three different degree programs: Security, Network and Software.

* RosterUnitTest.cpp and StudentUnitTest.cpp - Two unit tests for the Roster and Student classes, respectively.

* And a main function.

## Compile and run program:
The program can be run in a standard way. However, to be able to pass in an enum variable the program utilizes a method that was not introduced until C++11. This only means that when running the program it is safer to pass in the -std=c++11 flag to avoid a compiler warning.

To compile and run main:

g++ -o TestMain Student.cpp Roster.cpp main.cpp -std=c++11, then run with ./TestMain

To compile and run unit tests:

g++ -o TestRoster Student.cpp Roster.cpp RosterUnitTest.cpp -std=c++11, then run with ./TestRoster

and

g++ -o TestStudent Student.cpp StudentUnitTest.cpp -std=c++11, then run ./TestStudent