#include <iostream>

using namespace std;

struct Time {
  unsigned int day : 5; // 1-31
  unsigned int month : 4; //1-12
  unsigned int year : 11; //0-2048
  unsigned int hour : 5; //0-23
  unsigned int minute : 6; //0-59
  unsigned int second : 6; //0-59
};

int main() {
  Time new_year = { 31, 12, 2022, 23, 59, 59 };
  cout << "Party will start at " << new_year.day << '.' <<
    new_year.month << '.' <<
    new_year.year << ' ' <<
    new_year.hour << ':' <<
    new_year.minute << ':' <<
    new_year.second  << endl;

  cout << "To save this crucial information were used " << sizeof(new_year) << " bytes!" << endl;
}