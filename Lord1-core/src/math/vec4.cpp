#include "vec4.h"
#include "math.h"
#include "vec2.h"
#include "vec3.h"

namespace Lord1 { namespace math {

	Vec4::Vec4(float x, float y, float z, float w)
		: x(x)
		, y(y)
		, z(z)
		, w(w)
	{
	}

	Vec4::Vec4()
		: Vec4(0, 0, 0, 0)
	{
	}

	Vec4& Vec4::add(const Vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	Vec4& Vec4::add(float x, float y, float z, float w)
	{
		this->x += x;
		this->y += y;
		this->z += z;
		this->w += w;
		return *this;
	}

	Vec4& Vec4::sub(const Vec4& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
		return *this;
	}

	Vec4& Vec4::sub(float x, float y, float z, float w)
	{
		this->x -= x;
		this->y -= y;
		this->z -= z;
		this->w -= w;
		return *this;
	}

	Vec4& Vec4::mul(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		this->w *= scalar;
		return *this;
	}

	float Vec4::length() const
	{
		return sqrtf(x * x + y * y + z * z + w * w);
	}

	Vec4& Vec4::normalize()
	{
		float len = length();
		if (len > 0.0f)
		{
			x /= len;
			y /= len;
			z /= len;
			w /= len;
		}
		return *this;
	}

	Vec4 Vec4::getNormal() const
	{
		float len = length();
		if (len > 0.0f)
		{
			return Vec4(x / len, y / len, z / len, w / len);
		}
		return Vec4(0, 0, 0, 0);
	}

	float Vec4::dot(const Vec4& other) const
	{
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}

	Vec4 Vec4::operator+(const Vec4& other) const
	{
		return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
	}

	Vec4 Vec4::operator-(const Vec4& other) const
	{
		return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	float Vec4::operator*(const Vec4& other) const
	{
		return dot(other);
	}

	Vec4 Vec4::operator*(float scalar) const
	{
		return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	Vec4& Vec4::operator+=(const Vec4& other)
	{
		return add(other);
	}

	Vec4& Vec4::operator-=(const Vec4& other)
	{
		return sub(other);
	}

	Vec4& Vec4::operator*=(float scalar)
	{
		return mul(scalar);
	}

	bool Vec4::operator==(const Vec4& other)
	{
		return (x == other.x && y == other.y && z == other.z && w == other.w);
	}

	bool Vec4::operator!=(const Vec4& other)
	{
		return !(*this == other);
	}

	Vec4& Vec4::operator=(const Vec2& other)
	{
		x = other.x;
		y = other.y;
		z = 0;
		w = 0;
		return *this;
	}

	Vec4& Vec4::operator=(const Vec3& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = 0;
		return *this;
	}
}}