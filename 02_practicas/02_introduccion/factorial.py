def factorial(num):
	if num == 0:
		return 1
	else:
		return (num * factorial(num-1))

num = float(input("Calcular el factorial de : \n"))
print("El factorial de ",num,"es :",factorial(300))