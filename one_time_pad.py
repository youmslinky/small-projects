import random
import string
charList = string.printable
charListLen = len(charList)
dic = dict(zip(charList,range(charListLen)))
def otpad(l):
	secureRandom = random.SystemRandom()
	return ''.join(secureRandom.choice(charList) for i in range(l))

def encrypt(msg,pad):
	ciphertext = ''
	for m,p in zip(msg,pad):
		cc = charList[int(dic[m]+dic[p]) % 26]
		ciphertext += cc
		#print(m,' ',p,' ',cc)
	return ciphertext

def decrypt(msg,pad):
	cleartext = ''
	for m,p in zip(msg,pad):
		cc = charList[int(dic[m]-dic[p]) % 26]
		cleartext += cc
		#print(m,' ',p,' ',cc)
	return cleartext

pad = otpad(100)
message = "hello"
cipherText = encrypt(message,pad)
print('ciphertext: ',cipherText)
clearText = decrypt(cipherText,pad)
print('cleartext:  ',clearText)
print('message:    ',message)
if message == clearText:
	print('SUCCESS')
else:
	print('FAILURE!!!')

#print(dic)
#print(otpad(100))
