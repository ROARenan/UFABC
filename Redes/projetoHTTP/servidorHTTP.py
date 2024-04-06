import socket
import os
import random

# globais
DB_FILE = "sample_database.db"

# definicoes de funcoes

def gerar_pagina_index(diretorio):
    # Lista os arquivos na pasta htdocs
    arquivos = os.listdir(diretorio)

    # Filtra apenas os arquivos HTML e ordena-os em ordem alfabética
    arquivos_html = sorted([arquivo for arquivo in arquivos if arquivo.endswith('.html')])

    # Inicializa o conteúdo HTML com o estilo CSS
    html_content = """
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Menu Principal</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f4f4f4;
                margin: 0;
                padding: 0;
            }
            #menu {
                background-color: #333;
                padding: 20px;
                color: white;
            }
            #menu ul {
                list-style-type: none;
                padding: 0;
                margin: 0;
            }
            #menu ul li {
                display: inline;
                margin-right: 20px;
            }
            #menu ul li a {
                color: white;
                text-decoration: none;
            }
            #menu ul li a:hover {
                text-decoration: underline;
            }
        </style>
    </head>
    <body>
        <div id="menu">
            <h1>Menu Principal</h1>
            <ul>
    """

    # Adiciona os links ao menu em ordem alfabética
    for arquivo in arquivos_html:
        html_content += f"<li><a href='{arquivo}'>{arquivo}</a></li>"
    
    # Adiciona a opção "Sortear Imagem" ao menu
    html_content += """
            <li><a href='/sortear_imagem'>Sortear Imagem</a></li>
    """

    # Fecha as tags HTML
    html_content += """
            </ul>
        </div>
    </body>
    </html>
    """

    # Salva o arquivo index.html na pasta htdocs
    with open(os.path.join(diretorio, 'index.html'), 'w') as file:
        file.write(html_content)

    print("Arquivo index.html gerado com sucesso!")
    
def http_get(page_ref: str, client_connection):
    try:
        # abrir o arquivo e enviar para o cliente
        fin = open("htdocs" + page_ref)
        # leio o conteúdo do arquivo para uma variável
        content = fin.read()
        # fecho o arquivo
        fin.close()
        # envia a resposta
        response = "HTTP/1.1 200 OK\n\n" + content

    except FileNotFoundError:
        # caso o arquivo solicitado não exista no servidor, gera uma resposta de erro
        response = "HTTP/1.1 404 NOT FOUND\n\n<h1>ERROR 404!<br>File Not Found!</h1>"

    client_connection.sendall(response.encode())

    client_connection.close()

    return True


def http_put(filename: str, body: str):
    try:
        file_path = os.path.abspath(f"htdocs/{filename}")
        print("Caminho de escrita: ", file_path)

        with open(file_path, "w") as file:
            file.write(body)

        response = "HTTP/1.1 200 OK\n\n" + "Gravacao realizada"
    except:
        response = "HTTP/1.1 404 NOT FOUND\n\n<h1>ERROR 404!<br>File Not Found!</h1>"

    client_connection.sendall(response.encode())

    client_connection.close()

    return response

def recvall(sock):
    BUFF_SIZE = 4096
    data = b''
    while True:
        part = sock.recv(BUFF_SIZE)
        data += part
        if len(part) < BUFF_SIZE:
            break
    return data

def extract_put_body(request):
    lines = request.split("\n")
    
    body = ""

    for line in lines:
        if line.startswith("Content-Length:"):
            content_length = int(line.split(": ")[1])
            break

    body_index = request.find("\r\n\r\n") + 4

    body = request[body_index:]
    
    return body

def send_image(conn, img_folder):
    try:
        img_files = [f for f in os.listdir(img_folder) if os.path.isfile(os.path.join(img_folder, f))]
        if not img_files:
            print(f"Nenhuma imagem encontrada na pasta {img_folder}.")
            return

        img_filename = random.choice(img_files)
        img_path = os.path.join(img_folder, img_filename)

        with open(img_path, 'rb') as file:
            data = file.read()
            conn.sendall(data)

        print(f"Imagem {img_filename} enviada com sucesso.")
    except FileNotFoundError:
        print(f"Erro: Arquivo {img_filename} não encontrado.")

# definindo o endereço IP do host
SERVER_HOST = ""
SERVER_PORT = 8080

# vamos criar o socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind((SERVER_HOST, SERVER_PORT))

# coloca o socket para escutar por conexões
server_socket.listen(1)

# mensagem inicial do servidor
print("Servidor em execução...")
print("Escutando por conexões na porta %s" % SERVER_PORT)

while True:
    # espera por conexões
    gerar_pagina_index('htdocs')
    client_connection, client_address = server_socket.accept()

    request = recvall(client_connection).decode()

    if request:
        # imprime a solicitação do cliente
        print(request)

        # analisa a solicitação HTTP
        headers = request.split("\n")
        for header in headers:
            if header.startswith("Content-Length:"):
                content_length = int(header.split(": ")[1])
                break

        # pega o nome do arquivo sendo solicitado
        filename = headers[0].split()[1]
        method = headers[0].split()[0]

        # verifica qual arquivo está sendo solicitado e envia a resposta para o cliente
        if filename == "/":
            filename = "/index.html"

        # verifica o tipo de request
        if method == "GET":
            print("Solicitacao GET recebida")
            http_get(filename, client_connection)
        elif method == "PUT":
            print("Solicitacao PUT recebida")
            body = extract_put_body(request)
            http_put(
                "new_HTML.html", body)

server_socket.close()
