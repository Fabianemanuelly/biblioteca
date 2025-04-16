#include <stdio.h>
#include <string.h>
#include "livro.h"
#include "cliente.h"
#include "validacao.h"

// Definindo um array para armazenar os livros e a variável que mantém o total de livros cadastrados
Livro livros[MAX_LIVROS];
int totalLivros = 0;


/**
 * @brief Função para cadastrar um novo livro no sistema.
 *
 * Esta função solicita ao usuário os dados do livro, como título, autor e ISBN, realiza a validação desses campos,
 * e se tudo estiver correto, adiciona o livro ao sistema.
 */
void cadastrarLivro() {
    // Verifica se há espaço para cadastrar mais livros
    if (totalLivros >= MAX_LIVROS) {
        printf("Nao ha espaco para mais livros.\n");
        return;
    }

    Livro novo_livro;

    // Solicita o título do livro
    printf("Digite o titulo do livro: ");
    while(getchar() != '\n');  // Limpa o buffer do teclado
    fgets(novo_livro.titulo, 100, stdin);
    novo_livro.titulo[strcspn(novo_livro.titulo, "\n")] = '\0';  // Remover o newline no final

    // Verifica se o título foi informado
    if (strlen(novo_livro.titulo) == 0) {
        printf("Erro: O titulo do livro e obrigatorio!\n");
        return;
    }

    // Solicita o autor do livro
    printf("Digite o autor do livro: ");
    fgets(novo_livro.autor, 100, stdin);
    novo_livro.autor[strcspn(novo_livro.autor, "\n")] = '\0';  // Remover o newline no final

    // Verifica se o autor foi informado
    if (strlen(novo_livro.autor) == 0) {
        printf("Erro: O autor do livro e obrigatorio!\n");
        return;
    }

    // Solicita o ISBN do livro e valida
    printf("Digite o ISBN do livro (somente numeros): ");
    fgets(novo_livro.isbn, 14, stdin);
    novo_livro.isbn[strcspn(novo_livro.isbn, "\n")] = '\0';  // Remover o newline no final

    // Valida o ISBN
    if (strlen(novo_livro.isbn) == 0 || !validarIsbn(novo_livro.isbn)) {
        printf("Erro: ISBN invalido! O ISBN deve conter 13 digitos numericos.\n");
        return;
    }

    // Atribui um ID único ao livro e define que ele está disponível
    novo_livro.id = totalLivros + 1;
    novo_livro.disponivel = 1;  // O livro está disponível inicialmente

    // Adiciona o livro no array de livros e incrementa o contador
    livros[totalLivros] = novo_livro;
    totalLivros++;

    // Confirma que o livro foi cadastrado com sucesso
    printf("Livro '%s' cadastrado com sucesso!\n", novo_livro.titulo);
}



/**
 * @brief Função para listar todos os livros cadastrados no sistema.
 *
 * Exibe informações sobre todos os livros, incluindo título, autor, ISBN, e seu status (disponível ou emprestado).
 */
void listarLivros() {
    // Verifica se não há livros cadastrados
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    // Exibe a lista de livros
    printf("Lista de livros:\n");
    for (int i = 0; i < totalLivros; i++) {
        Livro *livro = &livros[i];
        printf("ID: %d\n Titulo: %s\n Autor: %s\n ISBN: %s\n Status: %s\n",
               livro->id, livro->titulo, livro->autor, livro->isbn,
               livro->disponivel ? "Disponivel" : "Emprestado");

        // Se o livro está emprestado, exibe o ID do cliente que pegou
        if (!livro->disponivel) {
            for (int j = 0; j < totalClientes; j++) {
                if (clientes[j].livroEmprestadoId == livro->id) {
                    printf(" Emprestado para o cliente ID: %d\n", clientes[j].id);
                    break;
                }
            }
        }
        printf("\n");
    }
}

