/**
 * CS5600 - Computer Systems, Project 0
 *
 * caesar.c
 * 
 * Caesar cipher implementation with encryption and decryption of user input. 
 *
 * Author - Satish Kumar Anbalagan
 * Date - Sept 17, 2020
 * Email ID - anbalagan.s@northeastern.edu
 */

#include <stdio.h>
#include <stdlib.h>

// Function declarations

/**
 * Encrypts the input string with the given key.
 * @param plaintext: input string constant character pointer
 * @param key: key used to encrypt in integer
 */
void encode(const char *plaintext, int key);

/**
 * Decrypts the input string with the given key.
 * @param plaintext: input string constant character pointer
 * @param key: key used to decrypt in integer
 */
void decode(const char *plaintext, int key);

/**
 * Helper function to get user input key.
 * @param pKey: integer pointer to key
 */
void getKey(int *pKey);

/**
 * Helper function to get user input string.
 * @param pInput: character pointer to user input
 */
void getUserInput(char *pInput);

// Function definitions

void encode(const char *plaintext, int key)
{
    char temp;
    char *pInput = (char*) plaintext;

    if (pInput == NULL) {
        perror("\nERROR : Encode input NULL\n");
        exit(-1);
    }

    printf("\nEncode input string : %s\n", pInput);

    for (int i = 0; pInput[i] != '\0'; i++) {
        temp = pInput[i];
        if (temp >= 'a' && temp <= 'z') {
            temp = temp + key;
            if (temp > 'z') {
                temp = temp - 'z' + 'a' - 1;
            }
            pInput[i] = temp - 32; // to upper case
        }
        else if (temp >= 'A' && temp <= 'Z') {
            temp = temp + key;
            if (temp > 'Z') {
                temp = temp - 'Z' + 'A' - 1;
            }
            pInput[i] = temp;
        }
    }
    printf("\nEncrypted Message: %s\n", plaintext);
}

void decode(const char *plaintext, int key)
{
    char temp;
    char *pInput = (char*) plaintext;

    if (pInput == NULL) {
        perror("\nERROR : Decode input NULL\n");
        exit(-1);
    }

    printf("\nDecode input string : %s\n", pInput);
    for (int i = 0; pInput[i] != '\0'; i++) {
        temp = pInput[i];
        if (temp >= 'a' && temp <= 'z') {
            temp = temp - key;
            if (temp < 'a') {
                temp = temp + 'z' - 'a' + 1;
            }
            pInput[i] = temp - 32; // to upper case
        }
        else if (temp >= 'A' && temp <= 'Z') {
            temp = temp - key;
            if (temp < 'A') {
                temp = temp + 'Z' - 'A' + 1;
            }
            pInput[i] = temp;
        }
    }
    printf("\nDecrypted Message: %s\n", plaintext);
}

void getKey(int *pKey)
{
    printf("\nEnter key: ");
    scanf("%d", pKey);
    if (*pKey < 0 || *pKey > 25) {
        perror("\nERROR : Key must be within 0-25.\n");
        exit(-1);
    }
}

void getUserInput(char *pInput)
{
    int c;
    int i = 0;
    printf("\nEnter the message: ");

    // Read input characters until EOF and newline character is found.
    while ((c = getchar()) != '\n' && c != EOF) {
        pInput[i++] = c;
        pInput = realloc(pInput, i+1);
    }
    pInput[i] = '\0';  //NULL terminate string
}

int main(void)
{
    char *input = malloc(sizeof(*input));
    if (input == NULL) {
        perror("\nERROR : Memory not initialized\n");
        exit(-1);
    }
    int key;

    getUserInput(input);
    getKey(&key);

    encode(input, key);
    decode(input, key);

    printf("\n");

    free(input);
    return 0;
}
