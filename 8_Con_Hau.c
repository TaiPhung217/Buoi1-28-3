#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[20];
int n=4,count=0;

void KiemTra(int a[],int row)
{
    //kiểm tra có cùng cột, cùng đường chéo không
    if(row == n){
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        count++;
        printf("\n");
    }
    else{
        for(int i=0;i<n;i++){
            int check=1;
            //kiểm tra có đặt quân hậu ở đây được không
            for(int j=0;j<row;j++){
                if(i == a[j] || i == a[j] - j +row/*cheo phai*/||i==a[j]+j-row/*cheo trai*/){
                    check = 0;
                }
            }
            //nếu đặt được, lưu lại vị trí đặt
            if(check){
                a[row] = i;
                KiemTra(a,row+1); // đệ quy tìm vị trí tiếp theo
            }
        }
    }
}

int main()
{
    KiemTra(a,0);

    printf(" => Co %d cach dat\n",count);
    return 0;
}
