#ifndef CSATASK1__LANGUAGE_H_
#define CSATASK1__LANGUAGE_H_

//------------------------------------------------------------------------------
// language.h - содержит описание языка программирования как обобщенного артефакта
//------------------------------------------------------------------------------

#include <stdio.h>

#include "functional.h"
#include "procedural.h"
#include "object_oriented.h"

struct language {
  enum key {
    PROCEDURAL,
    OBJECT_ORIENTED,
    FUNCTIONAL
  };
  key k;
  union {
    procedural p;
    object_oriented ob;
    functional f;
  };
};

// Ввод языка программирования
language *In(int s, FILE* infile);

// Случайный ввод языка программирования
language *InRnd();

// Вывод языка программирования в файл
void Out(language &s, FILE* outfile);

// Вычисление частного от деления года создания на количество символов в названии
float Quotient(language &t);

#endif
