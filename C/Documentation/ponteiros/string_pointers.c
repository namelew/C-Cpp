# include <stdio.h>

int main(void){
    void CopieString(char *copie, char *paste);

    char string1[] = "Pao com mortadela";
    char string2[20];

    CopieString(string1, string2);
    printf("String2: %s", string2);

    return 0;
}

void CopieString(char *copie, char *paste){
    do{
        *paste = *copie;
        ++copie;
        ++paste;
    }while(*copie != '\0');
}