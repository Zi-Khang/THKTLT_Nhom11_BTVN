#include <stdio.h>
#include <ctype.h>

void printCharacters(char *str) {
    while (*str != '\0') {
        printf("%c ", *str);
        str++;
    }
    printf("\n");
}

void toUpperCase(char *str) {
    while (*str != '\0') {
        *str = toupper(*str);
        str++;
    }
}

void capitalizeWords(char *str) {
    int capitalize = 1;

    while (*str != '\0') {
        if (isspace(*str)) {
            capitalize = 1;
        } else if (capitalize && isalpha(*str)) {
            *str = toupper(*str);
            capitalize = 0;
        }
        str++;
    }
}

int main() {
    char str[100];

    // Nhập chuỗi
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    // a. Xuất giá trị từng ký tự của chuỗi
    printf("Cac ky tu cua chuoi la: ");
    printCharacters(str);

    // b. Chuyển các ký tự về dạng chữ hoa
    toUpperCase(str);
    printf("Chuoi sau khi chuyen chu hoa: %s\n", str);

    // c. Chuyển các ký tự đầu mỗi từ về dạng chữ hoa
    capitalizeWords(str);
    printf("Chuoi sau khi chuyen ky tu dau thanh chu hoa: %s\n", str);

    return 0;
}
