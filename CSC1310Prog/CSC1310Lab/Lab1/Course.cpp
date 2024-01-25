#include "Course.h"
#include <iostream>
using namespace std;
Course* createCourse(string Name,string Location, int numSec, int numCred){
    Course* course;

    course = new Course;

    course->Name  = Name;
    course->Location = Location;
    course->numSec = numSec;
    course->numCred = numCred;
    course->Sections = new string[numSec];

    return course;
}

void destroyCourse(Course* myCourse){
    delete [] myCourse->Sections;
    delete [] myCourse;
}

void printCourse(Course* myCourse){


    cout <<  "\nCOURSE NAME:\t\t" << myCourse->Name << endl;
    cout <<  "\nCOURSE LOCATION:\t" << myCourse->Location << endl;
    cout <<  "\nCOURSE HOURS:\t\t" << myCourse->numCred << endl;
    cout <<  "\nNUMBER OF SECTIONS?\t" << myCourse->numSec << endl;
     for (int i=0 ;i<myCourse->numSec; ++i) {
        cout << "\nSECTION "<< i+1 <<" :\t\t" << myCourse->Sections[i] << endl;
     }
        
}