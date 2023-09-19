#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[80];
    char str[80];

    bool trouble = false;
    printf("Input your name : ");
    gets(name);

    // Convert the name to uppercase
    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = toupper(name[i]);
    }

    puts(name);

    do {
        trouble = false;
        printf("Input your phone number : ");
        scanf("%s", str);

        // Check if the phone number has exactly 11 digits
        if (strlen(str) != 11) {
            printf("Please enter a valid 11-digit phone number\n");
            trouble = true;
            continue;
        }

        // Check if the phone number starts with "010"
        if (strncmp(str, "010", 3) != 0) {
            printf("Please enter a valid 010-xxxxxxxx phone number\n");
            trouble = true;
            continue;
        }

        // Format the phone number as "010-xxx-xxxxx"
        printf(" %c%c%c-%c%c%c%c-%c%c%c%c\n\n", str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10]);

    } while (trouble);

     // Format phone number with dashes
    char formattedPhoneNumber[20];
    sprintf(formattedPhoneNumber, "%c%c%c-%c%c%c%c-%c%c%c%c", str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10]);

    printf("Name : %s\n", name);
    printf("Phone Number : %s\n", formattedPhoneNumber);

    return 0;
}