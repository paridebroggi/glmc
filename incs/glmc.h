#ifndef GLMC_LIBRARY_H
# define GLMC_LIBRARY_H

enum	e_indexes
{
	X = 0,
	Y,
	Z,
	W
};

enum	e_frustum
{
	FOV = 0,
	ASPECT,
	NEAR,
	FAR
};

enum	e_clip
{
	LEFT = 0,
	RIGHT,
	BOTTOM,
	TOP
};

typedef double	t_vec3[3];
typedef double	t_vec4[4];
typedef double	t_mat4[16];

/*
** glmc_model.c
*/
void			glmc_model_matrix(t_vec3 scale_factor, t_vec3 rot_axis, double angle, t_vec3 translation, t_mat4 dest);
void			glmc_look_at(t_vec3 eye, t_vec3 target, t_vec3 up, t_mat4 dest);
void			glmc_perspective(t_vec4 frustum, t_mat4 dest);

/*
** glmc_matrix.c
*/
void			glmc_identity(t_mat4 dest);
void			glmc_rotate(t_mat4 m, double angle, t_vec3 a, t_mat4 dest);
void			glmc_scale(t_mat4 m, t_vec3 scale, t_mat4 dest);
void			glmc_translate(t_mat4 m, t_vec3 vec, t_mat4 dest);

/*
** glmc_vec3.c
*/
void			glmc_vec3(double x, double y, double z, t_vec3 dest);
void			glmc_vec4(double x, double y, double z, double w, t_vec4 dest);
void			glmc_sub_vec3(t_vec3 v1, t_vec3 v2, t_vec3 dest);
void			glmc_sub_vec4(t_vec4 v1, t_vec4 v2, t_vec4 dest);
void			glmc_cross(t_vec3 v1, t_vec3 v2, t_vec3 dest);
void			glmc_normalize(t_vec3 v);

#endif /* ! GLMC_LIBRARY_H */