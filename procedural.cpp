//------------------------------------------------------------------------------
// procedural.cpp - содержит процедуру ввода и вывода параметров и их обработки
// для уже созданного процедурного языка
//------------------------------------------------------------------------------

#include <string.h>

#include "procedural.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров процедурного языка из файла
void In(procedural &r, FILE *infile) {
  fscanf(infile, "%d %f %d", &r.creat_year, &r.popularity_perc, &r.abstract_data_types);
  fscanf(infile, "%s", &r.name);
}

// Случайный ввод параметров процедурного языка
void InRnd(procedural &r) {
  // Генерация года создания языка
  r.creat_year = RandomYear();
  // Генерация процента популярности языка
  r.popularity_perc = RandomPerc();
  // Генерация наличия абстрактных типов данных в языке
  r.abstract_data_types = RandomBool();
  // Генерация названия языка
  int length = rand() % 11 + 3;
  r.name[0] = 'A' + rand() % 26;
  for (int i = 1; i < length - 1; ++i) {
    r.name[i] = 'a' + rand() % 26;
  }
  r.name[length - 1] = '\0';
}

//------------------------------------------------------------------------------
// Вычисление частного от деления года создания на количесвто символов в названии
float Quotient(procedural &r) {
  return r.creat_year / (float) strlen(r.name);
}

//------------------------------------------------------------------------------
// Вывод параметров процедурного языка в файл
void Out(procedural &r, FILE *outfile) {
  fprintf(outfile, "It is procedural language %s: ", r.name);
  fprintf(outfile, "the year of creation = %d", r.creat_year);
  fprintf(outfile, ", popularity percentage = %.3f", r.popularity_perc);
  fprintf(outfile, ". Quotient = %.3f \n", Quotient(r));
}
