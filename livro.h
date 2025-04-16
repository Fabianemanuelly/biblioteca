#ifndef PROJETO02ORIGINAL_LIVRO_H
#define PROJETO02ORIGINAL_LIVRO_H


// Define o número máximo de livros permitidos no sistema
#define MAX_LIVROS 500

/**
 * @brief Estrutura que define as informações de um livro.
 *
 * A estrutura Livro armazena dados como o ID do livro, título, autor, ISBN e se o livro está disponível para empréstimo.
 */
typedef struct {
    int id;             /**< Identificador único do livro */
    char titulo[100];   /**< Título do livro */
    char autor[100];    /**< Autor do livro */
    char isbn[14];      /**< ISBN do livro (somente números) */
    int disponivel;     /**< Indica se o livro está disponível para empréstimo (1 - disponível, 0 - emprestado) */
} Livro;

// Declarações de variáveis externas
extern Livro livros[MAX_LIVROS];     /**< Array de livros cadastrados */
extern int totalLivros;              /**< Total de livros cadastrados no sistema */

// Declarações das funções relacionadas ao livro
void cadastrarLivro();  /**< Função para cadastrar um novo livro */
void listarLivros();    /**< Função para listar todos os livros cadastrados */



#endif //PROJETO02ORIGINAL_LIVRO_H
