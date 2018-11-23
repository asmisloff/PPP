using System;

class App {
	public static void Main()
	{
		while (true) {
			Console.Write("Введите число: ");
			string input = Console.ReadLine();

			int number;
			bool isParsed = Int32.TryParse(input, out number);

			if (isParsed) {
				Console.WriteLine(words[number]);
			}
			else {
				int i = Array.IndexOf(words, input);
				if (i != -1) {
					Console.WriteLine(numbers[i]);
				}
			}
		}
	}
	static int[] numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	static string[] words = {"zero", "one", "two", "three", "four", "five", "six",
                            "seven", "eight", "nine"};
}