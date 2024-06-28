//============================================================================
// Name        : Course.cpp
// Author      : Kristin Tucker
// Version     :
// Copyright   : Your copyright notice
// Description : Final project Module 7
//============================================================================

#include <iostream>		//inlcude headers for input, output, string and sorting
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Course {		//define structure for courses
	std :: string courseNumber;		//declare variables  number, title, and prereq
	std :: string courseTitle;
	std :: vector <string> prerequisites;
};
void loadDataStructure(std :: vector <Course>&courseData, const std :: string&filename) {  //function to load data file
	std :: ifstream file(filename);
		if (file.is_open()) {		//read from file
			std :: string courseNumber, courseTitle, prerequisites;  //with structures as this
			while (file >> courseNumber >> courseTitle) {
				Course course;
				course.courseNumber = courseNumber;
				course.courseTitle = courseTitle;
				while (file >> prerequisites) {
					course.prerequisites.push_back(prerequisites);
				}
				courseData.push_back(course);
				}
			file.close();  //close file
		} else {
			std :: cerr << "Error reading file." << std :: endl;
		}
}
void printCourseList (const std :: vector <Course>& courseData) {  //function to print list
	std :: vector<Course> sortedCourses = courseData;  //array to sort courses
	std :: sort(sortedCourses.begin(), sortedCourses.end(), [](const Course& a, const Course& b) {
		return a.courseNumber < b.courseNumber;});
	std :: cout << "Here's an example of a schedule: " << std :: endl;		//output example schedule
	for (const Course& course : sortedCourses) {
		std :: cout << course.courseNumber << " , " << course.courseTitle << std :: endl;		//output course number and title
	}
}
void PrintCourseInformation(const std :: vector <Course>& courseData, const std :: string& courseNumber) {
	for (const Course& course : courseData) {		//function to print course information by array
		if (course.courseNumber == courseNumber) {		//if course num found output course info
			std :: cout << course.courseNumber << " , " << course.courseTitle << std::endl;
			if (!course.prerequisites.empty()) {		// if no course print prereq
				std :: cout << "Prerequisites:" << std::endl;
				for (const std :: string& prerequisite : course.prerequisites) {
					std :: cout << prerequisite << std::endl;
				}

			}
			return;		//return course information
		}
	}
	std :: cout << "Course could not be found." << std::endl;  //output statement
}
int main () {
	std :: vector<Course> courseData;
	std :: string filename;

	std :: cout << "Course planner." << std::endl;
	while (true) {			//loop to go through list and print option(s)
		std :: cout << "1. Load data structure." << std ::endl;
		std :: cout << "2. Print course list." << std ::endl;
		std :: cout << "3. Print course." << std ::endl;
		std :: cout << "9. Exit." << std ::endl;
		std :: cout << "Select an option." << std ::endl;

		int choice;		//declare variable
		if (!(std :: cin >> choice)) {		//if selection invalid display statement
			std :: cerr << "Error: Invalid Input.Please select an option." << std::endl;
			std :: cin.clear();
	std :: cin.ignore(std :: numeric_limits<streamsize>::max(), '\n');  //set delimiter
			continue;
		}
		switch (choice) {
		case 1:
			std :: cout << "Enter the filename containing the data: ";
			std :: cin filename;
void LoadDataStructure(courseData, filename);		//load vector array with info output statements as you go through
			break;
		case 2:
			if (courseData.empty()) {
				std :: cerr << "Course data not loaded." << endl;
			} else {
				printCourseList(courseData);
			}
			break;
		case 3:
			if (courseData.empty()) {
				std :: cerr << "Error: Load course data first." << std::endl;
			} else {
				std :: string courseNumber;
				std :: cout << "Which course would you like to look at?" ;
				std :: cin >> courseNumber;
void PrintCourseInformation(courseData, courseNumber);  // print course info and exitr with statement
			}
			break;
		case 9:
			std :: cout << "Thank you for using our planner." << std::endl;
			return 0;
		}
	}
	return 0;
}


