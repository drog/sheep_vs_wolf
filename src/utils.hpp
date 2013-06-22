#ifndef UTILS_HPP
#define UTILS_HPP

#include <SFML/Graphics.hpp>  
#include <iostream> 
#include <sstream>
class Utils{
	public:
		static inline std::string int2Str(int x)
		{
		std::stringstream asd;
		asd << x;
		return asd.str();
		}
};

#endif 