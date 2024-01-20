#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void extractIntegers(const char* string) {
    for (int i = 0; string [i] != '\0'; i++) {
        if (isdigit(string[i])) {
            printf("%c", string[i]);
        }
    }
     printf("\n"); // adds newline after each number
} 

int main(void)
{
    FILE *file = fopen("aoc1.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* file_contents = malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    fread(file_contents, 1, file_size, file);
    file_contents[file_size] = '\0';

    extractIntegers(file_contents);

    free(file_contents);
    fclose(file);

    return 0;
}
