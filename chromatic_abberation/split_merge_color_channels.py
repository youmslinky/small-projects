#splits then merges the color channels in an image

import sys
import random
import string
from PIL import Image
import PIL

def save_image_random_name(img,filenamelen=10):
    filename = ''.join(random.choice(string.ascii_lowercase) for i in range(filenamelen))
    img.save(filename+".png","PNG")

try:
    img = Image.open(sys.argv[1])
    r,g,b = img.split()
    x = img.size[0]//10
    y = img.size[1]//10
    r = PIL.ImageChops.offset(r,x,0)
    b = PIL.ImageChops.offset(b,-x,y)
    #import pdb; pdb.set_trace()
    #r = r.rotate(1)
    #b = b.rotate(-1)
    img_channel_swapped = Image.merge("RGB",(r,g,b))
    img_channel_swapped.show()
    save_image_random_name(img_channel_swapped)

except IOError:
    print("need at least one input file name")
