#include <stdio.h>

int main() {
    // initialize score variable
    int score;

    // initialize play values
    int TD_2pt = 8;
    int TD_FG = 7;
    int TD = 6;
    int FG = 3;
    int Safety = 2;

    // begin loop
    while (1) {
        // query user
        printf("Enter an NFL score (0 or 1 to stop): ");

        // save response to score var's address
        scanf("%d", &score);

        // breaking condition for loop
        if (score <= 1) {
            break;
        }

        // preliminary print statement
        printf("Possible combinations of scoring plays if team's score is %d:\n", score);

        // for loops representing each type of scoring play
        // will iterate up to the max number of times the play can fit into the score
        for (int td2 = 0; td2 <= score / TD_2pt; td2++) {

            for (int td_fg = 0; td_fg <= score / TD_FG; td_fg++) {

                for (int td = 0; td <= score / TD; td++) {

                    for (int fg = 0; fg <= score / FG; fg++) {

                        for (int safety = 0; safety <= score / Safety; safety++) {
                            // calculate the total score from iteration
                            int total = td2 * TD_2pt + td_fg * TD_FG + td * TD + fg * FG + safety * Safety;

                            // check for score match
                            if (total == score) {
                                // print the found combination
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td_fg, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}