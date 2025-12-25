#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 3
#define MAX_NAME_LEN 20
#define SUBJECT_COUNT 3
typedef struct {
    char id[10];          
    char name[MAX_NAME_LEN]; 
    int chinese;           
    int math;             
    int english;         
    float average;          
} Student;
void inputStudents(Student students[], int n);
void calculateAverage(Student students[], int n);
void writeToFile(Student students[], int n, const char* filename);
void readFromFile(const char* filename);
void displayStudents(Student students[], int n);
int main() {
    Student students[MAX_STUDENTS];
    printf("=== 学生成绩管理系统 ===\n\n");
    printf("请输入%d个学生的信息：\n", MAX_STUDENTS);
    inputStudents(students, MAX_STUDENTS);
    calculateAverage(students, MAX_STUDENTS);
    printf("\n输入的学生数据如下：\n");
    displayStudents(students, MAX_STUDENTS);
    writeToFile(students, MAX_STUDENTS, "stud.txt");
    printf("\n数据已成功写入文件 stud.txt\n");
    printf("\n从文件读取的数据如下：\n");
    readFromFile("stud.txt");
    return 0;
}
void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n学生%d：\n", i + 1);
        printf("学号: ");
        scanf("%s", students[i].id);
        printf("姓名: ");
        scanf("%s", students[i].name);
        printf("语文成绩: ");
        scanf("%d", &students[i].chinese);
        printf("数学成绩: ");
        scanf("%d", &students[i].math);
        printf("英语成绩: ");
        scanf("%d", &students[i].english);
    }
}
void calculateAverage(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        students[i].average = (students[i].chinese + students[i].math + students[i].english) / 3.0;
    }
}
void displayStudents(Student students[], int n) {
    printf("学号\t姓名\t\t语文\t数学\t英语\t平均分\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t\t%d\t%d\t%d\t%.2f\n", 
               students[i].id, students[i].name, 
               students[i].chinese, students[i].math, 
               students[i].english, students[i].average);
    }
}
void writeToFile(Student students[], int n, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return;
    }
    fprintf(file, "学号,姓名,语文成绩,数学成绩,英语成绩,平均分\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%s,%d,%d,%d,%.2f\n", 
                students[i].id, students[i].name, 
                students[i].chinese, students[i].math, 
                students[i].english, students[i].average);
    }
    
    fclose(file);
}
void readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return;
    }
    char line[256];
    printf("学号\t姓名\t\t语文\t数学\t英语\t平均分\n");
    printf("------------------------------------------------------------\n");
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file)) {
        char id[10], name[MAX_NAME_LEN];
        int chinese, math, english;
        float average;
        sscanf(line, "%[^,],%[^,],%d,%d,%d,%f", 
               id, name, &chinese, &math, &english, &average);
        printf("%s\t%s\t\t%d\t%d\t%d\t%.2f\n", 
               id, name, chinese, math, english, average);
    }
    fclose(file);
}
