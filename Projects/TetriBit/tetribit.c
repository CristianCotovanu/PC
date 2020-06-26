#include <stdio.h>
#include <math.h>

void print_score(unsigned long long map, int completed_lines) {
	int i = 0, count0 = 0;
	float score;

	for (i = 0; i < 64; i++)
		if (((map >> i) & 1) == 0)
			count0 ++;

	score = sqrt(count0) + pow(1.25, completed_lines);
	printf("GAME OVER!\nScore:%.2f", score);
}

//Afiseaza harta
void print_map(unsigned long long map) {
	int i;
	for (i  = 63; i >= 0; i--) {
		if ((map >> i) & 1 == 1)
			printf("#");
		else
			printf(".");
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
}

/*
 * Elimina liniile completate si coboara liniile superioare.
 * Returneaza numarul de linii completate.
 */

int clear_completed_lines(unsigned long long *map) {
	int i, j, completed_lines = 0;
	unsigned long long full_line_mask = 0xFF;
	for(i = 0; i < 64; i+=8) {
		if(((*map >> i) & full_line_mask) == full_line_mask) {
			completed_lines++;
			for(j = i; j < 56; j+=8) {
				*map = *map & (~(full_line_mask << j));
				*map = *map | (((*map >> (j + 8)) & full_line_mask) << j);
			}

			*map = *map & ~(full_line_mask << 56);
			i-=8;
		}
	}

	if(completed_lines)
		print_map(*map);

	return completed_lines;
}

//Citeste o piesa, aplica mutarile, verifica coliziunile si o efectueaza 
int move(unsigned long long *map) {
	int mutare, j, i,
		maskb0 = 1,
		maskb7 = (1 << 7),
		maskb8 = (1 << 8),
		maskb15 = (1 << 15);
	unsigned long long piesa = 0;
	int round_over = 0;

	scanf("%llu", &piesa);
	for (i = 7; i >= 0; i--) {
		scanf("%d", &mutare);
		//Mutarea verticala a piesei
		if(!round_over) {
			if (i != 7)
				*map = *map & ~(piesa << (8 * (i+1)));

			// Coliziune la mutarea verticala
			if(((*map >> (8 * i)) & piesa) != 0) {
				
				// Piesa nu a intrat pe tabla
				if ((piesa & 0xFFFF) != 0 && (i == 7)) {
					print_map(*map);
					return 1;
				}
				// Piesa a intrat pe tabla partial
				else if((piesa & 0xFF00) != 0 && (i == 6)) {
					*map = *map | (piesa << (8 * (i+1)));
					print_map(*map);
					return 1;
				}
				// Piesa a intrat pe tabla integral
				else {
					*map = *map | (piesa << (8 * (i+1)));
					round_over = 1;
					continue;
				}
			}

			//Mutarea orizontala a piesei
			if (mutare >= 0 )
				for (j = 1; j <= mutare; j++) {
					if ((((piesa << (8 * i)) >> 1) & *map) == 0
						&& (piesa & maskb0) == 0
						&& (piesa & maskb8) == 0) {
						piesa = piesa >> 1;
					}
					else
						break;
				}
			else {
				for (j = 1; j <= -mutare; j++) {
					if ((((piesa << (8 * i)) << 1) & *map) == 0
						&& (piesa & maskb7) == 0
						&& (piesa & maskb15) == 0) {
						piesa = piesa << 1;
					}
					else
						break;
				}
			}

			*map = *map | (piesa << (8 * i));
			print_map(*map);
		}
	}

	return 0;
}

int main() {
	unsigned long long map;
	short nr_moves;
	int i, completed_lines = 0, is_game_over = 0;

	scanf("%llu", &map);
	scanf("%hu", &nr_moves);

	print_map(map);
	for(i = 0; i < nr_moves && !is_game_over; i++) {
		is_game_over = move(&map);
		completed_lines += clear_completed_lines(&map);
	}

	print_score(map, completed_lines);
	return 0;
}

