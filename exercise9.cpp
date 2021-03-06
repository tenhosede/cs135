/*
Bruce Powell, CS135 Lecture Section 1003, Lab Section 1009, Exercise # 09

Reads string values from a file, prints them, prints them backwards, counts the number of lower case vowels

and words
*/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void printName(int, char);
void printRev(string);
int countLC(string);


int main()
{
  string input = "";
  int words = 0;
  int lcasevowels = 0;

  printName(9, 'e');

  cin >> input;
  cout << endl << endl << "BACKWARDS WORDS" << endl;

  while (cin)
    {
      words++;
      printRev(input);
      lcasevowels = lcasevowels + countLC(input);
      cin >> input;
    }

  cout << "Words in file: " << words << endl;
  cout << "Lowercase vowels in file: " << lcasevowels << endl;

}

void printRev(string inword)
{
  
  for (int i = (inword.length() -1);i >= 0 ; i--)
      cout << inword[i];
  cout << endl;
}

int countLC(string input)
{
  int lcount = 0;

  for (int i = 0; i <= input.length() - 1; i++)
    {
      if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
	lcount++;
    }
  return lcount;
}

void printName(int num, char type)
{
  cout << "====================================================================" << endl << endl;
  cout << "Bruce Powell, Lecture Section 1003, Lab Section 1005,";
  if (type == 'a' || type == 'A')
    cout << " Assignment #" << num << endl << endl;
  else
    cout << " Exercise #" << num << endl << endl;
  cout << "====================================================================" << endl << endl;
}

