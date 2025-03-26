// • swap: Swaps the values of two given parameters. Does not return anything.
template <typename Banana>
void swap(Banana& a, Banana& b)
{
	Banana temp = a;
	a = b;
	b = temp;
}

// • min: Compares the two values passed as parameters and returns the smallest one.
// If they are equal, it returns the second one.
template <typename Banana>
Banana min(Banana a, Banana b)
{
	if (a < b)
		return a;
	else
		return b;
}
// • max: Compares the two values passed as parameters and returns the greatest one.
// If they are equal, it returns the second one.
template <typename Banana>
Banana max(Banana a, Banana b)
{
	if (a > b)
		return a;
	else
		return b;
}