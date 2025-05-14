#include <stdio.h>

int removeDuplicate(int* nums, int numSize){
    if (numSize==0){
        return 0;
    }
    int i=0;
    for(int j=1; j<numSize;j++){
        if(nums[j] != nums[i]){
        i++;
        nums[i] = nums[j];
        }
    }
    return i+1;
}

int main(){
    int nums[]={1,1,2,3,4,5,6,6};
    int size=sizeof(nums)/sizeof(nums[0]);
    int newLength=removeDuplicate(nums,size);

    printf("New Length: %d\n", newLength);

    for (int i=0; i<newLength; i++){
        printf("%d",nums[i]);
    }
    printf("\n");

    return 0;

}

