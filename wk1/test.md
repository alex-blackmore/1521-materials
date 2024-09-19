## Week 1
### intro
#### solution
Perform the requested steps in the binary:
```python
from pwn import *
import re
context(arch = 'i386', os = 'linux')

r = remote('ctfd.6447.lol', 18231)
print(r.read().decode('utf-8'))
r.sendline(str.encode('4919', 'utf-8'))
print(r.read().decode('utf-8'))
r.sendline(str.encode('0x1234', 'utf-8'))
print(r.read().decode('utf-8'))
r.sendline(str.encode('\x37\x13', 'utf-8'))
print(r.readline().decode('utf-8'))
print(r.readline().decode('utf-8'))
l = r.readline()[:-1]
print(l.decode('utf-8'))
print(f'reply with {unpack(l)}')
r.sendline(str.encode(str(unpack(l)), 'utf-8'))
print(r.read().decode('utf-8'))
print(r.read().decode('utf-8'))
r.sendline(str.encode(hex(unpack(l)), 'utf-8'))
n1, n2 = re.findall(r'(\d+) \+ (\d+)', r.read().decode('utf-8'))[0]
r.sendline(str.encode(str(int(n1) + int(n2)), 'utf-8'))
print(r.read().decode('utf-8'))
r.sendline(str.encode('3735928559'))
r.sendline(str.encode(str(unpack(r.read()[-9:-1], 64))))
print(r.read().decode('utf-8'))
r.interactive()
```
Flag located at `/flag`
#### yapping
### too-slow
#### solution
Create a script to answer the maths questions quickly
```python
from pwn import *
import re
context(arch = 'i386', os = 'linux')

r = remote('ctfd.6447.lol', 14292)
while q := r.read().decode('utf-8'):
	if '+' not in q:
    	r.interactive()
	# find the problem
	n1, n2 = [int(e) for e in re.findall(r'([0-9]+) \+ ([0-9]+)', q)[0]]
	print(f'send answer {n1 + n2}')
	r.sendline(str.encode(str(n1 + n2), 'utf-8'))
```
Flag located at `/flag`
#### yapping