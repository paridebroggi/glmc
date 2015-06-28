#include <math.h>
#include <glmc.h>

void		glmc_vec3(double x, double y, double z, t_vec3 dest)
{
	dest[X] = x;
	dest[Y] = y;
	dest[Z] = z;
}

void		glmc_vec4(double x, double y, double z, double w, t_vec4 dest)
{
	dest[X] = x;
	dest[Y] = y;
	dest[Z] = z;
	dest[W] = w;
}

void		glmc_sub_vec3(t_vec3 v1, t_vec3 v2, t_vec3 dest)
{
	dest[X] = v1[X] - v2[X];
	dest[Y] = v1[Y] - v2[Y];
	dest[Z] = v1[Z] - v2[Z];
}

void		glmc_sub_vec4(t_vec4 v1, t_vec4 v2, t_vec4 dest)
{
	dest[X] = v1[X] - v2[X];
	dest[Y] = v1[Y] - v2[Y];
	dest[Z] = v1[Z] - v2[Z];
	dest[W] = v1[W] - v2[W];
}

void		glmc_cross(t_vec3 v1, t_vec3 v2, t_vec3 dest)
{
	dest[X] = v1[Y] * v2[Z] - v1[Z] * v2[Y];
	dest[Y] = v1[Z] * v2[X] - v1[X] * v2[Z];
	dest[Z] = v1[X] * v2[Y] - v1[Y] * v2[X];
}

void		glmc_normalize(t_vec3 v)
{
	double 	magnitude;

	magnitude = sqrt(v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z]);
	if (magnitude == 0.0)
	{
        v[X] = 0.0;
        v[Y] = 0.0;
        v[Z] = 0.0;
        return ;
    }
	v[X] /= magnitude;
	v[Y] /= magnitude;
	v[Z] /= magnitude;
}