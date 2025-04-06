int i = 0;

// Returns the length of an array
int ft_strlen(char *c) {
	i = 0;
	while (c[i] != '\0') {
		i++;
	}
	return i;
}

// Copies an array to another array
void ft_strcpy(char *n, char *v) {
	i = 0;
	while (i < ft_strlen(v) && v[i] != '\0') {
		n[i] = v[i]; 
		i++;
	}
}

// Checks if an array has a character `a`
int ft_stravz(char *c, char a) {
	i = 0;
	while (c[i] != '\0') {
		if (c[i] == a) {
			return 1;
		}
		i++;
	}
	return 0;
}