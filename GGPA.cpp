#include<iostream>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    double totalPoints = 0;
    int totalCredits = 0;

    for(int i = 0; i < numCourses; i++) {
        int credits;
        double grade;
        cout << "Enter the number of credits for course " << i+1 << ": ";
        cin >> credits;
        cout << "Enter the grade for course " << i+1 << ": ";
        cin >> grade;

        totalPoints += credits * grade;
        totalCredits += credits;
    }

    double cgpa = totalPoints / totalCredits;
    cout << "The CGPA is: " << cgpa << endl;

    return 0;
}

