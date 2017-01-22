# Filformatet .bisys

Spelfilerna lagras som vanliga textfiler. Dessa filer beskriver hur spelvärlden ser ut.

## Generella regler för filformatets syntax

Då spelet skall läsa in spelfilen rad för rad, måste spelinformationen skrivas i en viss ordning.

Då spelet är rumbaserat, så konstruerar man föremål och NPC:er inuti ramarna för det rum som de skall befinna sig i.

Syntaxen fungerar som så att den är radkänslig så vid radbryte så är koden ovanför klar. Ett radbyte fungerar som ett semikolon i C++

Varje objekt eller modul som skrivs får inte plats på enbart en rad, så klammerparenteser används för att inkapsla vad som skall finnas i vilket objekt. Annars kan det bli problem med t.ex. vilket rum som behandlas eller om ett objekt skall finnas i rummet

Tillåtna datatyper enligt filformatets syntax är int, bool och string. I det här filformatet skrivs en int alltid som ett positivt heltal, bool kan vara YES eller NO och string är en kort textsträng som antingen kan vara ett eller flera tecken.

## Kommentarer

Likt C++ inleds kommentarer med två snedstreck och därefter skriver man sin kommentar på en rad. Vill man skriva kommentarer på flera rader måste man inleda varje rad med två snedstreck.

## Rum

Tillåtna identifierare:

- String Name, Description
- Int Exits[]

Ett rum i en spelfil skrivs:

```
Room:
{     
     Name: Namn     
     Description: Beskrivning

     Exits:     
     {          
          N 0          
          S 0          
          W 0          
          E 0          
     }     
}
```


Identifierarna Room, Name, Description, Exits samt utgångarna måste alltid definieras, dessutom skall de alltid skrivas i samma ordning.

Name och Description kommer från den abstrakta basklassen Entity och behövs därför alltid när man konstruera ett objekt från en klass som ärver från Entity.

Rummets utgångar måste alltid definieras. Dock måste de inte alltid leda någonstans, som i exemplet ovan. Om man vill ge varje riktning ett rum, skriver man så här:

```
Exits:
{     
     N 1     
     S 2     
     W 3     
     E 4     
}
```

Efter varje väderstreck skriver man in rummets ID. Detta ID beskriver var i rumlistan rummet befinner sig. 1 är t.ex. det första rummet i listan och därmed det första rummet som definieras i spelfilen. Vill man förtydliga vad varje rum har för ID-nummer, kan man lägga en kommentar där rummet skapas.

```
//1
Room:
{    
     ...     
}

//2
Room:
{     
     ...
```

Det är viktigt att man skriver väderstrecken i rätt ordning, då hela inläsningen av filen sker sekventiellt.



**Föremål**

Tillåtna identifierare:

- String Name, Description
- Bool Pickable, Sellable, Throwable
- Int Value

Föregående exempel ger dock ett tomt rum utan utgångar. Vill man fylla rummet med föremål måste man skapa föremålen inuti rummet genom att skriva Item: { och sedan fylla i föremålets egenskaper nedan. Förutom namn och beskrivning, tar föremål emot två booleans Pickable och Sellable, som bestämmer om föremålet går att plocka upp och om det går att sälja till en merchant. Dessutom skall en int value bestämma värdet på det aktuella föremålet. Detta värde bestämmer hur mycket pengar man får om man säljer föremålet till en försäljare. Här är ett exempel på ett rum med en nyckel:
```
Room:
{     
     Name: Namn     
     Description: Beskrivning

     Item:     
     {          
          Name: Nyckel          
          Description: Används för att öppna ett lås          
          Pickable: Yes          
          Sellable: Yes          
          Value: 0          
          Throwable: No          
     }

     Exits:     
     {          
          N 0          
          S 0          
          W 0          
          E 0          
     }     
}
```

Rum kan innehålla flera objekt, vilket man uppnår genom att skapa ännu ett föremål i rummet på samma sätt:
```
Room:
{     
     Name: Namn     
     Description: Beskrivning  

     Item:     
     {          
          Name: Fin nyckel          
          Description: Jättefin nyckel.          
          Pickable: Yes          
          Sellable: Yes          
          Value: 10          
          Throwable: No          
     }

     Item:     
     {          
          Name: Ful nyckel          
          Description: Usch vad ful den är.          
          Pickable: Yes          
          Sellable: Yes          
          Value: 1          
          Throwable: No          
     }

     Exits:     
     {          
          N 0          
          S 0          
          W 0          
          E 0          
     }     
}
```

## Person

Tillåtna identifierare:

- String Name, Description, Dialog, Recieved\_item\_dialog
- Item
- String Hair
- Int Height, Weight, Width
- String Wants

NPC:er (person) fungerar på ungefär samma sätt som objekt i spelfilen. Man kan skapa flera personer i ett rum genom att placera dem efter varandra på samma sätt som föremålen.

NPC:er kan bära på föremål som spelaren får ta emot antingen om spelaren pratar med NPC:n eller om NPC:n vill ha ett visst föremål som spelaren kan ge bort.

Ett föremål som en NPC kan ge bort beskrivs i koden precis på samma sätt som i rummet.

När en NPC tar emot ett föremål, skall en dialog _recieved\_item\_dialog_ visas.

```
Person:
{     
     Name: Lars Småberg.     
     Description: 60 år, väldigt tjock.     
     Dialog: Hej mitt namn är Lars och jag är borgmästare.     
     Recieved_item_dialog: Tack för den fina nyckeln.

     Item:     
     {

          Name: Ful nyckel          
          Description: Usch vad ful den är.          
          Pickable: Yes          
          Sellable: Yes          
          Value: 1          
          Throwable: No          
     }     
}
```

## Merchant

Tillåtna identifierare:

- String Name, Description, Dialog
- Item
- String Hair
- Int Height, Weight, Width

En merchant beskrivs spelfilen på ungefär samma sätt som en NPC. En merchant kan bära på flera items som delas ut till spelaren i utbyte mot pengar (föremålets värde, value).

Merchant skapas precis som en person med att den har strängar Name, Description och Dialog. Dock så innehåller även Merchant en vector med föremål som spelaren kan handla från. Dessa föremål skapas på samma sätt som i Room och Person.




```
Merchant:
{

     Name: Ulf T. Pressning     
     Description: Han gillar pengar.     
     Dialog: Kom och köp grejer av mig, billigt billigt!

     Item:     
     {          
          Name: Ful nyckel          
          Description: Usch vad ful den är.          
          Pickable: Yes          
          Sellable: Yes          
          Value: 1          
          Throwable: No          
     }

     Item:     
     {          
          Name: Gul nyckel          
          Description: Usch vad ful den är.          
          Pickable: Yes          
          Sellable: Yes          
          Value: 1          
          Throwable: No

     }     
     Hair: Skallig
     Height: 120     
     Weight: 400     
     Width: 100     
}
```
