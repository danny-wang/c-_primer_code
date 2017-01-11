
#ifndef RATIONAL_H
#define RATIONAL_H
//Description: Define non-member functions inside templates when type conversions are desired.
template<typename T>
class Rational{
public:
	Rational(const T &numerator=0, const T &denominator=1);
	Rational(const Rational &r);
	Rational& operator=(const Rational &r);
	const T numerator() const;
	const T denominator() const;
	friend 
	const Rational operator*(const Rational &lhs, const Rational &rhs){
		return Rational(lhs.numerator()*rhs.numerator(),lhs.denominator()*rhs.denominator());
	}
private:
	T nume;
	T deno;
};
template<typename T>
Rational<T>::Rational(const T &numerator, const T &denominator){
	this->nume=numerator;
	this->deno=denominator;
}
template<typename T>
Rational<T>::Rational(const Rational &r){
	nume=r.numerator();
	deno=r.denominator();
}
template<typename T>
Rational<T>& Rational<T>::operator=(const Rational &r){
	nume=r.numerator();
	deno=r.denominator();
	return *this;
}
template<typename T>
const T Rational<T>::numerator() const{
	return nume;
}

template<typename T>
const T Rational<T>::denominator() const{
	return deno;
}
#endif /* RATIONAL_H */