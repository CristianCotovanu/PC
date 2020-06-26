#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp_header.h"

typedef struct rgb {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;

typedef struct img {
	RGB** mat;
	int rows;
	int cols;
} IMG;


void RGB2BGR(IMG* img) {
	int i, j;
	unsigned char tmp;

	for (i = 0; i < img->rows; i++)
		for (j = 0; j< img->cols; j++) {
			tmp = img->mat[i][j].r;
			img->mat[i][j].r = img->mat[i][j].b;
			img->mat[i][j].b = tmp;
		}
}

//Filling every RGB struct of a matrix with color white (255, 255, 255)
void color_white(int row, int col, RGB **piece) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			piece[i][j].r = 255;
			piece[i][j].g = 255;
			piece[i][j].b = 255;
		}
	}
}


void matrix_alloc(int row, int col, RGB ***piece) {
	int i;

	// piece = malloc (col * 8);
	*piece = malloc (row * sizeof(RGB *));
	for (i = 0; i < row; i++) {
		(*piece)[i] = malloc(col * sizeof(RGB));
	}

}

//Coloring pixels of a matrix with specific rgb
void color_pixels(IMG* img, int i_row, int i_col, RGB color) {
	int i, j;

	for (i = i_row; i < i_row + 10; i++)
		for (j = i_col; j< i_col + 10; j++) {
			img->mat[i][j].r = color.r;
			img->mat[i][j].g = color.g;
			img->mat[i][j].b = color.b;
		}
}

IMG* pieceS () {
	IMG *img;
	int rows = 40, cols = 50;
	img = malloc(sizeof(IMG));

	RGB **S, red = {.r = 255, .g = 0, .b = 0};

	matrix_alloc(rows, cols, &S);
	img->cols = cols;
	img->rows = rows;
	img->mat = S;

	color_white(rows, cols, S);
	color_pixels(img, 10, 20, red);
	color_pixels(img, 10, 30, red);
	color_pixels(img, 20, 20, red);
	color_pixels(img, 20, 10, red);

	return img;
}


IMG* pieceL () {
	IMG *img;
	int rows = 50, cols = 40;
	img = malloc(sizeof(IMG));

	RGB **L, orange = {.r = 255, .g = 140, .b = 0};

	matrix_alloc(rows, cols, &L);
	img->cols = cols;
	img->rows = rows;
	img->mat = L;

	color_white(rows, cols, L);
	color_pixels(img, 10, 10, orange);
	color_pixels(img, 20, 10, orange);
	color_pixels(img, 30, 10, orange);
	color_pixels(img, 30, 20, orange);

	return img;
}


IMG* pieceI () {
	IMG *img;
	int rows = 60, cols = 30;
	img = malloc(sizeof(IMG));

	RGB **I, blue = {.r = 0, .g = 0, .b = 255};

	matrix_alloc(rows, cols, &I);
	img->cols = cols;
	img->rows = rows;
	img->mat = I;

	color_white(rows, cols, I);
	color_pixels(img, 10, 10, blue);
	color_pixels(img, 20, 10, blue);
	color_pixels(img, 30, 10, blue);
	color_pixels(img, 40, 10, blue);

	return img;
}


IMG* pieceO () {
	IMG *img;
	int rows = 40, cols = 40;
	img = malloc(sizeof(IMG));

	RGB **Y, yellow = {.r = 255, .g = 255, .b = 0};

	matrix_alloc(rows, cols, &Y);
	img->cols = cols;
	img->rows = rows;
	img->mat = Y;

	color_white(rows, cols, Y);
	color_pixels(img, 10, 10, yellow);
	color_pixels(img, 20, 10, yellow);
	color_pixels(img, 10, 20, yellow);
	color_pixels(img, 20, 20, yellow);

	return img;
}


IMG* pieceZ () {
	IMG *img;
	int rows = 40, cols = 50;
	img = malloc(sizeof(IMG));

	RGB **S, green = {.r = 0, .g = 255, .b = 0};

	matrix_alloc(rows, cols, &S);
	img->cols = cols;
	img->rows = rows;
	img->mat = S;

	color_white(rows, cols, S);
	color_pixels(img, 10, 10, green);
	color_pixels(img, 10, 20, green);
	color_pixels(img, 20, 20, green);
	color_pixels(img, 20, 30, green);

	return img;
}


