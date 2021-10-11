//------------------------------------------------------------------------------
// functional.cpp - содержит процедуру ввода и вывода параметров и их обработки
// для уже созданного функционального языка
//------------------------------------------------------------------------------

#include <string.h>

#include "functional.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров функционального языка из файла
void In(functional &r, FILE *infile) {
  fscanf(infile, "%d %d %f %d", &r.k, &r.creat_year, &r.popularity_perc, &r.lazy_calculations);
  fscanf(infile, "%s", &r.name);
  switch (r.k) {
    case 1:
      r.k = r.DYNAMIC_TIPISATION;
      break;
    case 2:
      r.k = r.STATIC_TIPISATION;
      break;
    default:printf("Incorrect typing key!");
      break;
  }
}

// Случайный ввод параметров функционального языка
void InRnd(functional &r) {
  // Генерация года создания языка
  r.creat_year = RandomYear();
  // Генерация процента популярности языка
  r.popularity_perc = RandomPerc();
  // Генерация наличия "ленивых" вычислений
  r.lazy_calculations = RandomBool();
  // Генерация названия языка
  int length = rand() % 11 + 3;
  r.name[0] = 'A' + rand() % 26;
  for (int i = 1; i < length - 1; ++i) {
    r.name[i] = 'a' + rand() % 26;
  }
  r.name[length - 1] = '\0';
  // Генерация типизации языка
  int key = rand() % 2 + 1;
  switch (key) {
    case 1:
      r.k = r.DYNAMIC_TIPISATION;
      break;
    case 2:
      r.k = r.STATIC_TIPISATION;
      break;
  }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления года создания на количесвто символов в названии
float Quotient(functional &r) {
  return r.creat_year / (float) strlen(r.name);
}

//------------------------------------------------------------------------------
// Вывод параметров функционального языка в файл
void Out(functional &r, FILE *outfile) {
  fprintf(outfile, "It is functional language %s: ", r.name);
  fprintf(outfile, "the year of creation = %d", r.creat_year);
  fprintf(outfile, ", popularity percentage = %.3f", r.popularity_perc);
  fprintf(outfile, ". Quotient = %.3f \n", Quotient(r));
}
