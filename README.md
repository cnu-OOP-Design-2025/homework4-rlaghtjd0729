[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/s_O7eY5a)
# C++ 클래스 실습 프로젝트

이번 과제는 C++의 클래스 개념을 실습하기 위한 과제입니다. 두 개의 주요 파일을 구현하며, 클래스 선언과 정의, 생성자/소멸자, 멤버 함수, 정적 멤버 변수 작성을 연습합니다.

---

## 🎯 실습 목적

- C++ 클래스 문법 이해
- 생성자 사용
- 초기화 리스트(initializer list) 사용
- 멤버 함수 정의
- static 변수 사용법 익히기
- this 포인터 사용

---

## 📁 파일 구성

### 1. `student_manager.cpp`

`StudentManager` 클래스의 기능을 구현합니다. 학생 추가, 삭제, 검색, 통계 기능을 포함합니다.

#### 구현해야 할 함수 (`/* TODO */`)

- `addStudent(const char* name, float midterm, float final)`
  - `last_student_id`를 증가시켜 고유 ID 자동 생성
  - 배열에 학생 객체 추가

- `deleteStudent(int id)`
  - 해당 ID를 가진 학생을 배열에서 삭제
  - 삭제 후 배열 재정렬

- `modifyStudent(const Student& student)`
  - 동일한 ID를 가진 학생을 찾아 정보 수정

- `findStudentByID(int id)`
  - 해당 ID를 가진 학생의 배열 인덱스 반환

- `findBestStudentInMidterm()`, `findBestStudentInFinal()`, `findBestStudent()`
  - 각각 중간/기말/총점 기준 최고 학생의 인덱스 반환

- `getMidtermAverage()`, `getFinalAverage()`, `getTotalAverage()`
  - 전체 평균 점수 계산

---

### 2. `student.cpp`

`Student`와 `StudentRecord` 클래스의 생성자 및 멤버 함수 구현을 담당합니다.

#### 구현해야 할 항목 (`/* TODO */`)

##### `StudentRecord`

- `StudentRecord(float midterm, float final)`
  - 초기화 리스트를 사용하여 `midterm`, `final` 초기화

- `getTotal()`
  - 평균 점수 계산하여 반환

- `updateScores(float midterm, float final)`
  - this 포인터를 사용하여 점수 수정

##### `Student`

- `Student()`
  - 초기화 리스트를 사용하여 기본값 설정

- `Student(const char* name, int id, float midterm, float final)`
  - 초기화 리스트를 사용하여 멤버 초기화

- `updateRecord(const char* name, float midterm, float final)`
  - 이름과 성적을 수정 (this 포인터 사용)

---

## 🧠 생각해보기
- `StudentManager` 클래스에서 `last_student_id`를 사용하여 학생 ID를 자동으로 생성하는 방식의 장/단점은 무엇인가요? 개선한다면 어떻게 디자인 해보겠나요?
- `Student::updateRecord` 함수에서 학생 ID를 입력받을 필요가 있을까요? 그 이유는 무엇인가요? 
- `StudentManager`에서 students 변수를 배열로 선언했을 때의 단점은 무엇인가요? 어떻게 개선할 수 있을까요?


## 🧪 테스트 방법
다 구현한 후, 아래 명령어를 통해 테스트를 실행하세요:

### Windows 사용자
```bash
.\test4.bat
```

### MacOS/Linux 사용자
```bash
/bin/bash test4.sh
```

