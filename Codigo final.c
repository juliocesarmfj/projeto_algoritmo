/*
Nome: Gabriel Nunes De Souza
Matricula: UC22200723

Nome: Guilherme Ferreira Silva
Matricula: UC22200632

Nome: Júlio César Silva de Moura Fé
Matricula: UC22200353
*/
#include <stdio.h>
#include <string.h>
int main(){

//Aqui declaramos as variaveis necessarias.
    int sessao,i,numpessoa[2],j,masculino=0,feminino=0,idade[100],ingresso[100],kid=0,adol=0,adult=0,idoso=0;
    int m18=0,f18=0,inteiratotal1=0,meiatotal1=0,inteiratotal2=0,meiatotal2=0,cont1=0,cont2=0,cont3=0,cont4=0;
    int avaliacao[100],soma=0,contador=0;
    char filme[30][100],genero[100];
    
    printf("Quantas sessoes gostaria de registrar?"); //Aqui a gente pega a variavel de sessao para cadastrar o numero de sessao, o while aqui e usado para ser especificamente 2.
    scanf("%i",&sessao);
    while(sessao>2 || sessao<=1){
        printf("Por favor coloque a quantidade de sessao correta: ");
        scanf("%i",&sessao);
    }

    for(i=0;i<sessao;i++) // usamos o for para repetir as sessões.
    {
        printf("Sessao %i\n",i+1); 
        printf("Digite o nome do filme: ");// Aqui pedimos para o usuario digitar o nome do filme utilizando fgets para dar espaço.
        fflush(stdin);
        fgets(filme[i],30,stdin);
        filme[i][strcspn(filme[i], "\n")] = 0; // Esse comando serve para o fgets não dar enter no final e pular as linhas.
        printf("Quantas pessoas compareceram na sessao?: "); // Aqui pedimos quantas pessoas apareceram na sessão e validando o valor usando o while.
        scanf("%i",&numpessoa[i]);

        while(numpessoa[i]<=10){   
            printf("Por favor selecione um numero maior que 10: ");
            scanf("%i",&numpessoa[i]);
        }
        
        for(j=0;j<numpessoa[i];j++){  // Aqui usamos o for para cadastrar as pessoas que estão na sessão.
            
            fflush(stdin);
            printf("Qual o genero da pessoa numero %i:",j+1); // Aqui pedimos o genêro e salvando a variavel genêro.
            scanf("%c",&genero[j]);

            while(genero[j]!= 'm' && genero[j]!= 'f') //Aqui usamos o while. enquanto o genêro for diferente de m ou f ele irá pedir para digitar um genêro valido.
            {
                printf("Por favor informar um genero valido: ");
                fflush(stdin);
                scanf("%c",&genero[j]);
            }

            switch(genero[j]){    // Aqui usamos o switch e todo vez que for m ou f ele vai somar 1.   
                case 'm':
                    masculino=masculino+1;
                break;

                case 'f':
                    feminino=feminino+1;
                break;
            
                
            }
            printf("Informar a idade da pessoa numero %i: ",j+1);   // Aqui pedimos para o usuario infomar a idade e validando com o while.
            scanf("%i",&idade[j]);
            while(idade[j]<3 || idade[j]>100){
            printf("Por favor selecione uma idade valida: ");
            scanf("%i",&idade[j]);
        }
            switch(idade[j]){ // Aqui utilizamos o switch para pegar as categorias e somando 1 para cada caso.

                case 3 ... 13:

                kid=kid+1;
                break;

                case 14 ...17:
                adol=adol+1;
                break;

                case 18 ... 64:
                adult=adult+1;
                break;

                case 65 ... 100:
                idoso=idoso+1;
                break;

            }
            // Aqui utilizamos o if para fazer a validação de maiores de idade de cada genêro.
            if (genero[j] == 'm' && idade[j]>=18){ 
                m18=m18+1;
            }
            else if (genero[j] == 'f' && idade[j]>=18){
                f18=f18+1;
            }
            
            
            printf("A pessoa numero %i pagou inteira(1) ou meia(2)? ",j+1); // Aqui pedimos para o usuario digitar se ele pagou inteira ou meia.
            scanf("%i",&ingresso[j]);

            switch(ingresso[j]){ // Aqui usamos o switch para pegar os valores dos ingressos. (quantidade e valores.)
                case 1:
                if(i==0){ // Aqui definimos que o caso so irá executar se estiver na sessão 1.
                    inteiratotal1+=50;
                    cont1+=1;

                }
                else{  // Aqui definimos que o caso so irá executar se estiver na sessão 2.
                inteiratotal2+=50;
                cont2+=1;
                
                }
                break;

                case 2:
                if (i==0){  // Aqui definimos que o caso so irá executar se estiver na sessão 1.
                    meiatotal1+=25;
                    cont3+=1;

                }
                else{  // Aqui definimos que o caso so irá executar se estiver na sessão 2.
                meiatotal2+=25;
                cont4+=1;
                }   
                break;
                
                default:
                while(ingresso[j]>2 ||ingresso[j]<1){ // Aqui usamos o while para validar os ingressos 
                printf("Por favor escrever um valor entre 1 e 2: "); // Aqui pedimos o usuarios para digitar um valor.
                fflush(stdin);
                scanf("%i",&ingresso[j]);
                }
            }

            printf("De 1 a 5 qual a avaliacao para essa sessao?"); // Aqui pedimos para o usuarios nos avaliar usando o while para a validação.
            scanf("%i",&avaliacao[j]);
            while(avaliacao[j]<1 || avaliacao[j]>5){
            printf("Por favor selecione de 1 a 5: ");
            scanf("%i",&avaliacao[j]);
        }
            contador+=1; // esse contador serve para saber quantas pessoas tiveram nas duas sessões.
        }

        for(j=0;j<numpessoa[i];j++){ // Aqui o for para fazer a soma nas avaliações.
            soma+=avaliacao[j];
        }


          // Aqui imprimimos as infomações das sessões.
        printf("Sessao %i\nNome do filme: %s\nQuantidade de pessoas do sexo masculino:%i\nQuantidade de pessoas do sexo feminino:%i\nNumero de criancas: %i\nNumero de Adolecentes:%i\nNumero de adultos: %i\nNumero de idoso: %i\n\n",i+1,filme[i],masculino,feminino,kid,adol,adult,idoso);


        //Aqui nos zeramos os valores das variaveis para quando voltar os laçoes de repetições
        masculino = 0;
        feminino=0;
        kid=0;
        adol=0;
        adult=0;
        idoso=0;

    }

    // Aqui nos fazemos a soma na inteira e a meia da sessão 1 e sessão 2.
    inteiratotal1=inteiratotal1+meiatotal1;
    meiatotal1=inteiratotal2+meiatotal2;
    // Aqui imprime os valores.
    printf("Foram um total de %i pessoas nas duas sessoes",contador);
    printf("\nNas duas sessoes tiveram %i homens maiores de 18 e %i mulheres maiores de 18\n",m18,f18); 
    printf("Na sessao 1(%s) foram vendidos:\t\tNa sessao 2(%s) foram vendidos:\n%i Inteiras\t\t\t\t%i Inteiras\n%i meias\t\t\t\t\t%i meias\nArrecadou:%i\t\t\t\tArrecadou:%i\n",filme[0],filme[1],cont1,cont2,cont3,cont4,inteiratotal1,meiatotal1);
    printf("Houve um faturamento das duas sessoes de %i\n",inteiratotal1+meiatotal1);
    printf("A media de avaliacao das duas sessoes foram de %i",soma/contador);// Aqui nos mostramos o valor da media das avaliaçoes.

    switch (soma/contador){ // De acordo com o valor do resultado ele irá imprimir um dos resultados abaixo.
        case 1:
        printf("(Muito insatisfeito)");
        break;
        case 2:
        printf("(Insatisfeito)");
        break;
        case 3:
        printf("(Neutro)");
        break;
        case 4:
        printf("(Satisfeito)");
        break;
        case 5:
        printf("(Muito satisfeito)");
        break;
    }


    // Aqui comparamos se houveram mais pagamentos de inteiras ou de meias.
    if(cont1+cont2>cont3+cont4){
        printf("\nHouveram mais pagamentos de inteiras");
    }
    else if(cont1+cont2<cont3+cont4){
        printf("\nHouveram mais pagamenos de meias");
    }
    else{
        printf("\nO numero de inteiras e meias foram iguais");
    }




}
