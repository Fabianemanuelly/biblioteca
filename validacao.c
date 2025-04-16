#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validacao.h"

/**
 * @brief Valida um CPF, verificando se ele possui 11 dígitos numéricos.
 *
 * A função verifica se o CPF tem exatamente 11 caracteres e se todos são números.
 *
 * @param cpf O CPF a ser validado.
 * @return Retorna 1 se o CPF for válido, 0 caso contrário.
 */
int validarCpf(char cpf[]) {
    // Verifica se o CPF tem exatamente 11 caracteres
    if (strlen(cpf) != 11) {
        return 0;
    }

    // Verifica se todos os caracteres do CPF são números
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }
    return 1; // CPF válido
}


/**
 * @brief Valida um ISBN, verificando se ele possui 13 dígitos numéricos.
 *
 * A função verifica se o ISBN tem exatamente 13 caracteres e se todos são números.
 *
 * @param isbn O ISBN a ser validado.
 * @return Retorna 1 se o ISBN for válido, 0 caso contrário.
 */
int validarIsbn(char isbn[]) {
    // Verifica se o ISBN tem exatamente 13 caracteres
    if (strlen(isbn) != 13) {
        return 0;
    }

    // Verifica se todos os caracteres do ISBN são números
    for (int i = 0; i < 13; i++) {
        if (!isdigit(isbn[i])) {
            return 0;
        }
    }
    return 1; // ISBN válido
}


/**
 * @brief Valida um número de telefone, verificando se ele possui 11 dígitos numéricos.
 *
 * A função verifica se o número de telefone tem exatamente 11 caracteres e se todos são números.
 *
 * @param telefone O telefone a ser validado.
 * @return Retorna 1 se o telefone for válido, 0 caso contrário.
 */
int validarTelefone(char telefone[]) {
    // Verifica se o telefone tem exatamente 11 caracteres
    if (strlen(telefone) != 11) {
        return 0;
    }

    // Verifica se todos os caracteres do telefone são números
    for (int i = 0; i < 11; i++) {
        if (!isdigit(telefone[i])) {
            return 0;
        }
    }
    return 1; // Telefone válido
}