#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "queue.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    t_queue* p_queue = create_queue(15);
    t_queue* g_queue = create_queue(15);

    char* entry = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    
    char** order = (char**)malloc(30 * sizeof(char*));
    
    int idx = 0;
    int count = 0;
    
    fgets(entry, MAX_NAME_LENGTH, stdin);
    
    while(entry[0] != 'f'){
        char* name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));

        switch(entry[0]){
            case 'p':
                if(is_full(p_queue)){
                    printf("Fila cheia!\n");
                    break;
                }

                strcpy(name, entry + 2);
                enqueue(name, p_queue);
                
                break;
            case 'g':
                if(is_full(g_queue)){
                    printf("Fila cheia!\n");
                    break;
                }

                strcpy(name, entry + 2);
                enqueue(name, g_queue);
                
                break;
            case 's':
                if(count < 3 && !is_empty(p_queue)){
                    strcpy(name, dequeue(p_queue));
                    count++;
                } else {

                    if(is_empty(g_queue)){
                        printf("Fila já está vazia!\n");
                        break;
                    }

                    strcpy(name, dequeue(g_queue));
                }
                
                order[idx] = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
                strcpy(order[idx++], name);
                printf("Aqui %s", name);
                break;
            default:
                printf("Instrução desconhecida.\n");
                break;
        }

        fgets(entry, MAX_NAME_LENGTH, stdin);
    }

    if(order[0] != NULL){
        for(int i = 0; i < idx; i++){
            printf("%s", order[i]);
        }
    }

    free(entry);

    for(int i = 0; i < idx; i++){
        free(order[i]);
    }

    free(order);
}