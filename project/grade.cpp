#include <iostream>
#include <string>
using namespace std;

#define kAssignmentCoeff  0.4
#define kMidTermCoeff     0.15
#define kFinalExamCoeff   0.35
#define kClassParticipationCoeff 0.1
#define kNumberOfAssignments 4

double GetScore(const string& scoreName) {
  double score;
  cout << "Enter the score for the " << scoreName << ": "; cin >> score;
  return score;
}

double AssignmentsGrade() {
  double totalScore = 0;
  string assignmentRank[kNumberOfAssignments] = { "first", "second", "third", "fourth" };
  for(int i = 0; i < kNumberOfAssignments; i++) {
    totalScore += GetScore(assignmentRank[i] + " assignment");
  }
  return totalScore * kAssignmentCoeff / kNumberOfAssignments;
}

double MidTermGrade() {
  double score = GetScore("midterm");
  return score * kMidTermCoeff;
}

double FinalExamGrade() {
  double score = GetScore("final");
  return score * kFinalExamCoeff;
}

double ClassParticipationGrade() {
  double score = GetScore("section grade");
  return score * kClassParticipationCoeff;
}

int main() {
  double assignments = AssignmentsGrade();
  double midterm = MidTermGrade();
  double final = FinalExamGrade();
  double section = ClassParticipationGrade();
  cout << "The final grade is: " << assignments + midterm + final + section << endl;
  return 0;
}