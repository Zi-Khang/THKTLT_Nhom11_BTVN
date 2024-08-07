#include <stdio.h>

void xuatCucTieu(int arr[], int n) {
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void xoaPhanTu(int arr[], int *n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = k; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void themPhanTu(int arr[], int *n, int k, int x) {
    if (k < 0 || k > *n) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = *n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    (*n)++;
}

void chuyenChanLe(int arr[], int n) {
    int temp;
    int i = 0, j = n - 1;
    while (i < j) {
        while (arr[i] % 2 == 0 && i < j) i++;
        while (arr[j] % 2 != 0 && i < j) j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int kiemTraXenKe(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 == 0) || 
            (arr[i] % 2 != 0 && arr[i - 1] % 2 != 0)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int arr[100], n, k, x;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    printf("Nhap mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Cac so cuc tieu: ");
    xuatCucTieu(arr, n);

    printf("Nhap vi tri can xoa: ");
    scanf("%d", &k);
    xoaPhanTu(arr, &n, k);
    printf("Mang sau khi xoa: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap vi tri can them: ");
    scanf("%d", &k);
    printf("Nhap gia tri can them: ");
    scanf("%d", &x);
    themPhanTu(arr, &n, k, x);
    printf("Mang sau khi them: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    chuyenChanLe(arr, n);
    printf("Mang sau khi chuyen chan len dau, le xuong cuoi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (kiemTraXenKe(arr, n)) {
        printf("Mang co chua chan le xen ke\n");
    } else {
        printf("Mang khong chua chan le xen ke\n");
    }

    return 0;
}
