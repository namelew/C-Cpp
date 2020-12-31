# include <stdio.h>

int main(){
    int x;
    // Chamando a função
    void ImprimeMensagem(void);
    // Chamando função que pede parâmetros
    float AreaRet(float base, float alt);
    // Utilizando a função
    ImprimeMensagem();
    // Utilizando a função com retorno
    float arear = AreaRet(10.0, 12.5);
    printf("A area do retangulo eh %.2f\n", arear);


    return 0;
}
// Criando uma função
void ImprimeMensagem(void){
    printf("Teste.\n");
}
// Criando uma função com retorno
float AreaRet(float base, float alt){
    float area = base * alt;
    return area;
}