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

    int n[16];  
    int len = 0; 

    
    while (num > 0) {
        n[len++] = num % 10;
        num /= 10;
    }

    int printed = 0; 
    int hasPrinted = 0; 
    for (int i = len - 1; i >= 0; i--) {
        if (i % 3 == 2 && n[i] > 0) {
            printf("%s ", unit3[n[i]]);
            printed = 1;
            hasPrinted = 1;
        } else if (i % 3 == 1) {
            if (n[i] > 1) {
                printf("%s ", unit2[n[i]]);
                printed = 1;
                hasPrinted = 1;
            } else if (n[i] == 1) {
                if (i == 0) { 
                    printf("%s ", unit[1]);
                } else {
                    printf("muoi ");
                }
                printed = 1;
                hasPrinted = 1;
            } else if (printed) { 
                printf("khong ");
                printed = 0;
            }
        } else if (i % 3 == 0) {
            if (n[i] > 0) {
                printf("%s ", unit[n[i]]);
                printed = 1;
                hasPrinted = 1;
            }
            if (i > 0) {
                printf("%s ", unit4[i / 3]);
            }
        }
    }

    if (!hasPrinted) {
        printf("%s ", unit[0]);
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
            printf("Nhap so (0 va be hon 1 nghin ty): ");
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
