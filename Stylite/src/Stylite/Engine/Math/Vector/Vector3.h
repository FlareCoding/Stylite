#pragma once
#include <iostream>
#include "../../../api_build.h"

namespace Stylite
{
	template <typename T>
	class Vector3
	{
	public:
		Vector3();
		Vector3(T x, T y, T z);

		union
		{
			struct
			{
				T x, y, z;
			};
		};

		bool operator==(const Vector3& vec);
		T& operator[](size_t idx);
		const T& operator[](size_t idx) const;

		Vector3 operator*(const Vector3& vec);
		Vector3 operator/(const Vector3& vec);
		Vector3 operator+(const Vector3& vec);
		Vector3 operator-(const Vector3& vec);

		Vector3 operator*(T rhs);
		Vector3 operator/(T rhs);
		Vector3 operator+(T rhs);
		Vector3 operator-(T rhs);

		T Length();
		T LengthSquared();
		Vector3 Normalize();
		Vector3 Negate();

		~Vector3();
	};

	template<typename T>
	inline Vector3<T>::Vector3() : x(0), y(0), z(0)
	{
	}

	template<typename T>
	inline Vector3<T>::Vector3(T x, T y, T z) : x(x), y(y), z(z)
	{
	}

	template<typename T>
	inline std::ostream& operator<<(std::ostream& stream, const Vector3<T>& vec)
	{
		stream << vec.x << ", " << vec.y << ", " << vec.z;
		return stream;
	}

	template<typename T>
	inline bool Vector3<T>::operator==(const Vector3<T> & vec)
	{
		return (x == vec.x && y == vec.y && z == vec.z);
	}

	template<typename T>
	inline T & Vector3<T>::operator[](size_t idx)
	{
		if (idx > 2 || idx < 0) throw std::out_of_range::exception("Invalid Element");
		return *(T*)(&x + idx);
	}

	template<typename T>
	inline const T & Vector3<T>::operator[](size_t idx) const
	{
		if (idx > 2 || idx < 0) throw std::out_of_range::exception("Invalid Element");
		return *(T*)(&x + idx);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator*(const Vector3<T> & vec)
	{
		return Vector3<T>(x * vec.x, y * vec.y, z * vec.z);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator/(const Vector3<T> & vec)
	{
		return Vector3<T>(x / vec.x, y / vec.y, z / vec.z);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator+(const Vector3<T> & vec)
	{
		return Vector3<T>(x + vec.x, y + vec.y, z + vec.z);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator-(const Vector3<T> & vec)
	{
		return Vector3<T>(x - vec.x, y - vec.y, z - vec.z);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator*(T rhs)
	{
		return Vector3<T>(x * rhs, y * rhs, z * rhs);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator/(T rhs)
	{
		return Vector3<T>(x / rhs, y / rhs, z / rhs);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator+(T rhs)
	{
		return Vector3<T>(x + rhs, y + rhs, z + rhs);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator-(T rhs)
	{
		return Vector3<T>(x - rhs, y - rhs, z - rhs);
	}

	template<typename T>
	inline T Vector3<T>::Length()
	{
		return (T)(sqrtf(x * x + y * y + z * z));
	}

	template<typename T>
	inline T Vector3<T>::LengthSquared()
	{
		return (T)(x * x + y * y + z * z);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::Normalize()
	{
		T magnitude = this->Length();
		return Vector3<T>(x / magnitude, y / magnitude, z / magnitude);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::Negate()
	{
		return Vector3<T>(-x, -y, -z);
	}

	template<typename T>
	inline Vector3<T>::~Vector3()
	{
	}
}
