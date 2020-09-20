/*
* CS5600 - Computer Systems, Project 0
*
* caesar.c
*
* Author - Satish Kumar Anbalagan
* NUID - 001351994
* Email ID - anbalagan.s@northeastern.edu
*/

#include <stdio.h>
#include <stdlib.h>

int encode(const char *plaintext, int key);
int decode(const char *plaintext, int key);

int encode(const char *plaintext, int key) {
  int ret = -1;
  printf("\nEncode input string : %s\n", plaintext);

  return ret;    
}

int decode(const char *plaintext, int key) {
  int ret = -1;
  printf("\nDecode input string : %s\n", plaintext);

  return ret;    
}

void getKey(int *pKey) {
  printf("\nEnter key: ");
  scanf("%d", pKey);
}

void getMessage(char *pInput) {
  int c;
  int i = 0;
  printf("\nEnter the message: ");

  // Read input characters until EOF and newline character is found.
  while((c = getchar()) != '\n' && c != EOF) {
    pInput[i++] = c;
    pInput = realloc(pInput, i+1);
  }
  pInput[i] = '\0';  //NULL terminate string
}

int main(void) {
  char *input = malloc(sizeof(*input));
  if(input == NULL) {
    perror("\nMemory not initialized\n");
    exit(-1);
  }
  int key;
  int choice;
  getMessage(input);
  getKey(&key);
  printf("Entered string: %s\n", input);
  printf("Entered key: %d\n", key);

  while(1) {
    printf("\n1. Encrytion\n2. Decryption\n3. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        encode(input, key);
        break;
      case 2:
        decode(input, key);
        break;
      case 3:
        exit(0);
        break;
      default:
        printf("\nPlease enter correct option.\n");
        break;
    }
  }
  free(input);
  printf("\n");

  return 0;

}
