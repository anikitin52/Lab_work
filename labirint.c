#include "stdlib.h"
#include <stdio.h>
#include <time.h>

int n = 25, m = 25;

void print_labirint(int array[n][m]);
void go(int array[n][m], int x, int y, int indicator);

int main() {
  printf("Добро пожаловать в игру Лабиринт \n Инструкция: \nВаша задача - "
     "пройти лабиринт, собирая монеты. Вы можете ходить только прямо, вправо, влево и "
     "назад \nКоманды: \n2 - шаг вперед \n8 - шаг назад \n4 - шаг влево "
     "\n6 - шаг право \nУдачной игры!\n");
  
  int labirint[25][25] = {
      {2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
      {2, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 2},
      {2, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 0, 1, 1, 0, 2},
      {2, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 2},
      {2, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 2},
      {2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 2},
      {2, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 2},
      {2, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 2},
      {2, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 2},
      {2, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 2},
      {2, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 4, 0, 0, 2},
      {2, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2},
      {2, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
      {2, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 2},
      {2, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 2},
      {2, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 4, 0, 1, 1, 1, 1, 2},
      {2, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 2},
      {2, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 2},
      {2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 2},
      {2, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 2},
      {2, 4, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 2},
      {2, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
      {2, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
      {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2}
  };


  
  print_labirint(labirint);
  int x = 0, y = 1;
  int indicator;
  while (x != n - 1 && y != m) {
    printf("\n");
    printf("Ваш ход:");
    scanf("%d", &indicator);
    go(labirint, x, y, indicator);
    if (indicator == 2) {
      x++;
    } else if (indicator == 8) {
      x--;
    } else if (indicator == 6) {
      y++;
    } else if (indicator == 4) {
      y--;
    } else {
      printf("Неверный ход");
    }
  }
  printf("\n");
  printf("Поздравляю, вы прошли лабиринт!");

  return 0;
}

void print_labirint(int array[n][m]) { // печать лабиринта
  for (int i = 0; i < n; i++) {
    printf("\n");
    for (int j = 0; j < m; j++) {
      if (array[i][j] == 2) {
        printf("🟩");
      } else if (array[i][j] == 0) {
        printf("⛔");
      } else if (array[i][j] == 3) {
        printf("🧍");
      } else if (array[i][j] == 4) {
        printf("🪙 ");
      }
      else {
        printf("  ");
      }
    }
  }
}

void go(int array[n][m], int x, int y, int indicator) {
  if (indicator == 2) {
    if (array[x + 1][y] == 1) {
      system("clear");
      array[x + 1][y] = 3;
      array[x][y] = 1;
      print_labirint(array);
      return;
    } else {
      printf("Неверный ход");
    }

  } else if (indicator == 8) {
    if (array[x - 1][y] == 1) {
      system("clear");
      array[x - 1][y] = 3;
      array[x][y] = 1;
      print_labirint(array);
      return;
    } else {
      printf("Неверный ход");
    }
  } else if (indicator == 6) {
    if (array[x][y + 1] == 1) {
      system("clear");
      array[x][y + 1] = 3;
      array[x][y] = 1;
      print_labirint(array);
      return;
    } else {
      printf("Неверный ход");
    }
  } else if (indicator == 4) {
    if (array[x][y - 1] == 1) {
      system("clear");
      array[x][y - 1] = 3;
      array[x][y] = 1;
      print_labirint(array);
      return;
    }
  }

  else {
    printf("Неверный ход");
  }
}
