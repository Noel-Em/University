enum stati_semaforo {rosso, giallo, verde};

enum stati_semaforo2 {rosso = 5, giallo = 3, verde = 10};


/*
Info: 
Lo spazio esatto occupato in memoria da un oggetto di
tipo enumerato dipende dal compilatoretipo enumerato dipende dal compilatore
 Tipicamente: stessa occupazione di memoria (inTipicamente: stessa occupazione di memoria (in
numero di byte) del tiponumero di byte) del tipo int


-

A partire dallo standard C++11, è stato introdotto un
nuovo tipo di dato, denotato comenuovo tipo di dato, denotato come enum classenum class
 La sintassi della dichiarazione di un nuovo tipoLa sintassi della dichiarazione di un nuovo tipo
enum classenum class è la seguenteè la seguente
<dichiarazione_tipo_enumeration><dichiarazione_tipo_enumeration> ::=::=
enum classenum class <identificatore><identificatore> {{<lista_dich_enumeratori><lista_dich_enumeratori>} ;} ;

--

A differenza del tipo enumenum, per utilizzare un enumeratore di un, per utilizzare un enumeratore di un
dato tipodato tipo enum classenum class, bisogna aggiungere come prefisso il, bisogna aggiungere come prefisso il
nome del tipo seguito danome del tipo seguito da ::::
 Esempi (data la dichiarazione nel precedente esempio)Esempi (data la dichiarazione nel precedente esempio)
cout<<blu; // ERRATOcout<<blu; // ERRATO
cout<<colore2_t::blu; // CORRETTOcout<<colore2_t::blu; // CORRETTO
 Questo permette a due o più tipi enumerati di avere gliQuesto permette a due o più tipi enumerati di avere gli
enumeratori con lo stesso nome senza che sorganoenumeratori con lo stesso nome senza che sorgano
problemi di compilazione o ambiguitàproblemi di compilazione o ambiguità

---

Benefici:

Decisamente migliore leggibilità

 Indipendenza del codice dal numero di enumeratori e daiIndipendenza del codice dal numero di enumeratori e dai
valori degli enumeratorivalori degli enumeratori

 Conseguenze importantissime:Conseguenze importantissime:

 se cambio il valore di qualche enumeratore, non devose cambio il valore di qualche enumeratore, non devo
modificare il resto del programmamodificare il resto del programma

 posso aggiungere nuovi enumeratori senza doverposso aggiungere nuovi enumeratori senza dover
necessariamente modificare il resto del programmanecessariamente modificare il resto del programma

 Maggiore robustezza agli erroriMaggiore robustezza agli errori

 Se si usano solo gli enumeratoriSe si usano solo gli enumeratori non è praticamentenon è praticamente
possibile usare valori sbagliatipossibile usare valori sbagliati

 Quindi: impariamo da subito adQuindi: impariamo da subito ad utilizzare gli enumerati eutilizzare gli enumerati e
non gli interinon gli interi ovunque i primi siano più appropriati deiovunque i primi siano più appropriati dei
secondi

*/