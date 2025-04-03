# Escolha uma imagem qualquer e realize um cisalhamento nela, sendo os fatores de sua escolha.

import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

# Carregar a imagem
image_path = 'Aula 5/mario.png'  # Substitua pelo caminho da sua imagem
image = Image.open(image_path)
image_array = np.array(image)

# Definir os fatores de cisalhamento
shear_factor_x = 0.5  # Fator de cisalhamento em x
shear_factor_y = 0.0  # Fator de cisalhamento em y

# Criar a matriz de cisalhamento
shear_matrix = np.array([[1, shear_factor_x],
                         [shear_factor_y, 1]])

# Aplicar o cisalhamento
height, width, channels = image_array.shape
new_width = int(width + height * shear_factor_x)
new_height = int(height + width * shear_factor_y)

sheared_image = np.zeros((new_height, new_width, channels), dtype=image_array.dtype)

for y in range(height):
    for x in range(width):
        new_x = int(x + y * shear_factor_x)
        new_y = int(y + x * shear_factor_y)
        sheared_image[new_y, new_x] = image_array[y, x]

# Exibir a imagem original e a imagem cisalhada
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.title('Imagem Original')
plt.imshow(image_array)
plt.axis('off')

plt.subplot(1, 2, 2)
plt.title('Imagem Cisalhada')
plt.imshow(sheared_image)
plt.axis('off')

plt.show()