# Algebra Booleana
Variabili Logiche o Booleane : Vero o Falso

 - **OR** : **Disgiunzione Logica** (a+b)
 - **AND** : **Congiunzione Logica** 
 (a*b)
  - **NOT** : **Negazione**
 - **XOR** : 01 e 10(Veri) ma non 11(Falso)
# Operatori Logici
 - **OR** : Lunetta( )>) (a,b) =)>- c
 - **AND** : D (a,b)=D-c  Es.(1,1)=D-1 Sennò c = 0
 - **NOT** : o 1-o-0 e 0-o-1
# Unità Elementari di Memoria
## Flip-Flop
Informazione(I) e Impulso Clock(c) Uscita(U)

SR FlipFlop Set,Reset e Uscita Info e NotInfo. Se Set e Reset entrambi 0 la Info sarà la Info precedentemente Memorizata, la Info dell'ultimo impulso clock

## Registro
Blocco di 8 Flip Flop in parallelo e il segnale di Clock gli attraversa contemporaneamente. 1 Byte

## Clock
Ogni Elaboratore contiene un Elemento di Temporizzazione detto Clock che genera un riferimento Temporale Comune a tutti gli elementi costituenti il Sistema di Elaborazione
- T : periodo tra un inpulso e l'altro in secondi
- f : frequenza in Hz 1/T inpulsi al secondo

Circuito Clock AND Info -> Se Info True allora il segnale trasmesso è un alta tensione di periodo trempo di clock (C,T)=D-a