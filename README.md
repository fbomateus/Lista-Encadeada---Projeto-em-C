# Lista Encadeada - Projeto em C

Este projeto consiste na implementação de uma lista encadeada em C como parte do trabalho prático para a disciplina de Estruturas de Dados. O objetivo é praticar o uso de ponteiros e a manipulação de estruturas dinâmicas.

## Funcionalidades

O programa permite as seguintes operações na lista encadeada:

1. Criar uma lista vazia.
2. Inserir um elemento na lista.
3. Exibir os elementos da lista.
4. Verificar se a lista está vazia.
5. Buscar um elemento específico na lista.
6. Excluir um elemento da lista.
7. Liberar toda a lista da memória.
8. Inserir elementos na lista em ordem crescente.

## Estrutura do Projeto

```
lista-projeto/
├── .vscode/
│   ├── tasks.json           // Configuração da tarefa de compilação para VS Code
│   └── launch.json          // Configuração para depuração
├── src/
│   └── lista.c              // Arquivo principal com a implementação das funções da lista
├── build/
│   └── lista                // Executável gerado após a compilação
├── Makefile                 // Arquivo para automatizar a compilação
└── README.md                // Documentação do projeto
```

## Requisitos

- GCC (GNU Compiler Collection)
- Make

## Instalação

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/fbomateus/Lista-Encadeada---Projeto-em-C.git
   cd lista-projeto
   ```

2. **Compile o projeto**:
   ```bash
   make
   ```

3. **Execute o programa**:
   ```bash
   ./build/lista
   ```

## Uso

Após executar o programa, ele permitirá que você insira, busque, exiba, exclua e libere elementos da lista.

## Compilação e Execução no VSCode (Linux)

1. **Instale o GCC e Make**:
   ```bash
   sudo apt update
   sudo apt install build-essential
   ```

2. **Instale o Visual Studio Code**:
   Baixe o pacote `.deb` do [site oficial do VSCode](https://code.visualstudio.com/) e instale-o usando:
   ```bash
   sudo dpkg -i code_*.deb
   sudo apt --fix-broken install
   ```

3. **Abra o projeto no VSCode**:
   ```bash
   code .
   ```

4. **Instale a extensão C/C++ da Microsoft**:
   No VSCode, vá para o painel de extensões (`Ctrl + Shift + X`) e procure por "C/C++".

5. **Configurar `tasks.json` para automatizar a compilação**:
   - Pressione `Ctrl + Shift + P` e selecione `Tasks: Configure Task`.
   - Escolha `Create tasks.json file from template`.
   - Selecione `Others`.
   - Configure o `tasks.json`:
     ```json
     {
         "version": "2.0.0",
         "tasks": [
             {
                 "label": "build",
                 "type": "shell",
                 "command": "make",
                 "group": {
                     "kind": "build",
                     "isDefault": true
                 },
                 "problemMatcher": ["$gcc"],
                 "detail": "Compila o projeto usando o Makefile."
             },
             {
                 "label": "run",
                 "type": "shell",
                 "command": "./build/lista",
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [],
                 "detail": "Roda o executável compilado."
             }
         ]
     }
     ```

6. **Configurar `launch.json` para depuração**:
   - Pressione `Ctrl + Shift + D` para abrir o painel de depuração.
   - Clique em "create a launch.json file".
   - Escolha `C++ (GDB/LLDB)`.
   - Configure o `launch.json`:
     ```json
     {
         "version": "0.2.0",
         "configurations": [
             {
                 "name": "(gdb) Launch",
                 "type": "cppdbg",
                 "request": "launch",
                 "program": "${workspaceFolder}/build/lista",
                 "args": [],
                 "stopAtEntry": false,
                 "cwd": "${workspaceFolder}",
                 "environment": [],
                 "externalConsole": false,
                 "MIMode": "gdb",
                 "setupCommands": [
                     {
                         "description": "Enable pretty-printing for gdb",
                         "text": "-enable-pretty-printing",
                         "ignoreFailures": true
                     }
                 ],
                 "preLaunchTask": "build",
                 "miDebuggerPath": "/usr/bin/gdb"
             }
         ]
     }
     ```

7. **Compile e execute o projeto**:
   - Para compilar, pressione `Ctrl + Shift + B`.
   - Para executar, vá até o terminal integrado do VSCode e digite:
     ```bash
     ./build/lista
     ```

