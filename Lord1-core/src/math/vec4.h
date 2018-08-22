#pragma once
#include <iostream>
#include <string>

namespace lord { namespace math {

	class Vec2;
	class Vec3;

	class Vec4
	{
	public:
		float x;
		float y;
		float z;
		float w;
	public:
		Vec4(float x, float y, float z, float w);
		Vec4();
		Vec4& add(const Vec4& other);
		Vec4& add(float x, float y, float z, float w);
		Vec4& sub(const Vec4& other);
		Vec4& sub(float x, float y, float z, float w);
		Vec4& mul(float scalar);
		float length() const;
		Vec4& normalize();
		Vec4 getNormal() const;
		float dot(const Vec4& other) const;

		Vec4 operator+(const Vec4& other) const;
		Vec4 operator-(const Vec4& other) const;
		float operator*(const Vec4& other) const;
		Vec4 operator*(float scalar) const;
		Vec4& operator+=(const Vec4& other);
		Vec4& operator-=(const Vec4& other);
		Vec4& operator*=(float scalar);
		bool operator==(const Vec4& other) const;
		bool operator!=(const Vec4& other) const;
		Vec4& operator=(const Vec2& other);
		Vec4& operator=(const Vec3& other);

		inline std::string toString() const
		{
			return ("X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z) + " W: " + std::to_string(w));
		}

		inline void print() const
		{
			std::cout << this->toString() << std::endl;
		}
	};

typedef Vec4 Color;

}}