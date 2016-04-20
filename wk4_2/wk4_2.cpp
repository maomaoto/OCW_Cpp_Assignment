MyInt & operator-(const MyInt & operand2){
	nVal -= operand2.nVal;
	return *this;
}