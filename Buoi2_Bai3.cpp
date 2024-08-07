#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char hoTen[100];
    char soDienThoai[20];
    int soVeNguoiLon;
    int soVeTreEm;
    char tenPhim[100];
    char phongChieu[50];
    char xuatChieu[50];
    int tienPhaiTra;
} KhachHang;

KhachHang dskh[MAX];
int n; 
void docDanhSachKhachHang(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong mo duoc file %s\n", filename);
        return;
    }

    fscanf(file, "%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(dskh[i].hoTen, sizeof(dskh[i].hoTen), file);
        dskh[i].hoTen[strcspn(dskh[i].hoTen, "\n")] = '\0';
        fgets(dskh[i].soDienThoai, sizeof(dskh[i].soDienThoai), file);
        dskh[i].soDienThoai[strcspn(dskh[i].soDienThoai, "\n")] = '\0';
        fscanf(file, "%d\n", &dskh[i].soVeNguoiLon);
        fscanf(file, "%d\n", &dskh[i].soVeTreEm);
        fgets(dskh[i].tenPhim, sizeof(dskh[i].tenPhim), file);
        dskh[i].tenPhim[strcspn(dskh[i].tenPhim, "\n")] = '\0';
        fgets(dskh[i].phongChieu, sizeof(dskh[i].phongChieu), file);
        dskh[i].phongChieu[strcspn(dskh[i].phongChieu, "\n")] = '\0';
        fgets(dskh[i].xuatChieu, sizeof(dskh[i].xuatChieu), file);
        dskh[i].xuatChieu[strcspn(dskh[i].xuatChieu, "\n")] = '\0';
    }

    fclose(file);
}

void xuatDanhSachKhachHang() {
    printf("Danh sach khach hang dat ve:\n");
    for (int i = 0; i < n; i++) {
        printf("Khach hang %d:\n", i + 1);
        printf("Ho va ten: %s\n", dskh[i].hoTen);
        printf("So dien thoai: %s\n", dskh[i].soDienThoai);
        printf("So ve nguoi lon: %d\n", dskh[i].soVeNguoiLon);
        printf("So ve tre em: %d\n", dskh[i].soVeTreEm);
        printf("Ten phim: %s\n", dskh[i].tenPhim);
        printf("Phong chieu: %s\n", dskh[i].phongChieu);
        printf("Xuat chieu: %s\n", dskh[i].xuatChieu);
        printf("Tien phai tra: %d\n", dskh[i].tienPhaiTra);
        printf("\n");
    }
}

void tinhTienPhaiTra() {
    int giaVeNguoiLon = 40000;
    int giaVeTreEm = 20000;

    for (int i = 0; i < n; i++) {
        dskh[i].tienPhaiTra = dskh[i].soVeNguoiLon * giaVeNguoiLon + dskh[i].soVeTreEm * giaVeTreEm;
    }
}

void tinhTongDoanhThu() {
    int tongDoanhThu = 0;
    for (int i = 0; i < n; i++) {
        tongDoanhThu += dskh[i].tienPhaiTra;
    }
    printf("Tong doanh thu cua rap phim: %d VND\n", tongDoanhThu);
}

void tinhTongDoanhThuTungPhim() {
    for (int i = 0; i < n; i++) {
        int tongDoanhThuPhim = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(dskh[i].tenPhim, dskh[j].tenPhim) == 0) {
                tongDoanhThuPhim += dskh[j].tienPhaiTra;
            }
        }
        printf("Tong doanh thu cua phim %s: %d VND\n", dskh[i].tenPhim, tongDoanhThuPhim);
        for (int k = 0; k < i; k++) {
            if (strcmp(dskh[i].tenPhim, dskh[k].tenPhim) == 0) {
                break;
            }
        }
    }
}

void timKhachHangTheoPhongVaXuat() {
    char phongChieu[50], xuatChieu[50];
    
    printf("Nhap phong chieu: ");
    fgets(phongChieu, sizeof(phongChieu), stdin);
    phongChieu[strcspn(phongChieu, "\n")] = '\0';

    printf("Nhap xuat chieu: ");
    fgets(xuatChieu, sizeof(xuatChieu), stdin);
    xuatChieu[strcspn(xuatChieu, "\n")] = '\0';

    printf("Danh sach khach hang dat ve cho phong chieu %s va xuat chieu %s:\n", phongChieu, xuatChieu);
    for (int i = 0; i < n; i++) {
        if (strcmp(dskh[i].phongChieu, phongChieu) == 0 && strcmp(dskh[i].xuatChieu, xuatChieu) == 0) {
            printf("Khach hang %d:\n", i + 1);
            printf("Ho va ten: %s\n", dskh[i].hoTen);
            printf("So dien thoai: %s\n", dskh[i].soDienThoai);
            printf("So ve nguoi lon: %d\n", dskh[i].soVeNguoiLon);
            printf("So ve tre em: %d\n", dskh[i].soVeTreEm);
            printf("Tien phai tra: %d\n", dskh[i].tienPhaiTra);
            printf("\n");
        }
    }
}

void bubbleSortTheoTienPhaiTra() {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (dskh[j].tienPhaiTra > dskh[j+1].tienPhaiTra) {
                KhachHang temp = dskh[j];
                dskh[j] = dskh[j+1];
                dskh[j+1] = temp;
            }
        }
    }
}

void selectionSortTheoTienPhaiTra() {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (dskh[j].tienPhaiTra < dskh[min_idx].tienPhaiTra) {
                min_idx = j;
            }
        }
        KhachHang temp = dskh[min_idx];
        dskh[min_idx] = dskh[i];
        dskh[i] = temp;
    }
}

void insertionSortTheoTienPhaiTra() {
    for (int i = 1; i < n; i++) {
        KhachHang key = dskh[i];
        int j = i - 1;
        while (j >= 0 && dskh[j].tienPhaiTra > key.tienPhaiTra) {
            dskh[j + 1] = dskh[j];
            j = j - 1;
        }
        dskh[j + 1] = key;
    }
}

void sapXepTheoHoTen() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(dskh[i].hoTen, dskh[j].hoTen) > 0) {
                KhachHang temp = dskh[i];
                dskh[i] = dskh[j];
                dskh[j] = temp;
            }
        }
    }
}

int binarySearchTheoHoTen(char* hoTen) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = strcmp(hoTen, dskh[mid].hoTen);
        if (res == 0) {
            return mid;
        }
        if (res > 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    docDanhSachKhachHang("danhsachkhachhang.txt");
	tinhTienPhaiTra();
    xuatDanhSachKhachHang();
	tinhTongDoanhThu();
	tinhTongDoanhThuTungPhim();
	timKhachHangTheoPhongVaXuat();
	bubbleSortTheoTienPhaiTra(); 
	//selectionSortTheoTienPhaiTra()
	//insertionSortTheoTienPhaiTra()
	sapXepTheoHoTen();

	char hoTenTimKiem[] = "Nguyen Van An";
    int index = binarySearchTheoHoTen(hoTenTimKiem);
    if (index != -1) {
        printf("Khach hang '%s' duoc tim thay tai vi tri %d trong danh sach.\n", hoTenTimKiem, index);
    } else {
        printf("Khach hang '%s' khong duoc tim thay.\n", hoTenTimKiem);
    }

    return 0;
}

