*This project has been created as part of the 42 curriculum by dodiogo.*

# ft_printf

## Descrição

O projeto **ft_printf** consiste em recriar a função `printf()` da biblioteca padrão da linguagem C.

O objetivo principal é compreender e implementar uma função capaz de receber um número variável de argumentos e formatá-los de acordo com uma string de formato.

A função principal implementada neste projeto é:

```c
int	ft_printf(const char *format, ...);
```

A implementação reproduz as principais funcionalidades de `printf()` exigidas pelo projeto, sem utilizar a própria função `printf()`.

O projeto permite trabalhar conceitos fundamentais da linguagem C, como:

* Funções variádicas;
* `va_list`;
* `va_start`;
* `va_arg`;
* `va_end`;
* Ponteiros;
* Conversão de tipos;
* Recursividade;
* Conversão de números para diferentes bases;
* Gestão do valor de retorno;
* Criação e utilização de uma biblioteca estática (`libftprintf.a`).

## Conversões suportadas

A função implementada suporta as seguintes conversões:

| Conversão | Descrição                                              |
| --------- | ------------------------------------------------------ |
| `%c`      | Imprime um único caractere                             |
| `%s`      | Imprime uma string                                     |
| `%p`      | Imprime um endereço de memória em hexadecimal          |
| `%d`      | Imprime um número inteiro decimal                      |
| `%i`      | Imprime um número inteiro decimal                      |
| `%u`      | Imprime um número inteiro sem sinal                    |
| `%x`      | Imprime um número hexadecimal usando letras minúsculas |
| `%X`      | Imprime um número hexadecimal usando letras maiúsculas |
| `%%`      | Imprime o caractere `%`                                |

## Instruções

### Compilação

O projeto utiliza um `Makefile` para automatizar a compilação.

Para compilar a biblioteca:

```bash
make
```

Esse comando cria a biblioteca estática:

```text
libftprintf.a
```

Para remover os arquivos objeto:

```bash
make clean
```

Para remover os arquivos objeto e a biblioteca:

```bash
make fclean
```

Para recompilar completamente o projeto:

```bash
make re
```

### Utilização

Depois de compilada, a biblioteca pode ser ligada a um programa C.

Exemplo:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s!\n", "world");
	ft_printf("Number: %d\n", 42);
	ft_printf("Hexadecimal: %x\n", 255);
	return (0);
}
```

A compilação pode ser feita utilizando a biblioteca:

```bash
cc main.c -L. -lftprintf
```

Depois:

```bash
./a.out
```

## Algoritmo e estruturas de dados

### Algoritmo principal

O algoritmo utilizado por `ft_printf()` percorre a string de formato caractere por caractere.

Quando encontra um caractere normal, ele é escrito diretamente na saída utilizando `write()`.

Quando encontra `%`, a função verifica o caractere seguinte para determinar qual conversão deve ser executada.

O funcionamento pode ser representado da seguinte forma:

```text
String de formato
       |
       v
Percorrer caractere por caractere
       |
       v
    É '%'?
    /     \
  Não      Sim
  |          |
  v          v
Escrever   Ler a conversão
caractere       |
                v
          Escolher função
                |
                v
        Imprimir argumento
```

Por exemplo, para:

```c
ft_printf("Número: %d\n", 42);
```

o algoritmo percorre a string até encontrar `%`.

Ao encontrar `%`, verifica o caractere seguinte:

```text
d
```

A partir disso, chama a função responsável por imprimir um número inteiro.

### Algoritmo utilizado para `%p`

Para a conversão `%p`, o endereço do ponteiro é convertido para `unsigned long` e apresentado em hexadecimal.

O algoritmo funciona da seguinte forma:

1. Verifica se o ponteiro é `NULL`. Nesse caso, imprime `(nil)` e retorna `5`, que corresponde ao número de caracteres escritos.
2. Caso o ponteiro não seja `NULL`, converte o endereço para `unsigned long`.
3. Imprime o prefixo `0x`.
4. Utiliza uma função recursiva para converter o endereço para hexadecimal. A cada chamada, o número é dividido por `16`, permitindo processar recursivamente os dígitos mais significativos.
5. O operador `% 16` obtém o último dígito hexadecimal, que é utilizado como índice na base `"0123456789abcdef"`.
6. A função retorna a quantidade total de caracteres escritos, incluindo os dois caracteres de `0x`.

Por exemplo, um endereço pode ser representado como:

```text
0x7ffabc123
```

O algoritmo constrói a parte hexadecimal do endereço através de divisões sucessivas por `16` e da utilização dos restos dessas divisões.

### Funções variádicas

A função `ft_printf()` utiliza uma lista de argumentos variáveis através de `va_list`.

O processo é iniciado com:

```c
va_start(args, format);
```

Cada argumento necessário é obtido através de:

```c
va_arg(args, tipo);
```

Quando todos os argumentos foram processados, a lista é finalizada:

```c
va_end(args);
```

Isso permite que `ft_printf()` receba uma quantidade variável de argumentos, tal como a função original `printf()`.

### Conversão hexadecimal

Para `%x` e `%X`, foi utilizado um algoritmo baseado na divisão sucessiva por `16`.

A cada etapa:

* `n / 16` permite processar os dígitos restantes;
* `n % 16` determina o próximo dígito hexadecimal.

A base utilizada para `%x` é:

```text
0123456789abcdef
```

Enquanto `%X` utiliza:

```text
0123456789ABCDEF
```

A função é recursiva porque primeiro processa `n / 16` e somente depois imprime o resto `n % 16`.

Por exemplo, para converter `255`:

```text
255 / 16 = 15
255 % 16 = 15

