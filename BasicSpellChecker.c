#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_LENGTH 20

//Note:

// This program uses a simple array-based dictionary.
// Structure to store words
typedef struct {
    char words[MAX_WORDS][MAX_LENGTH];
    int count;
} Dictionary;

// Function to add word to dictionary
void add_word(Dictionary *dict, char *word) {
    if (dict->count < MAX_WORDS) {
        strcpy(dict->words[dict->count], word);
        dict->count++;
    } else {
        printf("Dictionary full. Cannot add more words.\n");
    }
}

// Function to delete word from dictionary
void delete_word(Dictionary *dict, char *word) {
    int i;
    for (i = 0; i < dict->count; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            // Shift words to fill gap
            for (int j = i; j < dict->count - 1; j++) {
                strcpy(dict->words[j], dict->words[j + 1]);
            }
            dict->count--;
            break;
        }
    }
}

// Function to search word in dictionary
bool search_word(Dictionary *dict, char *word) {
    for (int i = 0; i < dict->count; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            return true;
        }
    }
    return false;
}

// Function to display dictionary
void display_dict(Dictionary *dict) {
    printf("Dictionary:\n");
    for (int i = 0; i < dict->count; i++) {
        printf("%s\n", dict->words[i]);
    }
}

int main() {
    Dictionary dict;
    dict.count = 0;

    // Add words to dictionary
    add_word(&dict, "Downtown");
    add_word(&dict, "University");
    add_word(&dict, "School");
    add_word(&dict, "Apple");
    add_word(&dict, "Banana");
    add_word(&dict, "Orange");
    add_word(&dict, "Pear");
    add_word(&dict, "Black");
    add_word(&dict, "White");
    add_word(&dict, "Yellow");
    add_word(&dict, "Green");
    add_word(&dict, "Compiler");
    add_word(&dict, "Program");
    add_word(&dict, "Spell");
    add_word(&dict, "Check");






    // Display dictionary
    display_dict(&dict);

    // Search for word
    char word[20];
    printf("Enter word to search: ");
    scanf("%s", word);
    if (search_word(&dict, word)) {
        printf("%s found in dictionary.\n", word);
    } else {
        printf("%s not found in dictionary.\n", word);
    }

    // Delete word
    delete_word(&dict, "banana");
    display_dict(&dict);

    return 0;
}




