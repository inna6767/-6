#include <stdio.h>
#include <locale.h>

int z1_year(int years);
double z2_f(double x);
int z3(int n);

int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Задание 1
    int y;
    printf("Задание 1: Високосный год\n");
    printf("Введите год: ");
    scanf("%d", &y);

    if (z1_year(y) == 1) {
        printf("%d - високосный год\n", y);
    }
    else {
        printf("%d - не високосный год\n", y);
    }

    // Задание 2
    double x, fx;
    printf("\nЗадание 2: Вычисление функции F(x)\n");
    printf("Введите x: ");
    scanf("%lf", &x);

    fx = z2_f(x);
    printf("F(%.2f) = %.6f\n", x, fx);

    // Задание 3
    int n;
    printf("\nЗадание 3: Произведение цифр числа\n");
    printf("Введите число N (N < 1000): ");
    scanf("%d", &n);

    int result = z3(n);
    if (result == 1) {
        printf("Произведение цифр числа %d — трёхзначное.\n", n);
    }
    else {
        printf("Произведение цифр числа %d — НЕ трёхзначное.\n", n);
    }

    return 0;
}

int z1_year(int years) {
    if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0)) {
        return 1;
    }
    return 0;
}

double z2_f(double x) {
    if (x <= 7) {
        return 3 * x - 9;
    }
    else {
        return 1.0 / (x * x - 4);
    }
}

int z3(int n) {
    int temp = n;
    int product = 1;

    if (n == 0) {
        product = 0;
    }
    else {
        while (temp > 0) {
            int digit = temp % 10;
            product *= digit;
            temp /= 10;
        }
    }

    if (product >= 100 && product <= 999) {
        return 1;
    }
    else {
        return 0;
    }
}
