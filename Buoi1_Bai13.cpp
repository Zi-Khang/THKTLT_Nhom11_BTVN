#include <stdio.h>

int main() {
    int a[100], b[100], n, m;

    printf("Nhap so luong phan tu cua mang a: ");
    scanf("%d", &n);

    printf("Nhap mang a: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Nhap so luong phan tu cua mang b: ");
    scanf("%d", &m);

    printf("Nhap mang b: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    if (n != m) {
        printf("Kich thuoc cua hai mang khong bang nhau. Khong the thuc hien phep chia.\n");
        return 1;
    }

    printf("Ket qua phep chia cac phan tu tuong ung cua mang a cho mang b:\n");
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            printf("Phan tu thu %d cua mang b bang 0, khong the thuc hien phep chia.\n", i + 1);
        } else {
            float result = (float)a[i] / b[i];
            printf("a[%d] / b[%d] = %.2f\n", i, i, result);
        }
    }

    return 0;
}
