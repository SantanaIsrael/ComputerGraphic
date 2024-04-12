# Computer Graphic

Aqui vão ser hospedados todos os códigos que voão ser desenvolvidos ao longo da disciplina.

ALGUMAS EXIGÊNCIAS

- Todos os códigos vão ser desenvolvidos para rodar no sistema operacional linux
- Deve ser possivel separa o arquivo de imagem em três matrizes RGB (opcional)
- O algoritmo tem três arquivos de saída no formato .ppm(preto e branco), .pgm(colorido com background preto) e .ppm(monocromatico)


`fpin, fpin2, fpout, fpoutR, fpoutG, fpoutB`: Ponteiros de arquivo para manipular vários arquivos de imagem (entrada, saída, vermelho, verde, azul).
`imagemR, imagemG, imagemB`: Três arrays bidimensionais de inteiros para armazenar os valores dos canais vermelho, verde e azul da imagem, respectivamente.
`ncol, nlin`: Inteiros para armazenar o número de colunas e linhas (altura) da imagem.
`quant_nivel_cinza`: Inteiro para armazenar o valor máximo de intensidade (nível de quantização) para os pixels da imagem.

**void segmentar_imagemColor()**

Este código é uma função de segmentação de imagem que compara duas imagens pixel a pixel. 

# Aqui está um resumo do que ele faz:

1. Ele percorre cada pixel das imagens.
2. Para cada pixel, ele calcula a diferença total dos canais RGB (Red, Green, Blue) das duas imagens.
3. Se essa diferença total for maior que um certo valor de erro percentual (percentual_erro), ele calcula a média de luminosidade para cada imagem (média dos valores RGB) e subtrai a média da segunda imagem da primeira. O resultado é armazenado nas matrizes segmentadaR, segmentadaG e segmentadaB.
4. Se a diferença total não for maior que o erro percentual, ele atribui 0 (preto) aos canais RGB da imagem segmentada.

Em resumo, esta função destaca as diferenças entre duas imagens ao subtrair a luminosidade média dos pixels que diferem mais do que um certo limite. Os pixels que não diferem o suficiente são definidos como preto na imagem de saída. Isso pode ser útil para identificar alterações entre duas imagens.

**void abrir_arquivos()**

Este código é uma função de segmentação de imagem que compara duas imagens pixel a pixel. Aqui está um resumo do que ele faz:

1. Ele percorre cada pixel das imagens.
2. Para cada pixel, ele calcula a diferença total dos canais RGB (Red, Green, Blue) das duas imagens.
3. Se essa diferença total for maior que um certo valor de erro percentual (`percentual_erro`), ele subtrai os valores RGB da segunda imagem dos da primeira e adiciona 255/2 (para manter os valores dentro do intervalo de 0 a 255). O resultado é armazenado nas matrizes segmentadaR, segmentadaG e segmentadaB.
4. Se a diferença total não for maior que o erro percentual, ele atribui 0 (preto) aos canais RGB da imagem segmentada.

Em resumo, esta função destaca as diferenças entre duas imagens ao subtrair os valores RGB dos pixels que diferem mais do que um certo limite e adicionando um offset para manter os valores dentro do intervalo válido. Os pixels que não diferem o suficiente são definidos como preto na imagem de saída. Isso pode ser útil para identificar alterações entre duas imagens. 

**void subtrair_imagens()**

Este código é uma função que subtrai os valores dos canais RGB (Red, Green, Blue) de duas imagens pixel a pixel. Aqui está um resumo do que ele faz:

1. Ele percorre cada pixel das imagens.
2. Para cada pixel, ele calcula a diferença total dos canais RGB das duas imagens.
3. Se essa diferença total for maior que um certo valor de erro percentual (`percentual_erro`), ele atribui o valor máximo de um canal de cor (225) aos canais RGB da imagem resultante. Isso pode indicar uma mudança significativa ou movimento entre as duas imagens.
4. Se a diferença total não for maior que o erro percentual, ele atribui 0 (preto) aos canais RGB da imagem resultante. Isso indica que não houve mudança significativa ou movimento entre as duas imagens nesses pixels.

Em resumo, esta função é usada para detectar mudanças ou movimentos entre duas imagens ao subtrair os valores RGB dos pixels e comparar o resultado com um limite de erro. As mudanças são destacadas na imagem de saída com a cor branca (RGB 225,225,225), enquanto as áreas sem mudanças são representadas em preto (RGB 0,0,0).