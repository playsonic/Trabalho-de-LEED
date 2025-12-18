#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 10
#define SENHA "jessica"

typedef struct {
    char nome[50], turma[50], email[50] ;
    float frequencia, nota;
    int matricula;

} Aluno;

int turmaValida(char turma[]) {
    return strcmp(turma, "Programação") == 0 ||
    strcmp(turma, "Empreendedorismo") == 0 ||
    strcmp(turma, "Probabilidade") == 0 ||
    strcmp(turma, "Sistemas") == 0;
}

int pedirSenha() {
    char senha[20];
    printf("Digite a senha: ");
    scanf("%s", senha);
    return strcmp(senha, SENHA) == 0;
}

int main() {

    setlocale(LC_ALL, "PT-br" );
    Aluno alunos[MAX];
    int qtd = 0, opcao, salvarIndex = -1;

    char alunoVerificacao[50], turmaVerificacao[50];

    while (1) {
        printf("\n\nMENU DE OPÇÕES:\n\n1 - Cadastrar alunos;\n2 - Excluir um aluno;\n3 - Mostrar todos os alunos;\n4 - Mostrar dados do aluno por nome;\n5 - Mostrar dados do aluno por matrícula;\n6 - Mostrar todos os alunos de determinada turma;\n7 - Ordenar alunos pela MATRICULA;\n8 - Mostrar alunos APROVADOS;\n9 - Mostrar alunos REPROVADOS;\n10 - sair\n");

        printf("Opção: ");

        scanf("%d", &opcao);

        if (opcao == 1) {
            if (!pedirSenha()) {
                printf("Senha incorreta!\n");
                continue;
            }

            if (qtd >= MAX) {
                printf("Turma cheia! Não é possível cadastrar mais.\n");
                continue;
            }

            printf("Nome: ");
            scanf(" %[^\n]", alunos[qtd].nome);

            do {
                printf("Matrícula (00000 a 99999): ");
                scanf("%d", &alunos[qtd].matricula);
            } while (alunos[qtd].matricula < 0 || alunos[qtd].matricula > 99999);

            printf("Frequência: ");
            scanf("%f", &alunos[qtd].frequencia);

            printf("Email: ");
            scanf(" %[^\n]", alunos[qtd].email);

            do {
                printf("Email: ");
                scanf(" %[^\n]", alunos[qtd].email);

                if (strstr(alunos[qtd].email, "@") == NULL || strstr(alunos[qtd].email, ".com") == NULL) {
                    printf(">> E-mail inválido! Deve conter '@' e '.com'. Tente novamente.\n");
                }

            } while (strstr(alunos[qtd].email, "@") == NULL || strstr(alunos[qtd].email, ".com") == NULL);

            printf("Nota: ");
            scanf("%f", &alunos[qtd].nota);

            do {
                printf("Turma: ");
                scanf(" %[^\n]", alunos[qtd].turma);
            } while (!turmaValida(alunos[qtd].turma));

            int existe = 0;
            for (int i = 0; i < qtd; i++) {
                if (alunos[i].matricula == alunos[qtd].matricula) {
                    existe = 1;
                    printf("Matrícula já existe!\n");
                    break;
                }
            }

            if (!existe) {
                qtd++;
                printf("Aluno cadastrado!\n");
            }

        } else if (opcao == 3) {
            for (int i = 0; i < qtd; i++) {
                printf("%s | Mat: %05d | Freq: %.1f | Nota: %.1f | Turma: %s\n",
                       alunos[i].nome,
                       alunos[i].matricula,
                       alunos[i].frequencia,
                       alunos[i].nota,
                       alunos[i].turma);
            }

        } else if (opcao == 2) {
            if (!pedirSenha()) {
                printf("Senha incorreta!\n");
                continue;
            }

            int mat, pos = -1;
            printf("Matrícula para excluir: ");
            scanf("%d", &mat);

            for (int i = 0; i < qtd; i++) {
                if (alunos[i].matricula == mat) {
                    pos = i;
                    break;
                }
            }

            if (pos != -1) {
                for (int i = pos; i < qtd - 1; i++)
                    alunos[i] = alunos[i + 1];
                qtd--;
                printf("Aluno removido!\n");
            } else {
                printf("Matrícula não encontrada!\n");
            }

        } else if (opcao == 4) {

            //Mostrar dados do aluno por nome

            strcpy(alunoVerificacao, "");

            printf("\nInforme o nome do aluno desejado: ");

            scanf("%s", alunoVerificacao);

            if (salvarIndex == -1) {

                for (int i = 0; i < qtd; i++ ) {

                    if (strcmp(alunoVerificacao, alunos[i].nome) == 0) {

                        salvarIndex = i;
                        break;

                    } else {
                        salvarIndex = 11;
                    }
                }

            } else {

                printf("\n\n*** ALUNO NÃO ENCONTRADO! ***\n\n");
            }

            if (salvarIndex != -1 && salvarIndex != 11) {
                printf("\n***************************\n");
                printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %f%%\nTurma do aluno: %s\nE-mail do aluno: %s",
                       alunos[salvarIndex].nome, alunos[salvarIndex].matricula, alunos[salvarIndex].nota, alunos[salvarIndex].frequencia, alunos[salvarIndex].turma, alunos[salvarIndex].email);
                printf("\n***************************\n");

            }

            salvarIndex = -1;

            strcpy(alunoVerificacao, "");

        } else if (opcao == 5) {

            //Mostrar dados do aluno por matrícula

            salvarIndex = -1;

            int matriculaVerificacao = 0;

            printf("\nInforme a matrícula do aluno desejado: ");

            scanf("%d", &matriculaVerificacao);

            if (salvarIndex == -1) {

                for (int i = 0; i < qtd; i++ ) {

                    if (alunos[i].matricula == matriculaVerificacao) {

                        salvarIndex = i;
                        break;

                    } else {
                        salvarIndex = 11;
                    }
                }

            }


            if (salvarIndex != -1 && salvarIndex != 11) {
                printf("\n***************************\n");
                printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %f%%\nTurma do aluno: %s\nE-mail do aluno: %s",
                       alunos[salvarIndex].nome, alunos[salvarIndex].matricula, alunos[salvarIndex].nota, alunos[salvarIndex].frequencia, alunos[salvarIndex].turma, alunos[salvarIndex].email);
                printf("\n***************************\n");

            }

            salvarIndex = -1;

            matriculaVerificacao = 0;

        } else if (opcao == 6) {

            //Mostrar todos os alunos de determinada turma

            strcpy(turmaVerificacao, "");

            printf("\n- Programação\n- Empreendedorismo\n- Probabilidade\n- Sistemas\nDigite a Turma do aluno: ");

            scanf("%s", turmaVerificacao);

            if (turmaValida(turmaVerificacao)) {

                for (int i = 0; i < qtd; i++ ) {

                    if (strcmp(turmaVerificacao, alunos[i].turma) == 0) {

                        printf("\n***************************\n");
                        printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %f%%\nE-mail do aluno: %s",
                               alunos[i].nome, alunos[i].matricula, alunos[i].nota, alunos[i].frequencia, alunos[salvarIndex].email);
                        printf("\n***************************\n");
                    }
                }

            } else {

                printf("\n\n*** TURMA INVÁLIDA! ***\n\n");
            }


            strcpy(alunoVerificacao, "");

        }else if (opcao == 7) {
            Aluno alunos_copia[MAX];
            Aluno temporario;

            for (int i = 0; i < qtd; i++) {
                alunos_copia[i] = alunos[i];
            }

            for (int i = 0; i < qtd - 1; i++) {
                for (int j = 0; j < qtd - 1 - i; j++) {
                    if (alunos_copia[j].matricula > alunos_copia[j + 1].matricula) {
                        temporario = alunos_copia[j];
                        alunos_copia[j] = alunos_copia[j + 1];
                        alunos_copia[j + 1] = temporario;
                    }
                }
            }

            printf("\n--- Alunos em ordem de matrícula ---\n");

            for (int i = 0; i < qtd; i++) {
                printf("%d - %s | Mat: %d | Freq: %.1f | Nota: %.1f | Turma: %s | Email: %s\n",
                       i+1,
                       alunos_copia[i].nome,
                       alunos_copia[i].matricula,
                       alunos_copia[i].frequencia,
                       alunos_copia[i].nota,
                       alunos_copia[i].turma,
                       alunos_copia[i].email);
            }

        } else if (opcao == 8) {
            printf("\n--- Alunos APROVADOS ---\n");

            for (int i = 0; i < qtd; i++) {
                if (alunos[i].nota > 7 && alunos[i].frequencia > 75) {

                    printf("%s | Mat: %d | Freq: %.1f | Nota: %.1f | Turma: %s | Email: %s\n",
                           alunos[i].nome,
                           alunos[i].matricula,
                           alunos[i].frequencia,
                           alunos[i].nota,
                           alunos[i].turma,
                           alunos[i].email);
                }
            }
        } else if (opcao == 9) {
            printf("\n--- Alunos REPROVADOS ---\n");

            for (int i = 0; i < qtd; i++) {
                if (alunos[i].nota <= 7 || alunos[i].frequencia <= 75) {
                    printf("%s | Mat: %d | Freq: %.1f | Nota: %.1f | Turma: %s | Email: %s\n",
                           alunos[i].nome,
                           alunos[i].matricula,
                           alunos[i].frequencia,
                           alunos[i].nota,
                           alunos[i].turma,
                           alunos[i].email);
                }
            }
        } else if (opcao == 10) {
            printf("Programa finalizado\n");
            break;

        } else {
            printf("Opção inválida!\n");




        }
    }

    return 0;
}
