#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "queue.h"

void remove_newline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    t_queue* p_queue = create_queue(15);
    t_queue* g_queue = create_queue(15);

    char* entry = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    char** order = (char**)malloc(30 * sizeof(char*));

    int idx = 0;
    int count = 0;

    while (1) {
        printf("> ");
        fgets(entry, MAX_NAME_LENGTH, stdin);
        remove_newline(entry);

        if (strlen(entry) == 0) {
            // não faz nada e volta pro próximo laço
        } else if (entry[0] == 'f') {
            break;
        } else {
            char* name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));

            if (strncmp(entry, "p ", 2) == 0) {
                if (is_full(p_queue)) {
                    printf("Fila cheia!\n");
                } else {
                    strcpy(name, entry + 2);
                    enqueue(name, p_queue);
                }
            }

            else if (strncmp(entry, "g ", 2) == 0) {
                if (is_full(g_queue)) {
                    printf("Fila cheia!\n");
                } else {
                    strcpy(name, entry + 2);
                    enqueue(name, g_queue);
                }
            }

            else if (strcmp(entry, "s") == 0) {
                if (count < 3 && !is_empty(p_queue)) {
                    strcpy(name, dequeue(p_queue));
                    count++;
                } else {
                    if (is_empty(g_queue)) {
                        printf("Fila já está vazia!\n");
                        free(name);
                        continue;  // aqui podemos manter o continue para evitar salvar um nome inválido
                    } else {
                        strcpy(name, dequeue(g_queue));
                    }
                }

                order[idx] = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
                strcpy(order[idx++], name);
                printf("%s\n", name);
            }

            else {
                printf("Instrução desconhecida.\n");
            }

            free(name);
        }
    }

    if (order[0] != NULL) {
        for (int i = 0; i < idx; i++) {
            printf("%s\n", order[i]);
        }
    }

    free(entry);

    for (int i = 0; i < idx; i++) {
        free(order[i]);
    }

    free(order);

    return 0;
}