#include <stdio.h>
int main() {
    int n, key, i, flag = 0;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
	}
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("found at position %d\n", i);
            flag = 1;
            break;
        }
	}
    if (!flag) {
        printf("%d not found\n", key);
	}
    return 0;
}
