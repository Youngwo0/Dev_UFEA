import numpy as np

n = 10_000_000
z = np.random.randn(n)
b = np.zeros(shape = (n+1,))
ito_integral = np.zeros(shape = (n+1, ))
dt = 1 / n
sqrt_dt = np.sqrt(dt)

for i, z_temp in enumerate(z):
	b[i+1] = b[i] + sqrt_dt * z_temp
	db = b[i+1] - b[i]
	betting = b[i]
	pl = betting * db
	ito_integral[i+1] = ito_integral[i] + pl

print(ito_integral[-1])
print(b[-1]**2 / 2 - 0.5)

