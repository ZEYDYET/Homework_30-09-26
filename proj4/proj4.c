#include <stdio.h>
#include <windows.h>

main(){
    //виставляю кодировку виводу консолі в UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Умова: Моніторинг стану сервера / системи. 
    // Написати програму, яка запитує температуру процесора CPU (°C) та рівень завантаження 
    // оперативної пам'яті RAM (%) і визначает режим роботи системи. 

    //Ввести змінні temp ram_usage
    int temp;
    int ram_usage ;

    //Зчитати значення temp ram_usage
    printf("Введіть температуру CPU (°C) та завантаження RAM (%%): ");
    if (scanf("%d %d", &temp, &ram_usage) != 2) {
        puts("Помилка введення даних!");
        return;
    }

    // Валідація вхідних даних
    if (temp < -50 || temp > 150 || ram_usage < 0 || ram_usage > 100) {
        puts("Помилка: Некоректні параметри системи!");
        return;
    }

    // Перевірити умови розгалуження
    if (temp >= 85 || ram_usage >= 95) {
        puts("[CRITICAL] Перегрів або нестача пам'яті! Увімкнено тротлінг.");
    } else if (temp >= 70 && ram_usage >= 70) {
        puts("[HIGH PERFORMANCE] Максимальна швидкість кулерів. Виділено додаткові ресурси.");
    } else if (temp < 50 && ram_usage < 40) {
        puts("[ECO] Низьке навантаження. Кулери зупинено (Silent mode).");
    } else {
        puts("[BALANCED] Стандартна робота системи.");
    }
}