IMG* pieceJ () {
	IMG *img;
	int rows = 50, cols = 40;
	img = malloc(sizeof(IMG));

	RGB **S, pink = {.r = 255, .g = 0, .b = 255};

	matrix_alloc(rows, cols, &S);
	img->cols = cols;
	img->rows = rows;
	img->mat = S;

	color_white(rows, cols, S);
	color_pixels(img, 10, 20, pink);
	color_pixels(img, 20, 20, pink);
	color_pixels(img, 30, 10, pink);
	color_pixels(img, 30, 20, pink);

	return img;
}


IMG* pieceT () {
	IMG *img;
	int rows = 40, cols = 50;
	img = malloc(sizeof(IMG));

	RGB **S, purple = {.r = 130, .g = 0, .b = 255};

	matrix_alloc(rows, cols, &S);
	img->cols = cols;
	img->rows = rows;
	img->mat = S;

	color_white(rows, cols, S);
	color_pixels(img, 10, 10, purple);
	color_pixels(img, 10, 20, purple);
	color_pixels(img, 10, 30, purple);
	color_pixels(img, 20, 20, purple);

	return img;
}


void delete_piece(IMG* img) {
	int i;
	for(i = 0; i < img->rows; i++)
		free(img->mat[i]);
	free(img->mat);
	free(img);
}


void writeBMP(const char* filename, IMG* img) {
	int i, j, k, padding;
	FILE* f;
	struct bmp_fileheader BMPFILEHEADER;
	struct bmp_infoheader BMPINFOHEADER;
	unsigned char zero = 0;

	if ((f = fopen(filename, "wb")) == NULL){
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}

	padding = sizeof(RGB) * img->cols % 4;

	BMPFILEHEADER.fileMarker1 = 'B';
	BMPFILEHEADER.fileMarker2 = 'M';
	BMPFILEHEADER.unused1 = 0;
	BMPFILEHEADER.unused2 = 0;
	BMPFILEHEADER.bfSize = sizeof(struct bmp_infoheader) + sizeof(struct bmp_fileheader) +
			img->rows * img->cols * sizeof(RGB) + img->rows * padding;
	BMPFILEHEADER.imageDataOffset = sizeof(struct bmp_fileheader) + sizeof(struct bmp_infoheader);

	BMPINFOHEADER.biSize = 40;
	BMPINFOHEADER.width = img->cols;
	BMPINFOHEADER.height = img->rows;
	BMPINFOHEADER.planes = 1;
	BMPINFOHEADER.bitPix = 24;
	BMPINFOHEADER.biCompression = 0;
	BMPINFOHEADER.biSizeImage = img->rows * img->cols * sizeof(RGB) + img->rows * padding;
	BMPINFOHEADER.biXPelsPerMeter = 0;
	BMPINFOHEADER.biYPelsPerMeter = 0;
	BMPINFOHEADER.biClrUsed = 0;
	BMPINFOHEADER.biClrImportant = 0;

	fwrite(&BMPFILEHEADER, sizeof(struct bmp_fileheader), 1, f);
	fwrite(&BMPINFOHEADER, sizeof(struct bmp_infoheader), 1, f);
	for(i = img->rows - 1; i >= 0; i--) {
		for(j = 0; j < img->cols; j++) {
			fwrite(&(img->mat[i][j]), sizeof(RGB), 1, f);
		}
		for(k = 0; k < padding; k++)
			fwrite(&zero, sizeof(unsigned char), 1, f);
	}

	fclose(f);
}


void task1() {
	IMG* img;

	img = pieceS();
	RGB2BGR(img);
	writeBMP("piesa_S.bmp", img);
	delete_piece(img);

	img = pieceL();
	RGB2BGR(img);
	writeBMP("piesa_L.bmp", img);
	delete_piece(img);


	img = pieceI();
	RGB2BGR(img);
	writeBMP("piesa_I.bmp", img);
	delete_piece(img);

	img = pieceO();
	RGB2BGR(img);
	writeBMP("piesa_O.bmp", img);
	delete_piece(img);

	img = pieceZ();
	RGB2BGR(img);
	writeBMP("piesa_Z.bmp", img);
	delete_piece(img);

	img = pieceJ();
	RGB2BGR(img);
	writeBMP("piesa_J.bmp", img);
	delete_piece(img);

	img = pieceT();
	RGB2BGR(img);
	writeBMP("piesa_T.bmp", img);
	delete_piece(img);
}


int main(int argc, char* argv[]) {

	if (argc > 1 && strcmp(argv[1], "1") == 0)
		task1();

	return 0;
}