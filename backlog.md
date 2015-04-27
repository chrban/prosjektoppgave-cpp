
## stufs to do

# HØYPRIORITET:

##Omstrukturere kode slik:

Struktur:
```
-Main
	-> Game
		-> Levelfactory
		-> boxFactoy
		-> GroundFactory
		-> cloudFactory
		-> groundFactory
```


Utrolig ineffektivt å slette alle objekter hver gang nytt brett skal tegnes.
Lage et globalt objekt som ikke dør hver gang, kan inneholde objekter som må dø.

Game lager et levelfactory objekt som inneholder alle objektene som trengs for et game.

Banenm leses ÉN gang fra fil, inn til en vektor.
En variabel 'Frame' representerer hvor i banen man er, dvs går du til høyre økes den, går du til venstre minkes den.
Utifra hvilket frame man er i, hentes riktige elementer til den framen.

Skrive om Levelfactory: Flytte metode for å lese fil til en egen abstract klasse, 
Skrive om metoden som leser inn fra fil, til å ta imot en variabel til, som representeres hvilket objekt det er snakk om. slik at 
1,800,600 betyr objekt type n, plasseres på posisjon x,y.
Lagres i en .map fil med denne strukturen:

```
// Type, X-posisjon, Y-posisjon
1,62,475 //start'frame 1'
1,93,475
1,124,475
1,155,475
1,186,475
2,217,475
2,248,475
3,279,475
3,310,475
3,341,475
-  // tolkes av leser som slutt frame
1,744,4300 //start 'frame 2'
1,775,4300
1,124,4300
3,155,4300
4,186,4300
4,217,4300
4,248,4300
5,279,4300
5,310,4300
5,341,4300
5,0,0
-  // tolkes av leser som slutt frame
1,40,40 //'frame 3'
```

- Idé for skalerbarhet: Mulig å lese N antall variabler i lesemetoden, slik at det er rom for å utvide med egenskaper. feks lese en skyobjet, med posisjon og haastighet. (mulig løsnign er å lese linje for linje, hvor hver linje representerer et objekt, hvor variabler separert med komma kan hentes ut deretter.)



* ~~gjøre hopping smuuth - chrbng~~

* ~~lage startmeny - trymz~~

* brettsetup! -chrbng 

* lyder - kristoffer 

* sol og skyer

* Mario i truse == enemy --> enemy is moving and having fun.

* Global ordning for liv og poeng - betty
* kode en fiende og kollisjon med denne - betty

* Plukke opp objekt - kristoffer 

* Lage mål, killscreen - trym?

> Skrive litt tanker jeg skal fullføre - chrban
> Når man beveger seg utenfor banen til høyre skal 'frame' variabelen øke, til venstre skal den minke.
> På den måten kan riktig frame tegnes.
> Banen lagres i en vektor som inneholder 2 par. En frame varibel og x,y koordinater.
> første parint kan kanskje brukes til å lagre andre objekter som skal tegnes.
> fiks en global frame
> legg deg
> fortsett imorgen

