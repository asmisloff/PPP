using System;

class App
{
	public static void Main()
	{
		ulong grains = 1;
		for	(int i = 0; i < 64; i++) {
			Console.WriteLine($"{i+1} : {grains *= 2} grains");
		}
	}
}