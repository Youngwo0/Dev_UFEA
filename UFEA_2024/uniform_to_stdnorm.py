import numpy as np

n = 10_000
def uniform_to_stdnorm(n):
	z = np.random.randn(n)
	uni = np.zeros(shape = (n+1, ))
	for i in range(n):
		uni[i] = sum(np.random.uniform(0, 1, 12)) - 6
	return np.mean(z), np.mean(uni)
	
print(uniform_to_stdnorm(n))