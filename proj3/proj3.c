#include <stdio.h>
#include <windows.h>

main() {
    //виставляю кодировку виводу консолі в UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Умова: Написати програму з використанням оператора множинного вибору switch, 
    // яка запитує у користувача номер місяця (число від 1 до 12) та визначає кількість днів у ньому. 
    // Якщо обрано лютий, додатково запитується, чи є рік високосним, і виводиться 28 або 29 днів. 
    // При введенні числа поза межами 1–12 виводиться повідомлення про помилку. 

    //Ввести змінні  month_number, days, month
    int month_number, days;
    const char *month = "none";

    //Зчитати month_number та перевірити правильність введення 
    printf("Введіть номер місяця (1-12): ");
    if (scanf("%d", &month_number) != 1) {
        printf("Помилка: потрібно ввести число!\n");
        return;
    }

    //Виконати оператор switch 
    switch (month_number)
    {
        case 1:  month = "Січень"; days = 31; break;
        case 2:  
        month = "Лютий"; 
        int is_leap;
        
        printf("Це високосний рік? (1 - так, 2 - ні)");
        if (scanf("%d", &is_leap) != 1) {
            return;
        }
        if (is_leap == 1) {
                days = 29;
            } else if (is_leap == 0) {
                days = 28;
            } else {
                printf("Помилка: потрібно ввести 1 (так) або 0 (ні).\n");
                return;
            }
        break;
        case 3:  month = "Березень"; days = 31; break;
        case 4:  month = "Квітень"; days = 30; break;
        case 5:  month = "Травень"; days = 31; break;
        case 6:  month = "Червень"; days = 30; break;
        case 7:  month = "Липень"; days = 31; break;
        case 8:  month = "Серпень"; days = 31; break;
        case 9:  month = "Вересень"; days = 30; break;
        case 10: month = "Жовтень"; days = 31; break;
        case 11: month = "Листопад"; days = 30; break;
        case 12: month = "Грудень"; days = 31; break;
        default:
            printf("Помилка: номери місяців можуть бути лише від 1 до 12.\n");
            return;
    }
    //Вивести результат
    printf("Обраний місяць: %s у ньому %d днів\n", month, days);
}