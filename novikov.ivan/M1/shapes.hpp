#ifndef SHAPES_HPP
#define SHAPES_HPP

namespace novikov
{
  class Circle
  {
  public:
    Circle(int r, int x, int y);

    int getX() const;
    int getY() const;
    int getRadius() const;

  private:
    int radius_;
    int x_;
    int y_;
  };

  class Polygon
  {
  public:
    Polygon(int x1, int y1, int x2, int y2);

    int getMaxX() const;
    int getMaxY() const;
    int getMinX() const;
    int getMinY() const;

    void setMaxX() const;
    void setMaxY() const;
    void setMinX() const;
    void setMinY() const;

  private:
    int max_x_;
    int max_y_;
    int min_x_;
    int min_y_;
  };
}

#endif
