
// dette er et sql kall for å sjekke om riktig gyldig brukernavn og passord er tastet inn

Qstring brukernavn = ui->brukernavn->text(); // setter brukernavn variablen som det som står i brukernavnteksboksen
Qstring passord = ui->passord->text(); // setter passord variablen som det som står i passordtekstboksen
QSqlQuery kall;
kall.prepare(«SELECT» brukernavn, passord from bruker WHERE 
                              brukernavn, :brukernavn AND passord, :passord» ); // Henter ut passord og brukernavn fra tabellen om brukere 
kall.bindValue(«:brukernavn», brukernavn); // setter brukernavn variablen i sql kallet som verdien til det som står i brukernavntekstboksen
kall.bindValue(«:passord, passord»): // setter passord variablen i sql kallet som verdien til det som står i passordteksboksen
if(kall.exec() )// Denner returnerer TRUE hvis kallet blir utført riktig
{
If(kall.size() > 0) // hvis det er noe resultater for både brukernavn og passord kan man gå videre
	{ 
GÅ TIL NESTE SIDE HER
}
Else // hvis det ikke er noen resulatater vil man få en feilmelding isteden
{
FEILMELDING
}
}




// dette er et sql kall for å hente ut objekter i lister med en bestemt dato

Qstring Dato = ui->dato->datotext(); // Får verdien til datoen fra brukergrensesnittet

QSqlQuery kall;
kall.prepare("SELECT Objekter, DATO from Liste WHERE // SQL kall for å hente ut alle resultater der datoen er den samme 
                              DATO, :DATO")  
kall.bindValue(«:DATO», DATO); // setter DATO variablen i sql kallet til verdien fra dato tekstboksen

if(kall.exec() )// Denner returnerer TRUE hvis kallet blir utført riktig
{
If(kall.size() > 0) // hvis det er noe resultater for Datoen blir denne koden utført
	{ 
while(kall.next()){ // så lenge det er flere resultater vil verdiene bli lagret
QSTRING objekter = kall.valure(0).toString(); // lagrer verdiene til objektene i listene med riktig dato 
}

}
Else // hvis det ikke er noen resulatater vil man få en feilmelding isteden
{
FEILMELDING
}
}

