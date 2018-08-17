#include "vec2.h"
#include <math.h>

namespace Lord1 { namespace math {

	Vec2::Vec2(float x, float y)
		: x(x)
		, y(y)
	{
	}

	Vec2::Vec2()
		: Vec2(0, 0)
	{
	}

	Vec2& Vec2::add(const Vec2& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Vec2& Vec2::add(float x, float y)
	{
		this->x += x;
		this->y += y;
		return *this;
	}

	Vec2& Vec2::sub(const Vec2& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	Vec2& Vec2::sub(float x, float y)
	{
		this->x -= x;
		this->y -= y;
		return *this;
	}

	Vec2& Vec2::mul(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		return *this;
	}

	float Vec2::length() const
	{
		return sqrtf(x * x + y * y);
	}

	Vec2& Vec2::normalize()
	{
		float len = length();
		if (len > 0.0f)
		{
			x /= len;
			y /= len;
		}
		return *this;
	}
	Vec2 Vec2::getNormal() const
	{
		float len = length();
		if (len >= 0)
		{
			return Vec2(x / len, y / len);
		}
		return Vec2(0, 0);
	}

	float Vec2::dot(const Vec2& other) const
	{
		return x * other.x + y * other.y;
	}

	Vec2 Vec2::operator+(const Vec2& other) const
	{
		return Vec2(x + other.x, y + other.y);
	}

	Vec2 Vec2::operator-(const Vec2& other) const
	{
		return Vec2(x - other.x, y - other.y);
	}

	float Vec2::operator*(const Vec2& other) const
	{
		return dot(other);
	}

	Vec2 Vec2::operator*(float scalar) const
	{
		return Vec2(x * scalar, y * scalar);
	}

	Vec2& Vec2::operator+=(const Vec2& other)
	{
		return add(other);
	}

	Vec2& Vec2::operator-=(const Vec2& other)
	{
		return sub(other);
	}

	Vec2& Vec2::operator*=(float scalar)
	{
		return mul(scalar);
	}

	bool Vec2::operator==(const Vec2& other) const
	{
		return (x == other.x && y == other.y);
	}

	bool Vec2::operator!=(const Vec2& other) const
	{
		return !(*this == other);
	}

}}