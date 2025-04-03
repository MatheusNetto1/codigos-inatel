# Crie uma função `mirror`, que recebe `img` (`np.array`), `reverse_x` (`bool`) e `reverse_y` (`bool`)
#  e retorna uma nova imagem, onde caso `reverse_EIXO` seja verdadeiro,
#  esta deve ser `img` espelhada em EIXO. Em seguida, teste sua função com uma imagem de sua escolha.

import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

# feito pela lib do numpy
def mirror(img: np.array, reverse_x: bool, reverse_y: bool) -> np.array:
    if reverse_x:
        img = np.flip(img, axis=1)
    if reverse_y:
        img = np.flip(img, axis=0)
    return img

# feito no lab
mario = np.array(Image.open('Aula 5/mario.png'))[:, :, :3]
(l, c, p) = mario.shape
def mirror_2(img: np.array, reverse_x: bool, reverse_y: bool) -> np.array:
    if reverse_x:
        mario_refl = np.zeros(shape=mario.shape, dtype=np.uint8)
        mario_refl[::-1, ::1] = mario
    if reverse_y:
        mario_refl = np.zeros(shape=mario.shape, dtype=np.uint8)
        for i in range(l):
            for j in range(c):
                new_x = -j
                new_y = i
                mario_refl[new_y, new_x] = mario[i, j]
    return mario_refl

img = np.array(Image.open('Aula 5/mario.png'))
mirrored_img = mirror(img, reverse_x=True, reverse_y=False)

plt.subplot(1, 2, 1)
plt.title('Imagem Original')
plt.imshow(img)

plt.subplot(1, 2, 2)
plt.title('Imagem Espelhada')
plt.imshow(mirrored_img)

plt.show()