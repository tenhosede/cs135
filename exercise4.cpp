
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  float question3, question4, question5;
  int question1, question2, question6, question7, question8, question9, question10;
  int x, y, z;
  double a, b;
  x = 17;
  y = 4;
  a = 5.8;
  question1 = (25 % 9 - 9 / 2);
  cout << "Question 1:" << question1 << endl;
  question2 = 6 + 11 % 15 - pow(3,2);
  cout << "Question 2:" << question2 << endl;
  question3 = 4 / 3 * 6 + 4.5;
  cout << "Question 3:" <<question3 << endl;
  question4 = 4 * (2.0 / 5) + 2;
  cout << "Question 4:" << question4 << endl;
  question5 = 101 / 5 % 7 - 3 * 2.0;
  cout << "Question 5:" << question5 << endl;
  z = 3 + x % 6;
  cout << "Question 6:" << z << endl;
  b = int(sqrt (x+9)) + y * 2;
  cout << "Question 7:" << b << endl;
  b = y / 3 + 9.1;
  cout << "Question 8:" << b << endl;
  z = a - x % y + (x - 11) * 0.5;
  cout << "Question 9:" << z << endl;
  z = double (y / x + 1) -a;
  cout << "Question 10:" << z << endl;
  return 0;
}
