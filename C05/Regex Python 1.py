import re

txt = "Viver é acalentar sonhos e esperanças, fazendo da fé a nossa inspiração maior. É buscar nas pequenas coisas, um grande motivo para ser feliz."

x = re.search("(sonhos)", txt)

if x:
    print("PERFEITO! tivemos um match no teste :)")
else:
    print("Não tivemos um match no teste :(")