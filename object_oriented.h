#ifndef CSATASK1__OBJECT_ORIENTED_H_
#define CSATASK1__OBJECT_ORIENTED_H_

//------------------------------------------------------------------------------
// object_oriented.h - содержит описание объектно-ориентированного языка программирования
//------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------
// объектно-ориентированный язык
struct object_oriented {
  // виды наследования
  enum inheritance {
    SINGLE_INHERITANCE,
    MULTIPLE_INHERITANCE,
    INTERFACE_INHERITANCE
  };
  inheritance k;
  int creat_year; // год создания языка
  float popularity_perc; // процент популярности
  char name[100]; // название языка
};

// Ввод параметров объектно-ориентированного языка из файла
void In(object_oriented &t, FILE* infile);

// Случайный ввод параметров объектно-ориентированного языка
void InRnd(object_oriented &е);

// Вывод параметров объектно-ориентированного языка в файл
void Out(object_oriented &t, FILE* outfile);

// Вычисление частного от деления года создания на количество символов в названии
float Quotient(object_oriented &t);

#endif
