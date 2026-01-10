typedef struct {
  char *hr_open;
  char *hr_done;
  char *hr_line;
  size_t hr_open_size;
  size_t hr_done_size;
  size_t hr_line_size;
} Header;

typedef struct {
  char *name;
  char *info;
  size_t name_size;
  size_t info_size;
} Detail;

typedef struct {
  char *name;
  char *exts;
  size_t name_size;
  size_t exts_size;
} Filename;

enum {
  HEADER_WIDTH = 80,
  LEFT_PADDING = 3,
};

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
  char *ext = malloc(len - i + 1);

  len = 0;
  while (s[i] != '\0') {
  ext[len] = s[i];
  len++;
  i++;
  }
  ext[len] = '\0';

  return ext;
}

char *extract_fil(char *s) {
  if (!s) return NULL;

  size_t len = ft_strlen(s);
  size_t i = len;
  while (s[i] != '.') {
    i--;
  }
  char *filename = malloc(i + 1);
  len = 0;
  while (len < i) {
    filename[len] = s[len];
    len++;
  }
  filename[len] = '\0';

  return filename;
}

Header *create_hr(char *s) {
  if (s == NULL) return NULL;

  const size_t BYTES = 4;
  Header *hr = malloc(sizeof *hr);
  if (hr == NULL) return NULL;

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

  if (ft_strcmp(".lua", s)) {
    ft_strcpy(hr->hr_open, "--");
    ft_strcpy(hr->hr_done, "--");
    ft_strcpy(hr->hr_line, "-");
  }
  else if (ft_strcmp(".html", s)) {
    ft_strcpy(hr->hr_open, "<!--");
    ft_strcpy(hr->hr_done, "-->");
    ft_strcpy(hr->hr_line, "-");
  }
  else if (ft_strcmp(".gd", s) || (ft_strcmp(".py", s))) {
    ft_strcpy(hr->hr_open, "#");
    ft_strcpy(hr->hr_done, "#");
    ft_strcpy(hr->hr_line, "#");
  }
  else if (ft_strcmp(".sh", s)) {
    ft_strcpy(hr->hr_open, ": '");
    ft_strcpy(hr->hr_done, "'");
    ft_strcpy(hr->hr_line, " ");
  }
  else {
    ft_strcpy(hr->hr_open, "/*");
    ft_strcpy(hr->hr_done, "*/");
    ft_strcpy(hr->hr_line, "*");
  }

  hr->hr_open_size = ft_strlen(hr->hr_open);
  hr->hr_done_size = ft_strlen(hr->hr_done);
  hr->hr_line_size = ft_strlen(hr->hr_line);

  return hr;
}

void destroy_hr(Header **hr) {
  free((*hr)->hr_open);
  free((*hr)->hr_done);
  free((*hr)->hr_line);
  free(*hr);
  *hr = NULL;
}

char *current() {
  time_t now;
  time(&now);
  char *t = ctime(&now);
  *(t + ft_strlen(t) - 1) = '\0';

  return t;
}
