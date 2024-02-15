#ifndef course_H
#define course_H
#include <iostream>
using namespace std;

struct Course
{
    string Name;
    string Location;
    string* Sections;
    int numSec;
    int numCred;
};


Course* createCourse(string, string, int, int);

void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);

#endif

