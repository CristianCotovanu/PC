TetriPic
==
Descriere
--
Implementarea unui program care creeaza prin intermediul utilizarii fisierelor    
binare, imaginile necesare pentru un joc de tetris.

Rulare
--
- Automata.   
Compilati folosind **Makefile**.  
Apoi rulati **./checker.sh**

Implementare
--
In implementare am folosit functii auxiliare pentru:
- completarea unei structuri rgb cu valorile corespunzatoare culorii alb
- "vopsirea" pixelilor dintr-o matrice pe o suprafata de 10x10
- functie pentru alocarea dinamica a spatiului necesar pieselor
- functie pentru dezalocarea spatiului necesar pieselor

Am creat o structura ce contine rgb si numarul de linii si de coloane,  
apoi am alocat dinamic spatiul necesar pieselor, apoi functii pentru  
fiecare piesa, completand ulterior structura de bmp.  