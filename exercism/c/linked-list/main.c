#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ____t;

int main(int argc, char **argv) {
  ____t status = 0;
  wait(10);
  while (1) {
    printf("Try To Do Your Best\n");
    status = (rand() % 10);
    switch (status) {
    case (0):
      printf("Don't Be Sad, Try Again\n");
      break;
    case (1):
      printf("Don't Be Happy, Keep Pushing\n");
      break;
    case (2):
      printf("Life is useless, don't give it attention.\n");
      break;
    case (3):
      printf("Today is your last day.\n");
      break;
    case (4):
      printf("Whatever Happens, Happens.\n");
      break;
    case (5):
      printf("May God be with you.\n");
      break;
    case (6):
      printf("Endure The Pain\n");
      break;
    case (7):
      printf("You Will Get there\n");
      break;
    case (8):
      printf("Everything Shall End Except God.\n");
      break;
    default:
      printf("Patience\n");
      break;
    }
  }
  return (EXIT_SUCCESS);
}
