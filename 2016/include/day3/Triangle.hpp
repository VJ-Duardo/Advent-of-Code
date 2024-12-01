#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle {
  public:
    Triangle(int na, int nb, int nc);
    operator bool() const;

  private:
    int a, b, c;
};


#endif