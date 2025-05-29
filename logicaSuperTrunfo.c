#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {

    // Definição das variáveis para armazenar as propriedades das cidades

    char nomeDoPais[30] = "N/A";
    char nomeDoPais2[30] = "N/A";

    unsigned long int populacao = 0; 
    unsigned long int populacao2 = 0; 
    int NumeroDePontosTuristicos = 0;
    int NumeroDePontosTuristicos2 = 0;
    float AreaPorKm2 = 0.0; 
    float AreaPorKm22 = 0.0; 
    float PIB = 0.0;
    float PIB2 = 0.0;

    float pibPerCapita = PIB / populacao;
    float densidadeDemografica = populacao / AreaPorKm2;
    float pibPerCapita2 = PIB2 / populacao2;
    float densidadeDemografica2 = populacao2 / AreaPorKm22;
    
    int opcaoMenu = 0;
    printf("==================================\n");
    printf("     SUPER TRUNFO - Países \n");
    printf("==================================\n");
    printf("1. Jogar\n");
    printf("2. Instruções\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcaoMenu);
    getchar();

    switch (opcaoMenu)
    {
    case 1:

    // ENTRADA DE DADOS CARTA 1
    printf("==================================\n");
    printf("             CARTA 1\n");
    printf("==================================\n");

    printf("Nome da cidade: ");
    fgets(nomeDoPais, sizeof(nomeDoPais), stdin); 
        // strcspn retorna o índice do primeiro caractere de nova linha '\n'
    nomeDoPais[strcspn(nomeDoPais, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao);
    printf("Número de pontos turísticos: ");
    scanf("%d", &NumeroDePontosTuristicos);
    printf("Área (km²): ");
    scanf("%f", &AreaPorKm2);
    printf("PIB: ");
    scanf("%f", &PIB);
    getchar(); // Limpa o buffer do teclado após a leitura do PIB

    // Cálculo do PIB per CAPITA e densidade demográfica
    float pibPerCapita = PIB / populacao;
    float densidadeDemografica = populacao / AreaPorKm2;

    printf("Densidade Demografica: %.2f\n", densidadeDemografica);
    printf("PIB per CAPITA: %.2f\n", pibPerCapita);

    // ENTRADA DE DADOS CARTA 2
    printf("==================================\n");
    printf("             CARTA 2\n");
    printf("==================================\n");

    printf("Nome da cidade: ");
    fgets(nomeDoPais, sizeof(nomeDoPais), stdin); 
        // strcspn retorna o índice do primeiro caractere de nova linha '\n'
    nomeDoPais[strcspn(nomeDoPais, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &NumeroDePontosTuristicos2);
    printf("Área (km²): ");
    scanf("%f", &AreaPorKm22);
    printf("PIB: ");
    scanf("%f", &PIB2);
        // Cálculo do PIB per CAPITA e densidade demográfica
    float pibPerCapita2 = PIB2 / populacao2;
    float densidadeDemografica2 = populacao2 / AreaPorKm22;

    printf("Densidade Demografica: %.2f\n", densidadeDemografica);
    printf("PIB per CAPITA: %.2f\n", pibPerCapita2);

    // Menu de seleção de atributos para comparação
    printf("==================================\n");
    printf("    ESCOLHA O ATRIBUTO DA CARTA:\n");
    printf("==================================\n");
    
    printf("    1. População\n");
    printf("    2. Número de pontos turísticos\n");
    printf("    3. PIB\n");
    printf("    4. PIB per CAPITA\n");
    printf("    5. Densidade demográfica\n\n");

        // Variáveis para armazenar as opções de atributos escolhidos pelo usuário
    int opcaoPrimeiroAtributo, opcaoSegundoAtributo;
        // Variáveis para armazenar os pontos de cada carta
    int pontos = 0, pontos2;
        // Variáveis para armazenar o nome da cidade vencedora
    float somaAtributosCarta = populacao + NumeroDePontosTuristicos + PIB + pibPerCapita + (densidadeDemografica / 1);
    float somaAtributosCarta2 = populacao2 + NumeroDePontosTuristicos2 + PIB2 + pibPerCapita2 + (densidadeDemografica2 / 1);
    
    printf(" # Escolha o 1° Atributo da carta: ");
    scanf("%d", &opcaoPrimeiroAtributo);
    printf(" # Escolha o 2° Atributo da carta: ");
    scanf("%d", &opcaoSegundoAtributo);
    printf("==================================\n");
    // Validação das opções de atributos escolhidos pelo usuário
    if(opcaoPrimeiroAtributo < 1 || opcaoPrimeiroAtributo > 5 || 
       opcaoSegundoAtributo < 1 || opcaoSegundoAtributo > 5) {
        printf("Opção inválida. Por favor, escolha um número entre 1 e 5.\n");
        printf("\n\n\n");
        return 1; // Encerra o programa se a opção for inválida
    }
    else if(opcaoPrimeiroAtributo == opcaoSegundoAtributo) {
        printf("Você escolheu o mesmo atributo para comparação. Por favor, escolha atributos diferentes.\n");
        printf("\n\n\n");
        return 1; // Encerra o programa se os atributos forem iguais
    }

    switch (opcaoPrimeiroAtributo)
    {
        case 1:
        // Comparação do primeiro atributo escolhido pelo usuário
        if(populacao > populacao2) {
            printf("    PRIMEIRO ATRIBUTO: POPULAÇÃO\n");
            printf("==================================\n");
            printf("%s tem %lu habitantes.\n", nomeDoPais, populacao);
            printf("%s tem %lu habitantes.\n\n", nomeDoPais2, populacao2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (populacao < populacao2) {
            printf("    PRIMEIRO ATRIBUTO: POPULAÇÃO\n");
            printf("==================================\n");
            printf("%s tem %lu habitantes.\n", nomeDoPais, populacao);
            printf("%s tem %lu habitantes.\n\n", nomeDoPais2, populacao2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm a mesma população.\n\n");
        }
        break;
        case 2:
        // Comparação do segundo atributo escolhido pelo usuário
        if(NumeroDePontosTuristicos > NumeroDePontosTuristicos2) {
            printf("PRIMEIRO ATRIBUTO: PONTOS TURÍSTICOS\n");
            printf("==================================\n");
            printf("%s tem %d pontos turísticos.\n", nomeDoPais, NumeroDePontosTuristicos);
            printf("%s tem %d pontos turísticos.\n\n", nomeDoPais2, NumeroDePontosTuristicos2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (NumeroDePontosTuristicos < NumeroDePontosTuristicos2) {
            printf("PRIMEIRO ATRIBUTO: PONTOS TURÍSTICOS\n");
            printf("==================================\n");
            printf("%s tem %d pontos turísticos.\n", nomeDoPais, NumeroDePontosTuristicos);
            printf("%s tem %d pontos turísticos.\n\n", nomeDoPais2, NumeroDePontosTuristicos2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm o mesmo número de pontos turísticos.\n");
        }
        break;
        case 3:
        // Comparação do terceiro atributo escolhido pelo usuário
        if(PIB > PIB2) {
            printf("PRIMEIRO ATRIBUTO: PIB\n");
            printf("==================================\n");
            printf("%s tem um PIB de %.2f.\n", nomeDoPais, PIB);
            printf("%s tem um PIB de %.2f.\n\n", nomeDoPais2, PIB2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (PIB < PIB2) {
            printf("PRIMEIRO ATRIBUTO: PIB\n\n");
            printf("%s tem um PIB de %.2f.\n", nomeDoPais, PIB);
            printf("%s tem um PIB de %.2f.\n\n", nomeDoPais2, PIB2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm o mesmo PIB.\n");
        }
        break;
        case 4:
        // Comparação do quarto atributo escolhido pelo usuário
        if(pibPerCapita > pibPerCapita2) {
            printf("PRIMEIRO ATRIBUTO: PIB per CAPITA\n");
            printf("==================================\n");
            printf("%s tem um PIB per CAPITA de %.2f.\n", nomeDoPais, pibPerCapita);
            printf("%s tem um PIB per CAPITA de %.2f.\n\n", nomeDoPais2, pibPerCapita2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (pibPerCapita < pibPerCapita2) {
            printf("PRIMEIRO ATRIBUTO: PIB per CAPITA\n");
            printf("==================================\n");
            printf("%s tem um PIB per CAPITA de %.2f.\n", nomeDoPais, pibPerCapita);
            printf("%s tem um PIB per CAPITA de %.2f.\n\n", nomeDoPais2, pibPerCapita2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm o mesmo PIB per CAPITA.\n");
        }
        break;
        case 5:
        // Comparação do quinto atributo escolhido pelo usuário
        if(densidadeDemografica < densidadeDemografica2) {
            printf("PRIMEIRO ATRIBUTO: DENSIDADE DEMOGRÁFICA\n");
            printf("==================================\n");
            printf("%s tem uma densidade demográfica de %.2f habitantes por km².\n", nomeDoPais, densidadeDemografica);
            printf("%s tem uma densidade demográfica de %.2f habitantes por km².\n\n", nomeDoPais2, densidadeDemografica2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (densidadeDemografica > densidadeDemografica2) {
            printf("PRIMEIRO ATRIBUTO: DENSIDADE DEMOGRÁFICA\n");
            printf("==================================\n");
            printf("%s tem uma densidade demográfica de %.2f habitantes por km².\n", nomeDoPais, densidadeDemografica);
            printf("%s tem uma densidade demográfica de %.2f habitantes por km².\n\n", nomeDoPais2, densidadeDemografica2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm a mesma densidade demográfica.\n");
        }
        break;
    default: 
        break;
    }

    switch (opcaoSegundoAtributo)
    {
        case 1:
        // Comparação do primeiro atributo escolhido pelo usuário
        if(populacao > populacao2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: POPULAÇÃO\n");
            printf("==================================\n");
            printf("%s tem %lu habitantes.\n", nomeDoPais, populacao);
            printf("%s tem %lu habitantes.\n\n", nomeDoPais2, populacao2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (populacao < populacao2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: POPULAÇÃO\n");
            printf("==================================\n");
            printf("%s tem %lu habitantes.\n", nomeDoPais, populacao);
            printf("%s tem %lu habitantes.\n\n", nomeDoPais2, populacao2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm a mesma população.\n\n");
        }
        break;
        case 2:
        // Comparação do segundo atributo escolhido pelo usuário
        if(NumeroDePontosTuristicos > NumeroDePontosTuristicos2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: PONTOS TURÍSTICOS\n");
            printf("==================================\n");
            printf("%s tem %d pontos turísticos.\n", nomeDoPais, NumeroDePontosTuristicos);
            printf("%s tem %d pontos turísticos.\n\n", nomeDoPais2, NumeroDePontosTuristicos2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (NumeroDePontosTuristicos < NumeroDePontosTuristicos2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: PONTOS TURÍSTICOS\n");
            printf("==================================\n");
            printf("%s tem %d pontos turísticos.\n", nomeDoPais, NumeroDePontosTuristicos);
            printf("%s tem %d pontos turísticos.\n\n", nomeDoPais2, NumeroDePontosTuristicos2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm o mesmo número de pontos turísticos.\n");
        }
        break;
        case 3:
        // Comparação do terceiro atributo escolhido pelo usuário
        if(PIB > PIB2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: PIB\n");
            printf("==================================\n");
            printf("%s tem um PIB de %.2f.\n", nomeDoPais, PIB);
            printf("%s tem um PIB de %.2f.\n\n", nomeDoPais2, PIB2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (PIB < PIB2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: PIB\n");
            printf("==================================\n");
            printf("%s tem um PIB de %.2f.\n", nomeDoPais, PIB);
            printf("%s tem um PIB de %.2f.\n\n", nomeDoPais2, PIB2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm o mesmo PIB.\n");
        }
        break;
        case 4:
        // Comparação do quarto atributo escolhido pelo usuário
        if(pibPerCapita > pibPerCapita2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: PIB per CAPITA\n");
            printf("==================================\n");
            printf("%s tem um PIB per CAPITA de %.2f.\n", nomeDoPais, pibPerCapita);
            printf("%s tem um PIB per CAPITA de %.2f.\n\n", nomeDoPais2, pibPerCapita2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (pibPerCapita < pibPerCapita2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: PIB per CAPITA\n");
            printf("==================================\n");
            printf("%s tem um PIB per CAPITA de %.2f.\n", nomeDoPais, pibPerCapita);
            printf("%s tem um PIB per CAPITA de %.2f.\n\n", nomeDoPais2, pibPerCapita2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm o mesmo PIB per CAPITA.\n");
        }
        break;
        case 5:
        // Comparação do quinto atributo escolhido pelo usuário
        if(densidadeDemografica < densidadeDemografica2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: DENSIDADE DEMOGRÁFICA\n");
            printf("==================================\n");
            printf("%s tem uma densidade demográfica de %.2f habitantes por km².\n", nomeDoPais, densidadeDemografica);
            printf("%s tem uma densidade demográfica de %.2f habitantes por km².\n\n", nomeDoPais2, densidadeDemografica2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais);
            pontos++;
        } else if (densidadeDemografica > densidadeDemografica2) {
            printf("==================================\n");
            printf("SEGUNDO ATRIBUTO: DENSIDADE DEMOGRÁFICA\n");
            printf("==================================\n");
            printf("%s tem uma densidade demográfica de %.2f habitantes por km².\n", nomeDoPais, densidadeDemografica);
            printf("%s tem uma densidade demográfica de %.2f habitantes por km².\n\n", nomeDoPais2, densidadeDemografica2);
            printf("        # %s ganhou um ponto.\n\n", nomeDoPais2);
            pontos2++;
        } else {
            printf("EMPATE: Ambas as cidades têm a mesma densidade demográfica.\n");
        }
        break;
    default: 
        break;
    }
    printf("==================================\n");
    printf("    SOMA DOS ATRIBUTOS DAS CARTAS:\n");
    printf("==================================\n");
    printf("Soma dos atributos da carta %s: %f\n", nomeDoPais, somaAtributosCarta);
    printf("Soma dos atributos da carta %s: %f\n\n", nomeDoPais2, somaAtributosCarta2);

    if(somaAtributosCarta > somaAtributosCarta2) {
        printf("%s ganhou um ponto extra por ter uma soma maior de atributos.\n\n", nomeDoPais);
        pontos++;
    } else if (somaAtributosCarta < somaAtributosCarta2) {
        printf("%s ganhou um ponto extra por ter uma soma maior de atributos.\n\n", nomeDoPais2);
        pontos2++;
    } else {
        printf("# EMPATE: Ambas as cidades têm a mesma soma de atributos.\n\n");
    }

    // Exibição do resultado final da partida

    printf("===================================\n");
    printf("       RESULTADO DA PARTIDA:\n");
    printf("===================================\n");
    printf("%s: %d pontos\n", nomeDoPais, pontos);
    printf("%s: %d pontos\n", nomeDoPais2, pontos2);
    printf("\n");
    if(pontos > pontos2) {
        printf("        # %s venceu a partida!\n", nomeDoPais);
    } else if(pontos < pontos2) {
        printf("        # %s venceu a partida!\n", nomeDoPais2);
    } else {
        printf("# EMPATE: Ambas as cidades têm o mesmo número de pontos.\n");
    }
        break;
    case 2:
    printf("==================================\n");
    printf("         INSTRUÇÕES DO JOGO\n");
    printf("==================================\n");
    printf("1. O jogo é jogado entre dois jogadores.\n");
    printf("2. Cada jogador escolhe uma carta com informações sobre uma cidade.\n");
    printf("3. Os jogadores escolhem dois atributos para comparar.\n");
    printf("4. O jogador com o maior valor no primeiro atributo ganha um ponto.\n");
    printf("5. O jogador com o maior valor no segundo atributo ganha um ponto.\n");
    printf("6. O jogador com a maior soma dos atributos ganha um ponto extra.\n");
    printf("7. O jogador com mais pontos no final vence a partida.\n");
    printf("8. Se houver empate em qualquer etapa, nenhum ponto é concedido.\n");
    printf("9. O jogo termina quando ambos os jogadores concordam em parar.\n");
    printf("10. Divirta-se ^^.\n");
    printf("\n\n\n");
        break;
    case 3:
    printf("==================================\n");
    printf("          FIM DO JOGO\n");
    printf("==================================\n");
    default:
        break;
    }
    

    printf("\n\n\n");

    return 0;
}