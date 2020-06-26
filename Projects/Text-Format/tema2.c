#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_NUMBER_PARAMATERS 6
#define MAX_LINE_NUMBER 1000

#define INVALID_WRAP "Cannot wrap!"
#define INVALID_OPERATION "Invalid operation!"

//Verify which line is the last one and return it
int last_line(char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	int i;

	for (i = 999; i >= 0; i--)
		if (original[i][0] != '\0')
			return i - 1;

	return 999;
}

//Counting how many words are on a line
int words_in_line(char line[MAX_LINE_NUMBER]) {
	char copy[MAX_LINE_NUMBER], *token;
	int result = 0;
	strcpy(copy, line);
	token = strtok(copy, " ");
	while (token) {
		result++;
		token = strtok(NULL, " ");
	}

	return result;
}

//Counting how many letters are in a line
int letters_in_line(char line[MAX_LINE_NUMBER]) {
	int result = 0, i;
	i = 0;
	while (line[i] != '\n') {
		if (line[i] != ' ' && line[i] != '\t')
			result++;
		i++;
	}

	return result;
}

int is_corect_list_type(char *list_type) {
	return !((strcmp(list_type, "n") != 0) && (strcmp(list_type, "a") != 0)
			 && (strcmp(list_type, "A") != 0) && (strcmp(list_type, "b") != 0));
}

//Bubble sort implementation
void sort_lines(char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER], int first_row, int last_row, char order) {
	int i, j;
	char tmp[MAX_LINE_NUMBER];
	for (i = first_row; i <= last_row; i++) {
		for (j = first_row; j < last_row; j++) {
			if (order == 'a') {
				if (strcmp(original[j], original[j + 1]) > 0) {
					strcpy(tmp, original[j]);
					strcpy(original[j], original[j + 1]);
					strcpy(original[j + 1], tmp);
				}
			} else {
				if (strcmp(original[j], original[j + 1]) < 0) {
					strcpy(tmp, original[j]);
					strcpy(original[j], original[j + 1]);
					strcpy(original[j + 1], tmp);
				}
			}

		}
	}
}

//Couting how many digits a number has 
int digits_number(int number) {
	int result = 0;
	while (number != 0) {
		result++;
		number = number / 10;
	}

	return result;
}

int min(int a, int b) {
	return a < b ? a : b;
}

//Number of spaces in line 
//Either from head to tail or reversed 
int nr_spaces(char line[MAX_LINE_NUMBER], int order) {
	int i, spaces = 0, length;
	length = strlen(line);

	if (order) {
		for (i = 0; i < length; i++) {
			if (line[i] != ' ')
				break;
			spaces++;
		}
	} else {
		for (i = length - 2; i >= 0; i--) {
			if (line[i] != ' ')
				break;
			spaces++;
		}
	}

	return spaces;
}


int min_word_length(char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	char copy[MAX_LINE_NUMBER][MAX_LINE_NUMBER], *token;
	int i, max = INT_MIN, tmp;

	for (i = 0; i < MAX_LINE_NUMBER; i++) {
		strcpy(copy[i], original[i]);
	}

	for (i = 0; i < MAX_LINE_NUMBER; i++) {
		token = strtok(copy[i], " ");
		while (token) {
			tmp = strlen(token);
			if (tmp > max)
				max = tmp;

			token = strtok(NULL, " ");
		}
	}

	return max;
}

//Finding the number of chars in the longest line  
int longest_line_length(char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	int i, max = 0, tmp;
	for (i = 0; i < MAX_LINE_NUMBER; i++) {
		tmp = strlen(original[i]);
		if (tmp > max)
			max = tmp;
	}

	return max;
}

//Checking if the line is empty or not 
int is_empty_line(char *line) {
	int i, length;
	length = strlen(line);
	for (i = 0; i < length; i++)
		if (line[i] != ' ')
			return 0;

	return 1;
}

