Formatare-Text
==
Descriere
--
Implementarea unei aplicatii pentru formatarea fisierelor    
text ce ofera functionalitatile descrise.

Rulare
--
Compilati folosind **Makefile**.  
Apoi rulati **./check.sh**

Implementare
--
1. Functii auxiliare: words_in_line, letters_in_line, sort_lines,  
digits_number, nr_spaces, string_to_num.  
Au fost folosite pentru modularizarea codului.

2. Functia execute_command: verifica primul caracter dintr-o comanda, acesta  
stabilind apelarea functiei corespunzatoare literei, in cazul unui caracter  
invalid afiseaza operatie invalida. 

3. Functia align right: se face raportat la cea mai lunga linie din text,  
numar spatiile de la sfarsit copiind textul.

4. Functia align left: numara spatiile de la inceputul fiecarei linii,  
acestea fiind eliminate ulterior prin copierea caracterelor corespunzatoare
peste acestea.

5. Functia center: face diferenta dintre dimensiunea celei mai lungi linii  
din fisier si linia curenta si adaug numarul de spatii la inceput, jumatate
din diferenta celor 2.

6. Functia paragraph: verific daca linia curenta este inceput de paragraf  
si in caz afirmativ adaug numarul de spatii specificat ca parametru la 
inceputul liniei.

7. Functia justify: calculez dimensiunea celei mai lungi linii din fisier  
pentru fiecare linie, aliniez la stanga linia curenta calculez numarul
de litere din linia curenta, numarul de cuvinte, numarul de spatii care
trebuie sa fie adaugate ca fiind diferenta dintre dimensiunea celei mai
lungi linii si numarul de litere din linia curenta, calculez numarul de 
spatii dintre 2 cuvinte consecutive ca fiind numarul de spatii necesare
impartit la numarul de cuvinte - 1 (intervale), calculez numarul de 
spatii aditionale ca fiind restul impartirii numarului de spatii 
necesare la nr de intervale adaug un cuvant urmat de numarul de spatii
corespunzator

8. Functia list: verific tipul listei si adaug contorul specific(cifra pt n,  
etc) in functie de tipul listei calculez spatiul necesar pt a adauga caract
speciale, adaug caracterul special si un spatiu urmat de textul din linia
curenta.

9. Functia ordered list: sortez lista si apoi aplic algoritmul de la lista  
simpla(8).

10. Functia wrap: verific cel mai lung cuvant(pentru a nu fi mai mare decat   
lungimea wrap-ului), fac o copie a matricei, pentru fiecare linie din  
matricea curenta calculez numarul spatiilor de inceput, daca linia curenta  
este mai lunga decat dimensiunea wrap-ului construiesc noua linie cu cate   
cuvinte pot, pe celelalte le adaug la urmatoarea linie, iar in cazul in   
care lungimea wrap este mai mare elimin spatiile din coada liniei curente  
adaugand apoi urmatorul cuvant de pe linia urmatoare, eliminand spatiile  
din fata sa.

La fiecare dintre functiile principale se verifica in interiorul lor si
existenta parametrilor, returnand in caz contrar un cod de eroare.
