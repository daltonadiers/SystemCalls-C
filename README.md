# SystemCalls-C

## Session simulator with thread control

This work was developed for the Operating Systems 1 discipline of the Computer Science course at the University of Passo Fundo. This code aims to simulate a space simulation chamber with x number of people inside it and y number of sessions that will take place on the day. These values ​​must be passed via the command line when executing the code. Considering the defined capacity, we know that the camera has an octagon shape, for this we will have a row of people on each side of the octagon, to be simulated by a thread. There are 8 threads to control each of the queues, 1 thread responsible for updating the number of people in each queue with a random value using rand(), and 1 thread that maintains main. All threads are controlled by critical sessions implemented through semaphores, so only one thread at a time can remove a person from the queue and place them inside the chamber. The session must begin when the chamber capacity is filled. If there is more than one session to take place, the chamber will be reset and the process will begin again. When there are no more sessions, the process will end.

## For execute 
compile: gcc yellow.c -o filename -pthread  
execute: ./filename 3 10  
Note that in this case 3 will be the number of sessions, while 10 will be the camera capacity. You can change these values.

## Simulador de sessões com controle de threads

Esse trabalho foi desenvolvido para a disciplina de Sistemas Operacionais 1 do curso de Ciência da Computação da Universidade de Passo Fundo. Esse código visa simular uma câmara de simulação espacial com um número x de capacidade de pessoas dentro dela e um y número de sessões que acontecerão no dia. Esses valores devem ser passados via linha de comando ao executar o código. Tendo em vista a capacidade definida, sabemos que a câmara tem formato octognal, para isto teremos uma fila de pessoas em cada lado do octógono, a ser simulada por uma thread. São 8 threads para controlar cada uma das filas, 1 thread responsável por atualizar o número de pessoas em cada fila com um valor aleatório utilizando rand(), e 1 thread que mantém a main. Todas as threads são controladas por sessões críticas implementadas através de semáforos, então, apenas uma thread por vez pode retirar uma pessoa da fila e colocá-la dentro da câmara. A sessão deve iniciar quando a capacidade da câmara for preenchida. Caso haja mais de uma sessão para acontecer, a câmara será zerada e o processo recomeçará. Quando não houverem mais sessões, o processo será encerrado.

## Para executar

compilar: gcc yellow.c -o nomedoarquivo -pthread  
executar: ./nomedoarquivo 3 10  
Note que nesse caso 3 será o número de sessões, enquanto 10 será a capacidade da câmara. Você pode alterar esses valores.
