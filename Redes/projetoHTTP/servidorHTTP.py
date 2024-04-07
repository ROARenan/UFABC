import socket
import os
import random

# globais
DB_FILE = "sample_database.db"
IMG_FOLDER = "htdocs/img"  # Pasta onde as imagens estão localizadas

# definicoes de funcoes


def gerar_pagina_index(diretorio):
    # Lista os arquivos na pasta htdocs
    arquivos = os.listdir(diretorio)

    # Filtra apenas os arquivos HTML e ordena-os em ordem alfabética
    arquivos_html = sorted(
        [arquivo for arquivo in arquivos if arquivo.endswith('.html')])

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
                    #sample_img {
            text-align: center;
        }
        #sample_img img {
            width: 100%;
            height: auto;
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

    # Fecha as tags HTML
    html_content += """
            </ul>
        </div>
        <div id= "sample_img">
        <p>
        <img src="img/nrede_gif.gif" alt="Example Image">
        </p>
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
        if page_ref == "/images_generate.html":
            # Se a requisição for para gerar uma imagem
            if False != generate_html_with_image(IMG_FOLDER):
                fin = open("htdocs" + page_ref, 'rb')
                content = fin.read()
                fin.close()
                response = "HTTP/1.1 200 OK\n\n".encode() + content
                client_connection.sendall(response)

        else:
            fin = open("htdocs" + page_ref, 'rb')
            content = fin.read()
            fin.close()
            response = "HTTP/1.1 200 OK\n\n".encode() + content
            client_connection.sendall(response)

    except FileNotFoundError:
        response = "HTTP/1.1 404 NOT FOUND\n\n<h1>ERROR 404!<br>File Not Found!</h1>".encode()
        client_connection.sendall(response)

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

    body = b""

    for line in lines:
        if line.startswith("Content-Length:"):
            content_length = int(line.split(": ")[1])
            break

    body_index = request.find("\r\n\r\n") + 4

    body = request[body_index:]

    return body


def generate_html_with_image(img_folder):
    try:
        img_files = [f for f in os.listdir(
            img_folder) if os.path.isfile(os.path.join(img_folder, f))]
        if not img_files:
            print(f"Nenhuma imagem encontrada na pasta {img_folder}.")
            return ""

        img_filename = random.choice(img_files)
        img_path = os.path.join(img_folder, img_filename)

        html = f"""
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Simple Image Example</title>
        </head>
        <body>
            <h1>Simple Image Example</h1>
            <img src="{img_path}" alt="{img_filename}">
        </body>
        </html>
        """

        print(f"HTML com imagem {img_filename} gerado com sucesso.")
        return img_filename
    except FileNotFoundError:
        print(f"Erro: Arquivo {img_filename} não encontrado.")
        return False


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
            http_put("put_HTML.html", body)

server_socket.close()
