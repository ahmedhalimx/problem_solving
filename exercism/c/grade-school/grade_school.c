#include "grade_school.h"
#include <stdlib.h>

void init_roster(roster_t *roster) {
  size_t i;  

	roster->count = 0;
	roster->students = calloc(MAX_STUDENTS, sizeof(student_t));
	for (i = 0; i < MAX_STUDENTS; ++i) {
		;
	}
}

bool add_student(roster_t *roster, char *name, uint8_t grade) {
    student_t *student = malloc(sizeof(student_t));
    student->name = malloc(sizeof(char) );
    student->name = *name;
}

roster_t get_grade(roster_t *roster, uint8_t grade);
