#include <stdio.h>

void flipArray(int*arr,int left,int right){
    while (left<right){
        int tmp=arr[left];
        arr[left]=arr[right];
        arr[right]=tmp;

        left++;
        right--;
    }
}
void rotateArray(int*arr,int arr_len,int shift){
    shift=shift%arr_len;

    flipArray(arr,0,arr_len-1);
    flipArray(arr,0,shift-1);
    flipArray(arr,shift,arr_len-1);
}
int main(){
    int test[]={23, 24, 25, 26, 27, 28};
    int len=sizeof(test)/sizeof(test[0]);
    int k=3;

    printf("Before rotation:");
    for(int i=0; i<len; i++){
        printf("%d", test[i]);
    }
    printf("I\n");

    rotateArray(test,len,k);

    printf("After rotation:");
    for(int i=0; i<len; i++){
        printf("%d", test[i]);
    }
    printf("\n");

    return 0;
}