15 / 16 = 0
15 % 16 = 15
```

Os restos correspondem aos dígitos:

```text
15 -> f
15 -> f
```

Resultado:

```text
ff
```

Este algoritmo foi escolhido porque é simples, direto e adequado para demonstrar a conversão de números inteiros para uma base diferente de 10.

### Estruturas de dados

O projeto não necessita de estruturas de dados complexas como listas ligadas, árvores ou tabelas hash.

A principal estrutura utilizada é a `va_list`, fornecida pela biblioteca `<stdarg.h>`, para armazenar e percorrer os argumentos variáveis recebidos por `ft_printf()`.

Também são utilizadas strings para representar as bases numéricas:

```c
"0123456789abcdef"
```

e:

```c
"0123456789ABCDEF"
```

Para o processamento da string de formato são utilizados índices inteiros, permitindo percorrer a string sequencialmente.

A escolha dessas estruturas mantém a implementação simples e adequada ao objetivo do projeto.

## Valor de retorno

Tal como `printf()`, `ft_printf()` deve retornar o número total de caracteres escritos.

Cada função de conversão retorna a quantidade de caracteres que imprimiu.

Por exemplo:

```c
ft_printchar()
```

retorna `1`, porque imprime um caractere.

Se uma string contém cinco caracteres:

```text
Hello
```

a função responsável pela string retorna `5`.

No caso de um ponteiro `NULL`, quando é impressa a representação:

```text
(nil)
```

são escritos cinco caracteres e o retorno correspondente é `5`.

O `ft_printf()` acumula esses valores numa variável `count` e retorna o total no final.

## Organização do projeto

A organização dos arquivos é:

```text
ft_printf/
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c
├── ft_printchar.c
├── ft_printstr.c
├── ft_printnumber.c
├── ft_printunsigned.c
├── ft_printhexa.c
└── ft_printpointer.c
```

A separação das diferentes conversões em funções independentes facilita a leitura, manutenção, testes e reutilização do código.

## Recursos

Durante o desenvolvimento foram consultados recursos relacionados à linguagem C, funções variádicas, saída de dados e conversão de números, incluindo:

* `printf(3)` — referência sobre o comportamento da função `printf()` e suas conversões.

* `stdarg(3)` — documentação sobre funções variádicas e utilização de `va_list`, `va_start`, `va_arg` e `va_end`.

* `write(2)` — documentação da função `write()`, utilizada para escrever os caracteres na saída padrão.

## Utilização de Inteligência Artificial

A Inteligência Artificial foi utilizada como ferramenta de apoio durante o desenvolvimento e aprendizagem do projeto.

A IA foi utilizada principalmente para:

* Explicar o funcionamento de funções variádicas;
* Compreender `va_list`, `va_start`, `va_arg` e `va_end`;
* Explicar o funcionamento das diferentes conversões de `printf()`;
* Esclarecer o funcionamento de ponteiros e da conversão `%p`;
* Compreender a conversão hexadecimal através de divisão e resto;
* Analisar a lógica de funções recursivas;
* Identificar e explicar erros lógicos no código;
* Analisar casos particulares, como ponteiros `NULL` e formatos incompletos;
* Auxiliar na revisão da organização do código e na compreensão das regras do projeto.

A IA foi utilizada principalmente como ferramenta de explicação, aprendizagem, revisão e debugging. A implementação, os testes e a compreensão final do código fazem parte do trabalho realizado no projeto.
