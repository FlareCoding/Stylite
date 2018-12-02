#pragma once
#include <iostream>
#include "../../../api_build.h"

namespace Stylite
{
	template <typename T>
	class Vector2
	{
	public:
		Vector2();
		Vector2(T x, T y);

		union
		{
			struct
			{
				T x, y;
			};
		};

		bool operator==(const Vector2& vec);
		T& operator[](size_t idx);
		const T& operator[](size_t idx) const;

		Vector2<T> operator*(const Vector2& vec);
		Vector2<T> operator/(const Vector2& vec);
		Vector2<T> operator+(const Vector2& vec);
		Vector2<T> operator-(const Vector2& vec);

		Vector2<T> operator*=(const Vector2& vec);
		Vector2<T> operator/=(const Vector2& vec);
		Vector2<T> operator+=(const Vector2& vec);
		Vector2<T> operator-=(const Vector2& vec);

		Vector2<T> operator*(T rhs);
		Vector2<T> operator/(T rhs);
		Vector2<T> operator+(T rhs);
		Vector2<T> operator-(T rhs);

		Vector2<T> operator*=(T rhs);
		Vector2<T> operator/=(T rhs);
		Vector2<T> operator+=(T rhs);
		Vector2<T> operator-=(T rhs);

		T Length();
		T LengthSquared();
		Vector2<T> Normalize();
		Vector2<T> Negate();
		Vector2<T> Rotate(float degrees);
		static Vector2<T> FrontVector;

		~Vector2();
	};

	template<typename T>
	Vector2<T> Vector2<T>::FrontVector = Vector2<T>((T)0, (T)1);

	template<typename T>
	inline Vector2<T>::Vector2() : x(0), y(0)
	{
	}

	template<typename T>
	inline Vector2<T>::Vector2(T x, T y) : x(x), y(y)
	{
	}

	template<typename T> 
	inline std::ostream& operator<<(std::ostream& stream, const Vector2<T>& vec) 
	{
		stream << vec.x << ", " << vec.y;
		return stream;
	}

	template<typename T>
	inline bool Vector2<T>::operator==(const Vector2<T>& vec)
	{
		return (x == vec.x && y == vec.y);
	}

	template<typename T>
	inline T & Vector2<T>::operator[](size_t idx)
	{
		if (idx > 1 || idx < 0) throw std::out_of_range::exception("Invalid Element");
		return *(T*)(&x + idx);
	}

	template<typename T>
	inline const T & Vector2<T>::operator[](size_t idx) const
	{
		if (idx > 1 || idx < 0) throw std::out_of_range::exception("Invalid Element");
		return *(T*)(&x + idx);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator*(const Vector2<T> & vec)
	{
		return Vector2<T>(x * vec.x, y * vec.y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator/(const Vector2<T> & vec)
	{
		return Vector2<T>(x / vec.x, y / vec.y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator+(const Vector2<T> & vec)
	{
		return Vector2<T>(x + vec.x, y + vec.y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator-(const Vector2<T> & vec)
	{
		return Vector2<T>(x - vec.x, y - vec.y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator*=(const Vector2<T> & vec)
	{
		return Vector2<T>(x *= vec.x, y *= vec.y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator/=(const Vector2<T> & vec)
	{
		return Vector2<T>(x /= vec.x, y /= vec.y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator+=(const Vector2<T> & vec)
	{
		return Vector2<T>(x += vec.x, y += vec.y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator-=(const Vector2<T> & vec)
	{
		return Vector2<T>(x -= vec.x, y -= vec.y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator*(T rhs)
	{
		return Vector2<T>(x * rhs, y * rhs);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator/(T rhs)
	{
		return Vector2<T>(x / rhs, y / rhs);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator+(T rhs)
	{
		return Vector2<T>(x + rhs, y + rhs);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator-(T rhs)
	{
		return Vector2<T>(x - rhs, y - rhs);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator*=(T rhs)
	{
		return Vector2<T>(x *= rhs, y *= rhs);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator/=(T rhs)
	{
		return Vector2<T>(x /= rhs, y /= rhs);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator+=(T rhs)
	{
		return Vector2<T>(x += rhs, y += rhs);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::operator-=(T rhs)
	{
		return Vector2<T>(x -= rhs, y -= rhs);
	}

	template<typename T>
	inline T Vector2<T>::Length()
	{
		return (T)(sqrtf(x * x + y * y));
	}

	template<typename T>
	inline T Vector2<T>::LengthSquared()
	{
		return (T)(x * x + y * y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::Normalize()
	{
		T magnitude = this->Length();
		return Vector2<T>(x / magnitude, y / magnitude);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::Negate()
	{
		return Vector2<T>(-x, -y);
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::Rotate(float degrees)
	{
		T xPrime = (T)(x * cosf((3.141592653589793f / 180.0f) * degrees) - y * sinf((3.141592653589793f / 180.0f) * degrees));
		T yPrime = (T)(x * sinf((3.141592653589793f / 180.0f) * degrees) + y * cosf((3.141592653589793f / 180.0f) * degrees));
		return Vector2<T>(xPrime, yPrime);
	}

	template<typename T>
	inline Vector2<T>::~Vector2()
	{
	}
}