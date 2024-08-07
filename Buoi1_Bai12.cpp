#include <stdio.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

int ucln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void rutGon(PhanSo *ps) {
    int gcd = ucln(ps->tu, ps->mau);
    ps->tu /= gcd;
    ps->mau /= gcd;
}

int soSanhPhanSo(PhanSo a, PhanSo b) {
    return a.tu * b.mau - b.tu * a.mau;
}

void timPhanSoLonNhatNhoNhat(PhanSo arr[], int n, PhanSo *lonNhat, PhanSo *nhoNhat) {
    *lonNhat = arr[0];
    *nhoNhat = arr[0];
    for (int i = 1; i < n; i++) {
        if (soSanhPhanSo(arr[i], *lonNhat) > 0) {
            *lonNhat = arr[i];
        }
        if (soSanhPhanSo(arr[i], *nhoNhat) < 0) {
            *nhoNhat = arr[i];
        }
    }
}

void xoaPhanSo(PhanSo arr[], int *n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = k; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void themPhanSo(PhanSo arr[], int *n, int k, PhanSo ps) {
    if (k < 0 || k > *n) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = *n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = ps;
    (*n)++;
}

int main() {
    PhanSo arr[100];
    int n, k;
    PhanSo lonNhat, nhoNhat, ps;

    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    printf("Nhap cac phan so: \n");
    for (int i = 0; i < n; i++) {
        printf("Nhap tu so va mau so: ");
        scanf("%d%d", &arr[i].tu, &arr[i].mau);
        rutGon(&arr[i]);
    }

    timPhanSoLonNhatNhoNhat(arr, n, &lonNhat, &nhoNhat);
    printf("Phan so lon nhat: %d/%d\n", lonNhat.tu, lonNhat.mau);
    printf("Phan so nho nhat: %d/%d\n", nhoNhat.tu, nhoNhat.mau);

    printf("Nhap vi tri can xoa: ");
    scanf("%d", &k);
    xoaPhanSo(arr, &n, k);
    printf("Mang sau khi xoa: \n");
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", arr[i].tu, arr[i].mau);
    }
    printf("\n");

    printf("Nhap vi tri can them: ");
    scanf("%d", &k);
    printf("Nhap tu so va mau so cua phan so moi: ");
    scanf("%d%d", &ps.tu, &ps.mau);
    rutGon(&ps);
    themPhanSo(arr, &n, k, ps);
    printf("Mang sau khi them: \n");
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", arr[i].tu, arr[i].mau);
    }
    printf("\n");

    return 0;
}
