while (True):
	s = input("Введите число: ")

	numbers = range(10)
	words = ("zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine")

	try:
		number = int(s)
		print(words[number])
	except:
		try:
			i = words.index(s)
			print(numbers[i])
		except:
			print("Неизвестное число");