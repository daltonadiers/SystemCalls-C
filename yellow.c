#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int sessoes = 0;
int capacidade = 0;
int fila[8];
int personIn = 0;

pthread_mutex_t mutex;

void atualizar_fila() {
    for (int i = 0; i < 8; i++) {
        fila[i] = rand() % 10;  // Gera um número aleatório entre 0 e 999
    }
    printf("Fila atualizada!");
}

void *thread_function(void *arg) {
    int valor = *((int *)arg);
    while (personIn < capacidade) {
        pthread_mutex_lock(&mutex);  // Bloqueia o mutex
        if (fila[valor - 1] > 0) {  // Ajuste do índice da fila
            if (personIn < capacidade) {
                personIn++;
                fila[valor - 1]--;  // Ajuste do índice da fila
                printf("Eu sou a fila numero (%d) e adicionei a pessoa %d na camara!\n", valor, personIn);
            }
        }
        pthread_mutex_unlock(&mutex);  // Libera o mutex
    }
    pthread_exit(NULL);
}

void *thread_main(void *arg) {
    pthread_t thread_id[8];
    int status[8];
    int args[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int erro = 0;
    while(sessoes>0){
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < 8; i++) {
            status[i] = pthread_create(&thread_id[i], NULL, thread_function, &args[i]);
            if (status[i] != 0) {
                printf("Erro ao criar a thread %d!\n", i + 1);
                erro++;
            }
        }
        if (erro == 0) {
            printf("Todas as threads foram criadas com sucesso.\n");
        }
        pthread_mutex_unlock(&mutex); 
        for (int i = 0; i < 8; i++) {
            pthread_join(thread_id[i], NULL);
        }
        sessoes--;
        personIn =0;
        printf("Sessao iniciando...\n");
        sleep(1);
        printf("Sessao terminou!\n");
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(1, "Uso indevido de argumentos!\n", 27);
        return -1;
    }

    pthread_t thread_idmain;
    capacidade = atoi(argv[2]);
    sessoes = atoi(argv[1]);
    pthread_mutex_init(&mutex, NULL);
    int status = pthread_create(&thread_idmain, NULL, thread_main, NULL);
    if(status!=0){
        printf("ERRO!");
    }
    srand(time(NULL));
    while (sessoes > 0) {
        // Resto do código dentro do while permanece o mesmo
        
        atualizar_fila();  // Chama a função para atualizar a fila com números aleatórios

        // Resto do código dentro do while permanece o mesmo
        
        sleep(5);  // Pausa a execução do programa por 5 segundos
    }
    pthread_join(thread_idmain, NULL);
    printf("Final do dia!");
    pthread_mutex_destroy(&mutex);
    return 0;
}
