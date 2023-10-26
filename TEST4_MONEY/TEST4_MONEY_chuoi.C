#include <stdio.h>

char *unit[] = {"", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
char *unit2[] = {"", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi"};
char *unit3[] = {"", "mot tram", "hai tram", "ba tram", "bon tram", "nam tram", "sau tram", "bay tram", "tam tram", "chin tram"};
char *unit4[] = {"", "nghin", "trieu", "ty"};

void readNumber(long long num) {
    if (num == 0) {
        printf("Khong dong\n");
        return;
    }

    int hasPrinted = 0; 
    char str[16]; 

    snprintf(str, sizeof(str), "%lld", num);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        int digit = str[i] - '0';

        if (i % 3 == len % 3 && i != 0) {
            printf("muoi ");
            hasPrinted = 1;
        }

        if (digit > 0) {
            if (i % 3 == 2) {
                printf("%s ", unit3[digit]);
                hasPrinted = 1;
            } else if (i % 3 == 1) {
                if (digit > 1) {
                    printf("%s ", unit2[digit]);
                    hasPrinted = 1;
                } else {
                    if (hasPrinted) {
                        printf("khong ");
                        hasPrinted = 0;
                    } else {
                        printf("%s ", unit[digit]);
                        hasPrinted = 1;
                    }
                }
            } else if (i % 3 == 0) {
                printf("%s ", unit[digit]);
                hasPrinted = 1;
            }
        } else if (digit == 0 && hasPrinted) {
            printf("khong ");
            hasPrinted = 0;
        }

        if ((len - i - 1) % 3 == 0 && len - i - 1 > 0) {
            printf("%s ", unit4[(len - i - 1) / 3]);
            hasPrinted = 1;
        }
    }

    printf("dong\n");
}

int main() {
    long long num;
    int choice;
    int isValid;

    do {
        isValid = 0;
        do {
            printf("Nhap so (>0 va be hon 1 nghin ty): ");
            scanf("%lld", &num);

            if (num == 0) {
                printf("Khong dong\n");
                isValid = 1;
            } else if (num < 0 || num >= 1000000000000LL) {
                printf("So khong hop le. ");
            } else {
                isValid = 1;
            }
        } while (!isValid);

        if (num != 0) {
            readNumber(num);
        }

        do {
            printf("Bam 1 de nhap lai, 2 de thoat: ");
            scanf("%d", &choice);

            if (choice != 1 && choice != 2) {
                printf("Nhap khong hop le. ");
            }
        } while (choice != 1 && choice != 2);
    } while (choice == 1);

    return 0;
}
