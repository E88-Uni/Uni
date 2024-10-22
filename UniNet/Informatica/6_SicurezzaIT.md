# Sicurezza Internet
## Malware
Carpire Informazioni e Creare Danni
### Tipi
 - Trojan Horse
    - Programma Nascosto
    - Capacità di autoinstallarsi all'interno di altri programmi
    - Generalmente per Carpire Informazioni
 - Virus
    - Segnemento di Codice
    - Si duplica autonomamente
    - Si inserisce da solo in altri programmi
    - Non si esegue da solo ma quando viene eseguito il programma che lo ospita
    - Non si propaga autonomamente
 - Worm - Network Virus
   - E' un programma
   - Si autoreplica
   - Si trasmette in automatico sulla rete
   - Non si nasconde all'interno di altri programmi 
 - Spyware
   - Insieme di malware 
   - Non si diffonde autonomamente
   - Richiedono l'intervento dell'utente per essere installati
 - Phishing : Far finta di essere un altra persona
 - Spamming - Scam
# Cripttografia
Per impedire a chi è in ascolto di decifrare i pacchetti nella rete non destinati a lui.

## Chiavi Simmetriche 'Casuale'
 1. Messaggio passa per software di Cripttografia
 2. Il Messaggio 'Viaggia' Criptato
 3. Il ricevitore ha una chiave speciale con cui decodificare tramite un  software di Cripttografia 

Il **tempo di cracking** cresce esponenzialmente con la crescita lineare della lunghezza della chiave. Se la chiave non è presente in delle librerie dell'Hacker

Se il codice di criptografia **non è adeguatamente complesso** la difficolta di cracking non sarà più esponenziale ma similmente lineare.
Es. a = a +3 = d, Es. Macchina enigma : complessa ma si può 'facilmente' invertire la criptazione.
Necessità di un **Intrinseca intelligenza**

Chiavi con 100 bit sono già molto sicure

**Numero** di chiavi simmetriche tra utenti? 
Il numero sarà  le possibili combinazioni tra due utenti 

### 3 Obbiettivi
 1. Informazione Nascosta
 2. Garanzia di chi è il mittente da parte del ricevitore
 3. Integrità del messaggio. Non è stato modificato

## Chiave Pubblica e Privata
Con il Software di Criptografica: dalla chiave privata estraggo n-chiavi di criptazione.
Ne metto pubblica una e ogni persona che mi invia un messaggio la usa per criptarmelo.
Solo con la chiave privata si ha la capacità di decriptare.

Risolto il problema 
 - Della chiave simmetrica dove chi intercetta il messaggio può decriptarlo
 - Autenticazione del mittente (tipo firma digitale). Nel caso il mittente cripta in invio con la sua chiave privata. Chi riceve con la chiave pubblica può confermare  l'autenticazione. Perchè la decriptazzione è positiva.

### SSL
Sicurezza della Criptografia e della Autenticazione
 1. Collegamento Browser
 2. Banca Invia Proprio Certificato
 3. Il client estrae la chiave Pubblica della Banca
 4. Il client crea una chiave simmetrica e la Codifica con la Pubblica della Banca
 5. La Banca Ottiene la Chiave Simmetrica del Cliet

### WEB of TRUST X.509
Standard X.509. E' una Gerarchia di Chiavi di Autenticazione.
 1. Io Banca di Italia, Certifico la Chiave Pubblica della FIAT
 2. Io FIAT, Certifico la Chiave Pubblica di Pippo
 3. ecc...

### SPID
Servizio Pubblico di Identità Digitale. L' **AGID** decide processi e standard. Usufriuzione Servizi es. Sanità. Come comunicano gli strumenti e servizi delle Regioni, Ministeri ed enti Esteri ed Euopei.

## Carte - Cell A Microprocessore EMV
Pagamento Contactless : processore che certifica la chiave pubblica del soggetto titolare della carta. 
Con una mini-chiave privata nascostra 'tra una serie di transistor'. 

TODO SPID -9min