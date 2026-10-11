#include <stdio.h>
#include <windows.h>

main() {
    //виставляю кодировку виводу консолі в UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    //Умова: Бортовий комп'ютер автономного дрона отримує дані від трьох далекомірів: 
    // лівого, центрального та правого. Для уникнення зіткнення дрон повинен миттєво обрати 
    // напрямок із максимальною вільною відстанню. 
    // За допомогою вкладеного тернарного оператора знайдіть максимальну дистанцію та виведіть відповідне повідомлення. 


    //Ввести змінні left, center, right
    int left, center, right;

    //Зчитаємо змінні left, center, right
    printf("Введіть дані датчика (ліворуч, по центру, праворуч у см)): ");
    if (scanf("%d %d %d", &left, &center, &right) != 3) {
        printf("Error: неправильний вхідний дані.\n");
        return;
    }

    // Пошук максимуму за допомогою тернарного оператора
    int max_dist = (left > center) 
                    ? ((left > right) ? left : right) 
                    : ((center > right) ? center : right);

    // Висновок
    printf("Sensor data (cm): Left = %d | Center = %d | Right = %d\n", left, center, right);
    printf("Autopilot Choice:  Safe corridor selected – %d cm.\n", max_dist);

    return;
}