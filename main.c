#include <stdio.h> 
#include <stdlib.h> 
#include "account.c"

int main() { 
    char username[50]; 

    printf("Enter your username: ");
    scanf("%49s", username);

    create_user_history_file(username);

    return 0;
}