#include "Vector.h"

STYLITE_API float Stylite::radians(float deg)
{
	return (deg * (3.141592653589793f / 180.0f));
}

STYLITE_API float Stylite::degrees(float rad)
{
	return (rad * (180.0f / 3.141592653589793f));
}
