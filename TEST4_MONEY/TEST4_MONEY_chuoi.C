 #include <stdio.h>

// Mảng chứa các chuỗi tương ứng với các chữ số
char *ones[] = {"không", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"};
char *teens[] = {"mười", "mười một", "mười hai", "mười ba", "mười bốn", "mười lăm", "mười sáu", "mười bảy", "mười tám", "mười chín"};
char *tens[] = {"", "", "hai mươi", "ba mươi", "bốn mươi", "năm mươi", "sáu mươi", "bảy mươi", "tám mươi", "chín mươi"};

void readNumber(int num) {
    if (num >= 100) {
        printf("%s trăm ", ones[num / 100]);
        num %= 100;
    }

    if (num >= 10 && num <= 19) {
        printf("%s đồng ", teens[num - 10]);
    } else if (num >= 20) {
        printf("%s ", tens[num / 10]);
        num %= 10;
    }

    if (num > 0) {
        printf("%s ", ones[num]);
    }
}

int main() {
    int number;

    printf("Nhập số tiền (dạng số): ");
    scanf("%d", &number);

    printf("Số tiền là: ");

    if (number == 0) {
        printf("không đồng\n");
    } else {
        readNumber(number);
        printf("đồng\n");
    }

    return 0;
}
