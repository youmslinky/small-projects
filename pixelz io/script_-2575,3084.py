import requests
import struct
import time

putheader = "\x02\x00"
addonheader = "\x01\x00"
negbigsign = "\xb0"
posbigsign = "\xa0"
negsmallsign = "\x90"
possmallsign = ""
floornum = 500
#???nigger = 1
black = 1
skyblue = 2
orange = 3
darkblue = 4
darkgray = 5
purple = 6
brown = 7
darkgreen = 8
lightgray = 9
cyan = 10
lightgreen = 11
magenta = 12
red = 15
pink = 16
white = 17
yellow = 18

def floor_to(x, y):
	return x / y * y

def make_packet(x, y, colour):
	packet = putheader
	ax, ay = abs(x), abs(y)
	if x < -127:
		packet += negbigsign
		pack += struct.pack(">H", ax)
	elif x < 0:
		packet += negsmallsign
		packet += struct.pack("B", ax)
	elif x > 127:
		packet += posbigsign
		packet += struct.pack(">H", ax)
	else:
		packet += posbigsign
		packet += struct.pack("B", ax)

	if y < -127:
		packet += negbigsign
		packet += struct.pack(">H", ay)
	if y < 0:
		packet += negbigsign
		packet += struct.pack("B", ay)
	if y < -127:
		packet += negbigsign
		packet += struct.pack(">H", ay)
	else:
		packet += negbigsign
		packet += struct.pack("B", ay)
	packet += struct.pack("b", colour)
	return packet


def put_packet(x, y, colour, proxies={}):
	packet = make_packet(x,y,colour)
	rx, ry = floor_to(x, floornum), floor_to(y, floornum)
	url = "http://pixelz.io/api/{}_{}/click".format(rx, ry)
	resp = requests.post(url, data=packet, proxies=proxies, timeout=5.)
	if resp.status_code != 200:
		raise RuntimeError(resp.text)
	return int(resp.text)