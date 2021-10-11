#ifndef CSATASK1__CONTAINER_H_
#define CSATASK1__CONTAINER_H_

//------------------------------------------------------------------------------
// container.h - содержит тип данных, представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "language.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
  enum {max_len = 10000}; // максимальная длина
  int len; // текущая длина
  language *cont[max_len];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного файла
void In(container &c, FILE* infile);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный файл
void Out(container &c, FILE* outfile);

// Сортировка по убыванию для частного от деления года создания
// на количество символов в названии и "слияние" двух массивов
void Merge(container *c, int first, int last);

// Функция рекурсивной сортировки
void MergeSort(container *c, int first, int last);

#endif