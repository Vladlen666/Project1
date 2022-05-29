#pragma once
#include"Figury.h"

template <class Type>
class TRectangle : public TObj<Type>
{
protected:
  int dim;
  TVector<Type> FirstPoint, SecondPoint;
  TString name;

public:
  TRectangle();
  TRectangle(const TRectangle<Type>& square);
  virtual void Print();
  virtual int GetDim();
  virtual void SetName(const TString& _name);
  virtual TString& GetName();
  virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TRectangle<Type>::TRectangle()
{
  std::cout << "input dim of first point" << std::endl;
  std::cin >> FirstPoint;

  std::cout << std::endl;

  std::cout << "input dim of second point" << std::endl;
  std::cin >> SecondPoint;

  dim = FirstPoint.GetLength();
  name.SetConstString("line");
  if (FirstPoint.GetLength() != SecondPoint.GetLength()) throw "dim of 1-st point != dim of 2-d point !!!";

 
}

template<class Type>
inline TRectangle<Type>::TRectangle(const TRectangle<Type>& square)
{
  FirstPoint = square.FirstPoint;
  SecondPoint = square.SecondPoint;
  dim = square.dim;
  name = square.name;
}

template<class Type>
inline void TRectangle<Type>::Print()
{
  std::cout << "name = " << name;
  std::cout << "dim =" << dim << std::endl;
  std::cout << "FirstPointOfSquare = " << FirstPoint << std::endl;
  std::cout << "SecondPointOfSquare = " << SecondPoint << std::endl;
}

template<class Type>
inline int TRectangle<Type>::GetDim()
{
  return dim;
}

template<class Type>
inline void TRectangle<Type>::SetName(const TString& _name)
{
  name = _name;
}

template<class Type>
inline TString& TRectangle<Type>::GetName()
{
  return name;
}

template<class Type>
inline TVector<Type>& TRectangle<Type>::operator[](int i)
{
  switch (i)
  {
  case 0:
	return FirstPoint;
  case 1:
	return SecondPoint;
	break;

  default:
	throw "undefined behavior. You trying to get unexist cell of array";
  }
}