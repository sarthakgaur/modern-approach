#include <stdio.h>
#include <ctype.h>

float compute_GPA(char grades[], int n);

int main(void) {
    char grades[] = {'a', 'b', 'c', 'd', 'f'};

    printf("Average grade: %f\n", compute_GPA(grades, 5));

    return 0;
}

float compute_GPA(char grades[], int n) {
    int grade_sum = 0;

    for (int i = 0; i < n; i++) {
        char grade = toupper(grades[i]);

        switch (grade) {
            case 'A': grade_sum += 4;
                      break;
            case 'B': grade_sum += 3;
                      break;
            case 'C': grade_sum += 2;
                      break;
            case 'D': grade_sum += 1;
                      break;
            case 'F': grade_sum += 0;
                      break;
        }
    }

    return (float) grade_sum / n;
}
