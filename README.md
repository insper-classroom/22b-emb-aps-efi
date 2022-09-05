# 22b-emb-aps1

Embarcados - APS 1 - Musical!

Para maiores informações acesse:

https://insper.github.io/ComputacaoEmbarcada/APS-1-Musical/

Issues serão abertos neste repositório para guiar o desenvolvimento
da dupla. **Vocês não devem fechar os issues, apenas a equipe de professores!**, porém devem referenciar nos commits quando um issue 
foi concluído! Isso gerará um PR no classroom que será avaliado pela equipe.

## Documentação

TODO: Aualizar pinos

| Função  | PINO (ex: PA11) |
|---------|-----------------|
| BUZZER  |       PC13      |
| START   |       PD28      |
| SELEÇÃO |       PC31      |

### Imagem da montagem

![alt text](https://github.com/insper-classroom/22b-emb-aps-efi/blob/main/img.jpeg)

### Vídeo do projeto



### Músicas e Direitos autorais

As músicas foram retiradas do seguinte repósitório git: https://github.com/robsoncouto/arduino-songs

As músicas utilizadas foram:
zeldaslullaby, imperialmarch e pinkpanther.

### Como usar

Conectar o pino positivo do buzzer na porta PC13, e o negativo no ground da placa. Conecte a placa OLED ao EXT1 da placa. Ao apertar o Button 1 da placa OLED, a música é pausada ou volta a tocar. Ao apertar o button 2, muda a música sendo tocada.
