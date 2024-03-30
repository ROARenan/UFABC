//Renan Santana RA11202131332

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_data() {
  char *temp = malloc(30);

  strcpy(temp, "Confidential details");
  printf("Stage 1: %s\n", temp);

  return temp;
}

void process_data(char *data) {
  int size = strlen(data) + 1;
  char *buffer = malloc(size);

  strcpy(buffer, data);
  printf("Stage 2: %s (copied)\n", buffer);
  //free(data); 

  int *progress = malloc(10 * sizeof(int));

  for (int i = 0; i < 10; i++) {
    progress[i] = i;
  }
  printf("Progress: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", progress[i]);
  }
  printf("\n");
  free(buffer);
  free(progress);
}

void perform_task(char *data) {
  process_data(data);
  printf("Stage 3: %s (using data)\n", data);
  free(data);
}

int main() {
  perform_task(get_data());

  return 0;
}