//Checking if the parameter is a number
int is_number(char *string) {
	int i, length;

	if (string == NULL || !strcmp(string, ""))
		return 0;

	length = strlen(string);
	for (i = 0; i < length; i++) {
		if (!isdigit(string[i]))
			return 0;
	}

	return 1;
}

int string_to_num(char *number) {
	int dec = 0, i, len;

	if (number == NULL)
		return 0;

	len = strlen(number);
	for (i = 0; i < len; i++) {
		dec = dec * 10 + (number[i] - '0');
	}

	return dec;
}

//Changing the spaces from 
void eliminate_last_spaces(char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	int i, j, length;
	for (i = 999; i >= 0; i--) {
		if (!is_empty_line(original[i])) {
			length = strlen(original[i]);
			for (j = length - 2; j >= 0; j--) {
				if (original[i][j] == ' ' || original[i][j] == '\t' || original[i][j] == '\n') {
					original[i][j] = '\n';
					original[i][j + 1] = '\0';
				} else
					break;
			}
		}
	}
}

//Wrapping text and checking existence of wrap parameters
int execute_command_W(char *command[MAX_NUMBER_PARAMATERS], char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER], int *original_line_count) {
	int max_line_length, crt_length, i, j, k, line_start, word_length, longest_word, starting_whitespaces;
	char copy[MAX_LINE_NUMBER][MAX_LINE_NUMBER], *token;

	if (command[2] != NULL) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}


	if (command[1] != NULL) {
		if (is_number(command[1]))
			max_line_length = string_to_num(command[1]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	// Check if all the words are smaller than wrap dimension
	longest_word = min_word_length(original);
	if (longest_word > max_line_length) {
		printf("%s\n", INVALID_WRAP);
		return 0;
	}

	for (i = 0; i < MAX_LINE_NUMBER; i++) {
		strcpy(copy[i], original[i]);
	}

	crt_length = 0;
	j = 0;
	for (i = 0; i < *original_line_count; i++) {
		starting_whitespaces = nr_spaces(copy[i], 1);
		token = strtok(copy[i], " ");
		line_start = 1;
		while (token) {
			word_length = strlen(token);

			if (!strcmp(token, "\n")) {
				if (line_start) {
					original[j][crt_length - 1] = '\n';
					original[j][crt_length] = '\0';
					j++;
					original[j][0] = '\n';
					original[j][1] = '\0';
					j++;
					crt_length = 0;
				}

				token = strtok(NULL, " ");
				line_start = 0;
				continue;
			}

			if (token[word_length - 1] == '\n')
				word_length--;

			if (starting_whitespaces && line_start && ((i == 0) || copy[i - 1][0] == '\n')
				&& (crt_length == 0 || crt_length + word_length > max_line_length)) {

				// End previous line
				if(crt_length != 0) {
					original[j][crt_length - 1] = '\n';
					original[j][crt_length] = '\0';
					j++;
				}

				// Remove starting whitespaces until they are fewer than wrap size
				while (starting_whitespaces > max_line_length) {
					original[j][0] = '\n';
					original[j][1] = '\0';
					j++;
					starting_whitespaces -= max_line_length;
				}

				// Eliminate a starting whitespace
				if (i != 0)
					starting_whitespaces--;

				// Add starting whitespaces
				for (k = 0; k < starting_whitespaces; k++)
					original[j][k] = ' ';
				crt_length = starting_whitespaces;
			}

			if (crt_length + word_length <= max_line_length) {
				strncpy(original[j] + crt_length, token, word_length);
				strncpy(original[j] + crt_length + word_length, " ", word_length);
				crt_length += word_length + 1;
			} else {
				original[j][crt_length - 1] = '\n';
				original[j][crt_length] = '\0';
				j++;
				strncpy(original[j], token, word_length);
				strncpy(original[j] + word_length, " ", word_length);
				crt_length = word_length + 1;
			}

			line_start = 0;

			token = strtok(NULL, " ");
		}
	}
	original[j][crt_length - 1] = '\n';
	original[j][crt_length] = '\0';
	*original_line_count = j + 1;

	return 1;
}

//Center text and checking the existence of center parameters
int execute_command_C(char *command[MAX_NUMBER_PARAMATERS], char original[1000][1000]) {
	int first_row = 0, last_row = 1000, i, j, line_length, additional_spaces, max_line_length;
	char tmp_line[1000];

	if (command[3] != NULL) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}


	if (command[1] != NULL) {
		if (is_number(command[1]))
			first_row = string_to_num(command[1]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	if (command[2] != NULL) {
		if (is_number(command[2]))
			last_row = string_to_num(command[2]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	if (first_row > last_row) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	last_row = min(last_row, last_line(original) + 1);
	if (first_row > last_row) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	max_line_length = longest_line_length(original);

	for (i = first_row; i <= last_row; i++) {
		line_length = strlen(original[i]);
		if ((max_line_length - line_length) % 2 == 0)
			additional_spaces = (max_line_length - line_length) / 2;
		else
			additional_spaces = (max_line_length - line_length) / 2 + 1;

		strcpy(tmp_line, original[i]);
		strncpy(original[i] + additional_spaces, tmp_line, line_length);

		for (j = 0; j < additional_spaces; j++) {
			original[i][j] = ' ';
		}
	}
	eliminate_last_spaces(original);
	return 1;
}

//Align left of text and checking the existence of align left parameters
int execute_command_L(char *command[MAX_NUMBER_PARAMATERS], char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	int first_row = 0, last_row = MAX_LINE_NUMBER, space_count, i, j, line_length;
	char tmp_line[MAX_LINE_NUMBER];

	if (command[3] != NULL) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[1] != NULL) {
		if (is_number(command[1]))
			first_row = string_to_num(command[1]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	if (command[2] != NULL) {
		if (is_number(command[2]))
			last_row = string_to_num(command[2]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	last_row = min(last_row, last_line(original) + 1);
	if (first_row > last_row) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	for (i = first_row; i <= last_row; i++) {
		if (is_empty_line(original[i])) {
			continue;
		}
		line_length = strlen(original[i]);
		space_count = 0;
		for (j = 0; j < line_length; j++) {
			if (original[i][j] != ' ')
				break;
			space_count++;
		}

		strcpy(tmp_line, original[i]);
		strncpy(original[i], tmp_line + space_count, line_length - space_count);
		original[i][line_length - space_count] = '\0';
	}
	eliminate_last_spaces(original);
	return 1;
}

//Align right of text and checking the existence of align right parameters
int execute_command_R(char *command[MAX_NUMBER_PARAMATERS], char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	int first_row = 0, last_row = MAX_LINE_NUMBER, i, j, line_length, align_length;
	char tmp_line[MAX_LINE_NUMBER];

	if (command[3] != NULL) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[1] != NULL) {
		if (is_number(command[1]))
			first_row = string_to_num(command[1]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	if (command[2] != NULL) {
		if (is_number(command[2]))
			last_row = string_to_num(command[2]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	last_row = min(last_row, last_line(original) + 1);
	if (first_row > last_row) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	align_length = longest_line_length(original);

	for (i = first_row; i <= last_row; i++) {
		if (is_empty_line(original[i])) {
			last_row++;
			continue;
		}
		line_length = strlen(original[i]);

		strcpy(tmp_line, original[i]);
		strncpy(original[i] + align_length - line_length, tmp_line, line_length);
		for (j = 0; j < align_length - line_length; j++)
			original[i][j] = ' ';
	}
	eliminate_last_spaces(original);
	return 1;
}

//Indenting paragraphs and checking the existence of paragraph parameters
int execute_command_P(char *command[MAX_NUMBER_PARAMATERS], char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	int first_row = 0, last_row = MAX_LINE_NUMBER, i, j, line_length, indent_length;
	char tmp_line[MAX_LINE_NUMBER];

	if (command[4] != NULL) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[1] == NULL || !is_number(command[1])) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[2] != NULL) {
		if (is_number(command[2]))
			first_row = string_to_num(command[2]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	if (command[3] != NULL) {
		if (is_number(command[3]))
			last_row = string_to_num(command[3]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	last_row = min(last_row, last_line(original) + 1);
	if (first_row > last_row) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	indent_length = string_to_num(command[1]);

	for (i = first_row; i <= last_row; i++) {
		if (i == 0 || original[i - 1][0] == '\n') {
			line_length = strlen(original[i]);
			strcpy(tmp_line, original[i]);
			strncpy(original[i] + indent_length, tmp_line, line_length);
			for (j = 0; j < indent_length; j++)
				original[i][j] = ' ';
		}
	}

	return 1;
}

//List func and checking the existence of list parameters
int execute_command_I(char *command[MAX_NUMBER_PARAMATERS], char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	int first_row = 0, last_row = MAX_LINE_NUMBER, i, line_length, contor, padding;
	char tmp_line[MAX_LINE_NUMBER], list_type, special_character;

	if (command[5] != NULL) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}


	if (command[1] == NULL || !is_corect_list_type(command[1])) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[2] == NULL || strlen(command[2]) != 1) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[3] != NULL) {
		if (is_number(command[3]))
			first_row = string_to_num(command[3]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	if (command[4] != NULL) {
		if (is_number(command[4]))
			last_row = string_to_num(command[4]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	last_row = min(last_row, last_line(original) + 1);
	if (first_row > last_row) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	list_type = command[1][0];
	special_character = command[2][0];
	contor = 0;
	padding = 1;

	for (i = first_row; i <= last_row; i++) {
		line_length = strlen(original[i]);
		strcpy(tmp_line, original[i]);

		switch (list_type) {
			case 'n':
				sprintf(original[i], "%d", contor + 1);
				padding = digits_number(contor + 1);
				original[i][padding] = ' ';
				break;
			case 'a':
				original[i][0] = contor + 'a';
				break;
			case 'A':
				original[i][0] = contor + 'A';
				break;
			default:
				break;
		}

		if (list_type == 'b') {
			strncpy(original[i] + 2, tmp_line, line_length);
			strcpy(original[i] + 2 + line_length, "\0");
			original[i][0] = special_character;
			original[i][1] = ' ';
		} else {
			strncpy(original[i] + 2 + padding, tmp_line, line_length);
			strcpy(original[i] + 2 + padding + line_length, "\0");
			original[i][padding] = special_character;
			original[i][1 + padding] = ' ';
		}

		contor++;
	}

	eliminate_last_spaces(original);
	return 1;
}

//Ordered list func and checking the existence of ordered list parameters
int execute_command_O(char *command[MAX_NUMBER_PARAMATERS], char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	int first_row = 0, last_row = MAX_LINE_NUMBER, i, line_length, contor, padding;
	char tmp_line[MAX_LINE_NUMBER], list_type, special_character, order, *align_left_command[6];

	if (command[1] == NULL || !is_corect_list_type(command[1])) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[2] == NULL || strlen(command[2]) != 1) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[3] == NULL || (strcmp(command[3], "a") != 0 && strcmp(command[3], "z") != 0)) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[4] != NULL) {
		if (is_number(command[4]))
			first_row = string_to_num(command[4]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	if (command[5] != NULL) {
		if (is_number(command[5]))
			last_row = string_to_num(command[5]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	last_row = min(last_row, last_line(original) + 1);
	if (first_row > last_row) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	list_type = command[1][0];
	special_character = command[2][0];
	order = command[3][0];
	contor = 0;
	padding = 1;


	sort_lines(original, first_row, last_row, order);
	align_left_command[0] = "L";
	align_left_command[1] = NULL;
	align_left_command[2] = NULL;
	align_left_command[3] = NULL;
	align_left_command[4] = NULL;
	align_left_command[5] = NULL;
	execute_command_L(align_left_command, original);
	for (i = first_row; i <= last_row; i++) {
		line_length = strlen(original[i]);
		strcpy(tmp_line, original[i]);

		switch (list_type) {
			case 'n':
				sprintf(original[i], "%d", contor + 1);
				padding = digits_number(contor + 1);
				original[i][padding] = ' ';
				break;
			case 'a':
				original[i][0] = contor + 'a';
				break;
			case 'A':
				original[i][0] = contor + 'A';
				break;
			default:
				break;
		}

		if (list_type == 'b') {
			strncpy(original[i] + 2, tmp_line, line_length);
			original[i][0] = special_character;
			original[i][1] = ' ';
			original[i][line_length + 3] = '\0';
		} else {
			strncpy(original[i] + 2 + padding, tmp_line, line_length);
			original[i][padding] = special_character;
			original[i][1 + padding] = ' ';
			original[i][line_length + 3 + padding] = '\0';
		}

		contor++;
	}

	eliminate_last_spaces(original);
	return 1;
}

//Justify and checking the parameters of justify
int execute_command_J(char *command[MAX_NUMBER_PARAMATERS], char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER]) {
	int spaces_needed, spaces_between, line_letters, line_words, longest_line, crt_length;
	int first_row = 0, last_row = 1000, i, k, additional_spaces;
	char tmp_line[1000], *token, *align_left_command[6];

	if (command[4] != NULL) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	if (command[1] != NULL) {
		if (is_number(command[1]))
			first_row = string_to_num(command[1]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	if (command[2] != NULL) {
		if (is_number(command[2]))
			last_row = string_to_num(command[2]);
		else {
			printf("%s\n", INVALID_OPERATION);
			return 0;
		}
	}

	last_row = min(last_row, last_line(original) + 1);
	if (first_row > last_row) {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}

	longest_line = longest_line_length(original);
	for (i = first_row; i <= last_row; i++) {
		if (original[i][0] == '\n' || original[i + 1][0] == '\n' || i == last_line(original) + 1) {
			align_left_command[0] = "L";
			align_left_command[1] = malloc(digits_number(i) * sizeof(char));
			align_left_command[2] = malloc(digits_number(i) * sizeof(char));
			sprintf(align_left_command[1], "%d", i);
			sprintf(align_left_command[2], "%d", i);
			align_left_command[3] = NULL;
			align_left_command[4] = NULL;
			align_left_command[5] = NULL;
			execute_command_L(align_left_command, original);
			free(align_left_command[1]);
			free(align_left_command[2]);
			continue;
		}

		crt_length = 0;
		strcpy(tmp_line, original[i]);
		line_letters = letters_in_line(tmp_line);
		line_words = words_in_line(tmp_line);
		spaces_needed = longest_line - line_letters - 1;
		spaces_between = (longest_line - line_letters - 1) / (line_words - 1);
		additional_spaces = spaces_needed % (line_words - 1);

		token = strtok(tmp_line, " \t");
		strcpy(original[i], token);
		crt_length += strlen(token);
		while (spaces_needed) {
			for (k = 0; k < spaces_between; k++) {
				strcpy(original[i] + crt_length, " ");
				crt_length++;
				spaces_needed--;
			}

			if (additional_spaces) {
				strcpy(original[i] + crt_length, " ");
				crt_length++;
				additional_spaces--;
				spaces_needed--;
			}

			token = strtok(NULL, " ");
			strcpy(original[i] + crt_length, token);
			crt_length += strlen(token);
		}
	}


	eliminate_last_spaces(original);
	return 1;
}

//Verify which operation to execute
int execute_command(char *command[MAX_NUMBER_PARAMATERS], char original[MAX_LINE_NUMBER][MAX_LINE_NUMBER], int *original_line_count) {

	if (!strcmp(command[0], "w") || !strcmp(command[0], "W")) {
		return execute_command_W(command, original, original_line_count);
	} else if (!strcmp(command[0], "c") || !strcmp(command[0], "C")) {
		return execute_command_C(command, original);
	} else if (!strcmp(command[0], "l") || !strcmp(command[0], "L")) {
		return execute_command_L(command, original);
	} else if (!strcmp(command[0], "r") || !strcmp(command[0], "R")) {
		return execute_command_R(command, original);
	} else if (!strcmp(command[0], "p") || !strcmp(command[0], "P")) {
		return execute_command_P(command, original);
	} else if (!strcmp(command[0], "i") || !strcmp(command[0], "I")) {
		return execute_command_I(command, original);
	} else if (!strcmp(command[0], "o") || !strcmp(command[0], "O")) {
		return execute_command_O(command, original);
	} else if (!strcmp(command[0], "j") || !strcmp(command[0], "J")) {
		return execute_command_J(command, original);
	} else {
		printf("%s\n", INVALID_OPERATION);
		return 0;
	}
}

int main(int argc, char *argv[]) {
	char buf[MAX_LINE_NUMBER],               // buffer used for reading from the file
			original[MAX_LINE_NUMBER][MAX_LINE_NUMBER],     // original text, line by line
			result[MAX_LINE_NUMBER][MAX_LINE_NUMBER];       // text obtained after applying operations
	int original_line_count = 0,  // number of lines in the input file
			result_line_count = 0,    // number of lines in the output file
			i, original_line_count_copy;
	char original_copy[MAX_LINE_NUMBER][MAX_LINE_NUMBER];

	int operations_num = 0;

	char *saveptr1, *saveptr2, *command_tmp, *parameter_tmp;
	char *command[MAX_NUMBER_PARAMATERS];


	if (argc != 4) {  // invalid number of arguments
		fprintf(stderr,
				"Usage: %s operations_string input_file output_file\n",
				argv[0]);
		return -1;
	}

	// Open input file for reading
	FILE *input_file = fopen(argv[2], "r");

	if (input_file == NULL) {
		fprintf(stderr, "File \"%s\" not found\n", argv[2]);
		return -2;
	}

	// Read data in file line by line
	while (fgets(buf, 1000, input_file)) {
		strcpy(original[original_line_count], buf);
		original_line_count++;
	}

	fclose(input_file);

	for (i = 0; i < original_line_count; i++)
		strcpy(original_copy[i], original[i]);
	original_line_count_copy = original_line_count;

	command_tmp = strtok_r(argv[1], ",", &saveptr1);
	while (command_tmp) {
		operations_num++;
		i = 0;
		parameter_tmp = strtok_r(command_tmp, " ", &saveptr2);
		while (parameter_tmp) {
			command[i] = parameter_tmp;
			i++;
			parameter_tmp = strtok_r(NULL, " ", &saveptr2);
		}

		for (; i < MAX_NUMBER_PARAMATERS; i++)
			command[i] = NULL;

		if (!execute_command(command, original, &original_line_count)) {
			for (i = 0; i < original_line_count_copy; i++)
				strcpy(original[i], original_copy[i]);
			original_line_count = original_line_count_copy;
			break;
		}

		command_tmp = strtok_r(NULL, ",", &saveptr1);
	}

	for (i = 0; i < original_line_count; i++) {
		strcpy(result[i], original[i]);
	}
	result_line_count = original_line_count;

	// Open output file for writing
	FILE *output_file = fopen(argv[3], "w");

	if (output_file == NULL) {
		fprintf(stderr, "Could not open or create file \"%s\"\n", argv[3]);
		return -2;
	}

	// Write result in output file
	for (i = 0; i < result_line_count; i++) {
		fputs(result[i], output_file);
	}

	fclose(output_file);
}
