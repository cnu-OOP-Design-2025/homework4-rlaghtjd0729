#include "student_manager.h"
#include "student.h"
#include <iostream>
#include <cstring> 

// StudentManager 클래스 구현

// 정적 멤버 변수 정의
int StudentManager::last_student_id = 1000;

// 생성자: 헤더에 정의되어 있으므로 삭제됨
// StudentManager::StudentManager() {}

// 학생 추가
void StudentManager::addStudent(char const* name, float midterm, float final) {
    if (num_of_students >= MAX_STUDENTS) {
        std::cerr << "Error: Maximum number of students reached." << std::endl;
        return;
    }

    int id = ++last_student_id;
    
    // 학생 객체 배열에 추가
    students[num_of_students] = Student(name, id, midterm, final);
    num_of_students++;
}

// 해당 ID를 가진 학생을 찾아 삭제 및 재정렬
void StudentManager::deleteStudent(int id) {
    int index = findStudentByID(id);
    if (index == -1) {
        std::cerr << "Error: Student with ID " << id << " not found for deletion." << std::endl;
        return;
    }

    // 배열 재정렬
    for (int i = index; i < num_of_students - 1; ++i) {
        students[i] = students[i + 1];
    }
    
    num_of_students--;
    }

// 동일한 ID를 가진 학생의 정보 수정
void StudentManager::modifyStudent(const Student& student) {
    int index = findStudentByID(student.getID());
    if (index == -1) {
        std::cerr << "Error: Student with ID " << student.getID() << " not found for modification." << std::endl;
        return;
    }
    students[index] = student;
    }

// 해당 ID를 가진 학생의 배열 인덱스 반환
int StudentManager::findStudentByID(int id) const {
    for (int i = 0; i < num_of_students; ++i) {
        if (students[i].getID() == id) {
            return i;
        }
    }
    return -1;
}

// 중간고사 최고 점수 학생의 ID 반환
int StudentManager::findBestStudentInMidterm() const {
    if (num_of_students == 0) return -1;
    int best_index = 0;
    for (int i = 1; i < num_of_students; ++i) {
        if (students[i].getRecord().getMidterm() > students[best_index].getRecord().getMidterm()) {
            best_index = i;
        }
    }
    return students[best_index].getID();
}

// 기말고사 최고 점수 학생의 ID 반환
int StudentManager::findBestStudentInFinal() const {
    if (num_of_students == 0) return -1;
    int best_index = 0;
    for (int i = 1; i < num_of_students; ++i) {
        if (students[i].getRecord().getFinal() > students[best_index].getRecord().getFinal()) {
            best_index = i;
        }
    }
    return students[best_index].getID();
}

// 총점 최고 점수 학생의 ID 반환
int StudentManager::findBestStudent() const {
    if (num_of_students == 0) return -1;
    int best_index = 0;
    float max_total = students[0].getRecord().getTotal();
    for (int i = 1; i < num_of_students; ++i) {
        if (students[i].getRecord().getTotal() > max_total) {
            max_total = students[i].getRecord().getTotal();
            best_index = i;
        }
    }
    return students[best_index].getID();
}

// 중간고사 평균 점수 계산
float StudentManager::getMidtermAverage() const {
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; ++i) {
        sum += students[i].getRecord().getMidterm();
    }
    return sum / num_of_students;
}

// 기말고사 평균 점수 계산
float StudentManager::getFinalAverage() const {
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; ++i) {
        sum += students[i].getRecord().getFinal();
    }
    return sum / num_of_students;
}

// 총점 평균 점수 계산
float StudentManager::getTotalAverage() const {
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; ++i) {
        sum += students[i].getRecord().getTotal();
    }
    return sum / num_of_students;
}
