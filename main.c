#include <stdio.h>
#include <stdlib.h>
typedef struct person {char *name; struct person *next; int age}person;
void cycle(person *l) {
  while (l != NULL) {
    printf("(%i %s)->", l->age, l->name);
    l = l->next;
  }
}
struct person *new_person(char *name, int age, struct person *next) {
  person *point = malloc(sizeof(struct person));
  point->name = strdup(name);
  point->age = age;
  point->next = next;
  return point;
}
int main(int num, char *args[]) {
  if (num != 2) {
    fprintf(stderr, "you entered %i arguments! this is improper, you need to enter 1!\n", (num -1));
    return 1;
  }
  else {
    if (fopen(*(args + 1), "r")) {
      FILE *read = fopen(*(args + 1), "r");
      char current[101];
      int age;
      person *start;
      int x = 0;
      person *last;
      while (fscanf(read, "%i %s[^\n]\n", &age, current) == 2) {
        person *currente = new_person(current, age, NULL);
        if (x == 0) {
          currente->next = NULL;
          x = 1;
        } else {
          currente->next = last;
        }
        last = currente;
      }
      fclose(read);
      person *lol = new_person("bob", 12, NULL);
      lol->next = last;
      cycle(last);
    }
    else {
      fprintf(stderr, "could not open file! maybe it does not excist!\n");
      return 1;
    }
  }
  return 0;
}
