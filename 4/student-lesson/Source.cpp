#include <iostream>
#include <string>

using namespace std;

const int kNumberOfSeatsInClass = 15;
const int kNumberOfLessons = 3;

struct Student {
  string name;
  int age;
  struct Lesson** schedule;
};

struct Lesson {
  string subject;
  int begining_hour;
  Student* participants[kNumberOfSeatsInClass];
  int participants_num;
};

int main() {
  Lesson Maths = { "Mathematics", 9, {0}, 0 };
  Lesson Physics = { "Physics", 11, {0}, 0 };
  Lesson Progr = { "Programming", 13, {0}, 0 };
  Lesson lesson_list[] = {Maths, Physics, Progr};

  cout << "Enter the number of students: ";
  int students_num;
  cin >> students_num;

  Student* student_list = new Student[students_num];

  cout << "Enter data about students" << endl;
  for (int i = 0; i < students_num; i++) {
    cout << "Student #" << i + 1 << endl;

    cout << "Name: ";
    cin >> student_list[i].name;

    cout << "Age: ";
    cin >> student_list[i].age;

    cout << "Number of lessons: ";
    int lessons_num;
    cin >> lessons_num;
    student_list[i].schedule = new Lesson* [lessons_num];
    for (int j = 0; j < lessons_num; j++) {
      cout << "Enter '0' to add maths, '1' to add physics, '2' to add programming: ";
      int subject;
      cin >> subject;
      student_list[i].schedule[j] = lesson_list + subject;
      lesson_list[subject].participants[lesson_list[subject].participants_num++] = &student_list[i];
    }

    cout << endl;
  }

  cout << "Here is an information about lessons: " << endl;
  for (int i = 0; i < kNumberOfLessons; i++) {
    cout << i + 1 << ". " << lesson_list[i].subject << ", ";
    cout << lesson_list[i].begining_hour << ":00" << endl;
    cout << "Participants: " << endl;
    for (int j = 0; j < lesson_list[i].participants_num; j++) {
      cout << "  " << j + 1 << ") " << lesson_list[i].participants[j]->name << ", ";
      cout << lesson_list[i].participants[j]->age << " y. o." << endl;
    }
    cout << endl;
  }
}