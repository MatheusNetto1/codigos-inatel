import re

txt = "Viver é acalentar sonhos e esperanças, fazendo da fé a nossa inspiração maior. É buscar nas pequenas coisas, um grande motivo para ser feliz."

for x in re.finditer("[a-z]*[éÉ][a-z]*", txt):
    print(x.group())