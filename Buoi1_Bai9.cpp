#include <stdio.h>
#include <conio.h>

int main() {
    int a, b;
    int *pa, *pb;
    int sum, diff, prod;
    float quotient;
    int *p_sum, *p_diff, *p_prod;
    float *p_quotient;

    printf("Nhap gia tri a: ");
    scanf("%d", &a);
    printf("Nhap gia tri b: ");
    scanf("%d", &b);

    pa = &a;
    pb = &b;

    sum = *pa + *pb;
    diff = *pa - *pb;
    prod = (*pa) * (*pb);
    quotient = (float)(*pa) / (*pb);

    p_sum = &sum;
    p_diff = &diff;
    p_prod = &prod;
    p_quotient = &quotient;

    printf("Tong: %d, dia chi: %p\n", sum, (void*)p_sum);
    printf("Hieu: %d, dia chi: %p\n", diff, (void*)p_diff);
    printf("Tich: %d, dia chi: %p\n", prod, (void*)p_prod);
    printf("Thuong: %.2f, dia chi: %p\n", quotient, (void*)p_quotient);

    getch();

}
