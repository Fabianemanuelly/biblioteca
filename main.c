#include <stdio.h>
#include "cliente.h"
#include "livro.h"

/**
 * @enum OpcoesMenu
 * @brief Define constantes nomeadas para as opções do menu principal do sistema.
 *
 * Este enum é utilizado para tornar o código mais legível e semântico,
 * substituindo números "mágicos" por nomes descritivos. Cada constante representa
 * uma ação disponível no menu, com valores inteiros associados.
 * Isso facilita a manutenção do código e melhora sua clareza.
 */
enum OpcoesMenu {
    SAIR = 0,              /**< Encerra o programa. */
    CADASTRAR_CLIENTE = 1, /**< Chama a função para cadastrar um cliente. */
    CADASTRAR_LIVRO,       /**< Chama a função para cadastrar um livro. */
    EMPRESTAR_LIVRO,       /**< Chama a função para emprestar um livro. */
    LISTAR_CLIENTES,       /**< Chama a função para listar todos os clientes. */
    LISTAR_LIVROS,         /**< Chama a função para listar todos os livros. */
    RENOVAR_LIVRO,         /**< Chama a função para renovar um empréstimo. */
    DEVOLVER_LIVRO         /**< Chama a função para devolver um livro emprestado. */
};


/**
 * @brief Função principal que exibe o menu e gerencia as operações do sistema.
 *
 * A função principal exibe um menu de opções para o usuário, permitindo que ele
 * escolha diferentes ações como cadastrar clientes, livros, emprestar livros,
 * listar clientes e livros, renovar empréstimos, devolver livros ou sair do sistema.
 * A escolha do usuário é lida e a ação correspondente é executada.
 *
 * @return Retorna 0 quando o programa termina.
 */
int main() {
    int opcao; /**< Variável que armazena a opção escolhida pelo usuário. */

    // Laço que mantém o menu em execução até o usuário escolher a opção de sair (opção 10).
    do {
        // Exibe o menu de opções
        printf("\n=====================================\n");
        printf("         MENU DE OPCOES\n");
        printf("=====================================\n");
        printf("  1. Cadastrar cliente\n");
        printf("  2. Cadastrar livro\n");
        printf("  3. Emprestar livro\n");
        printf("  4. Listar clientes\n");
        printf("  5. Listar livros\n");
        printf("  6. Renovar emprestimo\n");
        printf("  7. Devolver livro\n");
        printf("  0. Sair\n");
        printf("=====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); /**< Lê a opção escolhida pelo usuário. */

        // Verifica a opção escolhida e chama a função correspondente
        switch(opcao) {
            case CADASTRAR_CLIENTE:
                cadastrarCliente(); /**< Chama a função para cadastrar um cliente. */
                break;
            case CADASTRAR_LIVRO:
                cadastrarLivro();   /**< Chama a função para cadastrar um livro. */
                break;
            case EMPRESTAR_LIVRO:
                emprestarLivro();   /**< Chama a função para emprestar um livro. */
                break;
            case LISTAR_CLIENTES:
                listarClientes();   /**< Chama a função para listar todos os clientes cadastrados. */
                break;
            case LISTAR_LIVROS:
                listarLivros();     /**< Chama a função para listar todos os livros cadastrados. */
                break;
            case RENOVAR_LIVRO:
                renovarLivro();     /**< Chama a função para renovar o empréstimo de um livro. */
                break;
            case DEVOLVER_LIVRO:
                devolverLivro();    /**< Chama a função para devolver um livro emprestado. */
                break;
            case SAIR:
                printf("Saindo...\n"); /**< Mensagem de saída do sistema. */
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != SAIR); /**< O loop continua até o usuário escolher a opção de sair. */

    return 0;              /**< Retorna 0 indicando que o programa terminou com sucesso. */
}