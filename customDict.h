#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Value {
    int int_value;
    float float_value;
    double double_value;
    char* char_value;
};

struct Item {
    char *key;
    union Value *values;
    int n; 
    char type[10]; 
};

struct CustomDict {
    struct Item *items;
    int currentsize;
    int capacity;
};

struct CustomDict* create_dict() {
    struct CustomDict* dictionary = (struct CustomDict*)malloc(sizeof(struct CustomDict));
    dictionary->capacity = 0; 
    dictionary->currentsize = 0;
    dictionary->items = (struct Item*)malloc(sizeof(struct Item) * dictionary->capacity);
    return dictionary;
}

void add_item(struct CustomDict* dict, char* key, union Value* values, int n, char* type) {
    if (dict->currentsize >= dict->capacity) {
        dict->capacity += 2;
        struct Item* tempItems = (struct Item*)realloc(dict->items, sizeof(struct Item) * dict->capacity);
        if (tempItems == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        dict->items = tempItems;
    }
    int i,j;
    for (i = 0; i < dict->currentsize; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            for (j = 0; j < dict->items[i].n; j++) {
                if (strcmp(dict->items[i].type, "char") == 0) {
                    free(dict->items[i].values[j].char_value);
                }
            }
            free(dict->items[i].values);
            dict->items[i].values = (union Value*)malloc(sizeof(union Value) * n);
            for (j = 0; j < n; j++) {
                if (strcmp(type, "int") == 0) {
                    dict->items[i].values[j].int_value = values[j].int_value;
                } else if (strcmp(type, "double") == 0) {
                    dict->items[i].values[j].double_value = values[j].double_value;
                } else if (strcmp(type, "float") == 0) {
                    dict->items[i].values[j].float_value = values[j].float_value;
                } else if (strcmp(type, "char") == 0) {
                    dict->items[i].values[j].char_value = strdup(values[j].char_value);
                }
            }
            dict->items[i].n = n;
            strcpy(dict->items[i].type, type);
            return;
        }
    }

    dict->items[dict->currentsize].key = strdup(key);
    dict->items[dict->currentsize].values = (union Value*)malloc(sizeof(union Value) * n);
    for (i = 0; i < n; i++) {
        if (strcmp(type, "int") == 0) {
            dict->items[dict->currentsize].values[i].int_value = values[i].int_value;
        } else if (strcmp(type, "double") == 0) {
            dict->items[dict->currentsize].values[i].double_value = values[i].double_value;
        } else if (strcmp(type, "float") == 0) {
            dict->items[dict->currentsize].values[i].float_value = values[i].float_value;
        } else if (strcmp(type, "char") == 0) {
            dict->items[dict->currentsize].values[i].char_value = strdup(values[i].char_value);
        }
    }
    dict->items[dict->currentsize].n = n;
    strcpy(dict->items[dict->currentsize].type, type);
    dict->currentsize++;
}

void delete_item(struct CustomDict* dict, char* key) {
    int i,j,flag = 0;
    for (i = 0; i < dict->currentsize; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            for (j = 0; j < dict->items[i].n; j++) {
                if (strcmp(dict->items[i].type, "char") == 0) {
                    free(dict->items[i].values[j].char_value);
                }
            }
            free(dict->items[i].values);
            free(dict->items[i].key);
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("\nItem deleted.\n");
        for (i; i < dict->currentsize - 1; i++) {
            dict->items[i] = dict->items[i + 1];
        }
        dict->currentsize--;
    } else {
        printf("\nItem not found.\n");
    }
}

