#include "student_manager.h"
#include "student.h"
#include <iostream>

/* StudentManager */
// 정적 멤버 변수 초기화 (클래스 밖에서 한 번 정의 필요)
int StudentManager::last_student_id = 1000;

// 학생 추가
void StudentManager::addStudent(char const* name, float midterm, float final) {
    if (count_ >= MAX_STUDENTS) {
        std::cerr << "Error: Maximum number of students reached." << std::endl;
        return;
    }

    int id = ++last_student_id;
    // 배열의 다음 위치에 Student 객체 생성자를 직접 호출하여 추가
    students_[count_] = Student(name, id, midterm, final);
    count_++;
}

// 해당 ID를 가진 학생을 찾아 배열에서 삭제 및 재정렬
void StudentManager::deleteStudent(int id) {
    int index = findStudentByID(id);
    if (index == -1) {
        std::cout << "Student with ID " << id << " not found." << std::endl;
        return;
    }

    // 삭제: 해당 인덱스부터 뒤의 모든 요소를 한 칸씩 앞으로 당김
    for (int i = index; i < count_ - 1; ++i) {
        students_[i] = students_[i + 1];
    }
    
    // 학생 수 감소
    count_--;
    std::cout << "Student with ID " << id << " deleted." << std::endl;
}

// 동일한 ID를 가진 학생을 찾아 정보 수정
void StudentManager::modifyStudent(const Student& student) {
    int index = findStudentByID(student.getID());
    if (index == -1) {
        std::cout << "Student with ID " << student.getID() << " not found for modification." << std::endl;
        return;
    }
    // 복사 대입 연산자를 사용하여 정보 수정
    students_[index] = student;
}

// 해당 ID를 가진 학생의 배열 인덱스 반환
int StudentManager::findStudentByID(int id) const {
    for (int i = 0; i < count_; ++i) {
        if (students_[i].getID() == id) {
            return i;
        }
    }
    return -1; // 찾지 못함
}

// 중간고사 최고 점수 학생의 인덱스 반환
int StudentManager::findBestStudentInMidterm() const {
    if (count_ == 0) return -1;
    int best_index = 0;
    for (int i = 1; i < count_; ++i) {
        if (students_[i].getRecord().getMidterm() > students_[best_index].getRecord().getMidterm()) {
            best_index = i;
        }
    }
    return best_index;
}

// 기말고사 최고 점수 학생의 인덱스 반환
int StudentManager::findBestStudentInFinal() const {
    if (count_ == 0) return -1;
    int best_index = 0;
    for (int i = 1; i < count_; ++i) {
        if (students_[i].getRecord().getFinal() > students_[best_index].getRecord().getFinal()) {
            best_index = i;
        }
    }
    return best_index;
}

// 총점 최고 점수 학생의 인덱스 반환
int StudentManager::findBestStudent() const {
    if (count_ == 0) return -1;
    int best_index = 0;
    for (int i = 1; i < count_; ++i) {
        if (students_[i].getRecord().getTotal() > students_[best_index].getRecord().getTotal()) {
            best_index = i;
        }
    }
    return best_index;
}

// 중간고사 평균 점수 계산
float StudentManager::getMidtermAverage() const {
    if (count_ == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < count_; ++i) {
        sum += students_[i].getRecord().getMidterm();
    }
    return sum / count_;
}

// 기말고사 평균 점수 계산
float StudentManager::getFinalAverage() const {
    if (count_ == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < count_; ++i) {
        sum += students_[i].getRecord().getFinal();
    }
    return sum / count_;
}

// 총점 평균 점수 계산
float StudentManager::getTotalAverage() const {
    if (count_ == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < count_; ++i) {
        sum += students_[i].getRecord().getTotal();
    }
    return sum / count_;
}