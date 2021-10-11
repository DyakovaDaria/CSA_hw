//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
  c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов
void Clear(container &c) {
  c.len = 0;
  delete[] *c.cont;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного файла
void In(container &c, FILE *infile) {
  int l;
  while (fscanf(infile, "%d", &l) != EOF) {
    if ((c.cont[c.len] = In(l, infile)) != 0) {
      c.len++;
    }
  }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
  while (c.len < size) {
    if ((c.cont[c.len] = InRnd()) != nullptr) {
      c.len++;
    }
  }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный файл
void Out(container &c, FILE *outfile) {
  fprintf(outfile, "Container contains %d elements.\n", c.len);
  for (int i = 0; i < c.len; i++) {
    fprintf(outfile, "%d: ", i + 1);
    Out(*(c.cont[i]), outfile);
  }
}

//------------------------------------------------------------------------------
// Сортировка по убыванию методом слияния

// Метод для "слияния" двух массивов
// first - левый индекс, last - правый индекс подмассивов
void Merge(container *c, int first, int last) {
  int middle;
  int start;
  int final;
  int j;
  container *mas = new container[100];
  middle = (first + last) / 2; // Вычисление среднего элемента
  start = first; // Начало левой части
  final = middle + 1; // Начало правой части
  for (j = first; j <= last; j++) // Выполнять от начала до конца
    if ((start <= middle) && ((final > last) || (Quotient(*c->cont[start]) > Quotient(*c->cont[final])))) {
      mas->cont[j] = c->cont[start];
      start++;
    } else {
      mas->cont[j] = c->cont[final];
      final++;
    }
  // Возвращение результата в список
  for (j = first; j <= last; j++) {
    c->cont[j] = mas->cont[j];
  }
  delete[] mas;
}

// Рекурсивная функция сортировки
void MergeSort(container *c, int first, int last) {
  {
    if (first < last) {
      MergeSort(c, first, (first + last) / 2); // Сортировка левой части
      MergeSort(c, (first + last) / 2 + 1, last); // Сортировка правой части
      Merge(c, first, last); // Слияние двух частей
    }
  }
}
