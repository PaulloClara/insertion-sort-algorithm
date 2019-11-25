#include "stdio.h"
#include "stdlib.h"

int error(const char *error_msg) {
  printf("\n\t\033[1;93m%s\033[0;0m\n\n", error_msg);
  return 1;
}

void load(const char *input_array[], int *array, size_t array_size) {
  array[array_size - 1] = atoi(input_array[array_size]);

  if (array_size == 1) return;
  load(input_array, array, --array_size);
}

void show(const int *array, const size_t array_size, size_t i) {
  printf("%d, ", array[i++]);

  if (i >= array_size) return;
  show(array, array_size, i);
}

void sort(int *array, const int value, int j) {
  if (j < 0 || value >= array[j]) array[j + 1] = value;
  else {
    printf("%d ", j);
    array[j + 1] = array[j];

    sort(array, value, --j);
  }
}

void insertion_sort(int *array, const size_t array_size, int i) {
  if (i >= array_size) return;
  printf("\ni%d: ", i);

  sort(array, array[i], i - 1);

  printf("\n\n\t[");
  show(array, array_size, 0);
  printf("\b\b]\n\n");

  insertion_sort(array, array_size, ++i);
}

int main(const int argc, const char *argv[]) {
  if (argc < 3) return error("Array not found!");

  const size_t array_size = argc - 1;
  int array[array_size];

  load(argv, array, array_size);

  insertion_sort(array, array_size, 1);

  return 0;
}
