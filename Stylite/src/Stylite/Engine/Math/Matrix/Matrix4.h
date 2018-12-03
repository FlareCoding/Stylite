#pragma once
#include <iostream>
#include "../../../api_build.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector4.h"

namespace Stylite
{
	template <typename T>
	class Matrix4
	{
	public:
		Matrix4();
		Matrix4(T val);

		union
		{
			struct
			{
				T m00, m01, m02, m03;
				T m10, m11, m12, m13;
				T m20, m21, m22, m23;
				T m30, m31, m32, m33;
			};

			struct
			{
				float rc[4][4];
			};
		};

		T& operator[](size_t idx);
		const T& operator[](size_t idx) const;
		Matrix4<T> operator*(const Matrix4<T>& rhs);

		void SetIdentity();
		Matrix4<T> Translate(T x, T y, T z);
		Matrix4<T> Translate(Vector3<T> vec);
		Matrix4<T> Rotate(T angle, Vector3<T> vec);
		Matrix4<T> Scale(T x, T y, T z);
		Matrix4<T> Scale(Vector3<T> vec);
		Matrix4<T> Transpose();
		static Matrix4<T> Orthographic(T left, T right, T bottom, T top);
		static Matrix4<T> Orthographic(T left, T right, T bottom, T top, T zNear, T zFar);

		~Matrix4();
	};

	template<typename T>
	inline Matrix4<T>::Matrix4() : 
		m00(0), m01(0), m02(0), m03(0),
		m10(0), m11(0), m12(0), m13(0),
		m20(0), m21(0), m22(0), m23(0),
		m30(0), m31(0), m32(0), m33(0)
	{
	}

	template<typename T>
	inline Matrix4<T>::Matrix4(T val) : 
		m00(val), m01(0), m02(0), m03(0),
		m10(0), m11(val), m12(0), m13(0),
		m20(0), m21(0), m22(val), m23(0),
		m30(0), m31(0), m32(0), m33(val)
	{
	}

