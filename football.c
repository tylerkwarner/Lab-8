#include <stdio.h>

int main(void) {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (score == 1) {
            printf("Program terminated.\n");
            break;
        }

        if (score < 2) {
            printf("Invalid score. Must be at least 2.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

        int found = 0;
        for (int td2 = 0; td2 * 8 <= score; td2++) {
            for (int td1 = 0; td1 * 7 + td2 * 8 <= score; td1++) {
                for (int td = 0; td * 6 + td1 * 7 + td2 * 8 <= score; td++) {
                    for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; fg++) {
                        for (int s = 0; s * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; s++) {
                            if (8 * td2 + 7 * td1 + 6 * td + 3 * fg + 2 * s == score) {
                                printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d Safety\n",
                                       td2, td1, td, fg, s);
                                found = 1;
                            }
                        }
                    }
                }
            }
        }

        if (!found) {
            printf("No possible combinations.\n");
        }
    }

    return 0;
}
