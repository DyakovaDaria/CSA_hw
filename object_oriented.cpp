//------------------------------------------------------------------------------
// object_oriented.cpp - содержит процедуру ввода и вывода параметров и их обработки
// для уже созданного объектно-ориентированного языка
//------------------------------------------------------------------------------

#include <string.h>

#include "object_oriented.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров объектно-ориентированного языка из файла
void In(object_oriented &r, FILE *infile) {
  fscanf(infile, "%d %d %f", &r.k, &r.creat_year, &r.popularity_perc);
  fscanf(infile, "%s", &r.name);
  switch (r.k) {
    case 1:
      r.k = r.SINGLE_INHERITANCE;
      break;
    case 2:
      r.k = r.MULTIPLE_INHERITANCE;
      break;
    case 3:
      r.k = r.INTERFACE_INHERITANCE;
      break;
    default:
      printf("Incorrect inheritance key!");
      break;
  }
}

// Случайный ввод параметров объектно-ориентированного языка
void InRnd(object_oriented &r) {
  // Генерация года создания языка
  r.creat_year = RandomYear();
  // Генерация процента популярности языка
  r.popularity_perc = RandomPerc();
  // Генерация названия языка
  int length = rand() % 11 + 3;
  r.name[0] = 'A' + rand() % 26;
  for (int i = 1; i < length - 1; ++i) {
    r.name[i] = 'a' + rand() % 26;
  }
  r.name[length - 1] = '\0';
  // Генерация вида наследования в языке
  int key = rand() % 3 + 1;
  switch (key) {
    case 1:
      r.k = r.SINGLE_INHERITANCE;
      break;
    case 2:
      r.k = r.MULTIPLE_INHERITANCE;
      break;
    case 3:
      r.k = r.INTERFACE_INHERITANCE;
      break;
  }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления года создания на количесвто символов в названии
float Quotient(object_oriented &r) {
  return r.creat_year / (float) strlen(r.name);
}

//------------------------------------------------------------------------------
// Вывод параметров объектно-ориентированного языка в файл
void Out(object_oriented &r, FILE *outfile) {
  fprintf(outfile, "It is object-oriented language %s: ", r.name);
  fprintf(outfile, "the year of creation = %d", r.creat_year);
  fprintf(outfile, ", popularity percentage = %.3f", r.popularity_perc);
  fprintf(outfile, ". Quotient = %.3f \n", Quotient(r));
}
