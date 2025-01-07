# MiniMy

MiniMy é um projeto que utiliza a biblioteca OpenGL para desenhar elementos gráficos na tela, formando um personagem com diversas características personalizáveis.

## Instalação

Para compilar e executar o projeto, você precisará das bibliotecas OpenGL, GLU e GLUT. Certifique-se de que elas estão instaladas no seu sistema.

### Passos para Instalação

1. Clone este repositório:
    ```bash
    git clone https://github.com/seu-usuario/minimy.git
    cd minimy
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

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para fazer um fork do repositório e enviar pull requests.

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.