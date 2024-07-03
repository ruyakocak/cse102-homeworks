#include <stdio.h>
#include "customDict.h"
int main() {
    struct CustomDict* dictionary = create_dict();
    const char* file = "data.csv";
    if (read_csv(dictionary, file)) {
        printf("CSV data loaded successfully.\n");
    } else {
        printf("Failed to load CSV data.\n");
        return 0;
    }
    
    int choice, n, i, flag=0;
    char type[15], key[15];
    union Value* val = NULL;
    printf("MENU:\n");
    printf("1. Add item\n2. Delete item\n3. Set Value\n4. Search item\n5. Sort Dict\n6. Print current dictionary\n7. Free memory\n8. Exit\n");
    
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                strcpy(type, "char");
                strcpy(key, " ruya");
                val=malloc(sizeof(union Value)*3);
                val[0].char_value = strdup("R");
                val[1].char_value = strdup("Y");
                val[2].char_value = strdup("A");
                n = 3;
                add_item(dictionary, key, val, n, type);
                free(val);
                print_dict(dictionary);
                break;
            
            case 2: 
                strcpy(key, " age");
                delete_item(dictionary, key);
                print_dict(dictionary);
                break;

            case 3: 
                strcpy(key, " height");
                val=malloc(sizeof(union Value)*3);
                val[0].float_value = 22.2;
                val[1].float_value = 33.3;
                val[2].float_value = 44.4;
                n = 3;
                set_value(dictionary, key, val, n);
                free(val);
                print_dict(dictionary);
                break;

            case 4: 
                strcpy(key, " weight");
                {
                    val = search_item(dictionary, key, &n);
                    if (n) {
                        printf("\nItem found.\n");
                        printf("Key: %s -- ", key);
                        for (i = 0; i < n; i++) {
                            printf("%.2lf ",val[i].double_value);
                        }
                        printf("\n");
                    } else {
                        printf("Item not found.\n");
                    }
                    
                }
                break;

            case 5: 
                sort_dict(dictionary);
                printf("\nDictionary sorted.\n");
                print_dict(dictionary);
                break;

            case 6: 
                print_dict(dictionary);
                break;

            case 7:
                free_dict(dictionary);
                flag=1;
                printf("\nMemory deallocated.\n");
                break;

            default: 
                if (choice != 8) {
                    printf("Invalid choice. Enter a number between 1-8.\n");
                }
                break;
        }
        
    } while(choice != 8);

    if(!flag){
        free_dict(dictionary);
        printf("\nMemory deallocated and exiting...\n");
    }
    else{
        printf("\nExiting...\n");

    }

    return 0;
}
