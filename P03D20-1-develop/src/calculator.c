#include "Headers/calculator.h"

// Функция для расчета значения функции при Х =
/**
 * Функция `evaluateRPN` вычисляет выражение в обратной польской нотации (ОПН), содержащее
 * арифметические операции, тригонометрические функции и переменные, с возможностью
 * подставить значение для переменной 'x'.
 * 
 * @param rpn Параметр `rpn` — это двумерный массив строк, представляющий выражение в
 * обратной польской нотации. Каждая строка в массиве содержит элемент выражения ОПН.
 * Функция `evaluateRPN` обрабатывает данное выражение ОПН для вычисления
 * математического выражения, которое оно представляет.
 * @param rpnLength Параметр `rpnLength` в функции `evaluateRPN` представляет длину
 * выражения в обратной польской нотации (ОПН), которое оценивается. Он указывает
 * количество элементов в массиве `rpn`, которые необходимо обработать в процессе вычисления.
 * @param x Функция `evaluateRPN` принимает выражение в обратной польской нотации, хранящееся в 
 * двумерном массиве `rpn`, длину выражения `rpnLength` и значение `x`, которое используется для
 * вычисления выражения.
 * 
 * @return Функция `evaluateRPN` возвращает результат вычисления выражения в обратной
 * польской нотации (ОПН), хранящегося в массиве `rpn` с заданной длиной `rpnLength` и
 * указанным значением `x`.
 */
double evaluateRPN(char rpn[MAX_EXPR_SIZE][MAX_EXPR_SIZE], int rpnLength, double x) {
    Stack stack;  // Объявляем стек для хранения промежуточных значений
    stack.top = -1;  // Инициализируем стек (устанавливаем верхний индекс стека на -1, что означает, что стек пуст)

    for (int i = 0; i < rpnLength; i++) {  // Цикл по всем элементам выражения в ОПН
        if (isdigit(rpn[i][0])) {  // Проверяем, является ли текущий элемент числом
            // Конвертируем строку в число с плавающей точкой и помещаем его в стек
            push(&stack, atof(rpn[i]));
        } else if (rpn[i][0] == 'x') {  // Проверяем, является ли текущий элемент переменной 'x'
            // Помещаем значение переменной 'x' в стек
            push(&stack, x);
        } else if (isfunction(rpn[i])) {  // Проверяем, является ли текущий элемент тригонометрической функцией
            // Удаляем последний добавленный элемент (число), так как функция применится к нему
            double a = pop(&stack);
            // В зависимости от названия функции помещаем в стек результат вычисления
            if (strcmp(rpn[i], "sin") == 0) {
                push(&stack, sin(a));  // Синус
            } else if (strcmp(rpn[i], "cos") == 0) {
                push(&stack, cos(a));  // Косинус
            } else if (strcmp(rpn[i], "tg") == 0) {
                push(&stack, tan(a));  // Тангенс
            } else if (strcmp(rpn[i], "ln") == 0) {
                push(&stack, log(a));  // Натуральный логарифм
            } else if (strcmp(rpn[i], "sqrt") == 0) {
                push(&stack, sqrt(a));  // Квадратный корень
            } else if (strcmp(rpn[i], "ctg") == 0) {
                // Котангенс, вычисляется как 1 делить на тангенс
                push(&stack, (1.0f / tan(a)));
            }
        } else if (isoperator(rpn[i])) {  // Проверяем, является ли текущий элемент оператором
            // Удаляем последние два элемента из стека для выполнения операции
            double b = pop(&stack);
            double a = pop(&stack);
            // В зависимости от оператора помещаем в стек результат операции
            if (strcmp(rpn[i], "+") == 0) {
                push(&stack, a + b);  // Сложение
            } else if (strcmp(rpn[i], "-") == 0) {
                push(&stack, a - b);  // Вычитание
            } else if (strcmp(rpn[i], "*") == 0) {
                push(&stack, a * b);  // Умножение
            } else if (strcmp(rpn[i], "/") == 0) {
                if (b == 0) {  // Проверяем деление на ноль
                    printf("Ошибка: деление на ноль.");
                    exit(1);  // Завершаем программу в случае деления на ноль
                }
                push(&stack, a / b);  // Деление
            }
        }
    }
    return pop(&stack);  // Возвращаем окончательный результат вычисления из стека
}