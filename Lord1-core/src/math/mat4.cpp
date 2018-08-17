#include "mat4.h"
#include <math.h>

namespace Lord1 { namespace math {

	Vec4 Matrix4f::mul(const Vec4& other) const
	{
		return Vec4(
			get(0, 0) * other.x + get(1, 0) * other.y + get(2, 0) * other.z + get(3, 0) * other.w,
			get(0, 1) * other.x + get(1, 1) * other.y + get(2, 1) * other.z + get(3, 1) * other.w,
			get(0, 2) * other.x + get(1, 2) * other.y + get(2, 2) * other.z + get(3, 2) * other.w,
			get(0, 3) * other.x + get(1, 3) * other.y + get(2, 3) * other.z + get(3, 3) * other.w
		);
	}

	Matrix4f Matrix4f::mul(const Matrix4f& other) const
	{
		return Matrix4f{
			// First row
			get(0,0) * other.get(0,0) + get(1,0) * other.get(0,1) + get(2,0) * other.get(0,2) + get(3,0) * other.get(0,3),
			get(0,0) * other.get(1,0) + get(1,0) * other.get(1,1) + get(2,0) * other.get(1,2) + get(3,0) * other.get(1,3),
			get(0,0) * other.get(2,0) + get(1,0) * other.get(2,1) + get(2,0) * other.get(2,2) + get(3,0) * other.get(2,3),
			get(0,0) * other.get(3,0) + get(1,0) * other.get(3,1) + get(2,0) * other.get(3,2) + get(3,0) * other.get(3,3),
		
			// Second row
			get(0,1) * other.get(0,0) + get(1,1) * other.get(0,1) + get(2,1) * other.get(0,2) + get(3,1) * other.get(0,3),
			get(0,1) * other.get(1,0) + get(1,1) * other.get(1,1) + get(2,1) * other.get(1,2) + get(3,1) * other.get(1,3),
			get(0,1) * other.get(2,0) + get(1,1) * other.get(2,1) + get(2,1) * other.get(2,2) + get(3,1) * other.get(2,3),
			get(0,1) * other.get(3,0) + get(1,1) * other.get(3,1) + get(2,1) * other.get(3,2) + get(3,1) * other.get(3,3),
			
			// Third row
			get(0,2) * other.get(0,0) + get(1,2) * other.get(0,1) + get(2,2) * other.get(0,2) + get(3,2) * other.get(0,3),
			get(0,2) * other.get(1,0) + get(1,2) * other.get(1,1) + get(2,2) * other.get(1,2) + get(3,2) * other.get(1,3),
			get(0,2) * other.get(2,0) + get(1,2) * other.get(2,1) + get(2,2) * other.get(2,2) + get(3,2) * other.get(2,3),
			get(0,2) * other.get(3,0) + get(1,2) * other.get(3,1) + get(2,2) * other.get(3,2) + get(3,2) * other.get(3,3),
			
			// Fourth row
			get(0,3) * other.get(0,0) + get(1,3) * other.get(0,1) + get(2,3) * other.get(0,2) + get(3,3) * other.get(0,3),
			get(0,3) * other.get(1,0) + get(1,3) * other.get(1,1) + get(2,3) * other.get(1,2) + get(3,3) * other.get(1,3),
			get(0,3) * other.get(2,0) + get(1,3) * other.get(2,1) + get(2,3) * other.get(2,2) + get(3,3) * other.get(2,3),
			get(0,3) * other.get(3,0) + get(1,3) * other.get(3,1) + get(2,3) * other.get(3,2) + get(3,3) * other.get(3,3) };
	 
	}

	Matrix4f Matrix4f::identity()
	{
		return Matrix4f{ 
			1.0f,	0.0f,	0.0f,	0.0f,
			0.0f,	1.0f,	0.0f,	0.0f,
			0.0f,	0.0f,	1.0f,	0.0f,
			0.0f,	0.0f,	0.0f,	1.0f
		};
	}

	Matrix4f Matrix4f::perspective(float fovX, float fovY, float zNear, float zFar)
	{
		return Matrix4f{
			atan(fovX / 2.0f), 0,					0,									0,
			0,				   atan(fovY / 2.0f),	0,									0,
			0,				   0,					-((zFar + zNear) / (zFar - zNear)), -((2 * (zNear * zFar)) / (zFar - zNear)),
			0,				   0,					-1,									0
		};
	}

	Matrix4f Matrix4f::translation(const Vec4& translator)
	{
		return Matrix4f{
			1.0f, 0.0f, 0.0f, translator.x,
			0.0f, 1.0f, 0.0f, translator.y,
			0.0f, 0.0f, 1.0f, translator.z,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}

	Matrix4f Matrix4f::scale(const Vec4& scaler)
	{
		return Matrix4f{
			scaler.x, 0.0f,		0.0f,	  0.0f,
			0.0f,	  scaler.y, 0.0f,	  0.0f,
			0.0f,	  0.0f,		scaler.z, 0.0f,
			0.0f,	  0.0f,		0.0f,	  1.0f
		};
	}

	Matrix4f Matrix4f::ortho(float left, float right, float top, float bottom, float far, float near)
	{
		return Matrix4f{
			2.0f / (right - left), 0, 0, -((right + left) / (right - left)),
			0.0f,				2 / (top - bottom), 0.0f, -((top + bottom) / (top - bottom)),
			0.0f,				0.0f, (-2.0f) / (far - near), -((far + near) / (far - near)),
			0.0f,				0.0f, 0.0f,						1.0f 
		};
	}

	Matrix4f Matrix4f::operator*(const Matrix4f& other) const
	{
		return mul(other);
	}

	Vec4 Matrix4f::operator*(const Vec4& other) const
	{
		return mul(other);
	}
}}