//------------------------------------------------------------------------------
// language.cpp - содержит процедуры связанные с обработкой языка программирования
// и создания произвольного языка
//------------------------------------------------------------------------------

#include <stdlib.h>
#include "language.h"

//------------------------------------------------------------------------------
// Ввод параметров языка программирования из файла
language* In(int k, FILE* infile) {
  language *sp;
  switch(k) {
    case 1:
      sp = new language;
      sp->k = language::PROCEDURAL;
      In(sp->p, infile);
      return sp;
    case 2:
      sp = new language;
      sp->k = language::OBJECT_ORIENTED;
      In(sp->ob, infile);
      return sp;
    case 3:
      sp = new language;
      sp->k = language::FUNCTIONAL;
      In(sp->f, infile);
      return sp;
    default:
      return 0;
  }
}

// Случайный ввод языка программирования
language *InRnd() {
  language *sp;
  auto k = rand() % 3 + 1;
  switch(k) {
    case 1:
      sp = new language;
      sp->k = language::PROCEDURAL;
      InRnd(sp->p);
      return sp;
    case 2:
      sp = new language;
      sp->k = language::OBJECT_ORIENTED;
      InRnd(sp->ob);
      return sp;
    case 3:
      sp = new language;
      sp->k = language::FUNCTIONAL;
      InRnd(sp->f);
      return sp;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего языка в файл
void Out(language &s, FILE* outfile) {
  switch(s.k) {
    case language::PROCEDURAL:
      Out(s.p, outfile);
      break;
    case language::OBJECT_ORIENTED:
      Out(s.ob, outfile);
      break;
    case language::FUNCTIONAL:
      Out(s.f, outfile);
      break;
    default:
      printf("Incorrect language!");
  }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления года создания языка на длину названия
float Quotient(language &s) {
  switch(s.k) {
    case language::PROCEDURAL:
      return Quotient(s.p);
      break;
    case language::OBJECT_ORIENTED:
      return Quotient(s.ob);
      break;
    case language::FUNCTIONAL:
      return Quotient(s.f);
      break;
    default:
      printf("Incorrect language key!");
      break;
  }
}
