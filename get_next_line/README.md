*This project has been created as part of the 42 curriculum by dodiogo.*

# get_next_line

## Description

`get_next_line` é um projeto da 42 que consiste em implementar uma função que lê e retorna uma linha de um `file descriptor` por chamada.

```c
char	*get_next_line(int fd);
```

A função utiliza `read()` para realizar a leitura de forma incremental e um `static` para preservar os dados restantes entre chamadas.

O Bonus permite trabalhar com vários `file descriptors` simultaneamente.

## Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c
```

O `BUFFER_SIZE` pode ser alterado durante a compilação:

```bash
-D BUFFER_SIZE=1
-D BUFFER_SIZE=100
-D BUFFER_SIZE=9999
```

### Execution

```bash
./a.out
```

A função também pode ler de `stdin` utilizando:

```c
get_next_line(0);
```

## Algorithm

A implementação utiliza um `stash` para guardar os dados lidos que ainda não foram devolvidos.

```text
read() → stash → extrair linha → atualizar stash → retornar linha
```

A leitura continua até encontrar `\n` ou `EOF`.

No Bonus, cada `file descriptor` possui o seu próprio estado:

```text
stash[fd]
```

permitindo chamadas alternadas sem perder dados.

## Project Structure

### Mandatory

```text
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

### Bonus

```text
get_next_line_bonus.c
get_next_line_utils_bonus.c
get_next_line_bonus.h
```

## Tests

Foram testados:

* diferentes valores de `BUFFER_SIZE`;
* várias linhas;
* linhas maiores que o buffer;
* ficheiros vazios;
* última linha sem `\n`;
* `stdin`;
* múltiplos `file descriptors`;
* `Norminette`;
* `Valgrind`.

## Resources

* `man read`
* `man malloc`
* `man free`
* `man open`
* Subject oficial da 42 — `get_next_line`

### AI Usage

A IA foi utilizada como ferramenta de apoio para:

* compreender conceitos de C;
* estudar `read()`, `static` e `file descriptors`;
* analisar o algoritmo e a gestão do `stash`;
* identificar e corrigir erros;
* estudar e documentar o Bonus;
* rever a gestão de memória e a organização do projeto.
