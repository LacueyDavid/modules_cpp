class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other); // copy constructor (peut prendre par copy (sans ref) ou sans const(mais debile))
	Fixed& operator=(const Fixed&); // copy assignement operator (operator overload)
	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int fixedPoint;
	static const int fractionalBits = 8; // static == appartient a la class (namespace)
};
