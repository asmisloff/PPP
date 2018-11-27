def main():
	grains = 1
	for i in range(64):
		grains *= 2
		print(f"{i+1} : {grains} grains")

if __name__ == '__main__':
	main()