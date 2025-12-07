#include<stdio.h>
int main() {
    char arr[11] = {'q','w','e','r','t','y','u','M','o','p','e'};
    int i, j, n;
    char t;
    int compare_count, exchange_count;
    printf("Ã°ÅÝ·¨:\n");
    compare_count = 0;
    exchange_count = 0;
    for(n = 10; n >= 0; n--) {
        for(i = 0; i < n; i++) {
            compare_count++; 
            if(arr[i] > arr[i+1]) {
                t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
                exchange_count++;
            }
        }
    }
    for(i = 0; i < 11; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
    printf("Times of compare: %d\n", compare_count);
    printf("Times of exchange: %d\n\n", exchange_count);
    printf("Ñ¡Ôñ·¨:\n");
    compare_count = 0;
    exchange_count = 0;
    int min_index;
    for(i = 0; i < 10; i++) {
        min_index = i;
        for(j = i+1; j < 11; j++) {
            compare_count++; 
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if(min_index != i) {
            t = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = t;
            exchange_count++; 
        }
    }
    for(i = 0; i < 11; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
    printf("Times of compare: %d\n", compare_count);
    printf("Times of exchange: %d\n", exchange_count);
    return 0;
}

