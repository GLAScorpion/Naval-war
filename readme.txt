Features:
    1: battaglia_navale accetta qualsiasi combinazione degli argomenti p e c e le gestisce correttamente
    2: La partita dura 100 turni totali, 50 per player
    3: La compilazione può essere fatta attraverso lo script cmake_and_compile.sh e si trovano i binaries nella cartella build
    4: Per la compilazione manuale cmake è configurabile con cmake -S . -B <path-to-bin>
    5: I comandi aggiuntivi rispetto alla consegna sono "BB BB" e "CC CC" e funzionano come indicato nelle FAQ
Bug:
    1: Lo stream di input viene "inquinato" alla digitazione di caratteri speciali italiani (e.g. è) e anche
       cancellandoli sporcano l'acquisizione dell'input che porta a comandi non validi anche se corretti.
       E' sufficiente ridigitare il comando senza fare errori.