	template<typename T>
	inline std::ostream& operator<<(std::ostream& stream, const Matrix4<T>& matrix)
	{
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t ii = 0; ii < 4; ii++)
				stream << matrix.rc[i][ii] << " ";
			stream << "\n";
		}
		return stream;
	}

	template<typename T>
	inline T & Matrix4<T>::operator[](size_t idx)
	{
		if (idx > 16 || idx < 0) throw std::out_of_range::exception("Invalid Element");
		return *(T*)(&m00 + idx);
	}

	template<typename T>
	inline const T & Matrix4<T>::operator[](size_t idx) const
	{
		if (idx > 16 || idx < 0) throw std::out_of_range::exception("Invalid Element");
		return *(T*)(&m00 + idx);
	}

	template<typename T>
	inline Matrix4<T> Matrix4<T>::operator*(const Matrix4<T>& rhs)
	{
		Matrix4<T> result;
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				result.rc[i][j] = 0;
				for (size_t k = 0; k < 4; k++)
					result.rc[i][j] += this->rc[i][k] * rhs.rc[k][j];
			}
		}
		return result;
	}

	template<typename T>
	inline void Matrix4<T>::SetIdentity()
	{
		m00 = 1; m01 = 0; m02 = 0; m03 = 0;
		m10 = 0; m11 = 1; m12 = 0; m13 = 0;
		m20 = 0; m21 = 0; m22 = 1; m23 = 0;
		m30 = 0; m31 = 0; m32 = 0; m33 = 1;
	}

	template<typename T>
	inline Matrix4<T> Matrix4<T>::Translate(T x, T y, T z)
	{
		Matrix4<T> matrix = *this;
		matrix.m30 += x;
		matrix.m31 += y;
		matrix.m32 += z;
		return matrix;
	}

	template<typename T>
	inline Matrix4<T> Matrix4<T>::Translate(Vector3<T> vec)
	{
		Matrix4<T> matrix = *this;
		matrix.m30 += vec.x;
		matrix.m31 += vec.y;
		matrix.m32 += vec.z;
		return matrix;
	}

	template<typename T>
	inline Matrix4<T> Matrix4<T>::Rotate(T angle, Vector3<T> vec)
	{
		T a = angle;
		T c = cos(a);
		T s = sin(a);

		Vector3<T> axis = vec;
		axis = axis.Normalize();

		Vector3<T> temp = axis * (1.0f - c);

		Matrix4<T> rotation;
		rotation.m00 = c + temp.x * axis.x;
		rotation.m01 = 0 + temp.x * axis.y + s * axis.z;
		rotation.m02 = 0 + temp.x * axis.z - s * axis.y;

		rotation.m10 = 0 + temp.y * axis.x - s * axis.z;
		rotation.m11 = c + temp.y * axis.y;
		rotation.m12 = 0 + temp.y * axis.z + s * axis.x;

		rotation.m20 = 0 + temp.z * axis.x + s * axis.y;
		rotation.m21 = 0 + temp.z * axis.y - s * axis.x;
		rotation.m22 = c + temp.z * axis.z;

		Matrix4<T> result = *this;
		Vector4<T> currentRow0 = *(Vector4<T>*)(&this->m00);
		Vector4<T> currentRow1 = *(Vector4<T>*)(&this->m10);
		Vector4<T> currentRow2 = *(Vector4<T>*)(&this->m20);

		Vector4<T> newRow0 = currentRow0 * rotation.m00 + currentRow1 * rotation.m01 + currentRow2 * rotation.m02;
		result.m00 = newRow0.x;
		result.m01 = newRow0.y;
		result.m02 = newRow0.z;
		result.m03 = newRow0.w;

		Vector4<T> newRow1 = currentRow0 * rotation.m10 + currentRow1 * rotation.m11 + currentRow2 * rotation.m12;
		result.m10 = newRow1.x;
		result.m11 = newRow1.y;
		result.m12 = newRow1.z;
		result.m13 = newRow1.w;

		Vector4<T> newRow2 = currentRow0 * rotation.m20 + currentRow1 * rotation.m21 + currentRow2 * rotation.m22;
		result.m20 = newRow2.x;
		result.m21 = newRow2.y;
		result.m22 = newRow2.z;
		result.m23 = newRow2.w;

		return result;
	}

	template<typename T>
	inline Matrix4<T> Matrix4<T>::Scale(T x, T y, T z)
	{
		Vector3<T> scalingVector(x, y, z);
		Matrix4<T> result = *this;

		Vector4<T> currentRow0 = *(Vector4<T>*)(&this->m00);
		Vector4<T> currentRow1 = *(Vector4<T>*)(&this->m10);
		Vector4<T> currentRow2 = *(Vector4<T>*)(&this->m20);

		Vector4<T> newRow0 = currentRow0 * scalingVector.x;
		result.m00 = newRow0.x;
		result.m01 = newRow0.y;
		result.m02 = newRow0.z;
		result.m03 = newRow0.w;

		Vector4<T> newRow1 = currentRow1 * scalingVector.y;
		result.m10 = newRow1.x;
		result.m11 = newRow1.y;
		result.m12 = newRow1.z;
		result.m13 = newRow1.w;

		Vector4<T> newRow2 = currentRow2 * scalingVector.z;
		result.m20 = newRow2.x;
		result.m21 = newRow2.y;
		result.m22 = newRow2.z;
		result.m23 = newRow2.w;

		return result;
	}

	template<typename T>
	inline Matrix4<T> Matrix4<T>::Scale(Vector3<T> vec)
	{
		Matrix4<T> result = *this;

		Vector4<T> currentRow0 = *(Vector4<T>*)(&this->m00);
		Vector4<T> currentRow1 = *(Vector4<T>*)(&this->m10);
		Vector4<T> currentRow2 = *(Vector4<T>*)(&this->m20);

		Vector4<T> newRow0 = currentRow0 * vec.x;
		result.m00 = newRow0.x;
		result.m01 = newRow0.y;
		result.m02 = newRow0.z;
		result.m03 = newRow0.w;

		Vector4<T> newRow1 = currentRow1 * vec.y;
		result.m10 = newRow1.x;
		result.m11 = newRow1.y;
		result.m12 = newRow1.z;
		result.m13 = newRow1.w;

		Vector4<T> newRow2 = currentRow2 * vec.z;
		result.m20 = newRow2.x;
		result.m21 = newRow2.y;
		result.m22 = newRow2.z;
		result.m23 = newRow2.w;

		return result;
	}

	template<typename T>
	inline Matrix4<T> Matrix4<T>::Transpose()
	{
		Matrix4<T> result = *this;
		result.m00 = this->m00;
		result.m01 = this->m10;
		result.m02 = this->m20;
		result.m03 = this->m30;

		result.m10 = this->m01;
		result.m11 = this->m11;
		result.m12 = this->m21;
		result.m13 = this->m31;

		result.m20 = this->m02;
		result.m21 = this->m12;
		result.m22 = this->m22;
		result.m23 = this->m32;

		result.m30 = this->m03;
		result.m31 = this->m13;
		result.m32 = this->m23;
		result.m33 = this->m33;
		return result;
	}

	template<typename T>
	inline Matrix4<T> Matrix4<T>::Orthographic(T left, T right, T bottom, T top)
	{
		Matrix4<T> result(static_cast<T>(1));
		result.m00 = static_cast<T>(2) / (right - left);
		result.m11 = static_cast<T>(2) / (top - bottom);
		result.m30 = -(right + left) / (right - left);
		result.m31 = -(top + bottom) / (top - bottom);
		return result;
	}

	template<typename T>
	inline Matrix4<T> Matrix4<T>::Orthographic(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		Matrix4<T> result(static_cast<T>(1));
		result.m00 = static_cast<T>(2) / (right - left);
		result.m11 = static_cast<T>(2) / (top - bottom);
		result.m22 = -static_cast<T>(2) / (zFar - zNear);
		result.m30 = -(right + left) / (right - left);
		result.m31 = -(top + bottom) / (top - bottom);
		result.m32 = -(zFar + zNear) / (zFar - zNear);
		return result;
	}

	template<typename T>
	inline Matrix4<T>::~Matrix4()
	{
	}
}