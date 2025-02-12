#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int *arr = NULL, *even = NULL, *odd = NULL;
    int num = 0, sign = 1, count = 0, evenCount = 0, oddCount = 0;
    int ch;
    int inNumber = 0; 
    while (1) {
        ch = getchar();

        if (ch == '\n' && !inNumber) {
            break;
        }

        if (isdigit(ch) || (ch == '-' && !inNumber)) {
            if (ch == '-') {
                sign = -1;  // buat angka negatif
            } else {
                if (!inNumber) {
                    num = 0;  // reset num
                    sign = 1;
                }
                num = num * 10 + (ch - '0');
            }
            inNumber = 1;
        } else if (isspace(ch) && inNumber) {
            arr = realloc(arr, (count + 1) * sizeof(int));
            arr[count++] = num * sign;
            num = 0;
            sign = 1;
            inNumber = 0;
        }
    }

    if (inNumber) {
        arr = realloc(arr, (count + 1) * sizeof(int));
        arr[count++] = num * sign;
    }

    even = (int *)malloc(count * sizeof(int));
    odd = (int *)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++) {
        if (arr[i] % 2 == 0)
            even[evenCount++] = arr[i];
        else
            odd[oddCount++] = arr[i];
    }

    // sorting pake linear sort
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = i + 1; j < evenCount; j++) {
            if (even[i] > even[j]) {
                int temp = even[i];
                even[i] = even[j];
                even[j] = temp;
            }
        }
    }

    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = i + 1; j < oddCount; j++) {
            if (odd[i] < odd[j]) {
                int temp = odd[i];
                odd[i] = odd[j];
                odd[j] = temp;
            }
        }
    }

    for (int i = 0; i < evenCount; i++)
        printf("%d ", even[i]);
    for (int i = 0; i < oddCount; i++)
        printf("%d ", odd[i]);

    free(arr);
    free(even);
    free(odd);

    return 0;
}
