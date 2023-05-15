#ifndef POINT_HPP
#define POINT_HPP
#include <string>
using namespace std;

namespace ariel {
    class Point {
    private:
        double p_x;
        double p_y;
    public:
        Point(double p_x, double p_y);
        double getX()const;
        double getY()const;
        double distance(const Point& other) const;
        static Point moveTowards(Point& src, Point& dest, double dist);
        string print();
    };
}

#endif 