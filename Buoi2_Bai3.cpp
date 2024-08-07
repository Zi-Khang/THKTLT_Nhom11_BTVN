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



int main() {
    docDanhSachKhachHang("danhsachkhachhang.txt");
	tinhTienPhaiTra();
    xuatDanhSachKhachHang();
	tinhTongDoanhThu();
    return 0;
}

