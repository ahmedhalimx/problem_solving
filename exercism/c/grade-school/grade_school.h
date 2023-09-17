#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_NAME_LENGTH (20)
#define MAX_STUDENTS (20)

typedef struct student_s {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct roster_s {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

void init_roster(roster_t *roster);
bool add_student(roster_t *roster, char *name, uint8_t grade);
void sort_roster(roster_t *roster);
void swap_students(student_t *first_student, student_t *second_student);
roster_t get_grade(roster_t *roster, uint8_t grade);
#endif
