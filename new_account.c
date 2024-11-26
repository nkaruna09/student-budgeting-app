#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "new_account.h"

char *check_first_name() {
    const char *pattern = "^[A-Za-z]+$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *first_name = malloc(20 * sizeof(char));
    puts("Please enter your first name: ");

    while (scanf("%20s", first_name) || regexec(&regex, first_name, 0, NULL, 0 != 0)) {
        puts("Your first name cannot contain non-alphabetical characters");
        while(getchar()!='\n');
    }

    return first_name;

}

char *check_last_name() {
    const char *pattern = "^[A-Za-z]+$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *last_name = malloc(20 * sizeof(char));
    puts("Please enter your last name: ");

    while (scanf("%20s", last_name) || regexec(&regex, last_name, 0, NULL, 0 != 0)) {
        puts("Your last name cannot contain non-alphabetical characters");
        while(getchar()!='\n');
    }

    return last_name;
}

void check_email() {
    const char *pattern = "^[A-Za-z0-9]+[@][a-z]+[\\.][ca|com]$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *email = malloc(50 * sizeof(char));
    puts("Please enter your email: ");

    while (scanf("%50s", email) || regexec(&regex, email, 0, NULL, 0 != 0)) {
        puts("Please enter a valid email");
        while(getchar()!='n');

    }
	
}

typedef struct {
    int day;
    int month;
    int year;
} Date;

char *scan_birthday() {
    Date date;
    char *birthday = malloc(11*sizeof(char));

    printf("Enter your birthday (DD/MM/YYYY): ");

    while (scanf("%d/%d/%d", &date.day, &date.month, &date.year) != 3 || date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 1900 || date.month > 2100) {
        printf("Invalid input. Please enter your birthday in the format DD/MM/YYYY: ");
        // Clearing input buffer
        while (getchar() != '\n');
    }

    sprintf(birthday, "%02d/%02d/%d", date.day, date.month, date.year);

    return birthday;
}

char *scan_username(){
    const char *pattern = "^[a-zA-z]+[_0-9a-zA-z]*[a-zA-Z0-9]+$";
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *username = malloc(20 * sizeof(char));
    puts("Enter a username between 4-20 characters: ");

    while(scanf("%20s", username) != 1 || regexec(&regex, username, 0, NULL, 0 != 0)){
        puts("Username invalid. Kindly enter one in the format...:");
        while(getchar()!='\n');
    }

    //check existence of username

    return username;
}
