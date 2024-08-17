#include "quadratic_equation.h"

// Функция решает квадратное уравнение
ResultQuEq solve_equation(double a, double b, double c) {
  ResultQuEq result;
  result.num_roots = 0;
  // Проверяем, является ли уравнение квадратным
  if (a == 0) {
    result.num_roots = -1;
    printf("Equation is not quadratic\n");
  } else {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
      result.num_roots = 0;
      printf("Equation has no real roots\n");
    } else if (discriminant == 0) {
      result.x1 = -b / (2 * a);
      result.num_roots = 1;
      printf("Equation has one root: %lf\n", result.x1);
    } else if (discriminant > 0) {
      result.x1 = (-b + sqrt(discriminant)) / (2 * a);
      result.x2 = (-b - sqrt(discriminant)) / (2 * a);
      result.num_roots = 2;
      printf("Equation has two roots: %lf and %lf\n", result.x1, result.x2);
    }
  }
  // Функция возвращает кол-во корней (-1 если уравнение не квадратное)
  // и возвращает значение этих корней
  return result;
}
