
enum {
  hr_size = 2
};

typedef struct {
  char *hr_extf;
  char *hr_open;
  char *hr_done;
  char *hr_line;
} Header;


size_t ft_strlen(const char *s) {
  if (!s) {
    return 0;
  }
  size_t i = 0;
  while (*(s + i) != '\0') {
    i++;
  }
  return i;
}

void ft_putchar(const char c) {
  write(1, &c, 1);
}

void ft_puts(const char *s) {
  write(1, s, ft_strlen(s));
}

void ft_strcpy(char *dst, const char *src) {
  size_t len = ft_strlen(src);
  size_t i = 0;
  while (i < len) {
    dst[i] = src[i];
    i++;
  }
}

int ft_strcmp(const char *obj, const char *sub) {
  if (!obj || !sub) return 1;

  size_t i = 0;
  while (obj[i] != '\0') {
    if (obj[i] != sub[i]) return 0;
    i++;
  }

  return 1;
}

char *extract_ext(char *s) {
  if (!s) return NULL;
  
  size_t i;
  size_t len;
  i = len = ft_strlen(s);
  while (s[i] != '.') {
    i--;
  }
  char *ext = malloc(len - i);

  len = 0;
  while (s[i] != '\0') {
  ext[len] = s[i];
  len++;
  i++;
  }
  ext[len] = '\0';

  return ext;
}

Header *create_hr(char *s) {
  if (s == NULL) return NULL;

  char *ext = extract_ext(s);
  if (ext == NULL) return NULL;

  const size_t BYTES = 4;
  Header *hr = malloc(sizeof *hr);
  if (hr == NULL) return NULL;

  hr->hr_extf = malloc(ft_strlen(ext) + 1);
  if (hr->hr_extf == NULL) {
    free(hr);
    return NULL;
  }
  hr->hr_open = malloc(BYTES + 1);
  if (hr->hr_open == NULL) {
    free(hr);
    return NULL;
  }

  hr->hr_done = malloc(BYTES + 1);
  if (hr->hr_done == NULL) {
    free(hr);
    return NULL;
  }
  hr->hr_line = malloc(BYTES + 1);
  if (hr->hr_done == NULL) {
    free(hr);
    return NULL;
  }

  ft_strcpy(hr->hr_extf, ext); 

  if (ft_strcmp(".lua", ext)) {
    ft_strcpy(hr->hr_open, "--[[");
    ft_strcpy(hr->hr_done, "]]");
    ft_strcpy(hr->hr_line, " ");
  }
  else if (ft_strcmp(".html", ext)) {
    ft_strcpy(hr->hr_open, "<!--");
    ft_strcpy(hr->hr_done, "-->");
    ft_strcpy(hr->hr_line, "-");
  }
  else if (ft_strcmp(".gd", ext) || (ft_strcmp(".py", ext))) {
    ft_strcpy(hr->hr_open, "\"\"\"");
    ft_strcpy(hr->hr_done, "\"\"\"");
    ft_strcpy(hr->hr_line, " ");
  }
  else if (ft_strcmp(".sh", ext)) {
    ft_strcpy(hr->hr_open, ": '");
    ft_strcpy(hr->hr_done, "'");
    ft_strcpy(hr->hr_line, " ");
  }
  else {
    ft_strcpy(hr->hr_open, "/*");
    ft_strcpy(hr->hr_done, "*/");
    ft_strcpy(hr->hr_line, "*");
  }

  return hr;
}

void destroy_hr(Header **hr) {
  free((*hr)->hr_extf);
  free((*hr)->hr_open);
  free((*hr)->hr_done);
  free((*hr)->hr_line);
  free(*hr);
  *hr = NULL;
}

