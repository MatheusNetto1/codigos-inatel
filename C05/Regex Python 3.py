import re

txt = "Viver é acalentar sonhos e esperanças, fazendo da fé a nossa inspiração maior. É buscar nas pequenas coisas, um grande motivo para ser feliz."

x = re.sub("maior", "surreal", txt)
x = re.sub("grande", "surreal", x)

print(x)