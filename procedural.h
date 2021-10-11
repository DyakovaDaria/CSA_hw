#ifndef CSATASK1__PROCEDURAL_H_
#define CSATASK1__PROCEDURAL_H_

//------------------------------------------------------------------------------
// procedural.h - содержит описание процедурного языка программирования
//------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------
// процедурный язык
struct procedural {
  bool abstract_data_types; // наличие или отсутствие абстрактных типов данных
  int creat_year; // год создания языка
  float popularity_perc; // процент популярности
  char name[100]; // название языка
};

// Ввод параметров процедурного языка из файла
void In(procedural &t, FILE* infile);

// Случайный ввод параметров процедурного языка
void InRnd(procedural &е);

// Вывод параметров процедурного языка в файл
void Out(procedural &t, FILE* outfile);

// Вычисление частного от деления года создания на количество символов в названии
float Quotient(procedural &t);

#endif
