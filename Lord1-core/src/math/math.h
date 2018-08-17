#pragma once
#include <math.h>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace Lord1 { namespace math {

#define MATH_PI 3.14159f

#define TO_RADIANS(x) (x * MATH_PI / 180.0f)

	inline bool vecIsLonger(const Vec2& v1, const Vec2& v2)
	{
		return ((v1.x * v1.x + v1.y * v1.y) > (v2.x * v2.x + v2.y * v2.y));
	}

	inline bool vecIsLonger(const Vec3& v1, const Vec3& v2)
	{
		return ((v1.x * v1.x + v1.y * v1.y + v1.z * v1.z) > (v2.x * v2.x + v2.y * v2.y + v2.z * v2.z));
	}

	inline bool vecIsLonger(const Vec4& v1, const Vec4& v2)
	{
		return ((v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w) > (v2.x * v2.x + v2.y * v2.y + v2.z * v2.z + v2.w * v2.w));
	}

	inline Vec2 Lerp(const Vec2& v1, const Vec2& v2, float beta)
	{
		return Vec2((1.0f - beta) * v1.x + beta * v2.x, (1.0f - beta) * v1.y + beta * v2.y);
	}

	inline Vec3 Lerp(const Vec3& v1, const Vec3& v2, float beta)
	{
		return Vec3((1.0f - beta) * v1.x + beta * v2.x, (1.0f - beta) * v1.y + beta * v2.y, (1.0f - beta) * v1.z + beta * v2.z);
	}

	inline Vec4 Lerp(const Vec4& v1, const Vec4& v2, float beta)
	{
		return Vec4((1.0f - beta) * v1.x + beta * v2.x, (1.0f - beta) * v1.y + beta * v2.y, (1.0f - beta) * v1.z + beta * v2.z, (1.0f - beta) * v1.w + beta * v2.w);
	}
}}