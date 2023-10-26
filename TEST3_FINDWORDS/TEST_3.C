 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convertToUppercase(char* str) {
    int convert = 0; 
    while (*str != '\0') {
        if (*str == '.') {
            convert = 1;
        } else if (convert && *str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
}

void findAndPrintOccurrences(char* str, char* target) {
    int count = 0;
    char* ptr = str;
    while (*ptr != '\0') {
        int match = 1;
        char* subptr = ptr;

        for (int i = 0; target[i] != '\0'; i++) {
            if (*subptr != target[i]) {
                match = 0;
                break;
            }
            subptr++;
        }

        if (match) {
            count++;
            printf("Từ '%s' ở vị trí %ld\n", target, ptr - str);
            ptr += strlen(target);
        } else {
            ptr++;
        }
    }

    if (count == 0) {
        printf("Không tìm thấy từ '%s' trong chuỗi.\n", target);
    }
}

void replaceOccurrences(char* str, char* target, char* replacement) {
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);
    char* ptr = str;
    int found = 0; 

    while (*ptr != '\0') {
        int match = 1;
        char* subptr = ptr;

        for (int i = 0; target[i] != '\0'; i++) {
            if (*subptr != target[i]) {
                match = 0;
                break;
            }
            subptr++;
        }

        if (match) {
            found = 1;
            char* temp = (char*)malloc(strlen(ptr) - targetLen + replacementLen + 1);
            strncpy(temp, str, ptr - str);
            temp[ptr - str] = '\0';
            strcat(temp, replacement);
            strcat(temp, ptr + targetLen);
            strcpy(str, temp);
            free(temp);
            ptr += replacementLen;
        } else {
            ptr++;
        }
    }

    if (!found) {
        printf("Không có từ mà bạn muốn.\n");
    }
}

int main() {
    char str[100];
    char target[100], replacement[100];
    int choice;

    printf("Vui lòng nhập chuỗi của bạn và thực hiện theo hướng dẫn:\n");
    printf("1. Chuyển chuỗi thành chữ hoa sau dấu '.'.\n");
    printf("2. Tìm và in vị trí xuất hiện của từ.\n");
    printf("3. Thay thế từ.\n");
    printf("Nhấn Enter để tiếp tục...\n");
    getchar();

    printf("Nhập chuỗi của bạn: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

    convertToUppercase(str);
    printf("Đã chuyển: %s\n", str);

while (1) {
    printf("Nhập lựa chọn (1 để tìm từ, 2 để quay lại yêu cầu 1, 3 để thay từ ,4 để thoát): ");
    scanf("%d", &choice);
    getchar(); 
    if (choice == 1) {
        printf("Nhập từ cần tìm: ");
        fgets(target, sizeof(target), stdin);
        target[strcspn(target, "\n")] = 0; 
        findAndPrintOccurrences(str, target);
    } else if (choice == 2) {
         printf("Nhập chuỗi mới: ");
    scanf(" %[^\n]s", str); 
    convertToUppercase(str);
    printf("Đã chuyển: %s\n", str);
    
    } else if (choice == 3) {
        printf("Nhập từ cần thay thế: ");
        fgets(target, sizeof(target), stdin);
        target[strcspn(target, "\n")] = 0; 
        printf("Nhập từ thay thế: ");
        fgets(replacement, sizeof(replacement), stdin);
        replacement[strcspn(replacement, "\n")] = 0; 
        replaceOccurrences(str, target, replacement);
        printf("%s\n", str);
    } else if (choice == 4) {
        break;
    } else {
        printf("Lựa chọn không hợp lệ.\n");
    }
}


    return 0;
}