#include <unistd.h>
#include <string.h>
void			ft_putchar(char c);
void			ft_putnbr(int n);
int				ft_strlen(const char *s);
char			*ft_strcpy(char * dst, const char * src);
char			*ft_strncpy(char * dst, const char * src, int len);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strncat(char *s1, char *s2, int n);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size);
int				strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int 			ft_isalpha(int c);
int 			ft_isdigit(int c);
int 			ft_isalnum(int c);
int 			ft_isprint(int c);
unsigned char   ft_toupper(int c);
unsigned char	ft_lower(int c);
char   			*ft_strchr(const char *s, int c);
char    		*ft_strrchr(const char *s, int c);
char   			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
