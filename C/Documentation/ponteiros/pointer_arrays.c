# include <stdio.h>

int main(void){
    int array[5] = {1, 2, 3, 4, 5};
    int *pointer = array; // aponta automaticamente pro membro 0
    int *pointer2 = &array[2]; // aponta pra um membro especifico
   
    printf("End. Array[0]: %p\n", pointer);
    pointer = &array[1];
    printf("End. Array[1]: %p\n", pointer);

    printf("End. Array[2]: %p\n", pointer2);
    pointer2 = &array[3];
    printf("End. Array[3]: %p\n", pointer2);
    ++pointer2;
    printf("End. Array[4]: %p\n", pointer2);

    // alterando o valor
    *(pointer+1) = 10; // indicando o endereço de memoria do proximo espaço

    printf("%i", array[2]);

    return 0;
}