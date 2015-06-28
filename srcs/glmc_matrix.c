#include <glmc.h>
#include <math.h>

void			glmc_identity(t_mat4 dest)
{
	dest[0] = 1.0;
	dest[1] = 0.0;
	dest[2] = 0.0;
	dest[3] = 0.0;
	dest[4] = 0.0;
	dest[5] = 1.0;
	dest[6] = 0.0;
	dest[7] = 0.0;
	dest[8] = 0.0;
	dest[9] = 0.0;
	dest[10] = 1.0;
	dest[11] = 0.0;
	dest[12] = 0.0;
	dest[13] = 0.0;
	dest[14] = 0.0;
	dest[15] = 1.0;
}

void			glmc_scale(t_mat4 m, t_vec3 scale, t_mat4 dest)
{
    dest[0] = m[0] * scale[X];
    dest[1] = m[1] * scale[X];
    dest[2] = m[2] * scale[X];
    dest[3] = m[3] * scale[X];
    dest[4] = m[4] * scale[Y];
    dest[5] = m[5] * scale[Y];
    dest[6] = m[6] * scale[Y];
    dest[7] = m[7] * scale[Y];
    dest[8] = m[8] * scale[Z];
    dest[9] = m[9] * scale[Z];
    dest[10] = m[10] * scale[Z];
    dest[11] = m[11] * scale[Z];
    dest[12] = m[12];
    dest[13] = m[13];
    dest[14] = m[14];
    dest[15] = m[15];
}

void			glmc_rotate(t_mat4 m, double angle, t_vec3 axis, t_mat4 dest)
{
	double		n[9];
	double		sinus = sin(angle);
	double		cosinus = cos(angle);
	double		tang = 1.0 - cosinus;

	glmc_normalize(axis);
	n[0] = axis[X] * axis[X] * tang + cosinus;
	n[1] = axis[Y] * axis[X] * tang + axis[Z] * sinus;
	n[2] = axis[Z] * axis[X] * tang - axis[Y] * sinus;
	n[3] = axis[X] * axis[Y] * tang - axis[Z] * sinus;
	n[4] = axis[Y] * axis[Y] * tang + cosinus;
	n[5] = axis[Z] * axis[Y] * tang + axis[X] * sinus;
	n[6] = axis[X] * axis[Z] * tang + axis[Y] * sinus;
	n[7] = axis[Y] * axis[Z] * tang - axis[X] * sinus;
	n[8] = axis[Z] * axis[Z] * tang + cosinus;
	dest[0] = m[0] * n[0] + m[4] * n[1] + m[8] * n[2];
	dest[1] = m[1] * n[0] + m[5] * n[1] + m[9] * n[2];
	dest[2] = m[2] * n[0] + m[6] * n[1] + m[10] * n[2];
	dest[3] = m[3] * n[0] + m[7] * n[1] + m[11] * n[2];
	dest[4] = m[0] * n[3] + m[4] * n[4] + m[8] * n[5];
	dest[5] = m[1] * n[3] + m[5] * n[4] + m[9] * n[5];
	dest[6] = m[2] * n[3] + m[6] * n[4] + m[10] * n[5];
	dest[7] = m[3] * n[3] + m[7] * n[4] + m[11] * n[5];
	dest[8] = m[0] * n[6] + m[4] * n[7] + m[8] * n[8];
	dest[9] = m[1] * n[6] + m[5] * n[7] + m[9] * n[8];
	dest[10] = m[2] * n[6] + m[6] * n[7] + m[10] * n[8];
	dest[11] = m[3] * n[6] + m[7] * n[7] + m[11] * n[8];
	dest[12] = m[12];
	dest[13] = m[13];
	dest[14] = m[14];
	dest[15] = m[15];
}

void			glmc_translate(t_mat4 m, t_vec3 vec, t_mat4 dest)
{
	dest[0] = m[0];
	dest[1] = m[1];
	dest[2] = m[2];
	dest[3] = m[3];
	dest[4] = m[4];
	dest[5] = m[5];
	dest[6] = m[6];
	dest[7] = m[7];
	dest[8] = m[8];
	dest[9] = m[9];
	dest[10] = m[10];
	dest[11] = m[11];
	dest[12] = m[0] * vec[X] + m[4] * vec[Y] + m[8] * vec[Z] + m[12];
	dest[13] = m[1] * vec[X] + m[5] * vec[Y] + m[9] * vec[Z] + m[13];
	dest[14] = m[2] * vec[X] + m[6] * vec[Y] + m[10] * vec[Z] + m[14];
	dest[15] = m[3] * vec[X] + m[7] * vec[Y] + m[11] * vec[Z] + m[15];
}
