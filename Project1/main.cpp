#include"Figury.h"
#include"Point.h"
#include"Vector.h"
#include"Complex.h"
#include "Line.h"
#include"Square.h"
#include"Circle.h"
#include"Triangle.h"
#include"Saver.h"
#include"Tetrahedron.h"
#include"Rectangle.h"
#include"IsiscelesTriangle.h"

int main()
{	
  TSet<int> set;
  TCircle<int> circle(10);
  TLine<int>line;
  set.SetObj(&circle);
  set.SetObj(&line);
  set.ToPrint();
  set.ToPlot();

  return 0;
}