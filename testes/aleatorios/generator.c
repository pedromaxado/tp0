#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RAND 10

unsigned long long int total=0;
int MAX=0;

void imprimir(int* vet, int size){
	int i=0;
	for(i=0; i<size; i++)
		printf("%d ", vet[i] );

	printf("\n");

}

void random_shuffle(int arr[]){
    int i, j, temp;
    srand(time(NULL));

    int cont=0;

    for (i = 0 ; i < MAX; i++) {
         j = rand()%(RAND);

         if(j!=0) {
         	arr[i] = j > 0? j: j*(-1);
         }else{
         	arr[i] =1;
         }

         if(arr[i]%2==0){
         	total = total + arr[i];
         }else{

         	if(total == 0) total=1;

         	if(cont>10){
         		total = total + arr[i];
         	}else{
         		total = total * arr[i];
         	}

         	cont++;
         }

         //printf("Arr %d \n",arr[i]);
         //printf("total %d ",total);
    }
    //printf("\n");

}

void salvarArq(char* file){

    FILE* saida = fopen(file, "wb");

    int* vet = malloc((MAX+1)*sizeof(int));
    random_shuffle(vet);

    if( saida == NULL){
      printf("Erro na abertura do arquivo");
      exit(1);
    }

    int i=0;
    int j=0;

    //imprimir(vet, MAX);

    for( i=0; i< MAX-1; i++){

       if(i==0){
       	  fprintf(saida,"%d %d ? ",vet[j],vet[j+1]);
       	  j= j+2;
       }else{
	      fprintf(saida,"%d ? ",vet[j]);
	      j++;
       }



    }

    fprintf(saida,"\n");
    fprintf(saida,"%d\n",total);

    fclose(saida);
    //printf("\n");

}

long sizeArq(){
   FILE* entrada = fopen("dados_entrada.txt", "r");
  // guarda o estado ante de chamar a função fseek
  long posicaoAtual = ftell(entrada);

  // guarda tamanho do arquivo
  long tamanho;

  // calcula o tamanho
  fseek(entrada, 0, SEEK_END);
  tamanho = ftell(entrada);

  // recupera o estado antigo do arquivo
  fseek(entrada, posicaoAtual, SEEK_SET);

  return tamanho;

}

void count2Asc(int integer, char* ascii){

	int temp,count=0,i,cnd=0;

    if(integer>>31)
    {
	     integer=~integer+1;
	     for(temp=integer;temp!=0;temp/=10,count++);
	     ascii[0]=0x2D;
	     count++;
	     cnd=1;
    } else
	     for(temp=integer;temp!=0;temp/=10,count++);

	for(i=count-1,temp=integer;i>=cnd;i--) {

	        ascii[i]=(temp%10)+0x30;
	        temp/=10;
	}

    //printf("\n count =%d ascii=%s ",count,ascii);

}

int main(){

  int i=0;
  char file[100];
  char ascii[10]={0};

  for(i=11; i<101; i++){
    MAX = i;
    total =0;

    count2Asc(i-1, ascii);

    file[0] = ascii[0];
    file[1] = ascii[1];
    file[2] = '.';
    file[3] = 't';
    file[4] = 'x';
    file[5] = 't';
    file[6] = '\0';

    salvarArq(file);

  }

  return 0;

}
