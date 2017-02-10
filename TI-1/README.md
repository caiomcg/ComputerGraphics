# TI-1
Algoritmos de rasterização

---

## Introdução

O objetivo do projeto consiste na implementação de algoritmos para a renderização de pontos e linhas. O projeto será escrito
na linguagem C++ e todo o seu código fonte pode ser encontrado na pasta TI-1 deste repositório.

---

### Rasterização de pontos

A rasterização é o processo de "escrever imagens" na tela, ou seja, é a transição da imagem do meio virtual para a sua
representação visual através do display de vídeo. Para realizar está operação devemos ativar os pixels do display com cores
específicas com o intuito de formar imagens. Os pixels são representados em uma malha ```X x Y``` onde ```X``` é a largura da
tela e ```Y``` é a altura da mesma - para uma tela Full HD temos ```1920x1080 pixels```. Para saber o local correto de desenhar
o pixel devemos calcular o offset do mesmo
