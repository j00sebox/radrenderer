#pragma once

namespace math {

	/**********************************************
	class Vec3
	@brief Class used to represent a vector in 3D
			space.
	************************************************/
	template <typename T>
	class Vec3
	{
	public:
		Vec3() : x(0), y(0), z(0) {};

		Vec3(float c[3]) : x(c[0]), y(c[1]), z(c[2]) {};

		void cross(Vec3& line, Vec3& normal)
		{
			normal.x = y * line.z - z * line.y;
			normal.y = z * line.x - x * line.z;
			normal.z = x * line.y - y * line.x;
		}

		float dot(Vec3& vec)
		{
			return x * vec.x + y * vec.y + z * vec.z;
		}

		void normalize()
		{
			float normalize = sqrtf(pow(x, 2) + pow(y, 2) + pow(z, 2));

			x /= normalize;
			y /= normalize;
			z /= normalize;
		}

		void subtract(Vec3& inputVec, Vec3& outVec)
		{
			outVec.x = x - inputVec.x;
			outVec.y = y - inputVec.y;
			outVec.z = z - inputVec.z;
		}

		void scalar_mul(Vec3& outVec, float scalar)
		{
			outVec.x = scalar * x;
			outVec.y = scalar * y;
			outVec.z = scalar * z;
		}

		void add(Vec3& a, Vec3& outVec)
		{
			outVec.x = x + a.x;
			outVec.y = y + a.y;
			outVec.z = z + a.z;
		}

		void operator = (std::vector<T> f)
		{
			x = f[0]; y = f[1]; z = f[2];
		}

		T x, y, z;
	};

}