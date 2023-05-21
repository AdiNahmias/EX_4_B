#include "Point.hpp"
#include <cmath>
#include <string>
#include <stdexcept>
using namespace std;

namespace ariel
{
    Point::Point(){
        this->p_x = 0;
        this->p_y=0;
    }
    
    Point::Point(double p_x, double p_y){
        this->p_x = p_x;
        this->p_y = p_y;
    }


    double Point::getX() const{
        return this->p_x;
    }

    double Point::getY() const{
        return this->p_y;
    }


    double Point::distance(const Point &other) const{
        double d_x = other.getX() - p_x;
        double d_y = other.getY() - p_y;
        return std::sqrt(d_x * d_x + d_y * d_y);
    }

    Point Point::moveTowards(Point &src, Point &dest, double dist){
        if (dist < 0){
        throw invalid_argument("Distance cannot be negative number");
        }
        double d_x = dest.getX() - src.getX();
        double d_y = dest.getY() - src.getY();
        double currentDistance = src.distance(dest);
        if (currentDistance <= dist){
            // Already within the given distance
            return dest;
        }
        else{
            double ratio = dist / currentDistance;
            return Point(src.getX() + ratio * d_x, src.getY() + ratio * d_y);
        }
    }

    string Point::print(){
    string str = "(" + to_string(p_x) + "," + to_string(p_y) + ")";
    return str;
    }
}
