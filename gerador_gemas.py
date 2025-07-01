import json
import random

def gerar_cor_hex():
    return "#{:02X}{:02X}{:02X}".format(
        random.randint(0, 255),
        random.randint(0, 255),
        random.randint(0, 255)
    )

def gerar_gemas(qtd=100, nome_arquivo='gemas2.txt'):
    with open(nome_arquivo, 'w') as f:
        for i in range(1, qtd + 1):
            gema = {
                "id": i,
                "cor": gerar_cor_hex()
            }
            f.write(json.dumps(gema, separators=(',', ':')) + '\n')
    print(f"{qtd} gemas geradas e salvas em '{nome_arquivo}'")

if __name__ == "__main__":
    gerar_gemas(qtd=100)
