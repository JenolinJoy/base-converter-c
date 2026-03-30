#include <stdio.h>

// Function to convert Decimal to Binary
void decimalToBinary(int num) {
    int binary[32], i = 0;

    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

// Function to convert Binary to Decimal
void binaryToDecimal(int num) {
    int decimal = 0, base = 1, remainder;

    while (num > 0) {
        remainder = num % 10;
        decimal += remainder * base;
        num = num / 10;
        base *= 2;
    }

    printf("Decimal: %d\n", decimal);
}

// Function to convert Decimal to Hexadecimal
void decimalToHex(int num) {
    char hex[32];
    int i = 0;

    if (num == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    while (num > 0) {
        int rem = num % 16;
        if (rem < 10)
            hex[i] = rem + '0';
        else
            hex[i] = rem - 10 + 'A';
        num = num / 16;
        i++;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

// Function to convert Hexadecimal to Decimal
void hexToDecimal(char hex[]) {
    int decimal = 0, i = 0;
    char ch;

    while (hex[i] != '\0') {
        ch = hex[i];

        if (ch >= '0' && ch <= '9')
            decimal = decimal * 16 + (ch - '0');
        else if (ch >= 'A' && ch <= 'F')
            decimal = decimal * 16 + (ch - 'A' + 10);
        else if (ch >= 'a' && ch <= 'f')
            decimal = decimal * 16 + (ch - 'a' + 10);

        i++;
    }

    printf("Decimal: %d\n", decimal);
}

int main() {
    int choice, num;
    char hex[32];

    while (1) {
        printf("\n=== Base Converter ===\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Decimal number: ");
                scanf("%d", &num);
                decimalToBinary(num);
                break;

            case 2:
                printf("Enter Binary number: ");
                scanf("%d", &num);
                binaryToDecimal(num);
                break;

            case 3:
                printf("Enter Decimal number: ");
                scanf("%d", &num);
                decimalToHex(num);
                break;

            case 4:
                printf("Enter Hexadecimal number: ");
                scanf("%s", hex);
                hexToDecimal(hex);
                break;

            case 5:
                printf("Exiting... bye \n");
                return 0;

            default:
                printf("Invalid choice \n");
        }
    }

    return 0;
}
