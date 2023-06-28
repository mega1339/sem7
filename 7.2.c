#include <stdio.h>
#include <stdlib.h>

char* readString() {
    int capacity = 2; // Начальная емкость буфера
    int size = 0; // Текущий размер строки
    char* buffer = (char*)malloc(capacity * sizeof(char)); // Буфер для строки

    if (buffer == NULL) {
        printf("mistake giving memory.\n");
        return NULL;
    }

    char ch = getchar();

    while (ch != '\n' && ch != EOF) {
        buffer[size++] = ch;

        // Если достигнута текущая емкость буфера, увеличиваем его размер
        if (size >= capacity) {
            capacity *= 2;
            char* temp = (char*)realloc(buffer, capacity * sizeof(char));

            if (temp == NULL) {
                printf("mistake a lot of memory.\n");
                free(buffer);
                return NULL;
            }

            buffer = temp;
        }

        ch = getchar();
    }

    buffer[size] = '\0'; // Добавляем символ конца строки

    return buffer;
}

int main() {
    printf("enter string: ");
    char* str = readString();

    printf("the resulting string: %s\n", str);

    free(str);

    return 0;
}
