# MiniMy

MiniMy é um projeto que utiliza a biblioteca OpenGL para desenhar elementos gráficos na tela, formando um personagem com diversas características personalizáveis.

## Contribuição

Este projeto foi desenvolvido por: 

|[<img loading="lazy" src="https://github.com/user-attachments/assets/7f416696-b9c6-4b16-88a2-ada81d06b1e3" width=70><br><sub>Israel Santana</sub>](https://github.com/SantanaIsrael)<p> | [<img loading="lazy" src="https://github.com/user-attachments/assets/fe61249e-cab9-459c-9aa5-873cf4820d94" width=70><br><sub>Adrielle Maria</sub>](https://github.com/AdrielleQueiroz) |

## Instalação

Para compilar e executar o projeto, você precisará das bibliotecas OpenGL, GLU e GLUT. Certifique-se de que elas estão instaladas no seu sistema.

### Passos para Instalação

1. Clone este repositório:
    ```bash
    git clone https://github.com/SantanaIsrael/ComputerGraphic/tree/main/MyPersona
    cd MyPersona
    ```

2. Compile o projeto:
    ```bash
    gcc -o myPersona myPersona.c -lGL -lGLU -lglut -lm
    ```

3. Execute o projeto:
    ```bash
    ./myPersona
    ```

## Uso

Após executar o projeto, você verá uma janela onde poderá interagir com o personagem utilizando o teclado para alterar suas características:

- `Cabelo`: teclas `b` a `m`
- `Sapato`: teclas `z` a `x`
- `Olho`: teclas `1` a `7`
- `Nariz`: teclas `Q` a `e`
- `Boca`: teclas `a` a `f`