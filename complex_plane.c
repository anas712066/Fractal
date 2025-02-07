#include <stdio.h>

typedef struct s_complex
{
	// x
	double	real;
	// y component
	double	i;
}			t_complex;

int	main(void)
{
	int			i;
	t_complex	z;
	t_complex	c;
	double		tmp_real;

	//	point
	z.real = 0;
	z.i = 0;
	c.real = 0.255;
	c.i = 0.42;
	i = 0;
	while (i < 42)
	{
		//General formula
		// z = z^2 + c;
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		//Adding the c values
		z.real += c.real;
		z.i += c.i;
		printf("iteration n -> %d real%f imaginary%f\n", i, z.real, z.i);
		i++;
	}
}
