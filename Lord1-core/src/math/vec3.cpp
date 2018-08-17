#include "vec3.h"
#include <math.h>

namespace Lord1 { namespace math {

	Vec3::Vec3(float x, float y, float z)
		: x(x)
		, y(y)
		, z(z)
	{
	}

	Vec3::Vec3()
		: Vec3(0, 0, 0)
	{
	}

	Vec3& Vec3::add(const Vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vec3& Vec3::add(float x, float y, float z)
	{
		this->x += x;
		this->y += y;
		this->z += z;
		return *this;
	}

	Vec3& Vec3::sub(const Vec3& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		return *this;
	}

	Vec3& Vec3::sub(float x, float y, float z)
	{
		this->x -= x;
		this->y -= y;
		this->z -= z;
		return *this;
	}

	Vec3& Vec3::mul(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return *this;
	}

	float Vec3::length() const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	Vec3& Vec3::normalize()
	{
		float len = length();
		if (len > 0.0f)
		{
			x /= len;
			y /= len;
			z /= len;
		}
		return *this;
	}

	Vec3 Vec3::getNormal() const
	{
		float len = length();
		if (len > 0.0f)
		{
			return Vec3(x / len, y / len, z / len);
		}
		return Vec3(0, 0, 0);
	}

	float Vec3::dot(const Vec3& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vec3 Vec3::cross(const Vec3& other) const
	{
		return Vec3(y * other.z - z * other.y,
					z * other.x - x * other.z,
					x * other.y - y * other.x);
	}

	Vec3 Vec3::operator+(const Vec3& other) const
	{
		return Vec3(x + other.x, y + other.y, z + other.z);
	}

	Vec3 Vec3::operator-(const Vec3& other) const
	{
		return Vec3(x - other.x, y - other.y, z - other.z);
	}

	float Vec3::operator*(const Vec3& other) const
	{
		return dot(other);
	}

	Vec3 Vec3::operator*(float scalar) const
	{
		return Vec3(x * scalar, y * scalar, z * scalar);
	}

	Vec3& Vec3::operator+=(const Vec3& other)
	{
		return add(other);
	}

	Vec3& Vec3::operator-=(const Vec3& other)
	{
		return sub(other);
	}

	Vec3& Vec3::operator*=(float scalar)
	{
		return mul(scalar);
	}

	bool Vec3::operator==(const Vec3& other) const
	{
		return (x == other.x && y == other.y && z == other.z);
	}

	bool Vec3::operator!=(const Vec3& other) const
	{
		return !(*this == other);
	}
}}