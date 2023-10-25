/* This function finds the first occurrence of a given pattern in the text and returns the number position.
If nothing is found, -1 is returned.*/

int strstr(char *text, char *pattern) {
	if ((*pattern) != '\0') {

		int position = -1;
		int *number_position = &position;
		int position_pattern = 0;
		int *number_position_pattern = &position_pattern;
		char *first_pattern = pattern;

		while ((*text) != '\0') {
			(*number_position)++;
			while ((*text) == (*pattern)) {
				++text;
				++pattern;
				if ((*pattern) == '\0') {
					return position;
				}
				if ((*text) != (*pattern)) {
					--text;
					break;
				}
				++(*number_position_pattern);
			}
			++text;
			(*number_position) += (*number_position_pattern);
			pattern = first_pattern;
			*number_position_pattern = 0;
		}
		return -1;
	}
	return 0;
}
