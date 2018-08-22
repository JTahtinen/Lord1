#include "mat4.h"
#include "math.h"

namespace lord { namespace math {

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

	Matrix4f Matrix4f::perspective(float fov, float aspect, float near, float far)
	{
		float fovRad = TO_RADIANS(fov);
		return Matrix4f{
			1.0f /(aspect * tan(fovRad / 2.0f)), 0,			0,									0,
			0,				   1.0f / tan(fovRad / 2.0f),	0,									0,
			0,				   0,					-((far + near) / (far - near)), -((2 * (near * far)) / (far - near)),
			0,				   0,					-1,									0
		};
	}

	Matrix4f Matrix4f::translate(const Vec3& translation)
	{
		return Matrix4f{
			1.0f, 0.0f, 0.0f, translation.x,
			0.0f, 1.0f, 0.0f, translation.y,
			0.0f, 0.0f, 1.0f, translation.z,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}

	Matrix4f Matrix4f::scale(const Vec3& scalar)
	{
		return Matrix4f{
			scalar.x, 0.0f,		0.0f,	  0.0f,
			0.0f,	  scalar.y, 0.0f,	  0.0f,
			0.0f,	  0.0f,		scalar.z, 0.0f,
			0.0f,	  0.0f,		0.0f,	  1.0f
		};
	}

	Matrix4f Matrix4f::ortho(float left, float right, float top, float bottom, float near, float far)
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