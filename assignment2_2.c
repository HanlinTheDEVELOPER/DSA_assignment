//
// Created by hanlin on 12/16/23.
//
#include "stdio.h"

int calculateTotal(int marks[6]);
void studentStat(int student[6], int totalMarks);
void grading(int agagTotal, int mgmgTotal, int ngngTotal);
void options(int opt);

int agagMarks[6] = {45, 43, 56, 76, 81, 87};
int mgmgMarks[6] = {43, 33, 86, 76, 76, 81};
int ngngMarks[6] = {71, 41, 12, 98, 74, 40};


int main() {
    int next = 0;
    int opt = 0;
    printf("Please choose data you want to view.\n");
    printf("Press 1 for gradings\n");
    printf("Press 2 for Aung Aung's Stat.\n");
    printf("Press 3 for Maung Maung's Stat.\n");
    printf("Press 4 for Naung Naung's Stat.\n");
    printf("Option : ");
    scanf("%d", &opt);
    options(opt);
    printf("\nTo go to main menu, press 1.\nTo exit press any:");
    scanf("%d", &next);
    if (next == 1) {
        main();
    }
    return 0;
    return 10;
}

void options(int opt) {
    int agagTotalMark = calculateTotal(agagMarks);
    int mgmgTotalMarks = calculateTotal(mgmgMarks);
    int ngngTotalMarks = calculateTotal(ngngMarks);
    switch (opt) {
        case 1:
            grading(agagTotalMark, mgmgTotalMarks, ngngTotalMarks);
            break;
        case 2:
            studentStat(agagMarks, agagTotalMark);
            break;
        case 3:
            studentStat(mgmgMarks, mgmgTotalMarks);
            break;
        case 4:
            studentStat(ngngMarks, ngngTotalMarks);
            break;
        default:
            printf("Only enter numbers available in option!!!\n");
            options(opt);
    }
}

int calculateTotal(int marks[6]) {
    int i = 0;
    int total = 0;
    for (i = 0; i < 6; i++) {
        total += marks[i];
    }
    return total;
}

void studentStat(int student[6], int totalMarks) {
    int i = 0;
    int pass = 1;
    for (i = 0; i < 6; i++) {
        if (student[i] < 40) {
            pass = 0;
            printf("He failed in subject %d with %d marks\n", i + 1, student[i]);
        } else if (student[i] > 80) {
            printf("He passed with destination in subject %d with %d marks\n", i + 1, student[i]);
        } else {
            printf("He passed in subject %d with %d marks \n", i + 1, student[i]);
        }
    }
    if (pass == 0) {
        printf("He failed in overall ");
    } else {
    printf("He got total score of %d marks\n", totalMarks);
    }
}

void grading(int agagTotal, int mgmgTotal, int ngngTotal) {
    if (agagTotal > mgmgTotal && agagTotal > ngngTotal) {
        printf("Aung Aung got first place with total of %d marks\n", agagTotal);
    } else if (mgmgTotal > agagTotal && mgmgTotal > ngngTotal) {
        printf("Maung Maung got first place with total of %d marks\n", mgmgTotal);
    } else if (ngngTotal > agagTotal && ngngTotal > mgmgTotal) {
        printf("Naung Naung got first place with total of %d marks\n", ngngTotal);
    }

    if (agagTotal > mgmgTotal && agagTotal < ngngTotal || agagTotal < mgmgTotal && agagTotal > ngngTotal) {
        printf("Aung Aung got second place with total of %d marks\n", agagTotal);
    } else if (mgmgTotal > agagTotal && mgmgTotal < ngngTotal || mgmgTotal < agagTotal && mgmgTotal > ngngTotal) {
        printf("Maung Maung got second place with total of %d marks\n", mgmgTotal);
    } else if (ngngTotal > agagTotal && ngngTotal < mgmgTotal || ngngTotal < agagTotal && ngngTotal > mgmgTotal) {
        printf("Naung Naung got second place with total of %d marks\n", ngngTotal);
    } else {
        printf("second\n");
    }

    if (agagTotal < mgmgTotal && agagTotal < ngngTotal) {
        printf("Aung Aung got third place with total of %d marks\n", agagTotal);
    } else if (mgmgTotal < agagTotal && mgmgTotal < ngngTotal) {
        printf("Maung Maung got third place with total of %d marks\n", mgmgTotal);
    } else if (ngngTotal < agagTotal && ngngTotal < mgmgTotal) {
        printf("Naung Naung got third place with total of %d marks\n", ngngTotal);
    }
}