void set_value(struct CustomDict* dict, char* key, union Value* value, int n) {
    int i,j;
    for (i = 0; i < dict->currentsize; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            for (j = 0; j < dict->items[i].n; j++) {
                if (strcmp(dict->items[i].type, "char") == 0) {
                    free(dict->items[i].values[j].char_value);
                }
            }
            dict->items[i].values = realloc(dict->items[i].values, n * sizeof(union Value));
            if (dict->items[i].values == NULL) {
                printf("Memory allocation failed\n");
                return;
            }
            for (j = 0; j < n; j++) {
                if (strcmp(dict->items[i].type, "int") == 0) {
                    dict->items[i].values[j].int_value = value[j].int_value;
                } else if (strcmp(dict->items[i].type, "double") == 0) {
                    dict->items[i].values[j].double_value = value[j].double_value;
                } else if (strcmp(dict->items[i].type, "float") == 0) {
                    dict->items[i].values[j].float_value = value[j].float_value;
                } else if (strcmp(dict->items[i].type, "char") == 0) {
                    dict->items[i].values[j].char_value = strdup(value[j].char_value);
                }
            }
            dict->items[i].n = n;
            return;
        }
    }
}

union Value* search_item(struct CustomDict* dict, char* key, int* n) {
    int i;
    for (i = 0; i < dict->currentsize; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            *n = dict->items[i].n;
            return dict->items[i].values;
        }
    }
    *n = 0;
    return NULL;
}

void print_dict(struct CustomDict* dictionary) {
    int i,j;
    for (i = 0; i < dictionary->currentsize; i++) {
        printf("Key: %s -- ", dictionary->items[i].key);
        if (strcmp(dictionary->items[i].type, "int") == 0) {
            printf("Values: ");
            for (j = 0; j < dictionary->items[i].n; j++) {
                printf("%d ", dictionary->items[i].values[j].int_value);
            }
            printf("\n\n");
        } else if (strcmp(dictionary->items[i].type, "double") == 0) {
            printf("Values: ");
            for (j = 0; j < dictionary->items[i].n; j++) {
                printf("%.2lf ", dictionary->items[i].values[j].double_value);
            }
            printf("\n\n");
        } else if (strcmp(dictionary->items[i].type, "float") == 0) {
            printf("Values: ");
            for (j = 0; j < dictionary->items[i].n; j++) {
                printf("%.2f ", dictionary->items[i].values[j].float_value);
            }
            printf("\n\n");
        } else if (strcmp(dictionary->items[i].type, "char") == 0) {
            printf("Values: ");
            for (j = 0; j < dictionary->items[i].n; j++) {
                printf("%s ", dictionary->items[i].values[j].char_value);
            }
            printf("\n");
        }
    }
}

void free_dict(struct CustomDict* dict) {
    int i,j;
    for (i = 0; i < dict->currentsize; i++) {
        for (j = 0; j < dict->items[i].n; j++) {
            if (strcmp(dict->items[i].type, "char") == 0) {
                free(dict->items[i].values[j].char_value);
            }
        }
        free(dict->items[i].values);
        free(dict->items[i].key);
    }
    free(dict->items);
    free(dict);
}

void sort_dict(struct CustomDict* dict) {
    int i,j;
    for (i = 0; i < dict->currentsize - 1; i++) {
        for (j = 0; j < dict->currentsize - i - 1; j++) {
            if (strcmp(dict->items[j].key, dict->items[j + 1].key) > 0) {
                struct Item temp = dict->items[j];
                dict->items[j] = dict->items[j + 1];
                dict->items[j + 1] = temp;
            }
        }
    }
}

int read_csv(struct CustomDict* dict, const char* filename) {
    char key[50], type[50], tempbig[256];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File opening error.\n");
        return 0;
    }

    while (fgets(tempbig, sizeof(tempbig), file) != NULL) {
        char *token;
        union Value *values = malloc(sizeof(union Value) * 1000);
        int n = 0;

        token = strtok(tempbig, ",");
        strcpy(type, token);

        token = strtok(NULL, ",");
        strcpy(key, token);

        token = strtok(NULL, ",");
        while (token != NULL) {
            if (strcmp(type, "int") == 0) {
                values[n].int_value = atoi(token);
            } else if (strcmp(type, "double") == 0) {
                values[n].double_value = atof(token);
            } else if (strcmp(type, "float") == 0) {
                values[n].float_value = atof(token);
            } else if (strcmp(type, "char") == 0) {
                values[n].char_value = strdup(token);
            }
            n++;
            token = strtok(NULL, ",");
        }

        add_item(dict, key, values, n, type);
        free(values);
    }

    fclose(file);
    return 1;
}
