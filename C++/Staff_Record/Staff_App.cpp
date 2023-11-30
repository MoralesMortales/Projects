#include <string>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

void staff(string &Name, int &Age, string &Job);
void saver(string Name, int Age, string Job);

int main()
{

string Name, Job;
int Age; 

cout << "Thank you for coming back. What do you want to do?" << endl;

staff( Name,  Age,  Job);
saver( Name,  Age,  Job);

    return 0;
}

void staff(string &Name, int &Age, string &Job){

cout << "Type your name: ";
cin >> Name;
cout << "Type your age: ";
cin >> Age;
cout << "Type your job position: ";
cin >> Job;
cout << "Thank you, all current files are done." << endl;

}


void saver(string Name, int Age, string Job){

ofstream file("staff/" + Name + ".txt");
file << Name << ", " << Age << " years old, " << Job << " currently." << endl;
file.close();
}