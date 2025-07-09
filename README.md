# Third Person Tower Defense

**Um jogo de tower defense onde o jogador pode defender o seu território indo para o campo de batalha!**

## Autores

- Pedro Lubaszewski Lima
- Thiago Frazzon Arend

## Data de Conclusão:

Julho, 2025

## Sumário:

- [Contribuições de cada Autor](#contribui%C3%A7%C3%B5es-de-cada-autor)
- [Uso de Inteligência Artificial](#uso-de-intelig%C3%AAncia-artificial)
- [Instalação](#instala%C3%A7%C3%A3o)
- [Funcionamento da Aplicação](#funcionamento-da-aplica%C3%A7%C3%A3o)
- [Conceitos de Fundamentos de Computação Gráfica Aplicados](#conceitos-de-fundamentos-de-computa%C3%A7%C3%A3o-gr%C3%A1fica-aplicados)

## Contribuições de cada Autor:

- **Seleção/importação de texturas e criação do cenário (paredes e estrada):** Thiago Arend
- **Seleção/importação dos modelos com texturas para o tanque, a torre, os balões e os tufos de grama:** Pedro Lima
- **Modelos de iluminação:** Pedro Lima
- **Todos os testes de colisão:** Thiago Arend
- **Movimentação dos balões:** Pedro Lima
- **Loop de gameplay:** Thiago Arend
- **Movimentação do tanque:** Thiago Arend

## Uso de Inteligência Artificial:

Para este projeto, utilizou-se o Gemini para gerar o código Python presente no arquivo ```utils/flip_faces.py```, utilizado para corrigir a orientação das faces de alguns modelos. Além disso, o ChatGPT foi usado para entender e replicar o padrão de geração dos planos do cenário. Para esses usos que são mais básicos e repetitivos, esses modelos de Inteligência Artificial se desempenharam muito bem, otimizando a produtividade dos membros do projeto. Esse tipo de uso não prejudicou as experiências necessárias para o aprendizado da disciplina.

## Instalação:

Para instalar e rodar a aplicação, basta baixar os arquivos do repositório e realizar os seguintes comandos na pasta do repositório:

- Linux (GNOME):

```
make run
```

## Funcionamento da Aplicação:

Com a aplicação aberta, o jogador se depara com uma câmera fixa observando a torre, o tanque e a rua por onde os balões inimigos passarão:

![Cenário inicial do jogo](img/Fixed%20Camera.png)

Nesse contexto, tanto a torre, quanto o tanque estão com as suas vidas cheias. O jogo consiste em defender a torre atirando nos balões através do tanque. Para controlar o tanque, existem as seguintes teclas:

| Tecla | Ação |
| --- | --- |
| <kbd>←</kbd> / <kbd>↑</kbd> / <kbd>→</kbd> / <kbd>↓</kbd> | Mover o tanque na direção indicada pelas flechas. Para realizar uma curva, é necessário pressionar as teclas horizontais junto das teclas verticais. |
| <kbd>espaço</kbd> | Atirar na direção para a qual o canhão do tanque está apontado. |

Pode-se utilizar também as seguintes opções de câmera na aplicação através das teclas abaixo:

| Tecla | Ação |
| --- | --- |
| <kbd>C</kbd> | Câmera totalmente livre, controlada por <kbd>W</kbd> / <kbd>A</kbd> / <kbd>S</kbd> / <kbd>D</kbd> e pela direção apontada pelo arraste do mouse (através do botão esquerdo do mouse). |
| <kbd>V</kbd> | Câmera em terceira pessoa sobre o tanque. |
| <kbd>B</kbd> | Câmera fixa sobre todo o cenário. |

Ao selecionar a câmera em terceira pessoa, logo após disparar um tiro, obtém-se a seguinte visão do jogo:

![Câmera em Terceira Pessoa](img/Tank%20Shooting.png)

Como visto pelas figuras acima, há uma certa pontuação registrada. Cada balão inflige uma quantidade de dano distinta e também pontua de forma distinta. Ao atingir um certo valor de pontuação, o jogador vence o jogo:

![Tela de Vitória](img/You%20Win.png)

Caso a vida da torre chegue a zero, o jogo é perdido:

![Tela de Derrota](img/Game%20Over.png)

Caso queira sair do jogo à qualquer momento, basta pressionar a tecla <kbd>ESC</kbd>.

## Conceitos de Fundamentos de Computação Gráfica Aplicados:

