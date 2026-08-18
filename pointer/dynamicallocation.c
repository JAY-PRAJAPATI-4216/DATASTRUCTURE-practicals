#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p,n,*temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    p = (int *)malloc(sizeof(int)*n);
    
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    temp = p;
    for(int i = 0; i<n; i++) {
        printf("%d \n", temp);
        temp ++;
    }
    temp = p;
    for (int i = 0; i < n; i++) {
        printf("Enter a value for index  %d: ", i);
        scanf("%d", (temp+i));
    }
    temp = p;
    for (int i = 0; i < n; i++) {
        printf("Value at index %d: %d\n", i, *temp);
        temp++;
    }
    
    return 0;
}

