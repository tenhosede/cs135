//Exercise 5 by Bruce Powell (WME for UNLV)
//Lecture Section 1003, Lab Section 1009
//Takes an integer value of seconds and displays resulting days, hours, minutes, and seconds.

#include<iostream>
using namespace std;

const int secondsperhour = 3600;
const int secondsperminute = 60;

int main()
{
  int iseconds = 0;
  int holdseconds = 0;
  int ohours = 0;
  int ominutes = 0;
  int oseconds = 0;

  cout << "Please enter total number of seconds:" << endl;
  cin >> iseconds;
  ohours = iseconds / secondsperhour;
  holdseconds = iseconds % secondsperhour;
  ominutes = holdseconds / secondsperminute;
  holdseconds = holdseconds % secondsperminute;
  oseconds = holdseconds;
  cout << iseconds << " seconds are equal to " << ohours << " hours " << ominutes << " minutes and " << oseconds << " seconds." << endl;
}
