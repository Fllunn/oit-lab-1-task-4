#include "iostream"
#include "cmath"
#include "iomanip"
#include "string"
#include <utility>


double CalculateRecursiveDouble(int n, double x, double summand = 1.0, int i = 0) {
    // Если кол-во членов ряда <= нулю, то сумма равна 0
    if (n <= 0)
        return 0.0;
    // Если кол-во членов ряда превышает заданное, то выходим из рекурсии
    if (i >= n)
        return 0.0;

    double currentSummand = summand;
    double numMult = ((i + 1.0) * (i + 1.0) + 1.0) / ((i + 1.0) * (i * i + 1.0)) * (x / 2.0);
    double nextSummand = currentSummand * numMult;

    return currentSummand + CalculateRecursiveDouble(n, x, nextSummand, i + 1);
}

float CalculateRecursiveFloat(int n, float x, float summand = 1.0f, int i = 0) {
    // Если кол-во членов ряда <= нулю, то сумма равна 0
    if (n <= 0)
        return 0.0f;
    // Если кол-во членов ряда превышает заданное, то выходим из рекурсии
    if (i >= n)
        return 0.0f;

    float currentSummand = summand;
    float numMult = ((i + 1.0f) * (i + 1.0f) + 1.0f) / ((i + 1.0f) * (i * i + 1.0f)) * (x / 2.0f);
    float nextSummand = currentSummand * numMult;

    return currentSummand + CalculateRecursiveFloat(n, x, nextSummand, i + 1);
}


double CalculateReccurrentDouble(int n, double x) {
    // Если кол-во членов ряда <= нулю, то сумма равна 0
    if (n <= 0)
        return 0.0;

    double sum = 1.0;
    double summand = 1.0;

    for (int i = 1; i < n - 1; i++) {
        // К сумме прибавляем предыдущий член ряда
        sum += summand;
        // Вычисляем рекуррентно следующий член ряда
        summand *= ((i + 1.0) * (i + 1.0) + 1.0) / ((i + 1.0) * (i * i + 1.0)) * (x / 2.0);
    }
    return sum;
}

float CalculateReccurrentFloat(int n, float x) {
    // Если кол-во членов ряда <= нулю, то сумма равна 0
    if (n <= 0)
        return 0.0f;

    float sum = 1.0f;
    float summand = 1.0f;

    for (int i = 1; i < n - 1; i++) {
        // К сумме прибавляем предыдущий член ряда
        sum += summand;
        // Вычисляем рекуррентно следующий член ряда
        summand *= ((i + 1.0f) * (i + 1.0f) + 1.0f) / ((i + 1.0f) * (i * i + 1.0f)) * (x / 2.0f);
        // std::cout << summand << std::endl;
    }
    return sum;
}


std::pair<double, int> CalculateEpsilonDouble(double x, double eps) {
    double sum = 0.0;
    int i = 0;
    double summand = 1.0;

    while (std::abs(summand) >= eps) {
        sum += summand;
        summand *= ((i + 1.0) * (i + 1.0) + 1.0) / ((i + 1.0) * (i * i + 1.0)) * (x / 2.0);
        i++;
    }
    return { sum, i };
}

std::pair<float, int> CalculateEpsilonFloat(float x, float eps) {
    float sum = 0.0f;
    int i = 0;
    float summand = 1.0f;

    while (std::abs(summand) >= eps) {
        sum += summand;
        summand *= ((i + 1.0f) * (i + 1.0f) + 1.0f) / ((i + 1.0f) * (i * i + 1.0f)) * (x / 2.0f);
        i++;
    }
    return { sum, i };
}


std::pair<double, int> CalculateMinEpsilonDouble(double x) {
    double eps = 0.0;

    double sum = 0.0;
    int i = 0;
    double summand = 1.0;

    // Выполняем пока член ряда не станет равен нулю
    while (std::abs(summand) != eps) {
        sum += summand;
        summand *= ((i + 1.0) * (i + 1.0) + 1.0) / ((i + 1.0) * (i * i + 1.0)) * (x / 2.0);
        i++;
    }
    return {sum, i };
}

std::pair<float, int> CalculateMinEpsilonFloat(float x) {
    float eps = 0.0f;

    float sum = 0.0f;
    int i = 0;
    float summand = 1.0f;

    // Выполняем пока член ряда не станет равен нулю
    while (std::abs(summand) != eps) {
        sum += summand;
        summand *= ((i + 1.0f) * (i + 1.0f) + 1.0f) / ((i + 1.0f) * (i * i + 1.0f)) * (x / 2.0f);
        i++;
    }
    return { sum, i };
}


float CalculateFunctionFloat(float x) {
    return ((x * x) / 4.0f + x / 2.0f + 1.0f) * std::exp(x / 2.0f);
}

double CalculateFunctionDouble(double x) {
    return ((x * x) / 4.0 + x / 2.0 + 1.0) * std::exp(x / 2.0);
}


void PrintRecursive(double x, int n) {
    float xFloat = static_cast<float>(x);

    std::cout << "Сумма ряда с помощью рекурсии (double): " << CalculateRecursiveDouble(n, x) << '\n';
    std::cout << "Сумма ряда с помощью рекурсии (float) : " << CalculateRecursiveFloat(n, xFloat) << '\n';
    std::cout << '\n';
}

