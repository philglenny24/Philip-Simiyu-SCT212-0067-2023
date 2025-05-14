#include <stdio.h>
#include <stdlib.h>

int summation(int arr[], int n) {
    int total_sum = 0;
    for (int i=0; i<n; i++) {
        total_sum += arr[i];
    }
    return total_sum;
}

int maximum(int arr[], int n) {
    if (n==0) {
        return 0;
    }
    int max = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i]>max) {
            max = arr[i];
        }
    }
    return max;
}

int main () {
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    if (n<0) {
printf("Invalid array size.\n");
return 1;
}
int numbers[1000];
for (int i=0; i<n; i++) {
scanf("%d", &numbers[i]);
}
int total = summation(numbers, n);
int max_value = maximum(numbers, n);
printf("\n sum of numbers: %d\n", total);
printf("Largest number: %d\n", max_value);
return 0;
}

