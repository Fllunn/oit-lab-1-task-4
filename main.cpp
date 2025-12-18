#include "iostream"
#include "cmath"
#include "iomanip"
#include <limits>


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


double CalculateEpsilonDouble(double x, double eps) {
    double sum = 0.0;
    int i = 0;
    double summand = 1.0;

    while (std::abs(summand) >= eps) {
        sum += summand;
        summand *= ((i + 1.0) * (i + 1.0) + 1.0) / ((i + 1.0) * (i * i + 1.0)) * (x / 2.0);
        i++;
    }
    return sum;
}

float CalculateEpsilonFloat(float x, float eps) {
    float sum = 0.0f;
    int i = 0;
    float summand = 1.0f;

    while (std::abs(summand) >= eps) {
        sum += summand;
        summand *= ((i + 1.0f) * (i + 1.0f) + 1.0f) / ((i + 1.0f) * (i * i + 1.0f)) * (x / 2.0f);
        i++;
    }
    return sum;
}


double CalculateMinEpsilonDouble(double x) {
    double eps = std::numeric_limits<double>::min();

    double sum = 0.0;
    int i = 0;
    double summand = 1.0;

    while (std::abs(summand) >= eps) {
        sum += summand;
        summand *= ((i + 1.0) * (i + 1.0) + 1.0) / ((i + 1.0) * (i * i + 1.0)) * (x / 2.0);
        i++;
    }
    return sum;
}

float CalculateMinEpsilonFloat(float x) {
    float eps = std::numeric_limits<float>::min();

    float sum = 0.0f;
    int i = 0;
    float summand = 1.0f;

    while (std::abs(summand) >= eps) {
        sum += summand;
        summand *= ((i + 1.0f) * (i + 1.0f) + 1.0f) / ((i + 1.0f) * (i * i + 1.0f)) * (x / 2.0f);
        i++;
    }
    return sum;
}


float CalculateFunctionFloat(float x) {
    return ((x * x) / 4.0f + x / 2.0f + 1.0f) * std::exp(x / 2.0f);
}

double CalculateFunctionDouble(double x) {
    return ((x * x) / 4.0 + x / 2.0 + 1.0) * std::exp(x / 2.0);
}


int main() {
    int n = 5;
    float x = 1.0f;
    double doubleX = 1.0;
    float eps = 0.00000001f;

    // Стандартно в cout выводится 6 знаков после запятой, меняем на 15 для сравнения типов
    std::cout << std::fixed << std::setprecision(15);
    // Передаем в рекурсию (n - 1) чтобы посчиталась сумма ряда, где n слагаемых
    std::cout << "Recursive " << CalculateRecursiveFloat(n - 1, x) << '\n';
    std::cout << "Reccurrent " << CalculateReccurrentFloat(n, x) << '\n';
    std::cout << "Eps " << CalculateEpsilonFloat(x, eps) << '\n';
    std::cout << "Func float " << CalculateFunctionFloat(x) << '\n';
    std::cout << "Func double " << CalculateFunctionDouble(x) << '\n';
    std::cout << "Eps float min " << CalculateMinEpsilonFloat(x) << '\n';
    std::cout << "Eps double min " << CalculateMinEpsilonDouble(x) << '\n';
    return 0;
}
