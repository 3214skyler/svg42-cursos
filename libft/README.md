*Este projeto foi criado como parte do currículo da 42 por dodiogo.*
# Libft

## Descrição

A Libft é uma biblioteca em C criada como parte do currículo da 42.

O objetivo deste projeto é recriar um conjunto de funções da biblioteca padrão
da linguagem C e implementar funções utilitárias adicionais que possam ser reutilizadas
em projetos futuros da 42.

Este projeto ajuda a desenvolver uma compreensão melhor da programação em C,
gerenciamento de memória, ponteiros, strings, alocação dinâmica de memória,
ponteiros de função, descritores de arquivo e listas encadeadas.

A biblioteca é compilada como uma biblioteca estática chamada `libft.a`.

## Descrição detalhada da biblioteca

A Libft é composta por funções para manipulação de caracteres, strings,
memória, conversão de dados, saída em descritores de arquivo e listas
encadeadas.

### Funções de caracteres

- `ft_isalpha` verifica se um caractere é alfabético.
- `ft_isdigit` verifica se um caractere é um dígito.
- `ft_isalnum` verifica se um caractere é alfanumérico.
- `ft_isascii` verifica se um caractere pertence à tabela ASCII.
- `ft_isprint` verifica se um caractere é imprimível.
- `ft_toupper` converte uma letra minúscula para maiúscula.
- `ft_tolower` converte uma letra maiúscula para minúscula.ft_lstclear.c: OK!
ft_lstiter.c: OK!

### Funções de memória

- `ft_memset` preenche uma área de memória com um determinado valor.
- `ft_bzero` preenche uma área de memória com zeros.
- `ft_memcpy` copia uma área de memória para outra.
- `ft_memmove` copia uma área de memória permitindo sobreposição.
- `ft_memchr` procura um byte dentro de uma área de memória.
- `ft_memcmp` compara duas áreas de memória.
- `ft_calloc` aloca memória e inicializa a memória com zero.

### Funções de strings

- `ft_strlen` calcula o comprimento de uma string.
- `ft_strchr` procura a primeira ocorrência de um caractere.
- `ft_strrchr` procura a última ocorrência de um caractere.
- `ft_strncmp` compara duas strings até um determinado número de caracteres.
- `ft_strnstr` procura uma substring dentro de outra string.
- `ft_strdup` cria uma cópia de uma string.
- `ft_strlcpy` copia uma string respeitando o tamanho especificado.
- `ft_strlcat` concatena strings respeitando o tamanho especificado.

### Funções de conversão e manipulação

- `ft_atoi` converte uma string em um número inteiro.
- `ft_itoa` converte um número inteiro em uma string.
- `ft_substr` cria uma substring.
- `ft_strjoin` junta duas strings.
- `ft_strtrim` remove determinados caracteres do início e do final de uma string.
- `ft_split` divide uma string em várias strings utilizando um delimitador.
- `ft_strmapi` cria uma nova string aplicando uma função a cada caractere.
- `ft_striteri` aplica uma função a cada caractere da string original.

### Funções de saída

- `ft_putchar_fd` escreve um caractere em um descritor de arquivo.
- `ft_putstr_fd` escreve uma string em um descritor de arquivo.
- `ft_putendl_fd` escreve uma string seguida de uma nova linha.
- `ft_putnbr_fd` escreve um número inteiro em um descritor de arquivo.

### Listas encadeadas

A biblioteca também implementa funções para trabalhar com listas encadeadas
através da estrutura `t_list`.

A estrutura utilizada é:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```
### Funções  de listas encadeadas

- `ft_lstnew` cria um novo nó.
- `ft_lstadd_front` adiciona um nó no início da lista.
- `ft_lstsize` calcula o número de nós da lista.
- `ft_lstlast` retorna o último nó da lista.
- `ft_lstadd_back` adiciona um nó no final da lista.
- `ft_lstdelone` elimina um nó e o seu conteúdo.
- `ft_lstclear` elimina uma lista e todos os seus nós.
- `ft_lstiter` aplica uma função ao conteúdo de cada nó.
- `ft_lstmap` cria uma nova lista aplicando uma função aos conteúdos dos nós.

## Instruções

### Compilação

O projeto inclui um `Makefile` que compila todos os arquivos-fonte e cria
a biblioteca estática `libft.a`.

Para compilar a biblioteca, execute:

```bash
make
```


Isso compila os arquivos-fonte em arquivos objeto (`.o`) e depois cria a
biblioteca estática `libft.a`.

### Limpeza

Para remover os arquivos objeto criados durante a compilação:

```bash
make clean
```

Para remover os arquivos objeto e a biblioteca:

```bash
make fclean
```

Para remover a compilação anterior e reconstruir a biblioteca:

```bash
make re
```

### Utilização

Para utilizar a Libft em um programa C, inclua o cabeçalho:

```c
#include "libft.h"
```

Depois compile o programa vinculando a biblioteca:

```bash
cc main.c -L. -lft
```

A opção `-L.` indica que o compilador deve procurar a biblioteca no diretório
atual.

A opção `-lft` indica que o programa deve ser vinculado à biblioteca
`libft.a`.

Depois da compilação, o programa pode ser executado com:

```bash
./a.out
```

### Norminette

Para verificar se os arquivos seguem as regras de estilo da 42:

```bash
norminette
```
### Recursos

Os seguintes recursos foram utilizados para compreender os conceitos e verificar o comportamento esperado das funções implementadas neste projeto:

- Documentação e páginas de manual da biblioteca padrão C(`man`), especialmente `strlen`, `memcpy`, `memmove`, `strchr`, `strrchr`, `strncmp`, `strlcpy`, `strlcat`, `atoi`, `calloc`, `strdup`, e funções relacionadas.
- O PDF com o assunto 42 Libft e os requisitos do projeto.
- Documentação do compilador e mensagens de erro de `cc`.
- Norminette para verificação de conformidade com o padrão de codificação 42.
- O Libft Tester de Tripouille foi usado para testar a implementação em relação a casos extremos adicionais.
- Cadetes da segunda e terceira turma ajudaram me a entender melhor o projecto e como implementar cada ferramenta.

### Uso de IA

A inteligencia foi utilizada para aprendizado, consultoria e ajudar a identificar erros em determinadas funções e erros de norminette. 
Ela foi usada para:
- Crianção do arquivo Makefile, já que não tinha nenhum conhecimento de como criar um.
- Tradução de textos em inglês para portugues.
- Enteder melhor o que cada função fazia e como implementar.
- Criação de arquivos teste para testar cada função da Libft.

### Autor

dodiogo

42 Estudante
