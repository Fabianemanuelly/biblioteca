cmake_minimum_required(VERSION 3.27)
project(projeto02ORIGINAL C)

set(CMAKE_C_STANDARD 11)

add_executable(projeto02ORIGINAL main.c
        cliente.c
        cliente.h
        livro.c
        livro.h
        validacao.c
        validacao.h)
