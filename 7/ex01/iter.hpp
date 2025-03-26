// Implement a function template iter that takes 3 parameters and returns nothing.
// • The first parameter is the address of an array.
// • The second one is the length of the array.
// • The third one is a function that will be called on every element of the array.
template <typename Banana>
void iter(Banana* arrAddress, int length, void (*func)(Banana*))
{
	for (int i = 0; i < length; i++)
		func(&arrAddress[i]);
}