#include "student.h"
#include <cstring> 
#include <iostream> // Student::printInfo에서 사용

// ===================================
// 1. StudentRecord 클래스 구현
// ===================================

StudentRecord::StudentRecord(float midterm, float final)
    : midterm(midterm), final(final)
{
}

float StudentRecord::getTotal() const {
    return midterm + final;
}

void StudentRecord::updateScores(float midterm, float final)
{
    this->midterm = midterm;
    this->final = final;
}

// ===================================
// 2. Student 클래스 구현 (누락되어 링커 오류를 발생시킨 부분)
// ===================================

// (student.h에 static int last_student_id;가 없으므로 정의할 필요 없음)

// 1. 기본 생성자 구현 (StudentManager::StudentManager() 등에서 배열 초기화 시 사용됨)
Student::Student() 
    : name(""), id(0), record() // StudentRecord 기본 생성자 호출
{
}

// 2. 파라미터 있는 생성자 구현 (StudentManager::addStudent에서 사용됨)
Student::Student(const char *name_ptr, int student_id, float midterm_score, float final_score)
    // std::string name 초기화, id 초기화, StudentRecord 생성자 호출
    : name(name_ptr), id(student_id), record(midterm_score, final_score) 
{
}

// Student 클래스에 다른 멤버 함수 (예: updateRecord)가 있다면 여기에 추가 구현 필요
void Student::updateRecord(const char *name_ptr, float midterm_score, float final_score) {
    this->name = name_ptr;
    this->record.updateScores(midterm_score, final_score);
    // id는 보통 업데이트하지 않음
}