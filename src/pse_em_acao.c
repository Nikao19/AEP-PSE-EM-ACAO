#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int codigo;
    char escola[100];
    char tema[80];
    char data[11];
    char publico[80];
    char responsavel[100];
    int qtdPrevista;
    int situacao;
    int qtdEfetiva;
} Acao;

void cadastrar(Acao v[], int *total);
void listar(Acao v[], int total);
void pesquisar(Acao v[], int total);
void atualizar(Acao v[], int total);
void resumo(Acao v[], int total);

int main() {
    Acao acoes[MAX];
    int total = 0;
    int opcao;

    do {
        system("clear || cls");
        printf("=== PSE EM ACAO ===\n");
        printf("1. Cadastrar Acao\n");
        printf("2. Listar Acoes\n");
        printf("3. Pesquisar (Codigo, Escola ou Tema)\n");
        printf("4. Atualizar Situacao\n");
        printf("5. Gerar Resumo\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\nOpcao invalida!\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrar(acoes, &total);
                break;
            case 2:
                listar(acoes, total);
                break;
            case 3:
                pesquisar(acoes, total);
                break;
            case 4:
                atualizar(acoes, total);
                break;
            case 5:
                resumo(acoes, total);
                break;
            case 6:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao inexistente!\n");
        }

        if (opcao != 6) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcao != 6);

    return 0;
}

void cadastrar(Acao v[], int *total) {
    if (*total >= MAX) {
        printf("\nLimite atingido!\n");
        return;
    }

    Acao nova;

    printf("\n--- CADASTRAR ---\n");
    printf("Codigo: ");
    scanf("%d", &nova.codigo);
    while (getchar() != '\n'); // <-- LIMPA O ENTER DO SCANF

    for (int i = 0; i < *total; i++) {
        if (v[i].codigo == nova.codigo) {
            printf("\nCodigo ja cadastrado!\n");
            return;
        }
    }

    printf("Escola: ");
    fgets(nova.escola, sizeof(nova.escola), stdin);
    nova.escola[strcspn(nova.escola, "\n")] = '\0';

    printf("Tema: ");
    fgets(nova.tema, sizeof(nova.tema), stdin);
    nova.tema[strcspn(nova.tema, "\n")] = '\0';

    printf("Data (DD/MM/AAAA): ");
    fgets(nova.data, sizeof(nova.data), stdin);
    nova.data[strcspn(nova.data, "\n")] = '\0';

    // AQUI ESTAVA O PROBLEMA: Se a data ou o campo anterior deixou um '\n', o fgets abaixo pulava.
    printf("Publico-alvo: ");
    fgets(nova.publico, sizeof(nova.publico), stdin);
    nova.publico[strcspn(nova.publico, "\n")] = '\0';

    printf("Responsavel: ");
    fgets(nova.responsavel, sizeof(nova.responsavel), stdin);
    nova.responsavel[strcspn(nova.responsavel, "\n")] = '\0';

    printf("Quantidade prevista: ");
    scanf("%d", &nova.qtdPrevista);
    while (getchar() != '\n'); // <-- LIMPA O ENTER DO SCANF

    nova.situacao = 1;
    nova.qtdEfetiva = 0;

    v[*total] = nova;
    (*total)++;

    printf("\nCadastrado com sucesso!\n");
}

void listar(Acao v[], int total) {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada.\n");
        return;
    }

    printf("\n--- LISTA DE ACOES ---\n");
    for (int i = 0; i < total; i++) {
        printf("\nCodigo: %d\n", v[i].codigo);
        printf("Escola: %s\n", v[i].escola);
        printf("Tema: %s\n", v[i].tema);
        printf("Data: %s | Publico: %s\n", v[i].data, v[i].publico);
        printf("Responsavel: %s\n", v[i].responsavel);
        printf("Qtd Prevista: %d\n", v[i].qtdPrevista);
        
        printf("Situacao: ");
        if (v[i].situacao == 1) printf("Planejada\n");
        else if (v[i].situacao == 2) {
            printf("Realizada\n");
            printf("Qtd Efetiva: %d\n", v[i].qtdEfetiva);
        }
        else if (v[i].situacao == 3) printf("Cancelada\n");
        
        printf("------------------------\n");
    }
}

