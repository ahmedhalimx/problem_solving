#include "grade_school.h"
#include <stdlib.h>

void init_roster(roster_t *roster) {
    roster->count = 0;
}

bool add_student(roster_t *roster, char *name, uint8_t grade) {
    student_t *student = malloc(sizeof(student_t));
    student->name = malloc(sizeof(char) * 20);
    student->name = *name;
}

roster_t get_grade(roster_t *roster, uint8_t grade);
