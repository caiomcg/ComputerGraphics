# TI-2
Pipeline Gráfico

## Menu

* [Introdução](#introdução)
* [Etapas do pipeline](#etapas-do-pipeline)

---

## Introdução

O objetivo do projeto consiste na implementação de um pipeline gráfico completo. O projeto está escrito
na linguagem C++ e todo o seu código fonte pode ser encontrado na pasta TI-2 deste repositório.

O pipeline é uma série de passos que devem ser tomados para que uma cena possa ser levada do espaço 
do ```objeto``` para o espaço da ```tela``` - **Figura 1**. Abaixo veremos todas as etapas do pipeline.

<p align="center">
	<br>
	<img src="./screenshots/pipeline.png"/ width=600px height=200px>
	<h5 align="center">Figura 1 - Imagem retirada dos slides da aula 5 - Introduction to the Graphics Pipeline</h5>
	<br>
</p>

---

### Etapas do pipeline

#### Espaço do objeto para o espaço do universo

A primeira etapa do pipeline leva os objetos para o universo da cena, para tal
são usadas operações elementares que podem ser representadas como matrizes, dentre
estas operações podemos citar: escala, shear, translação e rotação. Portanto ao 
aplicarmos estas operações em nosso objeto colocamos o mesmo em função do eixo que 
representa o universo. A união de n matrizes distintas é denominada matriz model.





### Referências
