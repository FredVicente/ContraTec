#pragma once
#include <iostream>
/*
* Baseado no codigo de Matheus Burda.
*/

namespace Math {
	template <typename T>
	class Coord {
	public:
		T x;
		T y;

		Coord() { x = 0; y = 0; };
		Coord(T x, T y);
		~Coord() {};

		void operator=(Coord<T> other);
		void operator+=(Coord<T> other);
		void operator-=(Coord<T> other);
		void operator*=(double scalar);
		void operator/=(double scalar);

		Coord<T> operator+(Coord<T> other);
		Coord<T> operator-(Coord<T> other);
		Coord<T> operator*(Coord<T> other);
		Coord<T> operator*(double scalar);
		Coord<T> operator/(Coord<T> other);
		Coord<T> operator/(double scalar);
	};

	template <typename T>
	Coord<T>::Coord(T x, T y) {
		this->x = x;
		this->y = y;
	}

	template <typename T>
	void Coord<T>::operator=(Coord<T> other) {
		x = other.x;
		y = other.y;
	}

	template <typename T>
	void Coord<T>::operator+=(Coord<T> other) {
		x += other.x;
		y += other.y;
	}

	template <typename T>
	void Coord<T>::operator-=(Coord<T> other) {
		x -= other.x;
		y -= other.y;
	}

	template <typename T>
	void Coord<T>::operator*=(double scalar) {
		x *= scalar;
		y *= scalar;
	}

	template <typename T>
	void Coord<T>::operator/=(double scalar) {
		if (scalar == 0.0f) {
			std::cout << "ERROR: Cannot divide by zero." << std::endl;
			exit(1);
		}
		x /= scalar;
		y /= scalar;
	}

	template <typename T>
	Coord<T> Coord<T>::operator+(Coord<T> other) {
		return Coord<T>(this->x + other.x, this->y + other.y);
	}

	template <typename T>
	Coord<T> Coord<T>::operator-(Coord<T> other) {
		return Coord<T>(this->x - other.x, this->y - other.y);
	}

	template <typename T>
	Coord<T> Coord<T>::operator*(Coord<T> other) {
		return Coord<T>(this->x * other.x, this->y * other.y);
	}

	template <typename T>
	Coord<T> Coord<T>::operator*(double scalar) {
		return Coord<T>(this->x * scalar, this->y * scalar);
	}

	template <typename T>
	Coord<T> Coord<T>::operator/(Coord<T> other) {
		if (other.x == 0.0f || other.y == 0.0f) {
			std::cout << "ERROR: Cannot divide by zero." << std::endl;
			exit(1);
		}
		return Coord<T>(this->x / other.x, this->y / other.y);
	}

	template <typename T>
	Coord<T> Coord<T>::operator/(double scalar) {
		if (scalar == 0.0f) {
			std::cout << "ERROR: Cannot divide by zero." << std::endl;
			exit(1);
		}

		return Coord<T>(this->x / scalar, this->y / scalar);
	}
}