void pesquisar(Acao v[], int total) {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada.\n");
        return;
    }

    int tipo;
    printf("\nPesquisar por:\n");
    printf("1. Codigo\n");
    printf("2. Escola\n");
    printf("3. Tema\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &tipo);
    while (getchar() != '\n');

    int encontrado = 0;

    if (tipo == 1) {
        int codBusca;
        printf("Digite o codigo: ");
        scanf("%d", &codBusca);
        while (getchar() != '\n');

        for (int i = 0; i < total; i++) {
            if (v[i].codigo == codBusca) {
                printf("\n[Encontrado] Codigo: %d | Escola: %s | Tema: %s\n", v[i].codigo, v[i].escola, v[i].tema);
                encontrado = 1;
                break;
            }
        }
    } else if (tipo == 2 || tipo == 3) {
        char termo[100];
        printf("Digite o texto da busca: ");
        fgets(termo, sizeof(termo), stdin);
        termo[strcspn(termo, "\n")] = '\0';

        printf("\n--- RESULTADOS DA PESQUISA ---\n");
        for (int i = 0; i < total; i++) {
            int match = 0;
            if (tipo == 2 && strstr(v[i].escola, termo) != NULL) match = 1;
            if (tipo == 3 && strstr(v[i].tema, termo) != NULL) match = 1;

            if (match) {
                printf("Codigo: %d | Escola: %s | Tema: %s\n", v[i].codigo, v[i].escola, v[i].tema);
                encontrado = 1;
            }
        }
    } else {
        printf("\nOpcao de pesquisa invalida.\n");
        return;
    }

    if (!encontrado) {
        printf("\nNenhum registro encontrado com esses dados.\n");
    }
}

void atualizar(Acao v[], int total) {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada.\n");
        return;
    }

    int codigoBusca;
    printf("\nDigite o codigo da acao para atualizar: ");
    scanf("%d", &codigoBusca);
    while (getchar() != '\n');

    int pos = -1;
    for (int i = 0; i < total; i++) {
        if (v[i].codigo == codigoBusca) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nAcao nao encontrada!\n");
        return;
    }

    printf("Nova situacao (1-Planejada, 2-Realizada, 3-Cancelada): ");
    int novaSit;
    scanf("%d", &novaSit);
    while (getchar() != '\n');

    if (novaSit < 1 || novaSit > 3) {
        printf("\nSituacao invalida!\n");
        return;
    }

    v[pos].situacao = novaSit;

    if (novaSit == 2) {
        printf("Quantidade efetiva de participantes: ");
        scanf("%d", &v[pos].qtdEfetiva);
        while (getchar() != '\n');
    } else {
        v[pos].qtdEfetiva = 0;
    }

    printf("\nAtualizado com sucesso!\n");
}

void resumo(Acao v[], int total) {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada.\n");
        return;
    }

    int planejadas = 0, realizadas = 0, canceladas = 0;
    int totalPrevisto = 0, totalEfetivo = 0;

    for (int i = 0; i < total; i++) {
        if (v[i].situacao == 1) planejadas++;
        else if (v[i].situacao == 2) {
            realizadas++;
            totalPrevisto += v[i].qtdPrevista;
            totalEfetivo += v[i].qtdEfetiva;
        }
        else if (v[i].situacao == 3) canceladas++;
    }

    float percentual = 0;
    if (totalPrevisto > 0) {
        percentual = ((float)totalEfetivo / totalPrevisto) * 100;
    }

    printf("\n=== RESUMO GERAL ===\n");
    printf("Total de Acoes: %d\n", total);
    printf("Planejadas: %d\n", planejadas);
    printf("Realizadas: %d\n", realizadas);
    printf("Canceladas: %d\n", canceladas);
    printf("Participantes Efetivos: %d\n", totalEfetivo);
    printf("Percentual de Atendimento: %.2f%%\n", percentual);
}