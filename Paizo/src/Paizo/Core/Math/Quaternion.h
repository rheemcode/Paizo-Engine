#pragma once

struct Quaternion
{
	union
	{
		struct { float x, y, z, w; };
		float component[4] = { 0 };
	};
	typedef Quaternion Quat;

	Quaternion()
		: x(0), y(0), z(0), w(1) {}
	Quaternion(float x)
		: x(0), y(0), z(0), w(1) {}
	Quaternion(const Quat& p_quat);
	Quaternion(const Vector3& p_eulerAngles);
	Quaternion(const float& p_s, const Vector3& p_eulerAngles)
		: x(p_eulerAngles.x), y(p_eulerAngles.y), z(p_eulerAngles.z), w(p_s) {}
	Quaternion(const float& w, const float& x, const float& y, const float& z)
		: x(x), y(y), z(z), w(w) {}
	explicit Quaternion(const Matrix4x4& p_mat);
	explicit Quaternion(const Matrix3x3& p_mat);

	Quat& operator=(const Quat& p_quat);
	Quat& operator+=(const Quat& p_quat);
	Quat& operator-=(const Quat& p_quat);
	Quat& operator*=(const Quat& p_quat);
	Quat& operator*=(const float& p_s);
	Quat& operator/=(const float& p_s);

	friend bool operator==(const Quat& q1, const Quat& q2) { return (q1.x == q2.x) && (q1.y == q2.y) && (q1.z == q2.z) && (q1.w == q2.w);}
	friend bool operator!=(const Quat& q1, const Quat& q2) { return (q1.x != q2.x) || (q1.y != q2.y) || (q1.z != q2.z) || (q1.w != q2.w); }

	friend Quat operator-(const Quat& p_quatB);
	friend Quat operator/(const Quat& p_quat, const Quat& p_quatB);
	friend Quat operator+(const Quat& p_quat, const Quat& p_quatB);
	friend Quat operator*(const Quat& p_quat, const Quat& p_quatB);
	friend Quat operator*(const float& s, const Quat& p_quat);
	friend Quat operator*(const Quat& p_quat, const float& s);
	friend Vector3 operator*( const Quat& p_quat, const Vector3& s);
	friend Vector3 operator*(const Vector3& p_vec, const Quat& p_quat);
	friend Quat operator/(const Quat& p_quat, const float& s);

	static float Length(const Quat& p_quat);
	static Quat Normalize(const Quat& p_quat);
	static float Dot(const Quat& a, const Quat& b);
	static Quat Cross(const Quat& p_quat, const Quat& p_quatB);
	static Quat Lerp(const Quat& p_quat, const Quat& p_quatB, const float& p_w);
	static Quat NLerp(const Quat& p_quat, const Quat& p_quatB, const float& p_w);
	static Quat Slerp(const Quat& p_quat, const Quat& p_quatB, const float& p_w);
	static Quat Mix(const Quat& p_quat, const Quat& p_quatB, const float& p_w);
	static Quat Conjugate(const Quat& p_quat);
	static Quat Inverse(const Quat& p_quat);
	static Quat Rotate(const Quat& p_quat, const float& p_theta, const Vector3& p_axis);
	static Quat RotateX(const float& p_theta);
	static Quat RotateY(const float& p_theta);
	static Quat RotateZ( const float& p_theta);
	static Quat RotatePoint(const Vector3& p_point, const Quat& p_quat);
	static Quat LookRotation(const Vector3& p_forward, const Vector3& p_up);
	static Quat FromEulerAngles(const Vector3& p_eulerAngle);
	static Vector3 EulerAngles(const Quat& p_quat);
	static float Roll(const Quat& p_quat);
	static float Pitch(const Quat& p_quat);
	static float Yaw(const Quat& p_quat);
	static float Angle(const Quat& p_quat);
	static Vector3 Axis(const Quat& p_quat);
	static Quaternion AngleAxis(const float p_theta, const Vector3& p_axis);

	static Matrix3x3 ToMatrix3x3(const Quat& p_quat);
	static Matrix4x4 ToMatrix4x4(const Quat& p_quat);
	static Quat FromMatrix4x4(const Matrix4x4& p_quat);
	static Quat FromMatrix3x3(const Matrix3x3& p_quat);
};

