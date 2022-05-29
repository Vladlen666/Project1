#pragma once
#include"Figury.h"

template <class Type>
class TIsiscelesTriangle : public TObj<Type>
{
protected:
  TVector<Type> FirstPoint, SecondPoint, ThirdPoint;
  int dim;
  TString name;

public:
  TIsiscelesTriangle();
  TIsiscelesTriangle(const TIsiscelesTriangle<Type>& q);
  ~TIsiscelesTriangle();
  virtual void Print();
  virtual int GetDim();
  virtual void SetName(const TString& _name);
  virtual TString& GetName();
  virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TIsiscelesTriangle<Type>::TIsiscelesTriangle()
{
  std::cout << "input dim of first point" << std::endl;
  std::cin >> FirstPoint;

  std::cout << std::endl;

  std::cout << "input dim of second point" << std::endl;
  std::cin >> SecondPoint;

  std::cout << std::endl;

  std::cout << "input dim of third point" << std::endl;
  std::cin >> ThirdPoint;

  dim = FirstPoint.GetLength();
  name.SetConstString("triangle");
  if (FirstPoint.GetLength() != SecondPoint.GetLength() && FirstPoint.GetLength() != ThirdPoint.GetLength()) throw "dim of 1-st point != dim of 2-d point !!!";

}

template<class Type>
inline TIsiscelesTriangle<Type>::TIsiscelesTriangle(const TIsiscelesTriangle<Type>& q)
{
  name = q.name;
  FirstPoint = q.FirstPoint;
  SecondPoint = q.SecondPoint;
  ThirdPoint = q.ThirdPoint;
  dim = q.dim;
}

template<class Type>
inline TIsiscelesTriangle<Type>::~TIsiscelesTriangle()
{
}

template<class Type>
inline void TIsiscelesTriangle<Type>::Print()
{
  std::cout << "name = " << name;
  std::cout << "dim =" << dim << std::endl;
  std::cout << "FirstVector = " << FirstPoint << std::endl;
  std::cout << "SecondVector = " << SecondPoint << std::endl;
  std::cout << "ThirdVector = " << ThirdPoint << std::endl;
}


template<class Type>
inline int TIsiscelesTriangle<Type>::GetDim()
{
  return dim;
}

template<class Type>
inline void TIsiscelesTriangle<Type>::SetName(const TString& _name)
{
  name = _name;
}

template<class Type>
inline TString& TIsiscelesTriangle<Type>::GetName()
{
  return name;
}

template<class Type>
inline TVector<Type>& TIsiscelesTriangle<Type>::operator[](int i)
{
  switch (i)
  {
  case 0:
	return FirstPoint;
  case 1:
	return SecondPoint;
	break;
  case 2:
	return ThirdPoint;
	break;

  default:
	throw "undefined behavior. You trying to get unexist cell of array";
  }
}