#pragma once
#include <iostream>
#include "../../../api_build.h"

namespace Stylite
{
	template <typename T>
	class Vector4
	{
	public:
		Vector4();
		Vector4(T x, T y, T z, T w);

		union
		{
			struct
			{
				T x, y, z, w;
			};

			struct
			{
				T r, g, b, a;
			};
		};

		bool operator==(const Vector4& vec);
		T& operator[](size_t idx);
		const T& operator[](size_t idx) const;

		Vector4 operator*(const Vector4& vec);
		Vector4 operator/(const Vector4& vec);
		Vector4 operator+(const Vector4& vec);
		Vector4 operator-(const Vector4& vec);

		Vector4 operator*(T rhs);
		Vector4 operator/(T rhs);
		Vector4 operator+(T rhs);
		Vector4 operator-(T rhs);

		T Length();
		T LengthSquared();
		Vector4 Normalize();
		Vector4 Negate();

		~Vector4();
	};

	class STYLITE_API Color : public Vector4<float>
	{
	public:
		Color();
		Color(float r, float g, float b, float a);

		Color OpenGLFormat();
	};

	template<typename T>
	inline Vector4<T>::Vector4() : x(0), y(0), z(0), w(0)
	{
	}

	template<typename T>
	inline Vector4<T>::Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w)
	{
	}

	template<typename T>
	inline std::ostream& operator<<(std::ostream& stream, const Vector4<T>& vec)
	{
		stream << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
		return stream;
	}

	template<typename T>
	inline bool Vector4<T>::operator==(const Vector4 & vec)
	{
		return (x == vec.x && y == vec.y && z == vec.z && w == vec.w);
	}

	template<typename T>
	inline T & Vector4<T>::operator[](size_t idx)
	{
		if (idx > 3 || idx < 0) throw std::out_of_range::exception("Invalid Element");
		return *(T*)(&x + idx);
	}

	template<typename T>
	inline const T & Vector4<T>::operator[](size_t idx) const
	{
		if (idx > 3 || idx < 0) throw std::out_of_range::exception("Invalid Element");
		return *(T*)(&x + idx);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator*(const Vector4<T> & vec)
	{
		return Vector4<T>(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator/(const Vector4<T> & vec)
	{
		return Vector4<T>(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator+(const Vector4<T> & vec)
	{
		return Vector4<T>(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator-(const Vector4<T> & vec)
	{
		return Vector4<T>(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator*(T rhs)
	{
		return Vector4<T>(x * rhs, y * rhs, z * rhs, w * rhs);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator/(T rhs)
	{
		return Vector4<T>(x / rhs, y / rhs, z / rhs, w / rhs);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator+(T rhs)
	{
		return Vector4<T>(x + rhs, y + rhs, z + rhs, w + rhs);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator-(T rhs)
	{
		return Vector4<T>(x - rhs, y - rhs, z - rhs, w - rhs);
	}

	template<typename T>
	inline T Vector4<T>::Length()
	{
		return (T)(sqrtf(x * x + y * y + z * z + w * w));
	}

	template<typename T>
	inline T Vector4<T>::LengthSquared()
	{
		return (T)(x * x + y * y + z * z + w * w);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::Normalize()
	{
		T magnitude = this->Length();
		return Vector4<T>(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::Negate()
	{
		return Vector4<T>(-x, -y, -z, -w);
	}

	template<typename T>
	inline Vector4<T>::~Vector4()
	{
	}
}