void PrintRecurrent(double x, int n) {
    float xFloat = static_cast<float>(x);

    std::cout << "Сумма ряда с помощью рекуррентной формулы в цикле (double): " << CalculateRecursiveDouble(n, x) << '\n';
    std::cout << "Сумма ряда с помощью рекуррентной формулы в цикле (float) : " << CalculateRecursiveFloat(n, xFloat) << '\n';
    std::cout << '\n';
}

void PrintEps(double x, double eps) {
    float xFloat = static_cast<float>(x);
    float epsFloat = static_cast<float>(eps);

    std::pair<double, int> resDouble = CalculateEpsilonDouble(x, eps);
    std::pair<float, int> resFloat = CalculateEpsilonDouble(xFloat, epsFloat);

    std::cout << "Сумма ряда с помощью точности epsilon (double): " << resDouble.first << " Количество итераций: " << resDouble.second << '\n';
    std::cout << "Сумма ряда с помощью точности epsilon (float) : " << resFloat.first << " Количество итераций: " << resFloat.second << '\n';
    std::cout << '\n';

    std::pair<double, int> resMinEpsDouble = CalculateMinEpsilonDouble(x);
    std::pair<float, int> resMinEpsFloat = CalculateMinEpsilonFloat(x);

    std::cout << "Сумма ряда с помощью максимально возможной точностью (double): " << resMinEpsDouble.first << " Количество итераций: " << resMinEpsDouble.second << '\n';
    std::cout << "Сумма ряда с помощью максимально возможной точностью (float) : " << resMinEpsFloat.first << " Количество итераций: " << resMinEpsFloat.second << '\n';
    std::cout << '\n';
}

void PrintFunc(double x) {
    float xFloat = static_cast<float>(x);

    std::cout << "Точное значение функции f(x) (double): " << CalculateFunctionDouble(x) << '\n';
    std::cout << "Точное значение функции f(x) (float) : " << CalculateFunctionFloat(xFloat) << '\n';
}


int GetValidInt() {
    int numInput = 0;
    bool isChecked = false;

    do {
        try {
            std::string input;
            std::cin >> input;

            size_t pos = 0;
            numInput = std::stoi(input, &pos);

            if (pos !=  input.size()) {
                std::cout << "Пожалуйста, введите корректное целое число!" << '\n';
                continue;
            }
            isChecked = true;
        }
        catch (std::invalid_argument) {
            std::cout << "Пожалуйста, введите корректное целое число!" << '\n';
        }
        catch (std::out_of_range) {
            std::cout << "Введенное значение вышло за границы типа int!" << '\n';
        }
        catch (...) {
            std::cout << "Произошла непредвиденная ошибка" << '\n';
        }
    } while (!isChecked);

    return numInput;
}

double GetValidDouble() {
    double numInput = 0.0;
    bool isChecked = false;

    do {
        try {
            std::string input;
            std::cin >> input;

            size_t pos = 0;
            numInput = std::stod(input, &pos);

            if (pos != input.size()) {
                std::cout << "Пожалуйста, введите корректное дробное число!" << '\n';
                continue;
            }
            isChecked = true;
        }
        catch (std::invalid_argument) {
            std::cout << "Пожалуйста, введите корректное дробное число!" << '\n';
        }
        catch (std::out_of_range) {
            std::cout << "Введенное значение вышло за границы типа double!" << '\n';
        }
        catch (...) {
            std::cout << "Произошла непредвиденная ошибка" << '\n';
        }
    } while (!isChecked);

    return numInput;
}


int main() {
    // смена кодировки на utf-8
    system("chcp 65001");

    // setlocale(LC_ALL, "Russian"); // не работает в clion

    // Стандартно в cout выводится 6 знаков после запятой, меняем на 10для сравнения типов
    std::cout << std::fixed << std::setprecision(10);

    std::cout << "Введите число x: ";
    double numInput = GetValidDouble();

    while (numInput < -1000 || numInput > 1000) {
        std::cout << "Пожалуйста, введите число x в диапазоне [-1000, 1000], чтобы избежать переполнений: ";
        numInput = GetValidInt();
    }

    std::cout << '\n' << "Введите количество слагаемых в ряде: ";
    int cntSummand = GetValidInt();

    while (cntSummand > 2000) {
        std::cout << "Пожалуйста, введите число слагаемых в ряде, которое <= 2000, чтобы избежать переполнения стека!" << '\n';
        cntSummand = GetValidInt();
    }

    std::cout << '\n' << "Введите точность epsilon для вычисления суммы ряда с заданным epsilon:";
    double eps = GetValidDouble();

    while (eps < 0) {
        std::cout << "Пожалуйста, введите значение точности, которое больше нуля!" << '\n';
        eps = GetValidDouble();
    }

    PrintRecurrent(numInput, cntSummand);
    PrintRecursive(numInput, cntSummand);
    PrintEps(numInput, eps);
    PrintFunc(numInput);

    return 0;
}
