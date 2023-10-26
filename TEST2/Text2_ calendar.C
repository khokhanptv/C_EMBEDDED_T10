#include "stdio.h"

int kiemTraNgayThang(int ngay, int thang, int nam) 
{
    return (ngay > 0 && ngay <= 31 && thang > 0 && thang <= 12 && nam > 0);
}

int laNamNhuan(int nam) 
{
   
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// tính ngày Julian, theo cong thuc
// https://tex.stackexchange.com/questions/652168/automated-age-calculation-by-lualatex
int tinhNgayJulian(int ngay, int thang, int nam) 
{
  int ngay_julian = 1461 * (nam + 4800 + (thang - 14) / 12) / 4 +
                      367 * (thang - 2 - 12 * ((thang - 14) / 12)) / 12 -
                      3 * ((nam + 4900 + (thang - 14) / 12) / 100) / 4 +
                      ngay - 32075;

return ngay_julian;
}


void inNgayVaThu(int ngay, int thang, int nam) 
{
    char *week[] = {"Chu nhat", "Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7"};
    int thu = (tinhNgayJulian(ngay, thang, nam) + 1) % 7;
    printf("%d/%d/%d la %s\n", ngay, thang, nam, week[thu]);
}

int main() 
{
    int ngay, thang, nam;
    int check = 0;

    while (check != 1) 
    {
        printf("Vui long nhap ngay: ");
        scanf("%d", &ngay);
        printf("Vui long nhap thang: ");
        scanf("%d", &thang);
        printf("Vui long nhap nam: ");
        scanf("%d", &nam);

        if (!kiemTraNgayThang(ngay, thang, nam)) 
        {
            printf("Ngay, thang hoac nam chua chinh xac, nhap lai plzz\n");
        } 
        else 
        {
            check = 1;
        }
    }

    inNgayVaThu(ngay, thang, nam);

    if (laNamNhuan(nam)) 
    {
        
        printf("Nam %d la nam nhuan\n", nam);
    } 
    else 
    {
        printf("Nam %d khong phai la nam nhuan\n", nam);
    }

    return 0;
}
