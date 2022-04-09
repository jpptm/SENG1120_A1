// Student.h
// Course: SENG1120
// Coded by: SENG1120 Staff

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std; 

class Student 
{
	public:
		
		// Constructors
		Student();
		Student(const string, const int);

		// Destructor
		~Student();

		// Setters
		void set_name(const string);
		void set_score(const int);

		// Getters
		string get_name() const;
		int get_score() const;
		
	//Private member variables
	private:
		string name; 	// student's name
		int score;		// student's score
};

// output operator - non-member
ostream& operator <<(ostream&, const Student&);

// Code for overloading operator < for student written by Johanne Montano
// Overload < to evaluate if one student did better than the other in terms of score
bool operator <(const Student& lhs, const Student& rhs);
#endif