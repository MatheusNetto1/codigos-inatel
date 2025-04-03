import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

def rgb_to_hsv(img_rgb: np.array):
    img_rgb = img_rgb / 255.0
    
    img_hsv = np.zeros_like(img_rgb)
    
    l, c, p = img_rgb.shape
    
    for i in range(l):
        for j in range(c):
            r, g, b = img_rgb[i, j]
            
            c_max = max(r, g, b)
            c_min = min(r, g, b)
            delta = c_max - c_min
        
            if delta == 0:
                h = 0
            elif c_max == r:
                h = 60 * ((g - b) / delta)
                if g < b:
                    h += 360
            elif c_max == g:
                h = 60 * ((b - r) / delta) + 120
            else:
                h = 60 * ((r - g) / delta) + 240
            
            if c_max == 0:
                s = 0
            else:
                s = delta / c_max
            
            v = c_max
            
            img_hsv[i, j] = [h / 360.0, s, v]
    
    return img_hsv
    
img = Image.open("Aula 6/colors_rgb.png")
img_rgb = np.array(img)

img_hsv = rgb_to_hsv(img_rgb)
img_hsv_verify = np.array(img.convert('HSV'))[:,:,:3]

plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.imshow(img_rgb)
plt.title("Imagem RGB")

plt.subplot(1, 2, 2)
plt.imshow(img_hsv)
plt.title("Imagem Convertida para HSV")
plt.show()