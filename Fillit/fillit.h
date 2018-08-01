#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct  s_tet
{
	    int cdif1;
		    int cdif2;
			    int cdif3;
}               c_tet;

int		*validate(int *n, char **argv);
void	zero_all(int **a, int n, int l);
void	upsize_tet(int *a, int l, int init_l);
void	upsize_all(int **a, int l, int init_l, int n);
