TetriBit
==
Descriere
--
Implementarea unui joc de tetris care se bazeaza pe o harta stocata ca un numar si operatii pe biti.

Rulare
--
- Automata.   
Compilati folosind **Makefile**.  
Apoi rulati **./check.sh**

Implementare
--
1. Citirea de la tastatura a unui numar pe 64 de biti ce va reprezenta ulterior harta jocului.  
2. Citirea unei piese pe care se vor aplica ulterior mutari atat verticale cat si   
orizontale sub forma unor numere.
3. Efectuarea mutarilor  
    - pe verticala se verifica daca piesa are loc initial pe harta (in caz contrar jocul se termina), daca se va produce o coliziune cu orice piesa de sub aceasta , trecand apoi la mutarea pe orizontala din nou.
    - pe orizontala mutarea se face verificand fiecare coliziune cu orice piesa deja existenta sau cu marginile hartii.
4. In cazul completarii unei linii se va efectua stergerea acesteia (inlocuirea bitilor de 1 cu biti de 0) apoi coborarea liniilor superioare.
5. Finalizarea jocului se face prin afisarea mesajului "GAME OVER!" si a scorului obtinut pe parcursul jocului.
6. Au fost folositi pointeri pentru a transmite prin referinta variabila ce memoreaza harta si a modulariza codul.
