#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define T 10

typedef struct{
    char nome[50];
    int matricula;
    float nota;
    int frequcia;
    char turma[50];

}Alunos;


void senhaFalha(int *plimiteTentativa) {

    printf("\n\n*** SENHA INCORRETA ***\n");

    *plimiteTentativa = *plimiteTentativa + 1;

    if(*plimiteTentativa == 3){

        printf("\n*** TRÊS TENTATIVAS REALIZADAS ***\n");

        printf("\n*** RETORNANDO À TELA PRINCIPAL ***\n");
        
    }
}


int main () {

    setlocale(LC_ALL, "PT-br");

    int escolheropcao, contadorAluno = 0, limiteTentativa = 0, senha; //variaveis

    int matriculaVerificacao = -1, salvarIndex = -1, matriculaComparação = 0; //vericações do programa

    int i, j; //variaveis do loop

    char turmaVerificacao[50], alunoVerificação[50]; //vericações do programa

    int *plimiteTentativa = &limiteTentativa; //ponteiros int

    Alunos alunos[T], alunosOrdenados; //struct

    system("clear");

    do {

    printf("\n\n===== MENU DE OPÇÕES =====\n\n------\n\n1 - Cadastrar alunos;\n2 - Excluir um aluno;\n3 - Mostrar todos os alunos;\n4 - Mostrar dados do aluno por nome;\n5 - Mostrar dados do aluno por matrícula;\n6 - Mostrar todos os alunos de determinada turma;\n7 - Ordenar alunos pela MATRICULA;\n8 - Mostrar alunos APROVADOS;\n9 - Mostrar alunos REPROVADOS;\n10 - Limpar sistemas;\n11 - SAIR\n\n------\n");

    printf("\nDigite a opção desejada: ");

    scanf("%d", &escolheropcao);

    if (escolheropcao == 1) {

        //Cadastrar alunos

        // Senha para entrada de Alta Probabilidade é 123

        limiteTentativa = 0;
        *plimiteTentativa = 0;

        do {

            if(limiteTentativa < 3) {

            senha = 0;

            printf("\nDigite a senha do administrador: ");

            scanf("%d", &senha);

            if (senha == 123) {

                if (contadorAluno < T) {

                printf("\nInforme o nome do aluno: ");
                scanf("%s", alunos[contadorAluno].nome);

                printf("\nInforme a matrícula do aluno: ");
                scanf("%d", &alunos[contadorAluno].matricula);

                if (alunos[contadorAluno].matricula <= 0 || alunos[contadorAluno].matricula >= 100000) {

                    printf("\n\n*** MATRÍCULA INVÁLIDA! ***\n\n");

                    strcpy(alunos[contadorAluno].nome, "");
                    alunos[contadorAluno].matricula = -1;
                    break;

}

                    matriculaComparação = 0;

                    for (i = 0;i <contadorAluno;i++ ) {

                    if(alunos[contadorAluno].matricula == alunos[i].matricula) {

                        printf("\n\n*** MATRÍCULA JÁ CADASTRADA! ***\n\n");
                        strcpy(alunos[contadorAluno].nome, "");
                        alunos[contadorAluno].matricula = -1;
                        matriculaComparação = 1;
                        break;
                    }

                    }

                    if (matriculaComparação == 1) {

                        printf("\n\n*** ESCOLHA OUTRO NÚMERO! ***\n\n");
                        break;

                    }


                printf("\nInforme a nota do aluno (0 a 10): ");

                scanf("%f", &alunos[contadorAluno].nota);

                if (alunos[contadorAluno].nota <= -1 || alunos[contadorAluno].nota >= 11) {

                    printf("\n\n*** NOTA INVÁLIDA! ***\n\n");

                    strcpy(alunos[contadorAluno].nome, "");
                    alunos[contadorAluno].matricula = -1;
                    alunos[contadorAluno].nota = -1;
                    break;
                }

                printf("\nInforme a frequência do aluno (0 a 100): ");

                scanf("%d", &alunos[contadorAluno].frequcia);

                if (alunos[contadorAluno].frequcia < 0 || alunos[contadorAluno].frequcia > 100) {

                    printf("\n\n*** FREQUÊNCIA INVÁLIDA! ***\n\n");

                    strcpy(alunos[contadorAluno].nome, "");
                    alunos[contadorAluno].matricula = -1;
                    alunos[contadorAluno].nota = -1;
                    alunos[contadorAluno].frequcia = -1;
                    break;
                }

                strcpy(turmaVerificacao, "");

                printf("\n- Programação\n- Empreendedorismo\n- Probabilidade\n- Sistemas\n\nDigite a turma do aluno: ");
                scanf("%s", turmaVerificacao);

                if (strcmp(turmaVerificacao, "Programação") == 0 || strcmp(turmaVerificacao, "Empreendedorismo") == 0 || strcmp(turmaVerificacao, "Probabilidade") == 0 || strcmp(turmaVerificacao, "Sistemas") == 0) {

                    strcpy(alunos[contadorAluno].turma, turmaVerificacao);

                    printf("\nAluno cadastrado com sucesso!\n");

                    strcpy(turmaVerificacao, "");
                    
                    contadorAluno++;

                    break;
                } else {

                    printf("\n\n*** TURMA INVÁLIDA! ***\n\n");

                    strcpy(alunos[contadorAluno].nome, "");
                    alunos[contadorAluno].matricula = -1;
                    alunos[contadorAluno].nota = -1;
                    alunos[contadorAluno].frequcia = -1;
                    break;
                }

    } else {

        printf("\n\n*** NÚMERO MÁXIMO DE ALUNOS ATINGIDO! ***\n\n");
        break;

    }


    }   else {

        senhaFalha(plimiteTentativa);

        if(limiteTentativa == 3){

            break;
        }


    }

    }


    }while (limiteTentativa < 3);

    } else if (escolheropcao == 2) {

        //Excluir um aluno

             // Senha para entrada de Alta Probabilidade é 123

            limiteTentativa = 0;
            *plimiteTentativa = 0;
            matriculaVerificacao = -1;

            do{

                senha = 0;

                printf("\nDigite a senha do administrador: ");

                scanf("%d", &senha);

                if (senha == 123) {

                    salvarIndex = -1;

                    printf("\n\nInforme a matrícula do aluno desejado: ");

                    scanf("%d", &matriculaVerificacao);

                    for (int i = 0; i < contadorAluno; i++ ) {

                        if (alunos[i].matricula == matriculaVerificacao) {

                            salvarIndex = i;
                            break;

    }
                    }

                    if (salvarIndex != -1) {
                        for (int j = salvarIndex;j <contadorAluno;j++ ) {
                            alunos[j] = alunos[j + 1];
                        }
                        contadorAluno--;

                        matriculaVerificacao = -1;

                        printf("\nAluno excluído com sucesso.\n");

                        break;

            } else {

                printf("\n\n*** ALUNO NÃO ENCONTRADO! ***\n\n");
                break;
            }

            break;


    } else {

            senhaFalha(plimiteTentativa);


            if(limiteTentativa == 3){

            break;
        }

            }
            }while (limiteTentativa < 3);




    } else if (escolheropcao == 3) {

        //Mostrar todos os alunos

        printf("\nLista de alunos cadastrados:\n");
        for (i = 0; i < contadorAluno; i++) {
            printf("\n--------------------------\n");
            printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %d%%\nTurma do aluno: %s",
                alunos[i].nome, alunos[i].matricula, alunos[i].nota, alunos[i].frequcia, alunos[i].turma);
            printf("\n--------------------------\n");
    }

    } else if (escolheropcao == 4) {

        //Mostrar dados do aluno por nome

        salvarIndex = -1;

        strcpy(alunoVerificação, "");

        printf("\nInforme o nome do aluno desejado: ");

        scanf("%s", alunoVerificação);

        if (salvarIndex == -1) {

        for (i = 0; i < contadorAluno; i++ ) {

            if (strcmp(alunoVerificação, alunos[i].nome) == 0) {

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
                printf("\n--------------------------\n");
                printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %d%%\nTurma do aluno: %s",
                       alunos[salvarIndex].nome, alunos[salvarIndex].matricula, alunos[salvarIndex].nota, alunos[salvarIndex].frequcia, alunos[salvarIndex].turma);
                printf("\n--------------------------\n");

            }

        salvarIndex = -1;

        strcpy(alunoVerificação, "");

    } else if (escolheropcao == 5) {

        //Mostrar dados do aluno por matrícula

    salvarIndex = -1;

    matriculaVerificacao = 0;

    printf("\nInforme a matrícula do aluno desejado: ");

    scanf("%d", &matriculaVerificacao);

    if (salvarIndex == -1) {

    for (i = 0; i < contadorAluno; i++ ) {

        if (alunos[i].matricula == matriculaVerificacao) {

            salvarIndex = i;
            break;

        } else {
            salvarIndex = 11;
        }
    }

    }


    if (salvarIndex != -1 && salvarIndex != 11) {
        printf("\n--------------------------\n");
        printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %d%%\nTurma do aluno: %s",
               alunos[salvarIndex].nome, alunos[salvarIndex].matricula, alunos[salvarIndex].nota, alunos[salvarIndex].frequcia, alunos[salvarIndex].turma);
        printf("\n--------------------------\n");

    }

    salvarIndex = -1;

    matriculaVerificacao = 0;

    } else if (escolheropcao == 6) {

        //Mostrar todos os alunos de determinada turma

        strcpy(turmaVerificacao, "");

        printf("\n- Programação\n- Empreendedorismo\n- Probabilidade\n- Sistemas\n\nDigite a Turma do aluno: ");

        scanf("%s", turmaVerificacao);

        if (strcmp(turmaVerificacao, "Programação") == 0 || strcmp(turmaVerificacao, "Empreendedorismo") == 0 || strcmp(turmaVerificacao, "Probabilidade") == 0 || strcmp(turmaVerificacao, "Sistemas") == 0) {

            for (i = 0; i < contadorAluno; i++ ) {

                if (strcmp(turmaVerificacao, alunos[i].turma) == 0) {

                    printf("\n--------------------------\n");
                    printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %d%%",
                           alunos[i].nome, alunos[i].matricula, alunos[i].nota, alunos[i].frequcia);
                    printf("\n--------------------------\n");
                }
            }

        } else {

            printf("\n\n*** TURMA INVÁLIDA! ***\n\n");
        }


        strcpy(alunoVerificação, "");

    } else if (escolheropcao == 7) {

        //Ordenar alunos pela MATRICULA

            for (i = 0; i < contadorAluno ; i++ ) {

                    for (j = 0; j < contadorAluno - 1; j++) {

                        if (alunos[0].matricula > alunos[j + 1].matricula) {
                            alunosOrdenados = alunos[j];
                            alunos[j] = alunos[j + 1];
                            alunos[j + 1] = alunosOrdenados;
                        }
                    }
            }


            for (i = 0; i <contadorAluno ; i++ ) {
                printf("\n--------------------------\n");
                printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %d%%\nTurma do aluno: %s",
                       alunos[i].nome, alunos[i].matricula, alunos[i].nota, alunos[i].frequcia, alunos[i].turma);
                printf("\n--------------------------\n");


}

    } else if (escolheropcao == 8) {

        //Mostrar alunos APROVADOS

            for (i = 0; i < contadorAluno; i++ ) {

                if (alunos[i].nota >= 7.00 && alunos[i].frequcia > 75) {

                    printf("\n--------------------------\n");
                    printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %d%%\nTurma do aluno: %s",
                           alunos[i].nome, alunos[i].matricula, alunos[i].nota, alunos[i].frequcia, alunos[i].turma);
                    printf("\n--------------------------\n");
                }
            }


    } else if (escolheropcao == 9) {

        //Mostrar alunos REPROVADOS

        for (i = 0; i < contadorAluno; i++ ) {

            if (alunos[i].nota < 7.00 || alunos[i].frequcia < 75) {

                printf("\n--------------------------\n");
                printf("Nome: %s\nNúmero da matricula: %d\nNota: %.2f\nFrequência do aluno: %d%%\nTurma do aluno: %s",
                       alunos[i].nome, alunos[i].matricula, alunos[i].nota, alunos[i].frequcia, alunos[i].turma);
                printf("\n--------------------------\n");
            }
        }


    } else if (escolheropcao == 10) {

        //Limpar sistemas

       system("clear");

    } else if (escolheropcao == 11) {

        printf("Programa finalizado. Até logo!\n");
    } else if (escolheropcao < 1 || escolheropcao > 11) {

        printf("Opção inválida. Tente novamente.\n");
    }

    } while(escolheropcao != 11);

    return 0;
}
