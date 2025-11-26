import random
import string

random_string = ''.join(random.choices(string.ascii_lowercase, k=3))

with open('file.txt', 'w') as f:
    f.write(random_string)
