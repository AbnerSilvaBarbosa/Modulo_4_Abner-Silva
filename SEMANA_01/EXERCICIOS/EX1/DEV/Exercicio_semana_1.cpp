/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

// Eu declaro os valores nos parametros da função e uma varialvel para armazenar o resultado da conta.
// A conta se resume em um Z-score 

int questao1(int valor, int min, int max){
    int resultado;
    resultado = (valor - min) * 100 / (max - min);
    return resultado;
}


// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor

// Eu declaro uma variavel para retornar o valor que o usuario colocar no log

int questao2(){
    int resultado;
    
	printf("Digite a distancia ... \n");
	cin >> resultado;
	
    return resultado;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer em um vetor fornecido. Note que como C não possui vetores nativosda 
//linguagem, lembre-se que você precisa passar o valor máximo do vetor assim como a última posição preenchida Evite também que, por 
//acidente, um valor seja escrito em uma área de memória fora do vetor


// Nos parametors eu declaro como dependende da função , o valor que será inserido , a lista que foi instanciada no main, o volume maximo do array e a ultima posição que foi preencgida, logo apos isso faço uma simples validação para saber se o ultimo posição não e maior que o volume total do array, se ela passar por essa validação eu coloco o valor que eu coloquei nos parametros na ultima posição do array e retorno o numero da ultimaposição do array que foi preenchida + 1 para sempre estár voltando a ultima posição mais 1. 

int questao3(int valor,int *lista, int maxVetor,int ultimaPreenchida){

    if (ultimaPreenchida < maxVetor){
        lista[ultimaPreenchida] = valor;
        return ultimaPreenchida + 1;
    }
    return ultimaPreenchida ;
}


// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.

// Eu declaro dentro da minha função 2 variaveis, 1 onde vai armazenar o maior  valor do array e o outro que armazena em qual index está esse valor, para ssim fazer um switch e assim retornar qual direção está com o maior valor.

char* questao4(int *vetor, int *distancia){
    
    int maior_lista = vetor[0];
    int maior_index = 0;
    
    for(int i = 1; i < 4; i++) {
        if (maior_lista < vetor[i]) {
            maior_lista = vetor[i];
            maior_index = i;
        }
    }
    *distancia = maior_lista;
    
    switch (maior_index) {
     case 0:
        return (char*)"Direita";
     case 1:
        return (char*)"Esquerda";
     case 2:
        return (char*)"Frente";
     case 3:
        return (char*)"Tras";
    }

}

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso


// Eu faço ele retornar 1 para continuar e 0 para parar, pois na lógica eu executo essa função sempre que ea retorna o valor 1

int questao5(){

    string usuario;
    printf("Voce deseja continuar o mapeamento? s/n: ");
    
    cin >> usuario;
    
    if (usuario == "s") {
        return 1;
    }
    else {
        return 0;
    }
}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 

// Eu utilizo todas as funções que crei a cima para cada uma das direções , pegando as suas mediadas para cada direção e realizadno o calculo de distancia no final. 

int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;
	
	while(dirigindo){	
	    
		int medidaDireita = questao2();
		medidaDireita = questao1(medidaDireita,0,830);
		posAtualVetor = questao3(medidaDireita,vetorMov,maxVetor,posAtualVetor);
		
		int medidaEsquerda = questao2();
		medidaEsquerda = questao1(medidaEsquerda,0,830);
		posAtualVetor = questao3(medidaEsquerda,vetorMov,maxVetor,posAtualVetor);
		
		int medidaFrente = questao2();
		medidaFrente = questao1(medidaFrente,0,830);
		posAtualVetor = questao3(medidaFrente,vetorMov,maxVetor,posAtualVetor);
		
		int medidaAtras = questao2();
		medidaAtras = questao1(medidaAtras,0,830);
		posAtualVetor = questao3(medidaAtras,vetorMov,maxVetor,posAtualVetor);
		
		
		
		dirigindo = questao5();		
	}
	return posAtualVetor;
}

// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = questao4(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}


int main(){
    
    //Teste das funçoes individualmente com print

    //questao1(30, 0, 100);
    //questao2();
    //questao3();
    //questao4(listaTeste);
    //questao5();
    
    int maxVetor = 100;
    int lista[maxVetor * 4];
    int posAtualVet = 0;

	posAtualVet = dirige(lista,maxVetor);
	percorre(lista,posAtualVet);
	
	return 0;


}
