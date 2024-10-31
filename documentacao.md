# Simulação de Semáforo com Arduino

Este projeto simula o funcionamento de um semáforo utilizando uma placa Arduino Uno, LEDs, resistores e uma protoboard. O objetivo é alternar entre as fases de um sinal de trânsito, seguindo os tempos típicos de cada cor: vermelho, amarelo e verde.

## Lógica do Semáforo

A lógica do semáforo foi programada em Arduino para funcionar da seguinte forma:

- **Fase Vermelho**: 6 segundos para interromper o tráfego.
- **Fase Amarelo**: 2 segundos para alertar que o sinal vai mudar.
- **Fase Verde**: 2 segundos para liberar o tráfego.
- **Fase Verde Adicional**: mais 2 segundos com o LED verde aceso, simulando um tempo extra para pedestres concluírem a travessia.
- **Fase Amarelo (final)**: 2 segundos antes de voltar ao vermelho.

Para implementar essa sequência, o código utiliza a função `millis()`, que permite controlar o tempo de cada fase sem pausar o Arduino, possibilitando que ele continue monitorando o estado do semáforo continuamente.

## Componentes e Montagem

- **LEDs**: Foram utilizados três LEDs – vermelho, amarelo e verde – conectados aos pinos 8, 9 e 10 do Arduino, representando cada fase do semáforo.
- **Resistores**: Cada LED tem um resistor em série para limitar a corrente, protegendo os LEDs de sobrecarga.
- **Protoboard e Fios de Conexão**: A protoboard organiza os componentes, e os fios conectam o Arduino aos LEDs e resistores.

## Explicação do Código

1. **Definição dos Pinos e Constantes**: Os LEDs foram mapeados para variáveis (`ledVermelho`, `ledAmarelo`, `ledVerde`) e os tempos de cada fase foram definidos em milissegundos para controle preciso.
2. **Variáveis de Controle**: `tempoAnterior` armazena o momento da última troca de estado, e `estadoAtual` indica a fase em que o semáforo está (0 = vermelho, 1 = amarelo, 2 = verde, 3 = verde adicional, 4 = amarelo final).
3. **Setup**: Configura os pinos dos LEDs como saídas para controlar o acendimento de cada LED.
4. **Loop Principal**: No `loop()`, o código monitora o tempo decorrido usando `millis()` e alterna entre os estados do semáforo com base nos intervalos definidos. Cada estado ativa o LED correspondente:
   - **Estado 0**: Acende o LED vermelho por 6 segundos, depois muda para o amarelo.
   - **Estado 1**: Acende o LED amarelo por 2 segundos, depois muda para o verde.
   - **Estado 2**: Acende o LED verde por 2 segundos, depois muda para o verde adicional.
   - **Estado 3**: Mantém o LED verde aceso por mais 2 segundos, depois muda para o amarelo final.
   - **Estado 4**: Acende o LED amarelo novamente por 2 segundos, então retorna para o vermelho.

Essa lógica permite que o semáforo funcione de maneira contínua e cíclica, simulando um semáforo realista para controle de trânsito.


### Tabela de Avaliação entre Pares

#### Avaliador: Otávio Vasconcelos

|Critério|	Contempla (Pontos)|	Contempla Parcialmente (Pontos)	|Não Contempla (Pontos)	|Observações do Avaliador|
|-|-|-|-|-| 
|Montagem física com cores corretas, boa disposição dos fios e uso adequado de resistores	|Até 3	|Até 1,5	|0 | Nota 2,8 houve diferenciação de cores entre positivo e negativo, porém não ideal. |	
|Temporização adequada conforme tempos medidos com auxílio de algum instrumento externo	|Até 3	|Até 1,5	|0 | Nota 3, funcionou corretamente.|	
|Código implementa corretamente as fases do semáforo e estrutura do código (variáveis representativas e comentários) |	Até 3|	Até 1,5 |	0 | Nota 3, está comentado e correto.|	
|Ir além: Implementou um componente de extra, fez com millis() ao invés do delay() e/ou usou ponteiros no código |	Até 1 |	Até 0,5 |	0 | 0,5, não implementou ponteiros e nem componente extra, mas utilizou millis() ao invés de delay()|	
| | | | |Pontuação Total| 9,3