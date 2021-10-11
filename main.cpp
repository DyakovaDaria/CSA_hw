//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>

#include "container.h"

void errMessage1() {
  printf("incorrect command line!\n"
         "  Waited:\n"
         "     command -f infile outfile01 outfile02\n"
         "  Or:\n"
         "     command -n number outfile01 outfile02\n");
}

void errMessage2(int size) {
  printf("incorrect number of languages = %d."
         "Set 0 < number <= 10000\n", size);
}

void errMessage3() {
  printf("incorrect qualifier value!\n"
         "  Waited:\n"
         "     command -f infile outfile01 outfile02\n"
         "  Or:\n"
         "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  if (argc != 5) {
    errMessage1();
    return 1;
  }
  printf("Start\n");
  container c;
  Init(c);
  if (!strcmp(argv[1], "-f")) {
    FILE* infile = fopen(argv[2], "r");
    In(c, infile);
  }
  else if (!strcmp(argv[1], "-n")) {
    int size = atoi(argv[2]);
    if ((size < 1) || (size > 10000)) {
      errMessage2(size);
      return 3;
    }
    // Системные часы в качестве инициализатора
    srand(static_cast<unsigned int>(time(0)));
    // Заполнение контейнера генератором случайных чисел
    InRnd(c, size);
  }
  else {
    errMessage3();
    return 2;
  }
  // Вывод содержимого контейнера в файл
  FILE* outfile1 = fopen(argv[3], "w");
  fprintf(outfile1, "Filled container:\n");
  Out(c, outfile1);
  // Вторая часть задания
  FILE* outfile2 = fopen(argv[4], "w");
  fprintf(outfile2, "Conditionally refilled container:\n");
  MergeSort(&c, 0, c.len - 1);
  Out(c, outfile2);
  Clear(c);
  printf("Stop \n");
  return 0;
}
