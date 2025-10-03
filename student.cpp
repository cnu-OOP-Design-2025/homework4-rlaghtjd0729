#include "student.h"

#include <iostream>
#include <cstring> // For strncpy

/* StudentRecord */

// 초기화 리스트를 사용하여 멤버 변수 초기화
StudentRecord::StudentRecord(float midterm, float final) 
    : midterm_(midterm), final_(final)
{}

// 총점 (중간 + 기말) 계산
float StudentRecord::getTotal() const {
    return midterm_ + final_;
}

// this 포인터를 사용하여 점수 수정
void StudentRecord::updateScores(float midterm, float final) {
    this->midterm_ = midterm;
    this->final_ = final;
}


/* Student */

// 기본 생성자: 초기화 리스트를 사용하여 기본값 설정
Student::Student() 
    : id_(-1), name_(""), record_(0.0f, 0.0f) // record_도 초기화 리스트로 초기화
{ }

// 매개변수가 있는 생성자: 초기화 리스트를 사용하여 멤버 초기화
Student::Student(const char *name, int id, float midterm, float final)
    : id_(id), record_(midterm, final) // record_는 StudentRecord 생성자를 호출하여 초기화
{
    // 이름 복사 (안전하게 최대 길이만큼 복사)
    std::strncpy(name_, name, MAX_NAME_LEN - 1);
    name_[MAX_NAME_LEN - 1] = '\0'; // 문자열 안전 종료 보장
}

// 이름과 성적을 수정 (this 포인터 사용)
void Student::updateRecord(const char *name, float midterm, float final) {
    // 이름 수정
    std::strncpy(this->name_, name, MAX_NAME_LEN - 1);
    this->name_[MAX_NAME_LEN - 1] = '\0';
    
    // 성적 수정은 StudentRecord 멤버 함수에 위임
    this->record_.updateScores(midterm, final);
}