/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3d.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/08 20:47:19 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3D_HPP
# define VEC3D_HPP

# include <iostream>
# include <cmath>

template<typename T>
class Vec3d
{
	public :
		T	x;
		T	y;
		T	z;

		Vec3d<T>(void) { }
		Vec3d<T>(T x_, T y_, T z_) : x(x_), y(y_), z(z_) { }
		Vec3d<T>(const Vec3d &src) { *this = src; }
		virtual ~Vec3d<T>(void) { }

		T			length(void) { return (sqrtf((*this) * (*this))); }

		void		normalize(void)
		{
			T	norm;

			norm = sqrtf(this->x * this->x + this->y * this->y + this->z *
				this->z);
			this->x /= norm;
			this->y /= norm;
			this->z /= norm;
		}

		/*
		**	ROTATION FUNCTIONS ARE SLOW !
		**	avoid use in time critical segments
		**	optimized variations will be added only if STRICTLY required
		*/

		// clockwise rotation around x axis
		// Pitch, similar to nose down pitch
		void		rotate_x(T angle)
		{
			T	y;
			T	z;
			T	cos_angle;
			T	sin_angle;

			cos_angle = cosf(angle);
			sin_angle = sinf(angle);
			y = this->y;
			z = this->z;
			this->y = y * cos_angle - z * sin_angle;
			this->z = y * sin_angle + z * cos_angle;
		}

		// clockwise rotation around y axis
		// Yaw, similar to heading/bearing
		void		rotate_y(T angle)
		{
			T	x;
			T	z;
			T	cos_angle;
			T	sin_angle;

			cos_angle = cosf(angle);
			sin_angle = sinf(angle);
			x = this->x;
			z = this->z;
			this->x = x * cos_angle + z * sin_angle;
			this->z = x * -sin_angle + z * cos_angle;
		}

		// clockwise rotation around z axis
		// Roll, similar to right roll
		void		rotate_z(T angle)
		{
			T	x;
			T	y;
			T	cos_angle;
			T	sin_angle;

			cos_angle = cosf(angle);
			sin_angle = sinf(angle);
			x = this->x;
			y = this->y;
			this->x = x * cos_angle + y * sin_angle;
			this->y = x * -sin_angle + y * cos_angle;
		}

		/*
		** ############################# Operators #############################
		*/

		Vec3d<T>	&operator=(const Vec3d<T> &rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			return (*this);
		}

		bool		operator==(const Vec3d<T> &rhs) const
		{ return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z); }

		bool		operator!=(const Vec3d<T> &rhs) const
		{ return (this->x != rhs.x || this->y != rhs.y || this->z != rhs.z); }

		// Vector addition
		Vec3d<T>	operator+(const Vec3d<T> &rhs) const
		{
			return (Vec3d<T>(this->x + rhs.x, this->y + rhs.y,
				this->z + rhs.z));
		}

		// Vector substraction
		Vec3d<T>	operator-(const Vec3d<T> &rhs) const
		{
			return (Vec3d<T>(this->x - rhs.x, this->y - rhs.y,
				this->z - rhs.z));
		}

		// Dot product
		T			operator*(const Vec3d<T> &rhs) const
		{ return (this->x * rhs.x + this->y * rhs.y + this->z * rhs.z); }

		// Scaling
		Vec3d<T>	operator*(T rhs) const
		{ return (Vec3d<T>(this->x * rhs, this->y * rhs, this->z * rhs)); }

		// Scaling
		Vec3d<T>	operator/(T rhs) const
		{ return (Vec3d<T>(this->x / rhs, this->y / rhs, this->z / rhs)); }

		// XYZ acces with index: x = vec[0], y = vec[1], z = vec[2] 
		T			&operator[](int i)
		{
			switch (i)
			{
				case 0:
					return (this->x);
				case 1:
					return (this->y);
				case 2:
					return (this->z);
				default:
					throw std::out_of_range("Invalid Index");
			}
		}

	protected:
	private:
};

template<typename T> 
std::ostream	&operator<<(std::ostream &lhs, const Vec3d<T> &vec)
{
	return (lhs << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]");
}

#endif
