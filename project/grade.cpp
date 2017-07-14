// grade.cpp, Sami Ramahasindry
// calculate final grade

#include <iostream>
#include <string>
using namespace std;

#define ASSIGNMENT_COEFF  0.4
#define MIDTERM_COEFF     0.15
#define FINAL_EXAM_COEFF   0.35
#define CLASS_PARTICIPATION_COEFF 0.1
#define NUMBER_OF_ASSIGNMENTS 4

double GetScore(const string& scoreName) {
  double score;
  cout << "Enter the score for the " << scoreName << ": "; cin >> score;
  return score;
}

double AssignmentsGrade() {
  double total_score = 0;
  string assignment_rank[NUMBER_OF_ASSIGNMENTS] = { "first", "second", "third", "fourth" };
  for(int i = 0; i < NUMBER_OF_ASSIGNMENTS; i++) {
    total_score += GetScore(assignment_rank[i] + " assignment");
  }
  return total_score * ASSIGNMENT_COEFF / NUMBER_OF_ASSIGNMENTS;
}

double MidTermGrade() {
  double score = GetScore("midterm");
  return score * MIDTERM_COEFF;
}

double FinalExamGrade() {
  double score = GetScore("final");
  return score * FINAL_EXAM_COEFF;
}

double ClassParticipationGrade() {
  double score = GetScore("section grade");
  return score * CLASS_PARTICIPATION_COEFF;
}

int main() {
  double assignments = AssignmentsGrade();
  double midterm = MidTermGrade();
  double final = FinalExamGrade();
  double section = ClassParticipationGrade();
  cout << "The final grade is: " << assignments + midterm + final + section << endl;
  return 0;
}