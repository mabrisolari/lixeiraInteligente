# lixeiraInteligente
Resumo do Código
O código implementa um sistema de monitoramento de nível de enchimento de lixeiras usando microcontroladores. A seguir, as funcionalidades principais:

Funcionalidades:
Sensores de Nível de Lixo: Monitoram continuamente o nível de enchimento das lixeiras.

Botões de Alerta: Quando pressionados, indicam que as lixeiras A ou B estão cheias e acendem um LED vermelho.

LED Indicador: Acende quando uma lixeira atinge o nível máximo de enchimento.

Notificações: Imprime mensagens no console indicando o estado de enchimento das lixeiras e os botões pressionados.

Estrutura do Código:
Definição dos Pinos GPIO:

LIXO_SENSOR_PIN: Sensor de nível de lixo.

BOTAO_A_PIN e BOTAO_B_PIN: Botões para indicar que as lixeiras A e B estão cheias.

LED_VERMELHO_PIN: LED vermelho que acende quando as lixeiras estão cheias.

Inicialização dos Componentes:

Configura os pinos GPIO para entrada e saída.

Ativa resistores pull-up internos para os sensores e botões.

Loop Principal:

Verifica continuamente o nível de lixo e a pressão dos botões.

Acende o LED vermelho e imprime mensagens no console quando as lixeiras estão cheias ou os botões são pressionados.

Utiliza um pequeno delay para evitar leituras errôneas (debounce).

Este código fornece uma base sólida para monitorar e gerenciar o enchimento das lixeiras em tempo real, contribuindo para uma gestão eficiente de resíduos urbanos.
