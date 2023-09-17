#include "grade_school.h"

void swap_students(student_t *first_student, student_t *second_student) {
	student_t temp_second_student;
	temp_second_student.grade = second_student->grade;
	strcpy(temp_second_student.name, second_student->name);

	strcpy(second_student->name, first_student->name);
	second_student->grade = first_student->grade;

	strcpy(first_student->name, temp_second_student.name);
	first_student->grade = temp_second_student.grade;
}

void sort_roster(roster_t *roster) {
	size_t sorted_index = 0, highest_grade = 0;

	for (size_t i = 0; i < roster->count; ++i) {
		if (roster->students[i].grade > highest_grade)
			highest_grade = roster->students[i].grade;
	}

	for (size_t grade = 1; grade <= highest_grade; ++grade) {
		for (size_t i = 0; i <= roster->count; ++i) {
			if (roster->students[i].grade == grade) {
				swap_students((roster->students + i), (roster->students + sorted_index));
				++sorted_index;
			}
		}
	}

	for (size_t i = 0; i < roster->count; ++i) {
		for (size_t j = 0; j < roster->count; ++j) {
			if (j == i)
				continue;
			if (roster->students[j].grade == roster->students[i].grade)
				if (roster->students[j].name[0] > roster->students[i].name[0])
					swap_students(roster->students + j, roster->students + i);
		}
	}
}

void init_roster(roster_t *roster) {
	roster->count = 0;
	for (int i = 0; i < MAX_STUDENTS; ++i) {
		roster->students[i].grade = 0;
	}
}

bool add_student(roster_t *roster, char *name, uint8_t grade) {
	size_t i;
	student_t *new_student = roster->students + roster->count;

	for (i = 0; i < roster->count; ++i) {
		if (strcmp(roster->students[i].name, name) == 0)
			return (false);
	}

	new_student->grade = grade;
	sprintf(new_student->name, "%s", name);
	++roster->count;

	if (roster->count > 1)
		sort_roster(roster);

	return (true);
}

roster_t get_grade(roster_t *roster, uint8_t grade) {
	roster_t new_roster;
	init_roster(&new_roster);

	for (size_t i = 0; i < roster->count; ++i) {
		if (roster->students[i].grade == grade)
			add_student(&new_roster, roster->students[i].name, grade);
	}

	return (new_roster);
}
