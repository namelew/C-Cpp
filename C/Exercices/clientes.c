# include <stdio.h>
// problemas com a função info
// incompleto
struct cliente{
    char cpf[12];
    char name[30];
    char city[20];
};

int main(void){
    int find(char search[], struct cliente agenda[]);
    void infos(int x, struct cliente agenda[]);

    char registro[12];
    int o, resul;
    struct cliente firma[10] = {{"03044618223", "Diogo Cunha", "Macapa/AP"}};
    printf("Registro da Firma C Shape\n");
    do{
        printf("1 - Adicionar registro;\n");
        printf("2 - Procurar registro;\n");
        printf("3 - Sair;\n");
        printf("Op%c%co: ", 135, 198);
        scanf("%d", &o);
        switch (o){
            case 1:
                break;
            case 2:
                printf("CPF(formato: xxxyyyzzzab): ");
                scanf("%s", &registro);

                resul = find(registro, firma);

                if(resul != -1){
                    infos(resul, firma);
                } else{
                    printf("Registro n%co encontrado", 198);
                }

                break;
            case 3:
                o = 0;
                break;
            default:
                printf("Opção Inv%clida!\n", 160);
                break;
        }
    }while(o != 0);
    
    return 0;
}

int find(char search[], struct cliente agenda[]){
    _Bool compare_str(char string1[], char str2[]);

    int i = 0;
    do{
        if(compare_str(search, agenda[i].cpf)){
            return i;
        } else {
            i++;
        }
    }while(search != agenda[i].cpf);
    
    return -1;
}

void infos(int x, struct cliente agenda[]){
    printf("Nome: %s\n", agenda[x].name);
    printf("Cpf: %s\n", agenda[x].cpf);
    printf("Cidade: %s\n", agenda[x].city);
}

_Bool compare_str(char string1[], char str2[]){
    int i = 0;

    while(string1[i] == str2[i] && string1 != '\0' && str2 != '\0'){
        i++;
    }

    if(string1[i] == '\0' && str2[i] == '\0'){
        return 1;
    } else {
        return 0;
    }
}