# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct diaria{
    char nome[25];
    int quant; 
}Diaria;

int main() {
    Diaria d;
    float total;
    printf("Tipo: ");
    fgets(&d.nome, 25, stdin);
    d.nome[strcspn(d.nome, "\n")] = '\0';
    printf("Quantidade: ");
    scanf("%d", &d.quant);

    if(!strcmp(d.nome, "Standard")){
        total = 1.08 * (float)(d.quant * 99.0);
    }
    if(!strcmp(d.nome, "Luxo")){
        total = 1.08 * (float)(d.quant * 139.0);
    }
    if(!strcmp(d.nome, "Super luxo")){
        total = 1.08 * (float)(d.quant * 189.0);
    }
    printf("Total: %.2f\n", total);
    
    return 0;
}