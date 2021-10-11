#ifndef CSATASK1__FUNCTIONAL_H_
#define CSATASK1__FUNCTIONAL_H_

//------------------------------------------------------------------------------
// functional.h - содержит описание функционального языка программирования
//------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------
// функциональный язык
struct functional {
  enum tipisation {
    STATIC_TIPISATION,
    DYNAMIC_TIPISATION
  };
  tipisation k;
  bool lazy_calculations; // наличие "ленивых" вычислений
  int creat_year; // год создания языка
  float popularity_perc; // процент популярности
  char name[100]; // название языка
};

// Ввод параметров функционального языка из файла
void In(functional &t, FILE* infile);

// Случайный ввод параметров функционального языка
void InRnd(functional &е);

// Вывод параметров функционального языка в файл
void Out(functional &t, FILE* outfile);

// Вычисление частного от деления года создания на количество символов в названии
float Quotient(functional &f);

#endif
