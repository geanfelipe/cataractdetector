# Cataract  detector

Trabalho para a nota final da disciplina de ITP/PTP da UFRN.



### O que é o projeto
O projeto foi desenvolvido com o objetivo de detectar o grau de catarata a partir da leitura de uma imagem do tipo PPM. 
  

### Clone, instalação e execução

Tenha a versão mais recente do gcc.

Clone o projeto e execute.

```sh
$ git clone https://github.com/geanfelipe/cataractdetector.git
$ cd cataractdetector 
$ make
$ ./catarata -i imagem.ppm -f format
```
 Os resultados das imagens estão no diretório "result".
```sh
$ eog images/result/binary.ppm
```
### Requisitos atendidos
Dos requisitos totais, os atendidos nesse projeto foram:
 -   transformação em escala de cinza
 -   filtro gaussiano
-   binarização

### Autores
* [Gean Felipe (geanfelipemoura@gmail.com)](mailto:geanfelipemoura@gmail.com)

### Créditos
Para a realização desse trabalho foram utilizados as seguintes fontes:
* [Processamento de imagens: Detecção de bordas](https://rhaylsonsilva.wordpress.com/2012/03/02/processamento-de-imagens-deteccao-de-bordas-de-imagens/)
* [Imagem Digital](http://webserver2.tecgraf.puc-rio.br/~mgattass/cg/pdf/03_ImagemDigital.pdf)
* [FORMATOS DE IMAGEM](http://disciplinas.ist.utl.pt/~leic-cg.daemon/textos/livro/Formatos%20de%20Imagem.pdf)
* [SUAVIZAÇÃO DE IMAGENS](http://www2.ic.uff.br/~aconci/suavizacao.pdf)
* [FILTRAGEM ESPACIAL](http://www.facom.ufu.br/~backes/gsi058/Aula06-FiltragemEspacial.pdf)
* [Trabalho 2 – Fundamentos de computação Gráfica](https://webserver2.tecgraf.puc-rio.br/~mgattass/fcg/trb11/Renato_Prado/t2.pdf)
* [Suavização por Média, Mediana, Gaussiana e Difusão Anisotrópica](https://www.youtube.com/watch?v=0x9sw5YAero&list=PL00D7F0634B35FA27&index=22)
