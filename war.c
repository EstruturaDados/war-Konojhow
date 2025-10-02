#include <stdio.h>  // Para funções de entrada e saída (printf, scanf)
#include <string.h> // Para manipulação de strings (embora não seja estritamente necessário para este caso, é uma boa prática incluir para lidar com strings)

// Definindo o número máximo de territórios a serem cadastrados
#define MAX_TERRITORIOS 5

/**
 * @brief Estrutura que representa um Território no jogo War.
 *
 * Contém informações essenciais sobre cada território.
 */
struct Territorio {
    char nome[30];    // Nome do território (máximo de 29 caracteres + '\0')
    char cor[10];     // Cor do exército que o ocupa (máximo de 9 caracteres + '\0')
    int tropas;       // Quantidade de tropas alocadas no território
};

// --- Início da função principal ---
int main() {
    // Declaração do vetor de structs para armazenar os 5 territórios
    // Este é o "banco de dados" inicial do nosso sistema.
    struct Territorio mapa[MAX_TERRITORIOS];
    int i; // Variável de controle para os laços 'for'

    // -------------------------------------------------------------------------
    // ETAPA 1: CADASTRO DOS TERRITÓRIOS
    // -------------------------------------------------------------------------

    printf("==========================================\n");
    printf("     SISTEMA DE CADASTRO DE TERRITÓRIOS\n");
    printf("==========================================\n");
    printf("Voce ira cadastrar %d territorios.\n\n", MAX_TERRITORIOS);

    // Laço 'for' para iterar sobre o vetor e preencher os dados de cada território
    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("--- Cadastro do Territorio %d/%d ---\n", i + 1, MAX_TERRITORIOS);

        // 1. Entrada do Nome do Território
        printf("Digite o nome do territorio (max. 29 caracteres): ");
        // Usamos scanf com "%s" para ler uma palavra (sem espaços)
        // e evitar problemas com o buffer, assumindo que o nome não terá espaços.
        // O limite de 29 protege o array 'nome'.
        if (scanf("%29s", mapa[i].nome) != 1) {
             // Tratamento de erro básico
             printf("Erro na leitura do nome. Encerrando.\n");
             return 1;
        }

        // 2. Entrada da Cor do Exército
        printf("Digite a cor do exercito (ex: Vermelho, Azul, etc): ");
        if (scanf("%9s", mapa[i].cor) != 1) {
            printf("Erro na leitura da cor. Encerrando.\n");
            return 1;
        }

        // 3. Entrada da Quantidade de Tropas
        printf("Digite a quantidade inicial de tropas: ");
        if (scanf("%d", &mapa[i].tropas) != 1) {
            printf("Erro na leitura das tropas. Encerrando.\n");
            return 1;
        }

        printf("\n"); // Linha em branco para melhor usabilidade
    }

    // -------------------------------------------------------------------------
    // ETAPA 2: EXIBIÇÃO DOS DADOS
    // -------------------------------------------------------------------------

    printf("==========================================\n");
    printf("     DADOS DOS TERRITÓRIOS CADASTRADOS\n");
    printf("==========================================\n");

    // Laço 'for' para percorrer o vetor e exibir as informações cadastradas
    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  Nome:   %s\n", mapa[i].nome);
        printf("  Cor:    %s\n", mapa[i].cor);
        printf("  Tropas: %d\n", mapa[i].tropas);
        printf("------------------------------------------\n"); // Separador
    }

    printf("Cadastro e exibicao concluidos com sucesso!\n");
    
    return 0; // Indica que o programa terminou com sucesso
}