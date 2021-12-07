//boa tarde fiz a questão mas trava quando eu entro na cmd 

//2) Implemente uma lista estática, com todas as funções e monte um menu de opções.
#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 1000
int Frente, Tras, Lista[MAXTAM];
void Lista_Construtor(){
Frente=0;
Tras=-1;
}
void Lista_mostrar_toda_lista( void )
{
    for( int i = 0; i < MAXTAM; ++i )
    {
        printf( "%04d - %d\n", i , Lista[ i ] );
    }
    system("pause");
}
int Lista_Vazia(){
if(Tras==-1)
return 1;
else
return 0;
}
int Lista_Cheia(){
if(Tras==MAXTAM-1)
return 1;
else
return 0;
}
int Lista_Tamanho(){
return Tras+1;
}
int Lista_Inserir_Inicio(int Valor){
if(Lista_Cheia()){
return 0;
}else{
/*se quero inserir na posição 0,
vou deslocar todos os elementos para frente*/
for(int i=Tras+1;i>Frente;i--){
Lista[i]=Lista[i-1];
}
Lista[Frente]=Valor;
Tras++;
return 1;
  }
}
int Lista_Inserir_Fim(int Valor){
if(Lista_Cheia()){
return 0;
}else{
Tras++;
Lista[Tras]=Valor;
return 1;
  }
}
int Lista_Inserir(int Valor, int Posicao){
if(Lista_Cheia()){
return 0;
}else{
/* Para verificar se a posição
está no meio da lista */
if(Posicao>Frente && Posicao<Tras){
for(int i=Tras+1;i>Posicao;i--){
Lista[i]=Lista[i-1];
}
Lista[Posicao]=Valor;
Tras++;
return 1;
}else{
return 0;
   }
  }
}
int Lista_Remover_Inicio(int *Valor){
if(Lista_Vazia()){
return 0;
}else{
*Valor =Lista[Frente];
for(int i=Frente;i<Tras;i++){
Lista[i]=Lista[i+1];
   }
Tras--;
  }
}
int Lista_Remover_Fim(int *Valor){
if(Lista_Vazia()){
return 0;
}else{
*Valor=Lista[Tras];
Tras--;
return 1;
  }
}
int Lista_Remover(int *Valor, int Posicao){
if(Lista_Vazia()){
return 0;
}else{
if(Posicao>Frente && Posicao<Tras){
*Valor=Lista[Posicao];
for(int i=Posicao;i<Tras;i++){
Lista[i]=Lista[i+1];
}
Tras--;
return 1;
   }
  }
}
int Lista_Get_inicio(int *Valor){
if(Lista_Vazia()){
return 0;
}else{
*Valor=Lista[Frente];
return 1;
  }
}
int Lista_Get_Fim(int *Valor){
if(Lista_Vazia()){
return 0;
}else{
*Valor=Lista[Tras];
return 1;
  }
}
int Lista_Busca_Valor(int Valor, int *Posicao){
int i;
if(Lista_Vazia()){
return 0;
}else{
for(i=Frente;i<Tras;i++){
if(Lista[i]==Valor){
break;
  }
}
if(i==Tras){
return 0;
}else{
*Posicao=i;
return 1;
   }
  }
}
int Lista_Busca_Posicao(int *Valor, int Posicao){
if(Lista_Vazia()){
return 0;
}else{
if(Posicao>Frente && Posicao<Tras){
*Valor=Lista[Posicao];
return 1;
}else{
return 0;
   }
  }
}
int main(){
int i,Valor,op=0,pos,Posicao;
Lista_Construtor();
while(op!=12){
printf("*** Menu de opções ***\n");
printf("1-Inserir início\n");
printf("2-Inserir fim\n");
printf("3-Inserir meio\n");
printf("4-Excluir início\n");
printf("5-Excluir fim\n");
printf("6-Excluir meio\n");
printf("7-Mostrar toda lista\n");
printf("8-Mostrar primeiro item da lista\n");
printf("9-Mostrar último item da lista\n");
printf("10-Mostrar a posição de um item da lista\n");
printf("11-Mostrar o valor de uma posição\n");
printf("12-Sair\n");
printf("Escolha uma opção: ");
scanf("%d", &op);
switch(op){
    case 1:
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &Valor);
        Lista_Inserir_Inicio(Valor);
        break;
    case 2:
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &Valor);
        Lista_Inserir_Fim(Valor);
        break;
      case 3:
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &Valor);
        printf("Digite a posição que deseja inserir: ");
        scanf("%d", &pos);
        Lista_Inserir(Valor, pos);
        break;
      case 4:
        printf("Digite a remoção do início: ");
        scanf("%d", &Valor);
        Lista_Remover_Inicio(Valor);
        break;
        case 5:
        printf("Digite a remoção do fim: ");
        scanf("%d", &Valor);
        Lista_Remover_Fim(Valor);
        break;
        case 6:
        printf("Digite a remoção do meio: ");
        scanf("%d", &Valor);
        printf("Digite a posição que deseja remover: ");
        scanf("%d", &Posicao);
        Lista_Remover(Valor, pos);
        break;
         case 7:
        printf("Digite ao a mostrar toda lista: ");
        scanf("%d", &Valor);
        Lista_mostrar_toda_lista();
        break;
       case 8:
        printf("Digite ao a mostrar primeiro item da lista: ");
        scanf("%d", &Valor);
        Lista_Get_inicio(Valor);
        break;
       case 9:
        printf("Digite ao a mostrar último item da lista: ");
        scanf("%d", &Valor);
        Lista_Get_Fim(Valor);
        break;
        case 10:
        printf("Digite ao a mostrar a posição de um item da lista: ");
        scanf("%d", &Valor);
        printf("Digite a posição que deseja mostrar na lista: ");
        scanf("%d", & pos);
        Lista_Busca_Valor(Valor, pos);
        break;
        case 11:
        printf("Digite ao a mostrar o valor de uma posição: ");
        scanf("%d", &Valor);
        printf("Digite a posição que deseja mostrar no valor: ");
        scanf("%d", &pos);
        Lista_Busca_Posicao(Valor, pos);
        break;
        case 12:
        default:
        printf("Valor Invalido!\n");
        system("PAUSE");

         }

    system("cls");
   }
 return 0;
}
