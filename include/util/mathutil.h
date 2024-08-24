#ifndef MATHUTIL_H
#define MATHUTIL_H

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832
#endif

#ifndef M_SQRT2
#define M_SQRT2	1.41421356237309504880
#endif

static inline v2d i2d(v2i i)
{
	return (v2d) {
	(double)i.x, (double)i.y};
}

static inline v2i d2i(v2d d)
{
	return (v2i) {
	(int)d.x, (int)d.y};
}

static inline double IEEE_754_remainder(double a, double b)
{
	return a - (b * round(a / b));
}

static inline int zundom_i_raw()
{
	return rand() % (2 << 16);
}

static inline int zundom_i(int a)
{
	return zundom_i_raw() % a;
}

static inline int zundom_i2(int a, int b)
{
	return zundom_i(b - a) + a;
}

static inline double zundom_f_raw()
{
	return (double)rand() / RAND_MAX;
}

static inline double zundom_f(double a)
{
	return zundom_f_raw() * a;
}

static inline double zundom_f2(double a, double b)
{
	return a + zundom_f_raw() * (b - a);
}

static inline double ang2rad(double angle)
{
	return M_PI / 180.0f * angle;
}

static inline double rad2ang(double rad)
{
	return rad / M_PI * 180.0f;
}

static inline double rsin(double x)
{
	return sin(ang2rad(x));
}

static inline double rcos(double x)
{
	return cos(ang2rad(x));
}

static inline double rtan(double x)
{
	return tan(ang2rad(x));
}

static inline double rarcsin(double x)
{
	return rad2ang(asin(x));
}

static inline double rarccos(double x)
{
	return rad2ang(acos(x));
}

static inline double rarctan(double x)
{
	return rad2ang(atan(x));
}

// bullet math util
static inline v2d ang2vec(double angle, double speed)
{
	return (v2d) {
	rsin(angle) * speed, -rcos(angle) * speed};
}

static inline double vec2ang(v2d vec)
{
	if (vec.y == 0) {
		return 0.0f;	// fix this if vec.y==0 will cause return a -Nan
	}
	return rarctan(-vec.x / vec.y);
}

static inline float abs_f(float f)
{
	if (f < 0.0f) {
		return -f;
	}
	return f;
}

static inline float abs_d(float d)
{
	if (d < 0.0f) {
		return -d;
	}
	return d;
}

double player_angle(v2d src);

#endif
