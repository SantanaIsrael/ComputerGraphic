![Badge em Desenvolvimento](http://img.shields.io/static/v1?label=STATUS&message=%20CONCLUIDO&color=blue&style=for-the-badge)
<p>

# Computer Graphic

### Desenvolvedores

|[<img loading="lazy" src="https://github.com/user-attachments/assets/7f416696-b9c6-4b16-88a2-ada81d06b1e3" width=70><br><sub>Israel Santana</sub>](https://github.com/SantanaIsrael)<p> | [<img loading="lazy" src="https://github.com/user-attachments/assets/fe61249e-cab9-459c-9aa5-873cf4820d94" width=70><br><sub>Adrielle Maria</sub>](https://github.com/AdrielleQueiroz) |

> Aqui serão hospedados todos os código que vão ser desenvolvidos ao longo do projeto.</br>

## Prática 1: 

### 🔨 ALGUMAS EXIGÊNCIAS

- Todos os códigos vão ser desenvolvidos para rodar no sistema operacional linux
- Apresentar duas imagens de saída
- Duas imagens de entrada
- Deve ser possivél  adicionar o percentual de erro
- O algoritmo tem três arquivos de saída no formato .ppm(preto e branco), .pgm(colorido com background preto) e .ppm(monocromatico)

*Como nosso código funciona:*

`fpin, fpin2, fpout, fpoutR, fpoutG, fpoutB` - Ponteiros de arquivo para manipular vários arquivos de imagem (entrada, saída, vermelho, verde, azul).

`imagemR, imagemG, imagemB` - Três arrays bidimensionais de inteiros para armazenar os valores dos canais vermelho, verde e azul da imagem, respectivamente.

`ncol, nlin` - Inteiros para armazenar o número de colunas e linhas (altura) da imagem.

`quant_nivel_cinza` - Inteiro para armazenar o valor máximo de intensidade (nível de quantização) para os pixels da imagem.


**void segmentar_imagemColor()**

O código segmentar_imagemColor é bastante similar ao segmentar_imagem, com a principal diferença sendo que, em vez de preencher as áreas de movimento com a média de luminosidade, ele as preenche com a cor original da imagem 1.

Algoritmo:
1. Percorre cada pixel das imagens imagem1 e imagem2.
2. Para cada pixel, calcula a diferença absoluta entre os valores RGB correspondentes nas duas imagens.
3. Se a soma das diferenças absolutas for maior que um valor de percentual_erro pré-definido, considera-se que há movimento naquele pixel.
4. Se houver movimento:
    - Define os valores RGB do pixel de resultado como os valores RGB correspondentes da imagem 1 (cor original).
5. Se não houver movimento, define os valores RGB do pixel de resultado como 0 (preto).

**void segmentar_imagem()**

O código segmentar_imagem também compara duas imagens pixel por pixel e determina se há movimento entre elas. No entanto, ao invés de simplesmente registrar a presença ou ausência de movimento, este código calcula a média de luminosidade da área de movimento e a utiliza para segmentar a imagem.

Algoritmo:
1. Percorre cada pixel das imagens imagem1 e imagem2.
2. Para cada pixel, calcula a diferença absoluta entre os valores RGB correspondentes nas duas imagens.
3. Se a soma das diferenças absolutas for maior que um valor de percentual_erro pré-definido, considera-se que há movimento naquele pixel.
4. Se houver movimento:
    - Calcula a média de luminosidade (R, G e B) da área de movimento ('monocormático').
    - Define os valores RGB do pixel de resultado como a média de luminosidade calculada.
5. Se não houver movimento, define os valores RGB do pixel de resultado como 0 (preto).

**void subtrair_imagens()**

O código subtrair_imagens compara duas imagens pixel por pixel e determina se há movimento entre elas. Se houver movimento, a função registra o movimento como branco (255 para cada canal RGB). Se não houver movimento, a função registra o pixel como preto (0 para cada canal RGB)

Algoritmo:
1. Percorre cada pixel das imagens imagem1 e imagem2.
2. Para cada pixel, calcula a diferença absoluta entre os valores RGB correspondentes nas duas imagens.
3. Se a soma das diferenças absolutas for maior que um valor de percentual_erro pré-definido, considera-se que há movimento naquele pixel.
4. Se houver movimento, define os valores RGB do pixel de resultado como 255 (branco).
5. Se não houver movimento, define os valores RGB do pixel de resultado como 0 (preto).

> [!CAUTION]
> O código assume que as imagens imagem1 e imagem2 têm o mesmo tamanho (mesmo número de linhas e colunas).
> O código não leva em consideração o movimento de objetos dentro da cena. Ele apenas detecta se as imagens como um todo são diferentes.

> [!TIP]
> O valor de percentual_erro determina a sensibilidade da detecção de movimento. Um valor menor resultará em uma detecção mais precisa, mas também pode gerar falsos positivos em áreas com ruído ou pequenas diferenças de iluminação.
