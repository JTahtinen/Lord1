#pragma once
#include <string>
#include <iostream>

namespace Lord1 { namespace math {

	class Vec2
	{
	public:
		float x;
		float y;
	public:
		Vec2(float x, float y);
		Vec2();
		Vec2& add(const Vec2& other);
		Vec2& add(float x, float y);
		Vec2& sub(const Vec2& other);
		Vec2& sub(float x, float y);
		Vec2& mul(float scalar);
		float length() const;
		Vec2& normalize();
		Vec2 getNormal() const;
		float dot(const Vec2& other) const;
		inline std::string toString() const
		{
			return ("X: " + std::to_string(x) + " Y: " + std::to_string(y));
		}
		inline void print() const
		{
			std::cout << this->toString() << std::endl;
		}

		Vec2 operator+(const Vec2& other) const;
		Vec2 operator-(const Vec2& other) const;
		float operator*(const Vec2& other) const;
		Vec2 operator*(float scalar) const;
		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(float scalar);
		bool operator==(const Vec2& other);
		bool operator!=(const Vec2& other);
	};

}}