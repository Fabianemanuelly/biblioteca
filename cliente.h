#ifndef PROJETO02ORIGINAL_CLIENTE_H
#define PROJETO02ORIGINAL_CLIENTE_H


// Inclui a biblioteca time.h para trabalhar com datas e horas
#include <time.h>

// Define o número máximo de clientes permitidos no sistema
#define MAX_CLIENTES 1000

/**
 * @brief Estrutura que define as informações de um cliente.
 *
 * A estrutura Cliente armazena dados como o ID do cliente, nome, CPF, endereço, telefone,
 * o ID do livro emprestado, as datas de empréstimo e devolução, e o valor da multa de atraso.
 */
typedef struct {
    int id;                 /**< Identificador único do cliente */
    char nome[100];         /**< Nome completo do cliente */
    char cpf[15];           /**< CPF do cliente (somente números) */
    char endereco[200];     /**< Endereço do cliente */
    char telefone[15];      /**< Telefone do cliente (somente números, incluindo o DDD) */
    int livroEmprestadoId;  /**< ID do livro emprestado (-1 se não houver livro emprestado) */
    time_t dataEmprestimo;  /**< Data e hora do empréstimo do livro */
    time_t dataDevolucao;   /**< Data e hora da devolução prevista do livro */
    double multa;           /**< Valor da multa caso o livro não seja devolvido no prazo */
} Cliente;

// Declarações de variáveis externas
extern Cliente clientes[MAX_CLIENTES]; /**< Array de clientes cadastrados */
extern int totalClientes;              /**< Total de clientes cadastrados no sistema */

// Declarações das funções relacionadas ao cliente
void cadastrarCliente();    /**< Função para cadastrar um novo cliente */
void listarClientes();      /**< Função para listar todos os clientes cadastrados */
void emprestarLivro();      /**< Função para emprestar um livro a um cliente */
void renovarLivro();        /**< Função para renovar o empréstimo de um livro */
void devolverLivro();       /**< Função para devolver um livro emprestado */



#endif //PROJETO02ORIGINAL_CLIENTE_H
