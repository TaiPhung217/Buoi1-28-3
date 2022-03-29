#include <stdio.h>
#include <stdlib.h>

/*ham gop 2 mang*/
void gop_mang(int a[], int start, int m, int end){
    int n1 = m - start + 1; // Số phần tử mảng con trái , tính cả m

    int n2= end-m;          // Số phần tử mảng con phải
    int left[n1]; int right[n2];  // khai báo 2 mảng phụ lưu mảng con

   //điền phần tử vào mảng con
    for(int i=0; i<n1; i++) left[i] = a[start+i];
    for(int j=0; j<n2; j++) right[j] = a[m+1+j];

    int i=0, j=0;
    int k=start;     // k vị trí bắt đầu mảng chính

    while(i<n1 && j<n2){    //khi số phần tử 2 mảng >1
        if(left[i]>=right[j]){   // Nếu phần tử mảng trái >= phần tử mảng  phải
            a[k]=right[j];   // Điển phần tử mảng phải vào mảng chính
            j++;             // xét phần tử tiếp theo của mảng phải
        }
        else{
            a[k]=left[i];
            i++;
        }
        k++;   //tăng vị trí của mảng chính
    }

    while(j<n2){      // Nếu mảng phải chưa hết, mảng trái đã hết
        a[k]=right[j]; // cho các giá trị vào mảng chính
        k++;
        j++;
    }
    while(i<n1){     //tương tự với mảng trái
        a[k]= left[i];
        k++;
        i++;
    }
}

//dùng đệ quy để chia mảng
void Merge_Sort(int a[], int start, int end){
    int m;    // biến vị trí giũa
    if(start<end){        //đệ quy
        m=(start+end)/2;    // tìm vị trí giữa
        Merge_Sort(a,start,m);   // Đệ quy mảng trái
        Merge_Sort(a,m+1,end);   // Đệ quy mảng phải
        gop_mang(a,start,m,end);   // gộp hai mảng lại
    }
    else    // mảng <1 dừng đệ quy
        return;
}

/*ham in mang*/
void Arr_Output(int a[],int size)
{
    int i;
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    Merge_Sort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    Arr_Output(arr, arr_size);
    return 0;
}
