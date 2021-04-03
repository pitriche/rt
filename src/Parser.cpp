/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/02 09:12:25 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "All.hpp"
#include "Parser.hpp"

#include "Sphere.hpp"
#include "Plan.hpp"
#include "SpotLight.hpp"
#include "ParaLight.hpp"
#include <string>

static Vec3d<float>	_parse_vec3df(std::istream &is)
{
	Vec3d<float>	tmp;

	is >> tmp.x >> tmp.y >> tmp.z;
	return (tmp);
}

static Color		_parse_color(std::istream &is)
{
	int	r;
	int	g;
	int	b;

	is >> r >> g >> b;
	return (Color(static_cast<unsigned char>(r),
		static_cast<unsigned char>(g),
		static_cast<unsigned char>(b)));
}

static float		_parse_real(std::istream &is)
{
	float	f;

	is >> f;
	return (f);
}

/*
** Check if the next character on the stream is '-'
*/
static void			_check(std::istream &is, std::string str)
{
	char	c;

	is >> c;
	if (c != '-')
		Utils::error_quit("Error on " + str + " parsing");
}

/*
** #############################################################################
*/

static void			parse_window(std::istream &is)
{
	unsigned	x_window;
	unsigned	y_window;
	std::string	name_window;
	is >> x_window >> y_window;
	_check(is, "Camera");
	std::getline(is, name_window);
	all.disp.init(name_window, x_window, y_window);
}
static Object		*parse_sphere(std::istream &is, unsigned &id)
{
	Sphere	*obj;
	obj = new Sphere(id++);
	obj->pos = _parse_vec3df(is);
	_check(is, "Sphere");
	obj->size = _parse_real(is);
	_check(is, "Sphere");
	obj->color = _parse_color(is);
	obj->is_full = true;
	obj->reflectivity = 0.0f;
	obj->transparency = 0.0f;
	return (static_cast<Object *>(obj));
}
static Object		*parse_plan(std::istream &is, unsigned &id)
{
	Plan	*obj;
	obj = new Plan(id++);
	obj->pos = _parse_vec3df(is);
	_check(is, "Plan");
	obj->dir = _parse_vec3df(is);
	obj->dir.normalize();
	_check(is, "Plan");
	obj->color = _parse_color(is);
	obj->is_full = false;
	obj->reflectivity = 0.0f;
	obj->transparency = 0.0f;
	return (static_cast<Object *>(obj));
}

static SpotLight	*parse_spot(std::istream &is)
{
	SpotLight	*obj;
	obj = new SpotLight();
	obj->pos = _parse_vec3df(is);
	_check(is, "Spot light");
	obj->lflux = _parse_real(is);
	return (obj);
}

static ParaLight	*parse_para(std::istream &is)
{
	ParaLight	*obj;
	obj = new ParaLight();
	obj->inverted_dir = _parse_vec3df(is) * -1.0f; // inverting the direction
	obj->inverted_dir.normalize();
	_check(is, "Parallel light");
	obj->illuminance = _parse_real(is);
	return (obj);
}

/*
** #############################################################################
*/

namespace Parser
{
	void	parse(std::istream &is, Scene &sc)
	{
		std::string	str;
		std::string	dump;
		unsigned	id;

		id = 0;
		is >> str;
		while (!str.empty())
		{
			if (str == "#")
				std::getline(is, dump);
			else if (str == "Sphere:")
				sc.obj.push_back(parse_sphere(is, id));
			else if (str == "Plan:")
				sc.obj.push_back(parse_plan(is, id));
			else if (str == "Window:")
				parse_window(is);
			else if (str == "SpotLight:")
				sc.spot.push_back(parse_spot(is));
			else if (str == "ParallelLight:")
				sc.para.push_back(parse_para(is));
			else if (str == "AmbiantLight:")std::getline(is, dump);
			else if (str == "Camera:")std::getline(is, dump);
			else
				Utils::error_quit("Invalid element: >" + str + "<");
			str.clear();
			is >> str;
		}
	}
}